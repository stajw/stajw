#include <stdio.h>
#include <string.h>

int main(){
	int menu;

	while (1){
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
		int usernum = 0;
		int tweetnum = 0;
		int follownum = 0;
		int userid[10000] = { 0 };
		int useridcnt[10000] = { -1 };
		int useridnum = 0;
		switch (menu){
		case 0: {
			
			char arr[1000];
			char *blk;

			FILE *fp = fopen("C:\\ds\\user.txt", "r");

			while (fgets(arr, sizeof(arr), fp) != NULL){
				if (!(arr[0] == '\n' || arr[0] == ' ')){
					int ID = atoi(arr);
					userid[useridnum++] = ID;
					fgets(arr, sizeof(arr), fp);
					fgets(arr, sizeof(arr), fp);

					if ((blk = strchr(arr, '\n')) != NULL) *blk = '\0';
					usernum++;
				}
			}
			printf("total users : %d\n", usernum);
			fclose(fp);
		
			fp = fopen("C:\\ds\\friend.txt", "r");

			while (fgets(arr, sizeof(arr), fp) != NULL){
				if (!(arr[0] == ' ' || arr[0] == '\n')){
					int firstID = atoi(arr);
					for (int i = 0; i < 10000; i++){
						if (firstID == userid[i]){
							useridcnt[i]++;
							break;
						}
					}
					fgets(arr, sizeof(arr), fp);
					int secondID = atoi(arr);
					for (int i = 0; i < 10000; i++){
						if (secondID == userid[i]){
							useridcnt[i]++;
							break;
						}
					}
					follownum++;
				}
			}
			printf("Total friendship records : %d\n", follownum);
			fclose(fp);

			fp = fopen("C:\\ds\\word.txt", "r");

			while (fgets(arr, sizeof(arr), fp) != NULL){
				if (!(arr[0] == ' ' || arr[0] == '\n')){
					fgets(arr, sizeof(arr), fp);
					fgets(arr, sizeof(arr), fp);
					int tweetword = arr;
					tweetnum++;
				}
			}
			printf("Total tweets : %d\n", tweetnum);
			fclose(fp);
		
		}
		break;
		case 1: {
			int max, min;
			max = useridcnt[0];
			for (int i = 1; i < 10000; i++){
				if (useridcnt[i] > max) max = useridcnt[i];
			}
			min = useridcnt[0];
			for (int i = 1; i < 100; i++){
				if (useridcnt[i] != -1 && useridcnt[i] < min) min = useridcnt[i];
			}

			printf("Average number of friends: %d", follownum / usernum);
			printf("Minimum friends : %d\n", min);
			printf("Maximum friends : %d\n", max);
			printf("\n");
		
			
		}
		break;
		}
	}
	return 0;
}
