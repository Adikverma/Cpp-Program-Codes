#include <bits/stdc++.h>
using namespace std;

class FavMusic
{
    // song list of the user in increasing order of their Favouriteness
    vector<pair<int, string>> songs;

    // Count to keep track that number of songs in the Favourite songs list is <= to List Size
    int currentNumberOfSongs = 0;

public:
    void incrementCount()
    {
        this->currentNumberOfSongs++;
    }

    // function to enter Music info
    string addNewMusic(string musicName, int fav, int N);

    // function to get the current least fav song from list
    string getLeastFav(void);

    // function to get the current most fav song from list
    string getMostFav(void);

    // get number of Distinct Favourite Values present in list
    int getLevelsCount(void);

    // get songs with given Values
    vector<string> songsWithLevel(int n);

    // get all songs in increasing Favouriteness
    vector<string> getAllSongs(void);
};
