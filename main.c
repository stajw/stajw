#include <stdio.h>
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
		switch (menu){
		case 0: {
			int usernum = 0;
			int tweetnum = 0;
			int follownum = 0;
			char arr[1000];
			char *blk;

			FILE *fp = fopen("C:\\ds\\user.txt", "r");

			while (fgets(arr, sizeof(arr), fp) != NULL){
				if (!(arr[0] == '\n' || arr[0] == ' ')){
					int ID = atoi(arr);
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
					int UserID = atoi(arr);
					fgets(arr, sizeof(arr), fp);
					int FollowID = atoi(arr);
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
		}
	}
	return 0;
}
