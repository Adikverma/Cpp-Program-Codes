#include "../src/bitmap.h"

/*
Function Input : This function takes input as
                1.Music Name
                2.Music Fav Value
                3.Size of Log File
Function Desc : Takes the song info and updates the Log file and updates the song list of size N
Function Returns :
                1.It returns the song that is being removed from the 'list'
                2.If nothing is removed then it returns empty string
Note:If a song being entered is not worthy of being in the Favourite Song list then it is not added or anything is removed
*/
string FavMusic::addNewMusic(string musicName, int fav, int N)
{

    // Data Structure to be used
    map<int, deque<string>> logg;
    vector<pair<int, string>> oldList = songs;
    for (auto i : oldList)
    {
        logg[i.first].push_back(i.second);
    }

    string removedString = "No Song!";
    // if Log file has not reached limit
    if (currentNumberOfSongs < N)
    {
        logg[fav].push_back(musicName);
        this->incrementCount();
    }
    // if Log file has reached limit of N
    else
    {
        auto fir = logg.begin();
        if (fir->first > fav)
            return "No Song!";

        string removed = (fir->second).front();
        (fir->second).pop_front();
        if ((fir->second).size() == 0)
        {
            logg.erase(fir);
        }
        logg[fav].push_back(musicName);
        removedString = removed;
    }

    // Updating the song list after this operation
    vector<pair<int, string>> newList;
    for (auto i : logg)
    {
        for (auto j : i.second)
        {
            newList.push_back({i.first, j});
        }
    }
    this->songs = newList;

    return removedString;
}

/*
Function Input : This function does not takes any input
Function Desc : This function returns the least Facourite song from the Favourite Song List
Function Returns : If the Favourite song list contains any songs then it returns the least favourite song otherwise returns empty string
*/
string FavMusic::getLeastFav(void)
{
    string leastFav = "No Song!";
    if ((this->songs).size() > 0)
    {
        leastFav = ((this->songs)[0]).second;
    }
    return leastFav;
}

/*
Function Input : This function does not takes any input
Function Desc : This function returns the most Facourite song from the Favourite Song List
Function Returns : If the Favourite song list contains any songs then it returns the most favourite song otherwise returns empty string
*/
string FavMusic::getMostFav(void)
{
    string mostFav = "No Song!";
    if ((this->songs).size() > 0)
    {
        mostFav = ((this->songs)[(this->songs).size() - 1]).second;
    }
    return mostFav;
}

/*
Function Input : This function does not takes any input
Function Desc : This function returns the number of different levels of Fav Values present currently in the Favourite Song list
Function Returns : If the Favourite song list contains any songs then it returns the number of different Fav Values currently present
*/
int FavMusic::getLevelsCount(void)
{
    int levelCount = 0;
    int level = 0;
    for (auto i : songs)
    {
        if (level != i.first)
        {
            level = i.first;
            levelCount++;
        }
    }
    return levelCount;
};

/*
Function Input : This function takes the Fav Value
Function Desc : Function to obtain a list of songs of fav value = n
Function Returns : This function returns the list of songs in the increasing order of Favouriteness of the Fav Value = n
*/
vector<string> FavMusic::songsWithLevel(int n)
{
    vector<string> songsLeveln;
    for (auto i : songs)
    {
        if (i.first == n)
        {
            songsLeveln.push_back(i.second);
        }
    }
    return songsLeveln;
};

/*
Function Input : This function does not takes any inputs
Function Desc : Function gives all the songs in increasing order of Favouriteness
Function Returns : This function simply returns the songs (vector<string>) i.e, increasing order of the Favouriteness
*/
vector<string> FavMusic::getAllSongs(void)
{
    vector<string> songList;
    for (auto i : songs)
    {
        songList.push_back(i.second);
    }
    return songList;
};
