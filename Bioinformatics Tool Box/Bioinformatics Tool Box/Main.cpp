//Timothy Schultz

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

//Function Declarations.
void menu();
void transcription();
void translation();
string getFile();
bool checkNucleotide(string);
bool checkNucleotideRna(string);
bool checkLength(string);
vector <int> indexStartCodon(vector<string>);
vector <int> indexStartCodonRna(vector<string>);
bool checkStartCodon(vector<int>);
vector <int> indexStopCodon(vector<string>);
vector <int> indexStopCodonRna(vector<string>);
bool checkStopCodon(vector<int>);
int findEndIndex(vector<int>, int);
bool checkPosition(int);
string translation(vector<string>, int, int);

int main()
{
	int choice;

	cout << "Bioinformatics Tool Box:\n" << endl;

	do {
		do {
			menu();
			cout << "Selection: ";
			cin >> choice;
			cout << "\n";
		} while (choice != 1 && choice != 2 && choice != 3);

		switch (choice) {
		case 1: transcription();
			break;
		case 2: translation();
			break;
		case 3: break;
		}
	} while (choice != 3);

	return 0;
}

void menu()
{
	cout << "1. Transcription" << endl;
	cout << "2. Translation" << endl;
	cout << "3. Quit\n" << endl;
}

void transcription()
{
	//Contains the name of file to be opened.
	string file;
	//Contains one nucleotide at a time.
	char nucleotide;
	//Contains nucleotides of DNA strand.
	string nucleoDNA = "";
	//Contains nucleotides of RNA strand.
	string nucleoRNA = "";
	//Contains strings of length 3.
	string holder = "";
	//Contains the index of start codon.
	int indexStart = 0;
	//Contains the index of stop codon.
	int endIndex = 0;
	//Contains the DNA broken up into strings of three.
	vector<string> dnaBreak;
	//Contains the indexes of all start codons.
	vector<int> startCodons;
	//Contains the indexes of all stop codons.
	vector<int> stopCodons;

	//Calls function getFile to retrieve and open desired file.
	file = getFile();

	ifstream input(file);

	//Reads in all nucleotides found in file and converts them to uppercase.
	while (input >> nucleotide)
	{
		nucleoDNA += toupper(nucleotide);
	}

	//Verfies the DNA strand is the correct length.
	if (!checkLength(nucleoDNA))
	{
		input.close();
		return;
	}

	//Calls function checkNucleotide to verify that all characters are correct.
	if (!checkNucleotide(nucleoDNA))
	{
		input.close();
		return;
	}

	//Keeps track of the number of codons.
	int index = 1;

	//Breaks up DNA into codons.
	for (int x = 0; x < nucleoDNA.length(); x++)
	{
		if (x % 3 == 0 && x != 0)
		{
			dnaBreak.push_back(holder);
			holder.clear();
			index++;
		}

		holder += nucleoDNA[x];
	}
	dnaBreak.push_back(holder);
	holder.clear();

	//Calls function indexStartCodon to find first occurence of start codon.
	startCodons = indexStartCodon(dnaBreak);

	//Calls function checkStartCodon to verify that there exists a start codon. If one
	//exists it is stored in indexStart.
	if (!checkStartCodon(startCodons))
	{
		input.close();
		return;
	}
	else
	{
		indexStart = startCodons.at(0);
	}

	//Calls function indexStopCodon to find indexes of all stop codons.
	stopCodons = indexStopCodon(dnaBreak);

	//Calls function checkStopCodon to verify there is a stop codon.
	if (!checkStopCodon(stopCodons))
	{
		input.close();
		return;
	}

	//Calls function findEndIndex to get index of stop codon after start codon.
	endIndex = findEndIndex(stopCodons, indexStart);

	//Calls funciton checkPosition to verify that there is stop codon after start codon.
	if (!checkPosition(endIndex))
	{
		input.close();
		return;
	}

	//Calls function translation to get mRNA.
	nucleoRNA = translation(dnaBreak, indexStart, endIndex + 1);

	//Writes mRNA to a file.
	ofstream output("mRNA.txt");
	output << nucleoRNA << endl;

	cout << "\nYour file has successfully been transcribed.\n" << endl;

	input.close();
	output.close();
}

