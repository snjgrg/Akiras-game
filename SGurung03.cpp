//============================================================================
// Name        : SGurung03.cpp
// Author      : Sanjay Gurung
// Version     :
// Copyright   : Your copyright notice
// Description : Animal Quiz, Akira's Version
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>

using namespace std;

void checkInput(string &input, vector<string>& v);
int main() {
	srand(unsigned(time(0)));        //for random

	vector<string> animals;          //a vector where user input animals names and store it
	vector<int> num;                // vector to list animals vector into integer
	vector<string> newAnimal;       //vector that add shuffle words
	vector<string> userInput;

	string input, answer,userAnswer;
	int count = 0;                  // Accumulation to 0
	int count1 = 0;                 // Accumulation to 0
	int underScore= 0;              // Accumulation to 0
	int total = 0;                  // Accumulation to 0
	string random = " ";            //random is equal to null
	string input1 = " ";
	int tot,randNum,limit;         //Initialization

	cout << "Enter at least five animal names, e.g., cat, dog, etc..." << endl;
	while ( true ){

			cout << ">";          //print > every time
			getline(cin, input);  // get input from user
			if (input.length() == 0 && count >= 5) {
				break;  //break if length of input of user is 0 and less than 5 times
			}else if (input.length() == 0 ){
				cerr<<"Error: You must enter at least 5 animals."<<endl; //error if user don't input at-least 5 animal names
			}
			else {
                 //space delimiter
				istringstream iss(input);

				for(string s; iss >> s; ){
					count++;
					animals.push_back(s);
				}
			}
		}

	for (int i = 0; i < animals.size(); i++) {
		cout << i + 1 << ": " << animals[i] << endl; //print all animals name with number order
	}

	for (int i = 0; i < animals.size(); i++) {
		num.push_back(i);                  // adding animals vector in num vector as integer
	}


	bool equal = false;  //flag

	do {

		randNum = rand() % 3 + 1;   //random number from 1 to 3
		random_shuffle(num.begin(), num.end());  //shuffle the input words of user
		random = "";
		for (int i = 0; i < randNum; i++) {
			random += animals[num[i]]; //adding the random words in random
			newAnimal.push_back(animals[num[i]]);  //vector to add animal names
		}
		for (int i = 0; i < underScore; i++) {
			limit = random.length();
			int k= rand() % limit;    //take random of limit which we is length of random
			while (random[k] == '_' && total < random.length()) {  //while loop to check statement whether its true
				total++;   //total =total+1;
				k = rand() % limit;     //random of limit in k variable
			}
			random[k] = '_';
		}
		random_shuffle(random.begin(), random.end()); //random shuffle

		cout << "What are " << randNum << " animals in " << random << " ? "; //ask user the random shuffle words to guess
		getline(cin, input1); //user input for random shuffle words
		userAnswer = input1; //  string userAnswer takes user input
		if (input1 == "quit")
			break; //go out of loop

		if (input1 == "?") {  //if input is ? then
				for (int i = 0; i < animals.size(); i++) {
					cout << i + 1 << ": " << animals[i] << endl; //if users input "?" during cin
				}
			}

		checkInput(input1, userInput); //check user input if it has space

		while (userInput.size() != newAnimal.size()){// the length of user input should be equal to randomized shuffled words length
			userInput.clear(); //clear the userInput as null
			cerr << "Your number of input is incorrect. Try again :";
			getline(cin, input1);
			if (input1 == "?") {
					for (int i = 0; i < animals.size(); i++) {
						cout << i + 1 << ": " << animals[i] << endl; //print list of animal that user input
					}
				}

			userAnswer = input1;
			if (input == "quit")
				break; //go out of loop
			 checkInput(input1, userInput);
		}

		int count2 = 0;
		for (int i = 0; i < userInput.size(); i++) { //nested for loop
			for (int j = 0; j <  newAnimal.size(); j++) {
				if (userInput[i] ==  newAnimal[j]) { //to check the letter of each words
					count2++;     // cout2=count2+1;
					 newAnimal[j] = "___";
				}
			}
		}
		if (count2 == randNum) {
			equal = true;
		}

	 //checking whether user make correct or wrong for number of times and play according to level, if two times correct then big level
		if (equal) {    //if false
			count1++;
			tot = 0;
			cout << "Yes!" << endl;
			if (count1 == 2) {
				cout << "Succeeded two consecutive times, challenge goes up!"<< endl; // print
				underScore++;
				count1 = 0;
			}
		} else {
			count1 = 0;
			tot++;
			cout << "No!" << endl;
			if (tot == 2) {
				cout << "Failed two consecutive times, challenge goes down!"<< endl; //print
				underScore--;
				tot = 0;
			}
		}
		if (underScore < 0) {
			underScore = 0;
		}

		 random = "";        //random =null
		 newAnimal.clear();  //clear the vector new Animal
		 userInput.clear();  //clear the user input
		 equal = false;     //flag equal to false

	} while (true);
	 cout<<"Bye..."; // if user enter quit then display "bye" before end the program
	 exit(0);        //end the program

}
//function passed to check whether user input has space and use the space delimter property
void checkInput(string &input, vector<string>& v) {

		istringstream iss(input);
		for(string s; iss >> s; ){
          v.push_back(s);
	}
}


