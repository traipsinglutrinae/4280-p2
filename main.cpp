/*Ian Lofton Green
 *CS428
 *Project 2 
*/

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "token.h"
#include "scanner.h"
#include "testTree.h"
#include "parser.h"

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inFile;
	char * inFileName;
	string userFile = "inputStream.sp2020";

	if (argc > 2) {
		cout << "##########################################################################" << endl;
		cout << "Error: Too many arguments. Correct invocation: parser <target file name>" << endl;
		cout << "##########################################################################" << endl;
		return -1;
	}
	else if (argc == 1) {
		cout << "Interactive User Input Mode:" << endl;
		string userInput;
		ofstream streamFile;
		streamFile.open(userFile.c_str());
		
		//Capture user keyboard input
		if (streamFile.is_open()) {
			cout << "Stream File Creation Successful" << endl;
			cout << "Please enter characters/words one at a time. Press CTRL-D to finish interactive input." << endl;
			while ( cin >> userInput) {
				streamFile << userInput << "\n";
			}
			streamFile.close();
			cout << "----------" << endl;
			cout << "Input saved to: " << userFile << endl;
			cout << "--------------" << endl;
			cout << "Words in input: " << endl;
			string line;
			ifstream file (userFile.c_str());
			if (file.is_open()) {
				while (getline(file, line)) {
					if ( (!line.empty()) && (line[line.length()-1] == '\n') ) {
						line.erase(line.length()-1);
					}
					cout << line << ", ";
				}
				file.close();
				cout << "\n----------" << endl;
			}
		}
		else {
			perror("Error Creating Stream File");
			return 1;
		}
		inFileName = new char[userFile.length() + 1];
		strcpy(inFileName, userFile.c_str());
		inFile.open(inFileName, ifstream::in);
		if (!inFile.is_open()) {
			cout << "Error: File could not be opened, please verify file name and extension if applicable." << endl;
			return -1;
		}
		else {	
			cout << "File opened, processing: " << endl;
			readFile(inFile);
		} 
	}
	else if (argc == 2) {
		string fileName = argv[1];
		if ((fileName[fileName.length() - 1] != '0') && (fileName[fileName.length() - 2] != '2') && (fileName[fileName.length() - 3] != '0') && (fileName[fileName.length() - 4] != '2') && (fileName[fileName.length() - 5] != 'p') && (fileName[fileName.length() - 6] != 's') && (fileName[fileName.length() - 7] != '.'))  {
			fileName.append(".sp2020");
		} //This isnt falwless
		inFileName = new char[fileName.length() + 1];
		strcpy(inFileName, fileName.c_str());
		inFile.open(inFileName, ifstream::in);
		if (!inFile.is_open()) {
			cout << "Error: File could not be opened, please verify file name and extension if applicable." << endl;
			return -1;
		}
		else {	
			cout << "File opened, processing: " << endl;
			readFile(inFile);
		}
	}
	else {
		cout << "##########################################################################" << endl;
		cout << "Error: Unknown file error . Correct invocation: parser <target file name>" << endl;
		cout << "##########################################################################" << endl;
		return -1;
	}
	node_t* root = parser();
	preOrder(root, root->level);
	inFile.close();
	return 0;
}
			
