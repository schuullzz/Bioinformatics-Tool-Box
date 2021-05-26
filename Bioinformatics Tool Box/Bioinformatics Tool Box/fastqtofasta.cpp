#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void fastqfasta(string inFile)
{
	string holder = "";
	size_t found;
	vector<string> fileData;

	ifstream input(inFile);

	while (getline(input, holder))
	{
		fileData.push_back(holder);
		holder.clear();
	}

	ofstream output("Conversion.txt");

	for (int x = 0; x < (int)fileData.size(); x++)
	{
		holder = fileData.at(x);
		found = holder.find("seq");
		if (found != string::npos)
		{
			holder[0] = '>';
			output << holder << endl;
			holder.clear();
			holder = fileData.at(x + 1);
			output << holder << endl;
			holder.clear();
		}
	}

	input.close();
	output.close();

	cout << "FASTQ to FASTA conversion Successful." << endl;		

	return;
}
