package com.example.tp2;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.fxml.FXML;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.stage.DirectoryChooser;
import javafx.util.Duration;

import java.io.File;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

public class MainController {
    @FXML
    private ImageViewer imageViewer;

    @FXML
    private CheckBox chkSlideshowMode;

    @FXML
    private CheckBox chkLoopMode;

    private Timeline slideshowTimeline;

    @FXML
    private Label lblImageCount;

    @FXML
    private Slider sliderDuration;

    @FXML
    public void initialize() {
        sliderDuration.valueProperty().addListener((obs, oldVal, newVal) -> updateSlideshowSpeed(newVal.doubleValue()));

        chkLoopMode.selectedProperty().addListener((obs, oldVal, newVal) -> imageViewer.setLoopMode(newVal));

        imageViewer.addPropertyChangeListener(new PropertyChangeListener() {
            @Override
            public void propertyChange(PropertyChangeEvent evt) {
                if ("imageCount".equals(evt.getPropertyName()) || "currentIndex".equals(evt.getPropertyName())) {
                    updateImageCountLabel();
                }
            }
        });

        updateImageCountLabel(); // init counter
    }

    private void updateImageCountLabel() {
        if (imageViewer.getImageCount() > 0) {
            lblImageCount.setText((imageViewer.getCurrentIndex() + 1) + "/" + imageViewer.getImageCount());
        } else {
            lblImageCount.setText("0/0");
        }
    }

    private void updateSlideshowSpeed(double newDuration) {
        if (slideshowTimeline != null && chkSlideshowMode.isSelected()) {
            slideshowTimeline.stop();
            slideshowTimeline.getKeyFrames().setAll(
                    new KeyFrame(Duration.seconds(newDuration), event -> {
                        imageViewer.showNextImage();
                        updateImageCountLabel();
                    })
            );
            slideshowTimeline.play();
        }
    }

    @FXML
    private void toggleSlideshow() {
        if (chkSlideshowMode.isSelected()) {
            System.out.println("Slide ativado");

            if (slideshowTimeline != null) {
                slideshowTimeline.stop();
            }

            slideshowTimeline = new Timeline(
                    new KeyFrame(Duration.seconds(sliderDuration.getValue()), event -> {
                        if (imageViewer.getImageCount() > 0) {
                            if (imageViewer.getCurrentIndex() < imageViewer.getImageCount() - 1) {
                                imageViewer.showNextImage();
                            } else if (imageViewer.isLoopMode()) {
                                imageViewer.showFirstImage();
                            } else {
                                slideshowTimeline.stop();
                            }
                            updateImageCountLabel();
                        }
                    })
            );
            slideshowTimeline.setCycleCount(Timeline.INDEFINITE);
            slideshowTimeline.play();
        } else {
            System.out.println("Slide desativado");
            if (slideshowTimeline != null) {
                slideshowTimeline.stop();
            }
        }
        updateImageCountLabel();
    }

    @FXML
    private void selectDirectory() {
        File selectedDirectory = new DirectoryChooser().showDialog(null);
        if (selectedDirectory != null) {
            System.out.println("Repertoire selectione: " + selectedDirectory.getAbsolutePath());
            imageViewer.setDirectory(selectedDirectory.getAbsolutePath());
            imageViewer.resetIndex();
            imageViewer.showFirstImage();
        }
        updateImageCountLabel();
    }

    @FXML
    private void showFirstImage() {
        imageViewer.showFirstImage();
        updateImageCountLabel();
    }

    @FXML
    private void showLastImage() {
        imageViewer.showLastImage();
        updateImageCountLabel();
    }

    @FXML
    private void showNextImage() {
        imageViewer.showNextImage();
        updateImageCountLabel();
    }

    @FXML
    private void showPreviousImage() {
        imageViewer.showPreviousImage();
        updateImageCountLabel();
    }
}
