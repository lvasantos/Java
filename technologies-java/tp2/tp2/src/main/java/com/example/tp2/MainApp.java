package com.example.tp2;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class MainApp extends Application {

    @Override
    public void start(Stage stage) throws Exception {
         FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("/com/example/tp2/main-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 800, 600);
        stage.setResizable(false);
        stage.setTitle("TP2 - Image Viewer (Luciana ADRIÃO)");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
    
}
