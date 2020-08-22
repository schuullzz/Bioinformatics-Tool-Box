# Bioinformatics Toolbox

This script converts an antisense DNA sequence to an RNA sequence and translates RNA to a polypeptide.

## Installation

The Bioinformatics Toolbox has been tested on CentOS v6.10 with gcc v6.1.0.

```
g++ -o toolbox Main.cpp
```

## Usage

Calling the Bioinformatics Toolbox will generate a prompt asking for the user to choose between transcription, translation, or quitting the program.

```
./toolbox

Bioinformatics Tool Box:

1. Transcription
2. Translation
3. Quit
```

Choosing to start "Transcription" will generate the following prompt for an input file:

```
What is the name of the file you would like to read from?(Make sure to include .txt).
```

In this example, the following input was given as "test.txt".

```
TACAAAGGGTATGTAATT
```

Upon successful transcription, the RNA sequence will be written to the file "mRNA.txt" and a message will appear prompting the user to choose another option.

```
Your file has successfully been transcribed.

1. Transcription
2. Translation
3. Quit
```

Choosing "Translation" will generate another prompt for an input file, which here will be "mRNA.txt" generated in the previous step. 

```
AUGUUUCCCAUACAUUAA
```

Upon successful translation, the polypeptide will be written to the file "Protein.txt" and a message will appear prompting the user to choose another option. The user can transcribe/translate more files, or quit the program.

At the end of one transcription translation session, you should have three files: the original "test.txt" antisense DNA, the transcribed "mRNA.txt", and the translated "Protein.txt"

```
test.txt: TACAAAGGGTATGTAATT
mRNA.txt: AUGUUUCCCAUACAUUAA
Protein.txt: MetPheProIleHis
```
