/*
 * array_functions.cpp
 *
 *  Created on: Sep 16, 2019
 *      From: keith
 *      Author: Ben Gendell
 */

//============================================================================
//	TODO add necessary includes here
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

#include "array_functions.h"
#include "utilities.h"
#include "constants.h"

//============================================================================

//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur

//TODO add a global array of entry structs (global to this file)

//TODO add variable to keep track of next available slot in array

//TODO define all functions in header file

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
struct entries{
	std::string word;
	int num_occur;
};
void clearArray(){

}

int getArraySize(){
	return constants::SUCCESS;
}

std::string getArrayWordAt(int i){
	std::string testReturn = "return";
	return testReturn;
}

int getArrayWord_NumbOccur_At(int i){
	return i;
}

bool processFile(std::fstream &myfstream){
	return false;
}

void processLine(std::string &myString){

}

void processToken(std::string &token){

}

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode){
	//open file
	myfile.open(myFileName.c_str(),mode);

	//check for returns
	if(myfile.is_open()){
		return true;
	}
	else{
		return false;
	}
}

void closeFile(std::fstream& myfile){
	if (myfile.is_open()){
		myfile.close();
	}

}

int writeArraytoFile(const std::string &outputfilename){
	return constants::SUCCESS;
}

void sortArray(constants::sortOrder so){

}
