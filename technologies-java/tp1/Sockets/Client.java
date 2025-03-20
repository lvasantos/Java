package Sockets;
import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        String server = "127.0.0.1";
        int port = 5050;

        try (
            Socket socket = new Socket(server, port);
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in))
        ) {
            System.out.print("Directory path: ");
            String dir = keyboard.readLine();
            output.println(dir);
            System.out.println("Sent directory path to server: " + dir);

            String response = input.readLine();
            if (response == null) {
                System.out.println("Error: No response from server.");
                return;
            }

            int numFiles = Integer.parseInt(response);
            if (numFiles == -1) {
                System.out.println("Error: Invalid directory.");
            } else {
                System.out.println("Files in directory:");
                for (int i = 0; i < numFiles; i++) {
                    String fileName = input.readLine();
                    if (fileName != null) {
                        System.out.println(fileName);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
