/*
 * Cameron Mims
 * Personal Project - Shiritori
 * Date(Started): 05/10/19
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Dictionary{
private:
    vector<string> dictionary; //Acts as our dictionary of words
public:
    Dictionary();
    bool is_word(string word);
    vector<string> get_dictionary();
    void set_dictionary(vector<string> dictionary);
    void to_string();
    void to_string(char c);
};

/**
 * Default Dictionary contructor
 */
Dictionary::Dictionary() {
    ifstream i_file;
    i_file.open("words.txt");
    if(!i_file.is_open()){
        cout << "ERROR: File not opened" << endl;
    }else{
        cout << "File opened" << endl;
        string line;
        while(i_file >> line){
            tolower(line.at(0));
            dictionary.push_back(line);
        }
        i_file.close();
    }
}

/**
 * Check if given word is in the Dictionary
 * @param word
 * @return bool
 */
bool Dictionary::is_word(string word) {
    if(count(dictionary.begin(), dictionary.end(), word)){
        return true;
    }else{
        return false;
    }
}

/**
 * Get Dictionary
 * @return vector<string>
 */
vector<string> Dictionary::get_dictionary() {
    return this->dictionary;
}

/**
 * Set Dictionary
 * @param dictionary
 */
void Dictionary::set_dictionary(vector<string> dictionary) {
    this->dictionary = dictionary;
}

/**
 * String all contents in dictionary
 */
void Dictionary::to_string() {
    for(int i = 0; i < dictionary.size(); i++){
        cout << dictionary[i] <<  endl;
    }
}

/**
 * String all contents in dictionary based upon index
 * @param c
 */
void Dictionary::to_string(char c) {
    for(int i = 0; i < dictionary.size(); i++){
        if(dictionary[i].at(0) == c){
            cout << dictionary[i] << endl;
            cout << dictionary[i].length() << endl;
        }
    }
}

class AI{
private:
    Dictionary dictionary;
    vector<string> ai_dictionary = dictionary.get_dictionary();
    string difficulty;
    string name;
    int points;
public:
    AI();
    AI(string difficulty);
    AI(string difficulty, int points);
    AI(string difficulty, int points, string name);
    AI(string difficulty, int points, vector<string> dictionary);
    vector<string> get_ai_dictionary();
    void set_ai_dictionary(vector<string> dictionary);
    string get_difficulty();
    void set_difficulty(string difficulty);
    int get_points();
    void set_points(int points);
    string find_word();
    string find_word(char c);
};

/**
 * AI constructor
 * @param difficulty
 */
AI::AI(string difficulty) {
    if(difficulty == "Easy"){
        this->difficulty = difficulty;
        this->points = 100;
    }
    else if(difficulty == "Medium"){
        this->difficulty = difficulty;
        this->points = 100;
    }
    else if(difficulty == "Hard"){
        this->difficulty = difficulty;
        this->points = 100;
    }
    else if(difficulty == "Expert"){
        this->difficulty = difficulty;
        this->points = 100;
    }else{
        cout << "Invalid difficulty: please choose - Easy, Medium, Hard or Expert" << endl;
    }
}

/**
 * AI constructor
 * @param difficulty
 * @param points
 */
AI::AI(string difficulty, int points) {
    if(difficulty == "Easy"){
        this->difficulty = difficulty;
        this->points = points;
    }
    else if(difficulty == "Medium"){
        this->difficulty = difficulty;
        this->points = points;
    }
    else if(difficulty == "Hard"){
        this->difficulty = difficulty;
        this->points = points;
    }
    else if(difficulty == "Expert"){
        this->difficulty = difficulty;
        this->points = points;
    }else{
        cout << "Invalid difficulty: please choose - Easy, Medium, Hard or Expert" << endl;
    }
}

/**
 * AI contrsuctor
 * @param difficulty
 * @param points
 * @param name
 */
AI::AI(string difficulty, int points, string name) {
    if(difficulty == "Easy"){
        this->difficulty = difficulty;
        this->points = points;
        this->name = name;
    }
    else if(difficulty == "Medium"){
        this->difficulty = difficulty;
        this->points = points;
        this->name = name;
    }
    else if(difficulty == "Hard"){
        this->difficulty = difficulty;
        this->points = points;
        this->name = name;
    }
    else if(difficulty == "Expert"){
        this->difficulty = difficulty;
        this->points = points;
        this->name = name;
    }else{
        cout << "Invalid difficulty: please choose - Easy, Medium, Hard or Expert" << endl;
    }
}

/**
 * AI constructor
 * @param difficulty
 * @param points
 * @param dictionary
 */
