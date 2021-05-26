//Author: Timothy Schultz

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "dnatoprotein.h"
#include "burrowwheeler.h"

using namespace std;

//Static Variables
static int flagF;
static string fileName;

//Function Declarations.
static void usage(string);
static void menu();

int main(int argc, char* argv[])
{
	//Contains switch value
	int opt;
	//String containing file name
	fileName = argv[1];

	//Getopt to parse h
	while((opt = getopt(argc, argv, "h")) != -1)
	{
		switch(opt)
		{
			case 'h':
				usage(fileName);
				return 0;
			case '?':
				usage(fileName);
				return 0;
		}
	}

	//Determines the amount of arguments passed
	
	if(argc == 1)
	{
		usage(fileName);
		return 0;

	}
	else if(argc == 2)
	{
		flagF = 1;
	}
	else
	{
		usage(fileName);
		return 0;
	}

	//Contains users choice
	int choice;

	cout << "Bioinformatics Tool Box:\n" << endl;

	do {
		do {
			menu();
			cout << "Selection: ";
			cin >> choice;
			cout << "\n";
		} while (choice != 1 && choice != 2 && choice != 3);

		switch (choice) 
		{
			case 1: transcription(fileName);
				choice = 4;
				break;
			case 2: translation(fileName);
				choice = 4;
				break;
			case 3: burrowTransform(fileName);
				choice = 4;
				break;
			case 4: break;
			default: cout << "Invalid Choice. Program Terminated." << endl;
				 choice = 4;
				 break;
		}

	} while (choice != 3);

	return 0;
}

static void usage(string file)
{
	cout << "Usage: " << file << "[file]" << endl;
}

static void menu()
{
	cout << "1. Transcription" << endl;
	cout << "2. Translation" << endl;
	cout << "3. Burrow-Wheeler Transform" << endl;
	cout << "4. Quit\n" << endl;
}
