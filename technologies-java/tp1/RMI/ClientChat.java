package RMI;

import java.rmi.*;
import java.rmi.server.*;
import java.util.Scanner;

public class ClientChat extends UnicastRemoteObject implements InterfaceChatClient {
    private InterfaceChatServer server;
    private String pseudo;

    public ClientChat(String pseudo) throws RemoteException {
        this.pseudo = pseudo;
        try {
            Naming.rebind("rmi://localhost/" + pseudo, this);
            server = (InterfaceChatServer) Naming.lookup("rmi://localhost/ChatServer");
            // server.connect(pseudo, "rmi://localhost/" + pseudo);
            server.connect(pseudo, this);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void diffuseMessage(Message msg) throws RemoteException {
        System.out.println("(" + msg.getPseudo() + "): " + msg.getMessage());
    }

    public void sendMessage(String msg) throws RemoteException {
        server.broadcastMessage(new Message(pseudo, msg));
    }

    public void disconnect() throws RemoteException {
        server.disconnect(pseudo);
        System.out.println("Disconnected.");
    }

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter your pseudo: ");
            String pseudo = scanner.nextLine();
            
            ClientChat client = new ClientChat(pseudo);

            while (true) {
                System.out.print("> ");
                String msg = scanner.nextLine();

                if (msg.equalsIgnoreCase("exit")) {
                    client.disconnect();
                    break;
                }

                client.sendMessage(msg);
            }
            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