AI::AI(string difficulty, int points, vector<string> dictionary) {
    if(difficulty == "Easy"){
        this->difficulty = difficulty;
        this->points = points;
        this->ai_dictionary = dictionary;
    }
    else if(difficulty == "Medium"){
        this->difficulty = difficulty;
        this->points = points;
        this->ai_dictionary = dictionary;
    }
    else if(difficulty == "Hard"){
        this->difficulty = difficulty;
        this->points = points;
        this->ai_dictionary = dictionary;
    }
    else if(difficulty == "Expert"){
        this->difficulty = difficulty;
        this->points = points;
        this->ai_dictionary = dictionary;
    }else{
        cout << "Invalid difficulty: please choose - Easy, Medium, Hard or Expert" << endl;
    }
}

/**
 * Get AI dictionary
 * @return
 */
vector<string> AI::get_ai_dictionary() {
    return this->ai_dictionary;
}

/**
 * Set AI dictionary
 * @param dictionary
 */
void AI::set_ai_dictionary(vector<string> dictionary) {
    this->ai_dictionary = dictionary;
}

/**
 * Get AI difficulty
 * @return string
 */
string AI::get_difficulty() {
    return this->difficulty;
}

/**
 * Set AI difficulty
 * @param difficulty
 */
void AI::set_difficulty(string difficulty) {
    this->difficulty = difficulty;
}

/**
 * Get AI points
 * @return int
 */
int AI::get_points() {
    return this->points;
}

/**
 * Set AI points
 * @param points
 */
void AI::set_points(int points) {
    this->points = points;
}

/**
 * Find a word based on random index (character c) and return a single word based on difficulty
 * @return string
 */
string AI::find_word() {
    array<char, 26> letters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                                's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    random_device char_rd; //obtain a random number from hardware
    mt19937 char_eng(char_rd()); //seed the generator
    uniform_int_distribution<> char_distr(0, 25); //generate numbers { 0 - 25 } num

    char c = letters[char_distr(char_eng)]; //Pick a random character from our letters array

    if(difficulty == "Easy"){
        vector<string> temp_easy;
        temp_easy.clear();

        for(int i = 0; i < ai_dictionary.size(); i++){
            if(ai_dictionary[i].at(0) == c && ai_dictionary[i].length() <= 5){
                temp_easy.push_back(ai_dictionary[i]);
                //cout << ai_dictionary[i] << endl;
            }
        }
        random_device easy_word_rd; //obtain a random number from hardware
        mt19937 easy_word_eng(easy_word_rd()); //seed the generator
        uniform_int_distribution<> easy_word_distr(0, temp_easy.size());

        return temp_easy[easy_word_distr(easy_word_eng)];
    }
    else if(difficulty == "Medium"){
        vector<string> temp_medium;
        temp_medium.clear();

        for(int i = 0; i < ai_dictionary.size(); i++){
            if(ai_dictionary[i].at(0) == c && ai_dictionary[i].length() <= 8){
                temp_medium.push_back(ai_dictionary[i]);
            }
        }
        random_device medium_word_rd; //obtain a random number from hardware
        mt19937 medium_word_eng(medium_word_rd()); //seed the generator
        uniform_int_distribution<> medium_word_distr(0, temp_medium.size());

        return temp_medium[medium_word_distr(medium_word_eng)];
    }
    else if(difficulty == "Hard"){
        vector<string> temp_hard;
        temp_hard.clear();

        for(int i = 0; i < ai_dictionary.size(); i++){
            if(ai_dictionary[i].at(0) == c && ai_dictionary[i].length() >= 8){
                temp_hard.push_back(ai_dictionary[i]);
            }
        }
        random_device hard_word_rd; //obtain a random number from hardware
        mt19937 hard_word_eng(hard_word_rd()); //seed the generator
        uniform_int_distribution<> hard_word_distr(0, temp_hard.size());

        return temp_hard[hard_word_distr(hard_word_eng)];
    }
    else if(difficulty == "Expert"){
        vector<string> temp_expert;
        temp_expert.clear();

        for(int i = 0; i < ai_dictionary.size(); i++){
            if(ai_dictionary[i].at(0) == c && ai_dictionary[i].length() >= 12){
                temp_expert.push_back(ai_dictionary[i]);
            }
        }
        random_device expert_word_rd; //obtain a random number from hardware
        mt19937 expert_word_eng(expert_word_rd()); //seed the generator
        uniform_int_distribution<> expert_word_distr(0, temp_expert.size());

        return temp_expert[expert_word_distr(expert_word_eng)];
    }
}

