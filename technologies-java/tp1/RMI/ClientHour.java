package RMI;
import java.rmi.*;

public class ClientHour {
    public static void main(String[] args) {
        try {
            InterfaceServerHour server = (InterfaceServerHour) Naming.lookup("ServerHour");
            System.out.println("Time of the server: " + server.getHour());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
