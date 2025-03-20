package Sockets;
import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        int port = 5050;

        try (ServerSocket server = new ServerSocket(port)) {
            System.out.println("Server awaits connections on port " + port);

            while (true) {
                Socket client = server.accept();
                System.out.println("Client connected: " + client.getInetAddress());
                new Thread(new ClientManipul(client)).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class ClientManipul implements Runnable {
    private Socket socket;

    public ClientManipul(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        try (
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
        ) {
            String directory = input.readLine();
            if (directory == null) {
                System.out.println("Error: No directory received.");
                output.println("-1");
                return;
            }

            System.out.println("Received directory request: " + directory);
            File folder = new File(directory);
            System.out.println("Checking directory: " + folder.getAbsolutePath());

            if (folder.exists() && folder.isDirectory()) {
                File[] files = folder.listFiles();
                if (files != null) {
                    output.println(files.length);
                    output.flush();

                    if (files.length == 0) {
                        System.out.println("Directory is empty.");
                    } else {
                        for (File file : files) {
                            output.println(file.getName());
                            output.flush(); 
                        }
                    }
                } else {
                    System.out.println("Error reading directory.");
                    output.println("-1");
                }
            } else {
                System.out.println("Directory does not exist.");
                output.println("-1");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
