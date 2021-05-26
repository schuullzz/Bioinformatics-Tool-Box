//Author: Timothy Schultz

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

void burrowTransform(string inFile)
{
	//Contains a nucleotide read from a file
	char nucleotide;
	//Contains the amount of spaces to rotate.
	int rotateRight = 1;
	//Contains all the nucleotides read from a file.
	vector<char> nucleotideSequence;
	//Contains all the nucleotides read from a file.
	string holder = "";
	//Contains the sequence of the last column 
	string lastIndexSequence = "";
	//Contains the sequence to write to a file.
	vector<string> nucleotideStrings;

	ifstream input(inFile);

	//Reads in the nucleotides from the file.
	while (input >> nucleotide)
	{
		nucleotideSequence.push_back(nucleotide);
		holder += nucleotide;
	}

	nucleotideStrings.push_back(holder);
	holder.clear();

	//Rotates the sequence based on the number of characters in the original sequence.
	for (int x = 1; x < (int)nucleotideSequence.size(); x++)
	{
		rotate(nucleotideSequence.begin(), nucleotideSequence.begin() + rotateRight, nucleotideSequence.end());

		for (int i = 0; i < (int)nucleotideSequence.size(); i++)
		{
			holder += nucleotideSequence.at(i);
		}

		nucleotideStrings.push_back(holder);
		holder.clear();
	}

	ofstream output("Combination.txt");
	ofstream output2("LastIndexSequence.txt");

	//Sorts based on ascII characters.
	sort(nucleotideStrings.begin(), nucleotideStrings.end());

	//Writes out each combination of the sequence.
	for (int x = 0; x < (int)nucleotideStrings.size(); x++)
	{
		output << nucleotideStrings.at(x) << endl;
		lastIndexSequence = nucleotideStrings.at(x);
	}

	//Writes the last column of nucleotides to file.
	for (int x = 0; x < (int)nucleotideStrings.size(); x++)
	{
		lastIndexSequence = nucleotideStrings.at(x);
		output2 << lastIndexSequence[lastIndexSequence.length() - 1];
		lastIndexSequence.clear();
	}

	input.close();
	output.close();
	output2.close();

	cout << "Burrow-Wheeler Transformation Successful" << endl;

	return;
}
