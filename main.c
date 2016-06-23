#include <stdio.h>
int main(){
	int menu;
	printf("0. Read data files\n");
	printf("1. display statistics\n");
	printf("2. Top 5 most tweeted words\n");
	printf("3. Top 5 most tweeted users\n");
	printf("4. Find users who tweeted a word(e.g., ’연세대’)\n");
	printf("5. Find all people who are friends of the above users\n");
	printf("6. Delete all mentions of a word\n");
	printf("7. Delete all users who mentioned a word\n");
	printf("8. Find strongly connected components\n");
	printf("9. Find shortest path from a given user\n");
	printf("99. Quit\n");
	printf("Select Menu : ");
	scanf("%d", &menu);
	return 0;
}
