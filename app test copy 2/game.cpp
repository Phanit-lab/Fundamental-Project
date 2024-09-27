#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX_WORDS = 100;
const int MAX_WORD_LENGTH = 50;

// Load words from a file
int loadWords(const string& filePath, string words[]) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file \"" << filePath << "\"." << endl;
        return 0;
    }

    int wordCount = 0;
    while (file >> words[wordCount] && wordCount < MAX_WORDS) {
        wordCount++;
    }
    file.close();
    return wordCount;
}

// Select a random word
string selectRandomWord(string words[], int wordCount) {
    srand(time(0));
    return words[rand() % wordCount];
}

// Display the current progress
void displayProgress(const string& secretWord, string guessedLetters) {
    for (char letter : secretWord) {
        cout << (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end() ? letter : '_') << ' ';
    }
    cout << endl;
}

// Add a word to the file
void addWordToFile(const string& filePath) {
    ofstream file(filePath, ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file \"" << filePath << "\" for writing." << endl;
        return;
    }

    string newWord;
    cout << "Enter a new word to add: ";
    cin >> newWord;

    // Validate the word for alphabetic characters
    if (any_of(newWord.begin(), newWord.end(), [](char c) { return !isalpha(c); })) {
        cerr << "Error: Invalid word! Please enter letters only." << endl;
        return;
    }

    file << newWord << endl;
    file.close();
    cout << "Word added successfully!" << endl;
}

// Main game loop
void playGuessingGame() {
    string words[MAX_WORDS];
    string guessedLetters;
    int wordCount = loadWords("words.txt", words);

    if (wordCount == 0) {
        cerr << "Error: No words found in the file." << endl;
        return;
    }

    string secretWord = selectRandomWord(words, wordCount);
    int attempts = 6;

    cout << "Welcome to the Guessing Word Game!" << endl;

    while (attempts > 0) {
        displayProgress(secretWord, guessedLetters);
        cout << "Attempts left: " << attempts << endl;

        string guess;
        cout << "Guess a word: ";
        cin >> guess;

        // Validate the guess for alphabetic characters
        if (any_of(guess.begin(), guess.end(), [](char c) { return !isalpha(c); })) {
            cerr << "Error: Invalid word! Please enter letters only." << endl;
            continue;
        }

        // Add unguessed letters from the guess to guessedLetters
        for (char letter : guess) {
            if (find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end()) {
                guessedLetters += letter;
            }
        }

        // Check if the guess matches the secret word
        if (guess == secretWord) {
            cout << "\nCongratulations! You've guessed the word: " << secretWord << endl;
            return;
        } else {
            cout << "Sorry, that word is not correct." << endl;
            attempts--;
        }
    }

    cout << "\nSorry, you've run out of attempts. The word was: " << secretWord << endl;
}

// Main function to start the game
int main() {
    while (true) {
        cout << "1. Play Guessing Word Game\n2. Add a new word\n3. Exit\nChoose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                playGuessingGame();
                break;
            case 2:
                addWordToFile("words.txt");
                break;
            case 3:
                cout << "Exiting the game." << endl;
                return 0;
            default:
                cerr << "Error: Invalid choice. Please try again." << endl;
        }
    }
}