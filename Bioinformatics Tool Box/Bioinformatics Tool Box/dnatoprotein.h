//Author: Timothy Schultz

#ifndef DNATOPROTEIN_H
#define DNATOPROTEIN_H

using namespace std;

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

void transcription(string);
void translation(string);
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

#endif
