# spellchk
A spell-check program using hash table

```
MISSPELLED WORDS

[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```

## Getting Started

1. Compile `spellchk` by executing `make spellchk` or `make`.
2. Execute `spellchk` by running:
```
$ ./spellchk [dictionary] text
```
- `dictionary` is the dictionary for spell-check. Provision of `dictionary` is optional. If it is omitted, the the program will use `dictionaries/large` by default. 
- `text` is the file you wish to spell-check

## Description
```
/spellchk
 |-keys
 | |-frankenstein.txt
 | |-her.txt
 | |-wells.txt
 | |-carroll.txt
 | |-xueqin1.txt
 | |-whittier.txt
 | |-aca.txt
 | |-constitution.txt
 | |-holmes.txt
 | |-rinehart.txt
 | |-surgery.txt
 | |-austen.txt
 | |-grimm.txt
 | |-stein.txt
 | |-mansfield.txt
 | |-birdman.txt
 | |-lalaland.txt
 | |-burnett.txt
 | |-federalist.txt
 | |-xueqin2.txt
 | |-cat.txt
 | |-stoker.txt
 | |-revenant.txt
 | |-homer.txt
 | |-tolstoy.txt
 | |-shakespeare.txt
 | |-pneumonoultramicroscopicsilicovolcanoconiosis.txt
 | |-wordsworth.txt
 |-dictionary.c
 |-README.md
 |-dictionary.h
 |-texts
 | |-frankenstein.txt
 | |-her.txt
 | |-wells.txt
 | |-carroll.txt
 | |-xueqin1.txt
 | |-whittier.txt
 | |-aca.txt
 | |-constitution.txt
 | |-holmes.txt
 | |-rinehart.txt
 | |-surgery.txt
 | |-austen.txt
 | |-grimm.txt
 | |-stein.txt
 | |-mansfield.txt
 | |-birdman.txt
 | |-lalaland.txt
 | |-burnett.txt
 | |-federalist.txt
 | |-xueqin2.txt
 | |-cat.txt
 | |-stoker.txt
 | |-revenant.txt
 | |-homer.txt
 | |-tolstoy.txt
 | |-shakespeare.txt
 | |-pneumonoultramicroscopicsilicovolcanoconiosis.txt
 | |-wordsworth.txt
 |-dictionaries
 | |-small
 | |-large
 |-Makefile
 |-spellchk.c
```

`texts/`

Text files for testing the program

`keys/`

Text files contain all of the words that are mispelled. To verify if hte program is running correctly, users can comparing their output against to one of the answer keys side by side using the `diff` command



