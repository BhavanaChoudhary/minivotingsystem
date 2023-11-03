#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOTES 100
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

int TeamRed = 0, TeamBlue = 0, TeamYellow = 0, TeamGreen = 0;
// Part 4B- To check if the votes are repeated and to store the votes that have been casted
typedef struct {
  int voter_id;//to store voter id
  int vote; //to store the vote which has been casted
} Vote;

Vote votes[MAX_VOTES];
int numVotes = 0; //to store total number of votes

bool isVoteRepeated(int voter_id, int vote) {
  for (int i = 0; i < numVotes; i++) {
    if (votes[i].voter_id == voter_id && votes[i].vote == vote) {
      return true;
    }
  }
  return false;
}

void addVote(int voter_id, int vote) {
  if (isVoteRepeated(voter_id, vote)) {
    printf("YOU HAVE ATTEMPTED TO VOTE MULTIPLE TIMES, SO YOU HAVE BEEN BANNED.\n");
  } else {
    votes[numVotes].voter_id = voter_id;
    votes[numVotes].vote = vote;
    numVotes++;
    printf("Vote recorded successfully.\n");
  }
}
// Part 1 is to open the file and read the contents which are to be displayed
int main() {
  FILE *file = fopen("voternames&theirID.txt", "r");
  if (file == NULL) {
    printf("Failed to open the file.\n");
    return 1;
  }
  // Read and print the contents of the file
  char id[MAX_ID_LENGTH];
  char name[MAX_NAME_LENGTH];

  while (fscanf(file, "%s %s", id, name) != EOF) {
    printf("ID: %s, Name: %s\n", id, name);
  }

  fclose(file);
  // Part-2:-Accept voter_id and voter_name from the user

  int numVoters = 0;
  while (numVoters < 10) {  // Repeat until 10 voters have casted their votes
    printf("Voter %d\n", numVoters + 1);

    char voter_id[MAX_ID_LENGTH];
    char voter_name[MAX_NAME_LENGTH];
    char father_name[MAX_NAME_LENGTH];
    char mother_name[MAX_NAME_LENGTH];

    printf("Enter your ID: ");
    scanf("%s", voter_id);

    printf("Enter your Name (With Underscore For Space In Between Name): ");
    scanf("%s", voter_name);
    
    printf("Enter your father's name(With Underscore For Space In Between Name): ");
    scanf("%s", father_name);

    printf("Enter your mother's name (With Underscore For Space In Between Name): ");
      scanf("%s", mother_name);

      int voter_age;
      printf("Enter your age: ");
      scanf("%d", &voter_age);

    if(voter_age>=18)
    {
      printf("you are eligible for voting.");
    }
    else
    {
      printf("you are not eligible for voting ");
      break;
    }
    

    file = fopen("voternames&theirID.txt", "r");
    if (file == NULL) {
      printf("Failed to open the file.\n");
      return 1;
    }
  // Part 3 :-TO CHEECK IF THE ID AND NAME BELONG TO THE FILE AND VERIFY THEM
    int isValid = 0;
    while (fscanf(file, "%s %s", id, name) != EOF) {
      if (strcmp(voter_id, id) == 0 && strcmp(voter_name, name) == 0) {
        isValid = 1;
        break;
      }
    }

    fclose(file);
  // Proceed to the next part if the entered data belongs to the file
    if (isValid) {
      printf("ID and Voter Name Are Verified. Proceeding to the Next Part.\n");

      int choose;
      printf("The teams are:\n");
      printf("1. TeamRed\n");
      printf("2. TeamBlue\n");
      printf("3. TeamYellow\n");
      printf("4. TeamGreen\n");
      printf("Choose your team: ");
      scanf("%d", &choose);

      switch (choose) {
        case 1:
          TeamRed += 1;
          addVote(atoi(voter_id), choose);
          break;
        case 2:
          TeamBlue += 1;
          addVote(atoi(voter_id), choose);
          break;
        case 3:
          TeamYellow += 1;
          addVote(atoi(voter_id), choose);
          break;
        case 4:
          TeamGreen += 1;
          addVote(atoi(voter_id), choose);
          break;
        default:
          printf("Invalid choice. Please choose a valid team.\n");
          return 1;
      }

      numVoters++;
      printf("All votes are valid.\n");
    } else {
      printf("Invalid ID or name. Cannot proceed.\n");
    }
  }

  // Display the final results
  printf("\n-----FINAL RESULTS-----\n");
  printf("TeamRed: %d votes\n", TeamRed);
  printf("TeamBlue: %d votes\n", TeamBlue);
  printf("TeamYellow: %d votes\n", TeamYellow);
  printf("TeamGreen: %d votes\n", TeamGreen);
   // Determine the team with the highest votes
    int maxVotes = TeamRed;
    char winningTeam[20] = "TeamRed";

    if (TeamBlue > maxVotes) {
      maxVotes = TeamBlue;
      strcpy(winningTeam, "TeamBlue");
    }
    if (TeamYellow > maxVotes) {
      maxVotes = TeamYellow;
      strcpy(winningTeam, "TeamYellow");
    }
    if (TeamGreen > maxVotes) {
      maxVotes = TeamGreen;
      strcpy(winningTeam, "TeamGreen");
    }

    printf("\nTeam with the highest votes: %s\n", winningTeam);
    
  return 0;

}
// Coding By
// Bhavana Choudhary (bhavanabc017@gmail.com)
// Priya V.B (priyabirajdar73@gmail.com)
// Atheeq Ahmed M.J (mdatheeq.2004@gmail.com)
