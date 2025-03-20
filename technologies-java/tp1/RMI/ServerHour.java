package RMI;

import java.rmi.*;
import java.rmi.server.*;
import java.util.Calendar;

public class ServerHour extends UnicastRemoteObject implements InterfaceServerHour {
    public ServerHour() throws RemoteException {
        super();
    }

    @Override
    public String getHour() throws RemoteException {
        return Calendar.getInstance().getTime().toString();
    }

    public static void main(String[] args) {
        try {
            ServerHour server = new ServerHour();
            Naming.rebind("ServerHour", server);
            System.out.print("Time server seend~~");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}
