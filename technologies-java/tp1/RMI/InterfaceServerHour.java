package RMI;
import java.rmi.*;

public interface InterfaceServerHour extends Remote {
    public String getHour() throws RemoteException;
}
