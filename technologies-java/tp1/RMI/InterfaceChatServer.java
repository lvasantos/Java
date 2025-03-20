package RMI;
import java.rmi.*;

public interface InterfaceChatServer extends Remote {
    // void connect(String pseudo, String url) throws RemoteException;
    void connect(String pseudo, InterfaceChatClient client) throws  RemoteException;
    void disconnect(String pseudo) throws RemoteException;
    void broadcastMessage(Message msg) throws RemoteException;
}
