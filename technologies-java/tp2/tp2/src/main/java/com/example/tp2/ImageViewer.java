package com.example.tp2;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.io.File;
import java.io.Serializable;
import java.util.Arrays;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class ImageViewer extends ImageView implements Serializable {
    private static final long serialVersionUID = 1L;

    private final StringProperty directory = new SimpleStringProperty();
    private final IntegerProperty imageCount = new SimpleIntegerProperty();
    private final BooleanProperty loopMode = new SimpleBooleanProperty();

    private File[] images;
    private int currentIndex = 0;

    private final PropertyChangeSupport support = new PropertyChangeSupport(this);

    public ImageViewer() {
        directory.addListener((obs, oldDir, newDir) -> loadImages(newDir));
    }

    public void addPropertyChangeListener(PropertyChangeListener listener) {
        support.addPropertyChangeListener(listener);
    }

    public void removePropertyChangeListener(PropertyChangeListener listener) {
        support.removePropertyChangeListener(listener);
    }

    public String getDirectory() {
        return directory.get();
    }

    public void setDirectory(String dir) {
        this.directory.set(dir);
    }

    public StringProperty directoryProperty() {
        return directory;
    }

    public int getCurrentIndex() {
        return currentIndex;
    }

    public void setCurrentIndex(int index) {
        currentIndex = index;
        support.firePropertyChange("currentIndex", null, index);
    }

    public int getImageCount() {
        return imageCount.get();
    }

    public void setImageCount(int count) {
        int oldCount = this.imageCount.get();
        this.imageCount.set(count);
        support.firePropertyChange("imageCount", oldCount, count);
    }

    public IntegerProperty imageCountProperty() {
        return imageCount;
    }

    public boolean isLoopMode() {
        return loopMode.get();
    }

    public void setLoopMode(boolean loop) {
        this.loopMode.set(loop);
    }

    public BooleanProperty loopModeProperty() {
        return loopMode;
    }

    private void loadImages(String dirPath) {
        File dir = new File(dirPath);
        if (dir.exists() && dir.isDirectory()) {
            images = dir.listFiles((d, name) -> name.toLowerCase().endsWith(".jpg") || name.toLowerCase().endsWith(".png"));
            if (images != null) {
                Arrays.sort(images);
                setImageCount(images.length);
                if (images.length > 0) {
                    setCurrentIndex(0);
                    setImage(new Image(images[0].toURI().toString()));
                }
            }
        }
    }

    public void resetIndex() {
        setCurrentIndex(0);
    }

    public void showFirstImage() {
        if (images != null && images.length > 0) {
            setCurrentIndex(0);
            setImage(new Image(images[currentIndex].toURI().toString()));
        }
    }

    public void showLastImage() {
        if (images != null && images.length > 0) {
            setCurrentIndex(images.length - 1);
            setImage(new Image(images[currentIndex].toURI().toString()));
        }
    }

    public void showNextImage() {
        if (images != null && images.length > 0) {
            if (currentIndex < images.length - 1) {
                setCurrentIndex(currentIndex + 1);
            } else if (loopMode.get()) {
                setCurrentIndex(0);
            } else {
                return;
            }
            setImage(new Image(images[currentIndex].toURI().toString()));
        }
    }

    public void showPreviousImage() {
        if (images != null && images.length > 0) {
            if (currentIndex > 0) {
                setCurrentIndex(currentIndex - 1);
            } else if (loopMode.get()) {
                setCurrentIndex(images.length - 1);
            } else {
                return;
            }
            setImage(new Image(images[currentIndex].toURI().toString()));
        }
    }
}