/**
 * Find a word in our dictionary by index (character - c) and return a single word based on difficulty
 * @param c
 * @return string
 */
string AI::find_word(char c) {
    if(difficulty == "Easy"){
        vector<string> temp_easy;
        temp_easy.clear();

        for(int i = 0; i < ai_dictionary.size(); i++){
            if(ai_dictionary[i].at(0) == c && ai_dictionary[i].length() <= 5){
                temp_easy.push_back(ai_dictionary[i]);
                //cout << ai_dictionary[i] << endl;
            }
        }
        random_device easy_word_rd; //obtain a random number from hardware
        mt19937 easy_word_eng(easy_word_rd()); //seed the generator
        uniform_int_distribution<> easy_word_distr(0, temp_easy.size());

        return temp_easy[easy_word_distr(easy_word_eng)];
    }
    else if(difficulty == "Medium"){
        vector<string> temp_medium;
        temp_medium.clear();

        for(int i = 0; i < ai_dictionary.size(); i++){
            if(ai_dictionary[i].at(0) == c && ai_dictionary[i].length() <= 8){
                temp_medium.push_back(ai_dictionary[i]);
            }
        }
        random_device medium_word_rd; //obtain a random number from hardware
        mt19937 medium_word_eng(medium_word_rd()); //seed the generator
        uniform_int_distribution<> medium_word_distr(0, temp_medium.size());

        return temp_medium[medium_word_distr(medium_word_eng)];
    }
    else if(difficulty == "Hard"){
        vector<string> temp_hard;
        temp_hard.clear();

        for(int i = 0; i < ai_dictionary.size(); i++){
            if(ai_dictionary[i].at(0) == c && ai_dictionary[i].length() >= 8){
                temp_hard.push_back(ai_dictionary[i]);
            }
        }
        random_device hard_word_rd; //obtain a random number from hardware
        mt19937 hard_word_eng(hard_word_rd()); //seed the generator
        uniform_int_distribution<> hard_word_distr(0, temp_hard.size());

        return temp_hard[hard_word_distr(hard_word_eng)];
    }
    else if(difficulty == "Expert"){
        vector<string> temp_expert;
        temp_expert.clear();

        for(int i = 0; i < ai_dictionary.size(); i++){
            if(ai_dictionary[i].at(0) == c && ai_dictionary[i].length() >= 12){
                temp_expert.push_back(ai_dictionary[i]);
            }
        }
        random_device expert_word_rd; //obtain a random number from hardware
        mt19937 expert_word_eng(expert_word_rd()); //seed the generator
        uniform_int_distribution<> expert_word_distr(0, temp_expert.size());

        return temp_expert[expert_word_distr(expert_word_eng)];
    }
}

class Player{
private:
    string name;
    int points;
public:
    Player() = default;
    Player(string name);
    Player(string name, int points);
    string get_name();
    void set_name(string name);
    int get_points();
    void set_points(int points);
};

/**
 * Player constructor
 * @param name
 */
Player::Player(string name) {
    this->name = name;
}

/**
 * Player constructor
 * @param name
 * @param points
 */
Player::Player(string name, int points) {
    this->name = name;
    this->points = points;
}

/**
 * Get player name
 * @return string
 */

string Player::get_name() {
    return this->name;
}

/**
 * set player name
 * @param name
 */
void Player::set_name(string name) {
    this->name = name;
}

/**
 * Get player points
 * @return int
 */
int Player::get_points() {
    return this->points;
}

/**
 * Set player points
 * @param points
 */
void Player::set_points(int points) {
    this->points = points;
}

int RUNNING = 1;
int GAME_RUNNING = 1;
int TURN = 1;
int PLAYING = 1;

/**
 * Function prototype for playing loop
 * @param ai
 * @param p1
 */
void playing_loop(AI ai, Player p1);

/**
 * Function prototype for game loop
 */
void game_loop();

/**
 * Function prototype for play again loop
 */
void play_again();

