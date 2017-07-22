#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>
using namespace std;

void play_game(vector <vector<string>>& Words);
string get_key(int s, string& word, string& oldkey, char guess, int index);
int main(int argc, char* argv[])
{


    string input;
    ifstream myfile("dictionary.txt");
    vector <vector<string>> Words(30);
    //error handling for file
    if(!myfile)
    {
        cout << "could not open file" << endl;
    }



    //loading up the words from the text file
    while(myfile >> input)
    {
        Words[input.size()].push_back(input);
    }

    for(int i = 0; i < Words.size(); i++)
    {
        cout << "There are " << Words[i].size() << " words of size " << i << endl;
    }

    play_game(Words);

    return 0;

}

void play_game(vector <vector<string>>& Words)
{
    char guess;
    int guesses;
    int letters;
    string oldkey;
    string guessed;
    vector<string> vecCopy;
    map <string, vector<string>> bin;

    cout << "State the size of words you want to use" << endl;
    cin >> letters;
    cout << "State how many guesses you want" << endl;
    cin >> guesses;

    for(int i = 0; i < letters; i++)
    {
        oldkey.push_back('-');
    }
    //Set up. Initial set of words to play with.

    for(int i = 0; i <Words[letters].size(); i ++)
    {
        vecCopy.push_back(Words[letters][i]);
    }

    do
    {
        cout << "Enter your guess" << endl;
        cin >> guess;

        //handling repeated guesses
        while(guessed.find(guess) != string::npos)
        {
            cout << "You have already guessed that letter" << endl;
            cin >> guess;
        }

        guessed.push_back(guess);
        guessed.push_back(' ');
        //letter the player know their standing
        cout << "Your guessed letters " << guessed << endl;
        cout << "You have " << guesses << " guesses left" << endl;

        //separate the words by key family
        for(int i = 0; i <vecCopy.size(); i ++)
        {
            string key = get_key(letters, vecCopy.at(i), oldkey, guess, letters);
            bin[key].push_back(vecCopy.at(i));
        }

        //vecCopy.clear();
        //copying largest bin into vecCopy
        for(vector<string>::iterator i = bin.begin()->second.begin(); i != bin.begin()->second.end(); i++)
        {
            vecCopy.push_back(*i);
        }


        //updating oldkey
        oldkey = bin.begin()->first;

        if(oldkey.find(guess) == string::npos)
        {
             guesses--;
             cout << "There are no " << guess << " 's." << endl;
        }

        if(oldkey.find('-') == string::npos)
        {
             cout << "Congratulations you have won!!" << endl;
             cout << "The word was " << oldkey << "." << endl;
             return;
        }

        if(guesses == 0)
        {
            cout << "The word was: " << vecCopy.at(rand() % vecCopy.size()) << endl;
            return;
        }
        cout << "Word: "<< bin.begin()->first << endl;
        //cout << "There are " << vecCopy.size() << " words left" << endl;

        bin.clear();

    }   while(guesses > 0);


    return;
}

string get_key(int s, string& word, string& oldkey, char guess, int index)
{
    string key;
    for(int i = 0; i < s; i++)
    {
        key.push_back(oldkey[i]);
    }

    for(int i = 0; i < s; i++)
    {
        if (word[i] == guess)
        {
            key[i] = guess;
        }
    }


    return key;
}
