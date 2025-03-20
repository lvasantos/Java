package RMI;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import java.util.Date;

import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.text.SimpleDateFormat;

public class ChatClientGUI extends Application implements InterfaceChatClient {
    private InterfaceChatServer server;
    private String username;
    private TextArea chatArea;
    private TextField messageField;
    private TextField usernameField;
    private Button sendButton;

    public static void main(String[] args) {
        launch(args);
    }
    
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("RMI Chat");
    
        chatArea = new TextArea();
        chatArea.setEditable(false);
    
        usernameField = new TextField();
        usernameField.setPromptText("Enter your username...");
    
        messageField = new TextField();
        messageField.setPromptText("Type your message...");
        
        sendButton = new Button("Send");
        sendButton.setOnAction(e -> sendMessage());
    
        Button connectButton = new Button("Connect");
        connectButton.setOnAction(e -> connectToServer());
    
        VBox layout = new VBox(10, usernameField, connectButton, chatArea, messageField, sendButton);
        Scene scene = new Scene(layout, 400, 300);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    
    private void connectToServer() {
        try {
            if (usernameField.getText().isEmpty()) {
                chatArea.appendText("Please enter a username before trying to connect.\n");
                return;
            }
    
            username = usernameField.getText();
            server = (InterfaceChatServer) Naming.lookup("rmi://localhost/ChatServer");
            
            UnicastRemoteObject.exportObject(this, 0);
            // server.connect(username, "rmi://localhost/" + username);
            server.connect(username, this);
    
            chatArea.appendText("Connected as: " + username + "\n");
            usernameField.setDisable(true);
            sendButton.setDisable(false);
    
        } catch (Exception e) {
            e.printStackTrace();
            chatArea.appendText("Failed to connect to server.\n");
        }
    }
    
    private void sendMessage() {
        String message = messageField.getText();
        if (!message.isEmpty()) {
            try {
            String timeStamp = new SimpleDateFormat("HH:mm:ss").format(new Date());
            // server.broadcastMessage(new Message(username, "(" + timeStamp + ") " + message));
            server.broadcastMessage(new Message(username,message));
            messageField.clear();
            
            // messageField.clear();
            // chatArea.appendText("(" + timeStamp + ") " + username + ": " + message + "\n");
            } catch (RemoteException e) {
                e.printStackTrace();
                chatArea.appendText("Error sending message.\n");
            }
        }
    }
    
    // @Override
    // public void diffuseMessage(Message m) throws RemoteException {
    //     chatArea.appendText("(" + m.getPseudo() + "): " + m.getMessage() + "\n");
    // }
    @Override
    public void diffuseMessage(Message m) throws RemoteException {
    javafx.application.Platform.runLater(() -> {
        chatArea.appendText(m.getMessage() + "\n");
    });
}


}