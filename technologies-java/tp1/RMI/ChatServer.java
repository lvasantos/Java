package RMI;

import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class ChatServer extends UnicastRemoteObject implements InterfaceChatServer {
    private  Map<String, InterfaceChatClient> clients = new HashMap<>();

    public ChatServer() throws RemoteException {}

    // @Override
    // public synchronized void connect(String pseudo, String url) throws RemoteException {
    //     try {
    //         InterfaceChatClient client = (InterfaceChatClient) Naming.lookup(url);
    //         clients.put(pseudo, client);
    //         System.out.println(pseudo + " connected.");
    //     } catch (Exception e) {
    //         e.printStackTrace();
    //     }
    // }
    @Override
    public synchronized void connect(String pseudo, InterfaceChatClient client) throws RemoteException {
        clients.put(pseudo, client);
        System.out.println(pseudo + " connected.");
    }


    @Override
    public synchronized void disconnect(String pseudo) throws RemoteException {
        clients.remove(pseudo);
        System.out.println(pseudo + " disconnected.");
    }

    @Override
    public synchronized void broadcastMessage(Message msg) throws RemoteException {
    String timeStamp = new SimpleDateFormat("HH:mm:ss").format(new Date());
    String formattedMessage = "(" + timeStamp + ") " + msg.getPseudo() + ": " + msg.getMessage();

    System.out.println(formattedMessage);

    for (InterfaceChatClient client : clients.values()) {
        client.diffuseMessage(new Message(msg.getPseudo(), formattedMessage)); 
    }
}

    public static void main(String[] args) {
        try {
            LocateRegistry.createRegistry(1099);
            ChatServer server = new ChatServer();
            Naming.rebind("rmi://localhost/ChatServer", server);
            System.out.println("Server chat started.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
