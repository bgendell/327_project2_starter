/*
 * array_functions.cpp
 *
 *  Created on: Sep 16, 2019
 *      From: keith
 *      Author: Ben Gendell
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

#include "array_functions.h"
#include "utilities.h"
#include "constants.h"


struct entries{
	std::string word;
	int num_occur;
};
entries list[constants::MAX_WORDS];
int listSize = 0;

//zero out array that tracks words and their occurrences
void clearArray(){
	for(int i=0;i<=abs(sizeof(&list));i++){
		list[i].word = "";
		list[i].num_occur = 0;
	}
	listSize = 0;
}

//how many unique words are in array
int getArraySize(){
	while (list[listSize].word != ""){
		listSize++;
	}
	return listSize;
}

//get data at a particular location
std::string getArrayWordAt(int i){
	return list[i].word;
}
//get number of occurances of word at place i
int getArrayWord_NumbOccur_At(int i){
	return list[i].num_occur;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	if(!myfstream.is_open()){
		return false;
	}
	else{
		std::string line;
		while(!myfstream.eof()){
			getline(myfstream,line);
			processLine(line);
		}
		return true;
	}
}
/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){
	if(myString == ""){
		processToken(myString);
	}
	std::stringstream ss(myString);
	std::string temp;
	while(getline(ss,temp,constants::CHAR_TO_SEARCH_FOR)){
		processToken(temp);
	}
}
/*Keep track of how many times each token seen*/
void processToken(std::string &token){
	strip_unwanted_chars(token);
	if(token==""){
		return;
	}
	//toUpper(token);

	for(int i=0;i<listSize;i++){
		std::string a = token;
		std::string b = list[i].word;
		toUpper(a);
		toUpper(b);
		if(a == b){
			list[i].num_occur++;
			return;
		}
	}
	list[listSize].word = token;
	list[listSize].num_occur = 1;
	listSize++;
}

//opens file
bool openFile(std::fstream& myfile, const std::string& myFileName,std::ios_base::openmode mode){
	//open file
	myfile.open(myFileName.c_str(), mode);

	//check for returns
	if(!myfile.is_open()){
		return false;
	}
	else{
		processFile(myfile);
		return true;
	}
}
//closes file
void closeFile(std::fstream& myfile){
	if (myfile.is_open()){
		myfile.close();
	}

}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
	std::fstream fileToOut;
	fileToOut.open(outputfilename,std::ios_base::out);
	if (!fileToOut.is_open()){
		return constants::FAIL_FILE_DID_NOT_OPEN;
	}
	if (listSize == 0){
			return constants::FAIL_NO_ARRAY_DATA;
		}
	else{
		for (int i=0;i<listSize;i++){
					fileToOut << list[i].word;
					fileToOut << " ";
					fileToOut << list[i].num_occur;
					fileToOut <<"\n";
				}
				closeFile(fileToOut);
		return constants::SUCCESS;
	}

}
/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 * following lines include functions based on switch call
 */
void sortNone(){
	return;
}
void sortAsc(){
	for(int j = 0;j<listSize;j++){
		for (int i=0;i<listSize-1;i++){
			//these lines to insure total comparison between cases
			std::string a = list[i+1].word;
			std::string b = list[i].word;
			toUpper(a);
			toUpper(b);
			if(a<b){
				int temp = list[i+1].num_occur;
				std::string holder =  list[i+1].word;
				list[i+1].word = list[i].word;
				list[i+1].num_occur = list[i].num_occur;
				list[i].word = holder;
				list[i].num_occur = temp;
			}
		}
	}
}
void sortDesc(){
	for(int j = 0;j<listSize;j++){
		for (int i=0;i<listSize-1;i++){
			//these lines to insure total comparison between cases
			std::string a = list[i+1].word;
			std::string b = list[i].word;
			toUpper(a);
			toUpper(b);
			if(a<b){
				int temp = list[i+1].num_occur;
				std::string holder =  list[i+1].word;
				list[i+1].word = list[i].word;
				list[i+1].num_occur = list[i].num_occur;
				list[i].word = holder;
				list[i].num_occur = temp;
			}
		}
	}
}
void sortNum(){
	for(int j = 0;j<listSize;j++){
		for (int i=0;i<listSize-1;i++){
			if(list[i+1].num_occur > list[i].num_occur){
				int temp = list[i+1].num_occur;
				std::string holder =  list[i+1].word;
				list[i+1].word = list[i].word;
				list[i+1].num_occur = list[i].num_occur;
				list[i].word = holder;
				list[i].num_occur = temp;
			}
		}
	}
}
void sortArray(constants::sortOrder so){
	switch(so){
		case constants::sortOrder::NONE: sortNone(); break;
		case constants::sortOrder::ASCENDING: sortAsc(); break;
		case constants::sortOrder::DESCENDING: sortDesc(); break;
		case constants::sortOrder::NUMBER_OCCURRENCES: sortNum(); break;
	}

}
