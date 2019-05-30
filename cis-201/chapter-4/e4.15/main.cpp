#include <iostream>
#include <vector>

using namespace std;

int main() {
    string sentence;

    cout << "Enter the sentence you want to print in box: " << endl;
    getline(cin, sentence);

    // Split the sentence into individual words
    vector<string> words;

    // Find maximum word length, so that we can create a box
    int maxWordWidth = 0;
    int wordLength = 0;
    for(int i = 0; i < sentence.length(); i++) {
        if (sentence.at(i) == ' ') {
            if (maxWordWidth < wordLength) {
                maxWordWidth = wordLength;
            }
            words.push_back(sentence.substr(i-wordLength, wordLength));
            wordLength = 0;
        }

        wordLength++;
    }

    // For last word
    words.push_back(sentence.substr(sentence.length()-wordLength, wordLength));
    if (maxWordWidth < wordLength) {
        maxWordWidth = wordLength;
    }

    cout  << "+";
    for(int i = -1; i < maxWordWidth; i++)
        cout << "-";
    cout << "+" << endl;
    for(auto word: words) {

        // For smaller words to center them, we have to find padding for both side.
        int wordSize = int(word.size());
        int centerPadding = int(double(maxWordWidth - wordSize) / 2.0);

        cout << "|";
        for(int i = 0; i < centerPadding; i++)
            cout << " ";
        cout << word;

        // For odd length word padding will be one extra on right.
        for(int i = -1; i < (maxWordWidth-centerPadding-wordSize); i++)
            cout << " ";

        cout << "|";
        cout << endl;

    }
    cout  << "+";
    for(int i = -1; i < maxWordWidth; i++)
        cout << "-";
    cout << "+" << endl;
    return 0;
}

