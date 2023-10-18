#ifndef UNIX_H
#define UNIX_H

#define LENGTH 200

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

extern char **environ;

/**
 * struct Aliass - cmponents of an alias
 * @name: assigned name of the alias
 * @value: string assigned to the name
 */

struct Alias
{
	char name[30];
	char value[80];
};

extern struct Alias aliasses[20];
extern int aliassesNo;

int executee(char *args[]);
void tokeniser(char *command, char *args[], int *argNo);
int toExit(char *args[], int argNo);
void giveEnv(void);
void givePrompt(void);
int createEnv(const char *comm, const char *soln, int replace);
int unCreate(const char *comm);
int toCd(const char *path);
void createA(const char *name, const char *value);
void listA(const char *name);
void exefile(const char *filename);

#endif
