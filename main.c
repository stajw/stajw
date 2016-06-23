#include <stdio.h>
#include <string.h>

int main(){
	int menu;
	int avgfriend = 0;
	int avgtweet = 0;
	do{
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
		int friendnum = 0;
		int userid[10000] = { 0 };
		int useridcnt[10000] = { 0 };
		int tweetcnt[10000] = { 0 };
		int useridnum = 0;
		int maxfriend, minfriend, maxtweet, mintweet;

		switch (menu){
		case 0: {
			printf("\n");
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
					friendnum++;
				}
			}
			printf("Total friendship records : %d\n", friendnum);
			fclose(fp);

			fp = fopen("C:\\ds\\word.txt", "r");

			while (fgets(arr, sizeof(arr), fp) != NULL){
				if (!(arr[0] == ' ' || arr[0] == '\n')){
					int tweetID = atoi(arr);
					for (int i = 0; i < 10000; i++){
						if (tweetID == userid[i]){
							tweetcnt[i]++;
							break;
						}
					}
					fgets(arr, sizeof(arr), fp);
					fgets(arr, sizeof(arr), fp);

					if ((blk = strchr(arr, '\n')) != NULL) *blk = '\0';
					tweetnum++;
				}
			}
			printf("Total tweets : %d\n", tweetnum);
			fclose(fp);

			avgfriend = (int)(((float)(friendnum*2) / usernum)+0.5);
			avgtweet = (int)(((float)tweetnum / usernum)+0.5);

			maxfriend = useridcnt[0];
			minfriend = useridcnt[0];
			for (int i = 1; i < usernum; i++){
				if (useridcnt[i] > maxfriend) maxfriend = useridcnt[i];
			}
			for (int i = 1; i < usernum; i++){
				if (useridcnt[i] < minfriend) minfriend = useridcnt[i];
			}

			maxtweet = tweetcnt[0];
			mintweet = tweetcnt[0];
			for (int i = 1; i < usernum; i++){
				if (tweetcnt[i] > maxtweet) maxtweet = tweetcnt[i];
			}
			for (int i = 1; i < usernum; i++){
				if (tweetcnt[i] < mintweet) mintweet = tweetcnt[i];
			}
			printf("\n");

		}
				break;
		case 1: {
			printf("\n");
			printf("Average number of friends: %d\n", avgfriend);
			printf("Minimum friends : %d\n", minfriend);
			printf("Maximum friends : %d\n", maxfriend);
			printf("Average tweets per user : %d\n", avgtweet);
			printf("Minimum tweets per user : %d\n", mintweet);
			printf("Maximum tweets per user : %d\n", maxtweet);
			printf("\n");
		}
				break;
		}
	} while (menu != 99);

	return 0;
}