void translation()
{
	//Contains the name of file to be opened.
	string file;
	//Contains one nucleotide at a time.
	char nucleotide;
	//Contains nucleotides of RNA strand.
	string nucleoRNA = "";
	//Contains strings of length 3.
	string holder = "";
	//Contains the index of start codon.
	int indexStart = 0;
	//Contains the index of stop codon.
	int endIndex = 0;
	//Contains index of protein.
	int indexProtein = 0;
	//Contains the DNA broken up into strings of three.
	vector<string> rnaBreak;
	//Contains the indexes of all start codons.
	vector<int> startCodons;
	//Contains the indexes of all stop codons.
	vector<int> stopCodons;
	//Contains the transcribed mRNA.
	vector<string> proteinOutput;

	//Contains the codons for all proteins.
	const string codonsProteins[61] = { "UUU", "UUC", "UUA", "UUG", "CUU", "CUC", "CUA", "CUG", "AUU", "AUC",
	"AUA", "AUG", "GUU", "GUC", "GUA", "GUG", "UCU", "UCC", "UCA", "UCG", "CCU", "CCC", "CCA", "CCG", "ACU", "ACC",
	"ACA", "ACG", "GCU", "GCC", "GCA", "GCG", "UAU", "UAC", "CAU", "CAC", "CAA", "CAG", "AAU", "AAC",
	"AAA", "AAG", "GAU", "GAC", "GAA", "GAG", "UGU", "UGC", "UGG", "CGU", "CGC", "CGA", "CGG", "AGU",
	"AGC", "AGA", "AGG", "GGU", "GGC", "GGA", "GGG" };

	//Contains all proteins.
	const string proteins[61] = { "Phe", "Phe", "Leu", "Leu", "Leu", "Leu", "Leu", "Leu", "Ile", "Ile", "Ile",
	"Met", "Val", "Val", "Val", "Val", "Ser", "Ser", "Ser", "Ser", "Pro", "Pro", "Pro", "Pro", "Thr", "Thr",
	"Thr", "Thr", "Ala", "Ala", "Ala", "Ala", "Tyr", "Tyr", "His", "His", "Gln", "Gln", "Asn", "Asn", "Lys",
	"Lys", "Asp", "Asp", "Glu", "Glu", "Cys", "Cys", "Trp", "Arg", "Arg", "Arg", "Arg", "Ser", "Ser", "Arg",
	"Arg", "Gly", "Gly", "Gly", "Gly" };


	//Calls function getFile to retrieve and open desired file.
	file = getFile();

	ifstream input(file);

	//Reads in all nucleotides found in file and converts them to uppercase.
	while (input >> nucleotide)
	{
		nucleoRNA += toupper(nucleotide);
	}

	//Verfies the DNA strand is the correct length.
	if (!checkLength(nucleoRNA))
	{
		input.close();
		return;
	}

	//Calls function checkNucleotide to verify that all characters are correct.
	if (!checkNucleotideRna(nucleoRNA))
	{
		input.close();
		return;
	}

	//Keeps track of the number of codons.
	int index = 1;

	//Breaks up DNA into codons.
	for (int x = 0; x < nucleoRNA.length(); x++)
	{
		if (x % 3 == 0 && x != 0)
		{
			rnaBreak.push_back(holder);
			holder.clear();
			index++;
		}

		holder += nucleoRNA[x];
	}
	rnaBreak.push_back(holder);
	holder.clear();

	//Calls function indexStartCodon to find first occurence of start codon.
	startCodons = indexStartCodonRna(rnaBreak);

	//Calls function checkStartCodon to verify that there exists a start codon. If one
	//exists it is stored in indexStart.
	if (!checkStartCodon(startCodons))
	{
		input.close();
		return;
	}
	else
	{
		indexStart = startCodons.at(0);
	}

	//Calls function indexStopCodon to find indexes of all stop codons.
	stopCodons = indexStopCodonRna(rnaBreak);

	//Calls function checkStopCodon to verify there is a stop codon.
	if (!checkStopCodon(stopCodons))
	{
		input.close();
		return;
	}

	//Calls function findEndIndex to get index of stop codon after start codon.
	endIndex = findEndIndex(stopCodons, indexStart);

	//Calls funciton checkPosition to verify that there is stop codon after start codon.
	if (!checkPosition(endIndex))
	{
		input.close();
		return;
	}

	//Keeps track of number of codons.
	index = 1;

	//Breaks mRNA into codons.
	for (int x = 0; x < nucleoRNA.length(); x++)
	{
		if (x % 3 == 0 && x != 0)
		{
			proteinOutput.push_back(holder);
			holder.clear();
			index++;
		}

		holder += nucleoRNA[x];
	}
	proteinOutput.push_back(holder);
	holder.clear();

	ofstream output("Protein.txt");

	//Matches up the codons to their corresponding protein and writes them to
	//a file.
	for (int x = 0; x < index; x++)
	{
		for (indexProtein; indexProtein < 61; indexProtein++)
		{
			if (proteinOutput[x] == codonsProteins[indexProtein])
			{
				output << proteins[indexProtein];
			}
		}
		indexProtein = 0;
	}

	cout << "\nYour file has successfully been translated.\n" << endl;

	input.close();
	output.close();

}

//Retrieves the name of the file that is being read from.
string getFile()
{
	string inFile;

	cout << "What is the name of the file you would like to read from?";
	cout << "(Make sure to include .txt)." << endl;
	cin >> inFile;

	return inFile;
}

