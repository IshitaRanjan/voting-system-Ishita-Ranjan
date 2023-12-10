#include <stdio.h>
#include <string.h>

int main() {
    char candidate_name[50];
    char candidate_gender[10];
    int candidate_age;
    int num_of_parties = 5;
    char parties[][2] = {"A", "B", "C", "D", "E"};
    char parties_name[num_of_parties][2];
    int parties_count[num_of_parties];

    for (int i = 0; i < num_of_parties; i++) {
        strcpy(parties_name[i], parties[i]);
        parties_count[i] = 0;
    }

    while (1) {

        printf("\nEnter candidate's name : ");
        scanf("%s", candidate_name); 

        printf("Enter candidate's gender (male/female) : ");
        scanf("%s", candidate_gender);

        printf("Enter candidate's age : ");
        scanf("%d", &candidate_age);

        printf("\nCANDIDATE'S DETAILS : \n");
        if (strcmp(candidate_gender, "male") == 0) {
            printf("Name : Mr. %s\n", candidate_name);
        } 
        else if (strcmp(candidate_gender, "female") == 0) {
            printf("Name : Ms. %s\n", candidate_name);
        } 
        else {
            printf("Invalid gender entered.\n");
            continue;
        }
        printf("Age : %d\n\n", candidate_age);

        if (candidate_age < 18) {
            printf("Sorry, %s %s,\nyou are not eligible for voting.\n", (strcmp(candidate_gender, "male") == 0) ? "Mr." : "Ms.", candidate_name);
        } 
        else {
            printf("Welcome, %s %s,\nYou are eligible for voting.\n\n", (strcmp(candidate_gender, "male") == 0) ? "Mr." : "Ms.", candidate_name);
            printf("PARTIES LIST :\n");

            for (int i = 0; i < num_of_parties; i++) {
                printf("%d. %s\n", i + 1, parties[i]);
            }

            printf("\nVote from above provided list of parties (enter name) : ");
            char user_input[2]; 
            scanf("%s", user_input);

            int party_index = -1;
            for (int i = 0; i < num_of_parties; i++) {
                if (strcmp(user_input, parties[i]) == 0) {
                    party_index = i;
                    break;
                }
            }

            if (party_index != -1) {
                parties_count[party_index]++;
                printf("Vote for %s recorded, Total count : %d\n", parties_name[party_index], parties_count[party_index]);
            } 
            else {
                printf("Invalid party name. Please enter a valid party name : \n");
            }

        }

        printf("\nFinal Vote Counts For Each Party : \n");
        for (int i = 0; i < num_of_parties; i++) {
        printf("%s: %d votes\n", parties_name[i], parties_count[i]);
        }    

        printf("If you wish to continue voting type, 'yes'. If you want to end voting, type 'exit' : ");
        scanf("%s", candidate_name);

        if (strcmp(candidate_name, "exit") == 0) {
            break;
        }
    }
    return 0;
}

