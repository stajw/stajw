#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main(){
	int k = 0;
	int det = 0;
	int menu;
	int avgfriend = 0;
	int avgtweet = 0;
	int mosttweetuser[5] = { 0 };
	wchar_t mosttweetword[5] = { 0 };
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
		wchar_t tweet[100000] = { '\0' };
		int tweetwordnum[100000] = { 0 };
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
					
					for (int i = 0; i < 100000; i++){
						if (tweet[i] == arr){
							tweetwordnum[i]++;
							det = 1;
							break;
						}
					}

					if (det == 0){
						tweet[k] = arr;
						tweetwordnum[k]++;
						k++;
					}

					if ((blk = strchr(arr, '\n')) != NULL) *blk = '\0';
					tweetnum++;
				}
			}
			printf("Total tweets : %d\n", tweetnum);
			fclose(fp);

			avgfriend = (int)(((float)friendnum / usernum) + 0.5);
			avgtweet = (int)(((float)tweetnum / usernum) + 0.5);

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

			for (int i = 0; i < usernum - 1; i++){
				for (int j = i + 1; j < usernum; j++){
					if (tweetcnt[i] < tweetcnt[j]){
						int u = tweetcnt[i];
						tweetcnt[i] = tweetcnt[j];
						tweetcnt[j] = u;
						int x = userid[i];
						userid[i] = userid[j];
						userid[j] = x;
					}
				}
			}
			
			for (int i = 0; i < 5; i++) mosttweetuser[i] = userid[i];

			for (int i = 0; i < tweetnum - 1; i++){
				for (int j = i + 1; j < tweetnum; j++){
					if (tweetwordnum[i] < tweetwordnum[j]){
						int z = tweetwordnum[i];
						tweetwordnum[i] = tweetwordnum[j];
						tweetwordnum[j] = z;
						char ch = tweet[i];
						tweet[i] = tweet[j];
						tweet[j] = ch;
					}
				}
			}

			for (int i = 0; i < 5; i++) mosttweetword[i] = tweet[i];

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
		case 2: {
			printf("\n");
			printf("Top 5 most tweeted words\n");
			for (int i = 0; i < 5; i++){
				printf("%d. %c\n", i + 1, mosttweetword[i]);
			}
			printf("\n");
		}
				break;
		case 3: {
			printf("\n");
			printf("Top 5 most tweeted users\n");
			for (int i = 0; i < 5; i++){
				printf("%d. %d\n", i + 1, mosttweetuser[i]);
			}
			printf("\n");
		}
				break;
		}
	} while (menu != 99);

	return 0;
}