//Checks to verify only legal characters are used.
bool checkNucleotide(string nucleotides)
{
	for (int x = 0; x < nucleotides.length(); x++)
	{
		if (nucleotides[x] != 'A' && nucleotides[x] != 'T' && nucleotides[x] != 'G' && nucleotides[x] != 'C')
		{
			cout << "\nThe DNA contains an unrecognizable nucleotide." << endl;
			return false;
		}
	}

	return true;
}

//Checks to verify only legal characters are used.
bool checkNucleotideRna(string nucleotides)
{
	for (int x = 0; x < nucleotides.length(); x++)
	{
		if (nucleotides[x] != 'A' && nucleotides[x] != 'U' && nucleotides[x] != 'G' && nucleotides[x] != 'C')
		{
			cout << "\nThe RNA contains an unrecognizable nucleotide." << endl;
			return false;
		}
	}

	return true;
}

//Verifies that there is the correct number of nucleotides in the DNA strand.
bool checkLength(string nucleotides)
{
	if (nucleotides.length() % 3 != 0)
	{
		cout << "\nContains the wrong number of nucleotides." << endl;
		return false;
	}
	else
	{
		return true;
	}
}

//Retrieves the indexes of all start codons.
vector <int> indexStartCodon(vector<string> nucleotides)
{
	string start = "TAC";
	vector <int> indexCodons;

	for (int x = 0; x < nucleotides.size(); x++)
	{
		if (nucleotides.at(x) == start)
		{
			indexCodons.push_back(x);
		}
	}

	return indexCodons;
}

//Retrieves the indexes of all start codons.
vector <int> indexStartCodonRna(vector<string> nucleotides)
{
	string start = "AUG";
	vector <int> indexCodons;

	for (int x = 0; x < nucleotides.size(); x++)
	{
		if (nucleotides.at(x) == start)
		{
			indexCodons.push_back(x);
		}
	}

	return indexCodons;
}


//Verifies that DNA strand contains a start codon.
bool checkStartCodon(vector<int> indexStart)
{
	if (indexStart.empty())
	{
		cout << "\nContains no start codon." << endl;
		return false;
	}
	else
	{
		return true;
	}
}

//Retrieves indexes of all stop codons.
vector <int> indexStopCodon(vector<string> nucleotides)
{
	string stop[3]{ "ATT", "ATG", "AGT" };
	vector <int> indexStop;

	for (int x = 0; x < nucleotides.size(); x++)
	{
		if (nucleotides.at(x) == stop[0])
		{
			indexStop.push_back(x);
		}
		else if (nucleotides.at(x) == stop[1])
		{
			indexStop.push_back(x);
		}
		else if (nucleotides.at(x) == stop[2])
		{
			indexStop.push_back(x);
		}
	}

	return indexStop;
}

//Retrieves indexes of all stop codons.
vector <int> indexStopCodonRna(vector<string> nucleotides)
{
	string stop[3]{ "UAA", "UAG", "UGA" };
	vector <int> indexStop;

	for (int x = 0; x < nucleotides.size(); x++)
	{
		if (nucleotides.at(x) == stop[0])
		{
			indexStop.push_back(x);
		}
		else if (nucleotides.at(x) == stop[1])
		{
			indexStop.push_back(x);
		}
		else if (nucleotides.at(x) == stop[2])
		{
			indexStop.push_back(x);
		}
	}

	return indexStop;
}


//Verifies that there exists a stop codon.
bool checkStopCodon(vector<int> indexStop)
{
	if (indexStop.empty())
	{
		cout << "\nContains no stop codon." << endl;
		return false;
	}
	else
	{
		return true;
	}
}

//Retrieves the index of the first stop codon after start codon.
int findEndIndex(vector<int> stopIndex, int indexStart)
{
	int endIndex = 0;

	for (int x = 0; x < stopIndex.size(); x++)
	{
		if (indexStart < stopIndex.at(x))
		{
			endIndex = stopIndex.at(x);
			break;
		}
	}

	return endIndex;
}

//Verifies that there is a stop codon after the start codon.
bool checkPosition(int end)
{
	if (end == 0)
	{
		cout << "\nThere is no stop codon after the start codon." << endl;
		return false;
	}
	else
	{
		return true;
	}

}

//Translates the DNA into RNA.
string translation(vector<string> nucleotides, int start, int end)
{
	string DNA;
	string RNA;

	for (int x = 0; x < end; x++)
	{
		DNA += nucleotides.at(x);
	}

	for (int x = start * 3; x < DNA.length(); x++)
	{
		switch (DNA[x])
		{
		case 'A': RNA += 'U';
			break;
		case 'T': RNA += 'A';
			break;
		case 'C': RNA += 'G';
			break;
		case 'G': RNA += 'C';
			break;
		default:  cout << "\nYou have included a character not found in the Genetic Code!";
			return 0;
		}

	}

	return RNA;
}
