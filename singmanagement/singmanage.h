#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TRUE     1
#define FALSE    0

#define INSERT   1
#define RETRIEVE 2
#define PRINT    3
#define REMOVE   4
#define REWRITE  5
#define INIT     6
#define ABOUT    7
#define EXIT     0

//insert menu num
#define CONSOL_IN   1
#define FILE_IN     2
#define PREVIOUS 0

//insertconsol num
#define FIRST    1
#define RANDOM   2
#define LAST     3

//retrieve num
#define SONG     1
#define PREFER   2

//Printconsol num
#define UNORDERED   1

typedef struct _SongList{

	/*data field*/
	char chSongname[30];
	char chSinger[30];
	char chJanre[20];
	double lfPreference;
	/*link field*/
	struct _SongList *link;


}SongList;

SongList *pHeader;

int Displaymenu();



void Insertmenu();
void Insertconsol();
void Insertfile();

void Retrievemenu();
void Retrievesongname();
void Retrieveprefer();

void Printmenu();
void Printconsol();
void PCunordered();
void PCprefer();
void Printfile();
void PFunordered();
void PFprefer();

void Removemenu();

void Rewriteprefermenu();

void Initmenu();

void Aboutmenu();
