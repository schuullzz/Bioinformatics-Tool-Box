# Bioinformatics Toolbox
## Main.cpp dnatoprotein.cpp dnatoprotein.h

* This script converts an antisense DNA sequence to an RNA sequence and translates RNA to a polypeptide.

## Installation

The Bioinformatics Toolbox has been tested on CentOS v6.10 with gcc v6.1.0.

```
make
```

## Usage

Calling the Bioinformatics Toolbox will generate a prompt asking for the user to choose between transcription, translation, or quitting the program.

* toolbox [-h]

```
./toolbox [option var]
./toolbox [file]

Bioinformatics Tool Box:

1. Transcription
2. Translation
3. Quit
```
In this example, the following input was given as "test.txt"

```
TACAAAGGGTATGTAATT
```

Upon successful transcription, the RNA sequence will be written to the file "mRNA.txt".

```
Your file has successfully been transcribed.
```

Choosing "Translation" will generate another prompt for an input file, which here will be "mRNA.txt".

```
AUGUUUCCCAUACAUUAA
```
Upon successful translation, the polypeptide will be written to the file "Protein.txt".

```
test.txt: TACAAAGGGTATGTAATT
mRNA.txt: AUGUUUCCCAUACAUUAA
Protein.txt: MetPheProIleHis
```
