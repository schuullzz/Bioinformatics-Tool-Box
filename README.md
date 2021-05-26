# Bioinformatics Toolbox
## Main.cpp dnatoprotein.cpp burrowwheeler.cpp dnatoprotein.h burrowwheeler.h

* Converts an antisense DNA sequence to an RNA sequence and translates RNA to a polypeptide.
* Preforms a Burrow-Wheeler transformation on a user-input string, outputting the result of each transformation as well as the final transformed string.

## Installation

The Bioinformatics Toolbox has been tested on CentOS v6.10 with gcc v6.1.0.

```
make
```

## Usage

Calling the Bioinformatics Toolbox will generate a prompt asking for the user to choose between transcription, translation, burrow-wheeler tranform or quitting the program.

toolbox [-h]

```
./toolbox [option var]
./toolbox [file]

Bioinformatics Tool Box:

1. Transcription
2. Translation
3. Burrow-Wheeler Transform
4. Quit
```
##Transcription and Translation

In this example, the following input was given as "test1.txt"

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
##Burrow-Wheeler Tranformer

In this example, the follwing input was given as "test2.txt"

```
foobar
```

Upon success two files will be created Combination.txt and LastIndexSequence.txt.
Combination.txt contains each successive step of the transformation per line.
LastIndexSequence.txt contains the final transformed string.

"Combination.txt" will contain: 

```
arfoob
barfoo
foobar
obarfo
oobarf
rfooba
```

"LastIndexSequence.txt will contain:

```
borofa
```