void menu_loop(){
    //RUNNING = 1
    while(RUNNING){
        PLAYING = 1;
        GAME_RUNNING = 1;
        string menu_command;
        cout << "******** Welcome to Shiritori (By: Cameron Mims | Beta - 1.0 NO GUI) ********" << endl;
        cout << "1) About\n"
                "2) Rules\n"
                "3) Play Shiritori\n"
                "4) Exit\n";
        cout << "Choose your option (1, 2 or 3): ";
        cin >> menu_command;
        if(menu_command == "1"){
            cout << endl;
            cout << "*----------------------------------------------------------------------------------------------------------*\n"
                    "* SHIRITORI (shiritori) or しりとり is a Japanese word game in which the players are required to say a word *\n"
                    "* which begins with the final kana of the previous word. No distinction is made between                    *\n"
                    "* hiragana, katakana or kanji. Shiritori means 'taking the end' or 'taking the rear;                       *\n"
                    "*----------------------------------------------------------------------------------------------------------*" << endl;
            cout << endl;
        }else if(menu_command == "2"){
            cout << endl; //styling
            cout << "*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n"
                    "* RULESET (in order):                                                                                                                                                          *\n"
                    "* RULE 1) - TURNS will be decided randomly between either player/player or player/AI                                                                                           *\n"
                    "* RULE 2) - FOR the first round, either the player or the AI will start with a word                                                                                            *\n"
                    "* RULE 3) - FROM there, depending on who started, they must enter a word that starts with the character of the last word entered by player or AI                               *\n"
                    "* RULE 4) - IF the word is not a valid word, then points will be added                                                                                                         *\n"
                    "* RULE 5) - IF the word does not start with the character of the last word (if game is past its first iteration) then points will be added                                     *\n"
                    "* RULE 6) - IF the word is valid and starts with the last character of the last inputted word, points will be dedcuted                                                         *\n"
                    "* RULE 7) - THE winner is based upon who can reach 0 (zero) points first                                                                                                       *\n"
                    "* SPECIAL RULE 1) - NOT IMPLEMENTED YET - There will be a timer on word input, depending on the amount of time left, if positive, then that will be added to your word length  *\n"
                    "*                                         If the timer goes negative, then that will be subtracted from your word length, so think quickly :D                                  *\n"
                    "*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*" << endl;
            cout << endl; //styling
        }else if(menu_command == "3"){
            game_loop(); //direct to game loop
        }else if(menu_command == "4"){
            cout << "Thank your for playing Shiritori - Github @CMilly" << endl;
            RUNNING = 0; //Exit out of while loop and game
        }
    }
}

void game_loop(){
    while(GAME_RUNNING){
        string game_command;
        cout << endl;
        cout << "Please choose Game type..." << endl;
        cout << "1) Single-player\n"
                "2) Multi-player" << endl;
        cout << "Choose your option (1 or 2): ";
        cin >> game_command;
        cout << endl;

        if(game_command == "1"){
            cout << "Player set name: ";
            cin >> game_command;
            cout << "Player name set to: " << game_command << endl;
            Player p1 (game_command, 100);

            cout << "starting single-player game....\n";
            cout << "Choose your AI difficulty: " << endl;
            cout << "1) Easy\n"
                    "2) Medium\n"
                    "3) Hard\n"
                    "4) Expert" << endl;
            cout << "Choose your option (1, 2, 3 or 4): ";
            cin >> game_command;
            if(game_command == "1"){
                AI easy_ai ("Easy", 100);
                playing_loop(easy_ai, p1);
            }else if(game_command == "2"){
                AI medium_ai ("Medium", 100);
                playing_loop(medium_ai, p1);
            }else if(game_command == "3"){
                AI hard_ai ("Hard", 100);
                playing_loop(hard_ai, p1);
            }else if(game_command == "4"){
                AI expert_ai ("Expert", 100);
                playing_loop(expert_ai, p1);
            }
        }
    }
}

