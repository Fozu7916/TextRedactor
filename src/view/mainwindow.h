#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../player/player.h"
#include "../model/track.h"
#include "../controller/playercontroller.h"
#include <QListWidgetItem>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addTrackToList(const QString& name);
    void deleteTrackFromList(int index);
    void setCurrentRow(int index);
    void onPlayOrStopUI(bool isPlaying);
    
private slots:
    int getDuration(QString filePath);
    void on_playOrStopButton_clicked();
    void on_addButton_clicked();
    void on_TrackLists_itemClicked(QListWidgetItem *item);
    void on_deleteButton_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    void on_horizontalSlider_sliderMoved(int position);
private:
    Ui::MainWindow *ui;
    std::vector<Track> trackList;
    QTimer *sliderTimer;
    std::unique_ptr<PlayerController> playerController;

};

#endif // MAINWINDOW_H



