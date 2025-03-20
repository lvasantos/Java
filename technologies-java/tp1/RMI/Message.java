package RMI;
import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Message implements Serializable {
    private String pseudo;
    private String msg;
    private String timestamp;

    public Message(String pseudo, String msg) {
        this.pseudo = pseudo;
        this.msg = msg;
        this.timestamp = new SimpleDateFormat("HH:mm:ss").format(new Date());
    }

    public String getPseudo() { return pseudo; }
    public String getMessage() { return msg; }
    public String getTimestamp() { return timestamp; }

    @Override
    public String toString() {
        return "("+ timestamp +") " + pseudo + ": " + msg;
    }
}
