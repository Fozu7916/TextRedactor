#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "../player/player.h"
#include "../model/track.h"
#include <vector>
#include <memory>
#include <QObject>

class PlayerController : public QObject
{
    Q_OBJECT
public:
    PlayerController();
    void saveTracks(QString filename);
    void loadTracks(QString filename);
    void addTrack(const QString& filePath, int durationSec);
    void deleteTrack();
    void onItemClicked(int index);
    void playPrev();
    void playNext();
    void playOrStop();
    void setVolume(int value);
    // Getters and setters for all variables
    const std::vector<Track>& getTracks() const;
    int getTrackCount() const;
    const Track& getTrack(int index) const;
    void removeTrack(int index);
    void clearTracks();
    void setCurrentIndex(int index);
    int getCurrentIndex() const;
    Player* getPlayer() const;
signals:
    void trackLoaded(const QString& name);
    void trackDeleted(int index);
    void setCurrentRow(int index);
    void playOrStopUI(bool isPlaying);
private:
    std::vector<Track> tracks;
    std::unique_ptr<Player> player;
    bool isPlayed = false;
    int currentTrackIndex = -1;
    void playTrackAtIndex(int index);
};

#endif // PLAYERCONTROLLER_H