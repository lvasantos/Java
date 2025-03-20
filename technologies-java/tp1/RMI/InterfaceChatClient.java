package RMI;
import java.rmi.*;

public interface InterfaceChatClient extends Remote {
    public void diffuseMessage(Message m) throws RemoteException;
}
