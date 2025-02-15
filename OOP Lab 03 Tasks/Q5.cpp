//Samiya Khan
//24K-0768
//Task 05

#include <iostream>
#include <string>
using namespace std;

const int MAX_SONGS = 150;

class MusicPlayer{

private:
    string playlist[MAX_SONGS];
    int total_songs;
    string currentlyPlayingSong;

public:
    MusicPlayer()
    {
        total_songs = 0;
        currentlyPlayingSong = "No song is currently playing!!";
    }

    void add_song(string song)
    {
        if (total_songs < MAX_SONGS)
        {
            playlist[total_songs] = song;
            
            total_songs++;
            cout << song << " added to the playlist successfully!!" << endl;
        } 
        
        else
        {
            cout << "Error!! Cannot add more songs!!" << endl;
        }
    }

    void remove_song(string song)
    {
        for (int i = 0; i < total_songs; i++)
        {
            if (playlist[i] == song)
            {
                for (int j = i; j < total_songs - 1; j++)
                {
                    playlist[j] = playlist[j + 1];
                }
                
                total_songs--;
                cout << song << "  removed from the playlist successfully!!" << endl;
                
                if (currentlyPlayingSong == song)
                {
                    currentlyPlayingSong = "No song is currently playing!!";
                }
                return;
            }
        }
        
        cout << "Oops!! Song not found in the playlist!!" << endl;
    }

    void play_song(string song)
    {
        for (int i = 0; i < total_songs; i++)
        {
            if (playlist[i] == song)
            {
                currentlyPlayingSong = song;
                cout << "Now playing: " << song << endl;
                
                return;
            }
        }
        
        cout << "Oops!! Song not found in the playlist!!" << endl;
    }

    void display_playlist()
    {
        cout << "Playlist:\n" << endl;
        
        if (total_songs == 0)
        {
            cout << "Oops!! No songs in the playlist!!" << endl;
            return;
        }
        
        for (int i = 0; i < total_songs; i++)
        {
            cout << i + 1 << ". " << playlist[i] << endl;
        }
        
        cout << "Playing: " << currentlyPlayingSong << endl;
    }
};

int main() {
   
    MusicPlayer imran;

    imran.add_song("Song X");
    imran.add_song("Song Y");
    imran.add_song("Song Z");
    imran.display_playlist();
    imran.play_song("Song X");
    imran.remove_song("Song X");
    imran.display_playlist();

    return 0;
}