void playing_loop(AI ai, Player p1){
    Dictionary dictionary; //Instantiate our dictionary
    int game_iter = 0; //game iterations to control first ruleset
    string player_word_keep, ai_word_keep; //
    while(PLAYING){
        string word, ai_word; //hold cin
        if(p1.get_points() <= 0){
            cout << "Player: " << p1.get_name() << " has won! Word KING or QUEEN" << endl;
            // maybe show all  words that were played by AI or player
            play_again();
        }
        else if(ai.get_points() <= 0){
            cout << "AI: " << "He who shall not be named" << " has won! Word KING or QUEEN" << endl;
            // maybe show all words that were played by AI or Player
            play_again();
        }
        /**
         * If the amount of game iterations is 0 (beginning) then...
         * Player starts with the word and no character needs to be followed
         */
        if(game_iter == 0){
            cout << "\n" << endl;
            cout << "Player's Turn" << endl;
            cout << "----------------------------------\n"
                    "Player: " << p1.get_name() << "\nPoints: " << p1.get_points() << "\n"
                                                                                      "----------------------------------" << endl;
            cout << "Enter word: ";
            cin >> word;
            player_word_keep = word;

            cout << "You entered: " << word << endl; //Display the word Player has entered

            //Check our dictionary to see if the inputted word is valid
            //If it isn't...
            if(!dictionary.is_word(word)){
                cout << "Not a valid word, adding the length of the inputted word to points" << endl;

                p1.set_points(p1.get_points() + word.length()); //calculate the point addition

                cout << "Player: " << p1.get_name() << "| Current points: " << p1.get_points() << endl; //Show new amount of points to Player
                TURN++; //increment TURN to allow AI to make a move

                //If the Player's word is valid
            }else{
                cout << "Valid word, subtracting points by length of inputted word" << endl;

                p1.set_points(p1.get_points() - word.length()); //calculate the point deduction

                cout << "Player: " << p1.get_name() << " | Current points: " << p1.get_points() << endl; //Show new amount of points to Player
                TURN++; //increment TURN to allow AI to make a move
            }

        /**
         * If the game has iterated once already, then the rules change...
         * Player must start the word with the last character of the AI's word
         */
        }else{
            /**
             * For now, TURN 1 will be the Players turn
             */
            if(TURN == 1){
                cout << "\n" << endl;
                cout << "Player's Turn" << endl;
                cout << "----------------------------------\n"
                        "Player: " << p1.get_name() << "\nPoints: " << p1.get_points() << "\nAI Points: " << ai.get_points() << "\nWord must start with: " << ai_word_keep.at(ai_word_keep.length()-1) << "\nAI previous word: " << ai_word_keep << "\n" <<
                                                                                          "----------------------------------" << endl;

                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Enter word: ";
                cin >> word;

                player_word_keep = word; //

                //Check to see if the beginning character of the inputted string matches the last character of the ai's inputted string
                if(word.at(0) != ai_word_keep.at(ai_word_keep.length()-1)){
                    cout << "Word must start with the last characted of the last inputted string (AI)\n"
                            "Adding points of inputted word (Player) length" << "Points: " << "+" << word.length() << endl;

                    p1.set_points(p1.get_points() + word.length()); //calculate the point addition

                    cout << "Player: " << p1.get_name() << "| Current points: " << p1.get_points() << endl; //Show new amount of points to Player
                    TURN++; //increment TURN to allow AI to make a move
                }else{
                    cout << "You entered: " << word << endl; //Display the word Player has entered

                    //Check our dictionary to see if the inputted word is valid
                    //If it isnt...
                    if(!dictionary.is_word(word)){
                        cout << "Not a valid word, adding the length of the inputted word to points" << endl;

                        p1.set_points(p1.get_points() + word.length()); //calculate the point addition

                        cout << "Player: " << p1.get_name() << "| Current points: " << p1.get_points() << endl; //Show new amount of points to Player
                        TURN++; //increment TURN to allow AI to make a move

                     //If the Player's word is valid
                    }else{
                        cout << "Valid word, subtracting points by length of inputted word" << endl;

                        p1.set_points(p1.get_points() - word.length()); //calculate the point deduction

                        cout << "Player: " << p1.get_name() << " | Current points: " << p1.get_points() << endl; //Show new amount of points to Player
                        TURN++; //increment TURN to allow AI to make a move
                    }
                }
            }
            /**
             * For now, TURN 2 will be the AI's turn
             */
            else if(TURN == 2){
                cout << "\n" << endl;
                cout << "AI's Turn" << endl;
                cout << "----------------------------------\n"
                        "AI: " << "He who shall not be named" << "\nPoints: " << ai.get_points() << "\n"
                                                                                          "----------------------------------" << endl;

                ai_word = ai.find_word(player_word_keep.at(player_word_keep.length()-1)); //find word based on character of the word inputted by the player
                ai_word_keep = ai_word;

                cout << "AI Entered: " << ai_word << endl;

                cout << "AI entered valid word (of course :D)" << endl;
                cout << "subtracting AI's points by length of word" << endl;

                ai.set_points(ai.get_points() - ai_word.length()); //subtract AI's points

                cout << "AI: " << "He who shall not be named" << " | Current points: " << ai.get_points() << endl; //Show new amount of points to AI

                TURN--; //decrement TURN to allow player to make a move
            }
        }
        game_iter++; //update the game iterations to not repeat first iteration ruleset
    }
}

void play_again(){
    while(PLAYING){
        string pa_command;
        cout << "Would you like to play again or exit?" << endl;
        cout << "1) - Play Again\n"
                "2) - Exit" << endl;
        cout << "Choose options 1 or 2: ";
        cin >> pa_command;

        if(pa_command == "1"){
            PLAYING = 0;
            menu_loop();
        }
        if(pa_command == "2"){
            cout << "Thank you for playing Shiritori" << endl;
            PLAYING = 0;
            GAME_RUNNING = 0;
            RUNNING = 0;
        }
    }
}

int main() {
    menu_loop();
}