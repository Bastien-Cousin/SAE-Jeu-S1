#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // For strcmp()
#include <stdbool.h>
#include <locale.h>
#include <time.h>

#define MAX_LINE_LENGTH 512

// Setting constants for each file
const char* intro = "Histoire/Intro/Intro.txt";
const char* intro_fr = "Histoire/Intro/Intro_fr.txt";
const char* intro_gb = "Histoire/Intro/Intro_gb.txt";
const char* chapter1_fr = "Histoire/Histoire_fr/Chapter1_fr.txt";
const char* chapter1_gb = "Histoire/History_gb/Chapter1_gb.txt";
const char* chapter2_fr = "Histoire/Histoire_fr/Chapter2_fr.txt";
const char* chapter2_gb = "Histoire/History_gb/Chapter2_gb.txt";
const char* chapter3_fr = "Histoire/Histoire_fr/Chapter3_fr.txt";
const char* chapter3_gb = "Histoire/History_gb/Chapter3_gb.txt";
const char* enigmes_fr = "Histoire/Enigmes/Enigmes_fr.txt";
const char* enigmes_gb = "Histoire/Enigmes/Enigmes_gb.txt";


// Function for reading lines from a file: takes as parameters the path to the file,
// the desired line and an initially empty character string, which is then modified to contain the text of the chosen line
void read_line(const char* filename, int line_nbr, char* buffer) {
    char temp_buffer[MAX_LINE_LENGTH];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erreur pendant l'ouverture du fichier / File open error");
        exit(EXIT_FAILURE);
    }

    int actual_line = 1;
    while (fgets(temp_buffer, MAX_LINE_LENGTH, file) != NULL) {
        if (actual_line == line_nbr) {
            strcpy(buffer, temp_buffer);
            fclose(file);
            return;
        }
        actual_line++;
    }

    fclose(file);
    fprintf(stderr, "Ligne %d non trouvée dans le fichier / Line %d not found in file\n", line_nbr);
    exit(EXIT_FAILURE);
}

int main(void) {

    // UTF-8 character support
    setlocale(LC_ALL, "en_US.UTF-8");

    // Initializing the random number generator
    srand(time(NULL));

    char buffer[MAX_LINE_LENGTH]; // Variable to store the line read by the program in a text file
    char choice_language[3]; // Variable to store player's choice (2 characters + '\0' for terminator)
    char choice[33]; 
    char choice_nb[8];
    int nb;
    char riddle[50];
    int guard_state;
    int weapon;
    bool armor;
    bool health_potion;
    bool health_potion_unlocked;
    bool verif;

    // Language selection menu
    read_line(intro, 1, buffer);
    printf("%s", buffer);
    scanf("%2s", choice_language);

    // Comparison of strings to set the selected country
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) ||
        (strcmp(choice_language, "fR") == 0) || 
        (strcmp(choice_language, "Fr") == 0)) {
        
        read_line(intro, 3, buffer);
        printf("%s", buffer);

    } else if ((strcmp(choice_language, "gb") == 0) || 
            (strcmp(choice_language, "GB") == 0) || 
            (strcmp(choice_language, "gB") == 0) || 
            (strcmp(choice_language, "Gb") == 0)) {
        
        read_line(intro, 4, buffer);
        printf("%s", buffer);

    } else {
        read_line(intro, 5, buffer);
        printf("%s", buffer);
        return EXIT_FAILURE;
    }

    printf("\n");


    // Choice of player's name
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) || 
        (strcmp(choice_language, "fR") == 0) || 
        (strcmp(choice_language, "Fr") == 0)) {

        read_line(intro_fr, 1, buffer);
        printf("%s", buffer);
        scanf("%s", choice);

    }else if ((strcmp(choice_language, "gb") == 0) || 
             (strcmp(choice_language, "GB") == 0) || 
             (strcmp(choice_language, "gB") == 0) || 
             (strcmp(choice_language, "Gb") == 0)) {

        read_line(intro_gb, 1, buffer);
        printf("%s", buffer);
        scanf("%s", choice);
    }

    char player_name[33];
    strcpy(player_name, choice); 

    printf("\n");

    // Choice of player's role
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) || 
        (strcmp(choice_language, "fR") == 0) || 
        (strcmp(choice_language, "Fr") == 0)) {

        read_line(intro_fr, 3, buffer);
        printf("%s", buffer);
        read_line(intro_fr, 4, buffer);
        printf("%s", buffer);
        scanf("%s", choice);

    } else if ((strcmp(choice_language, "gb") == 0) || 
              (strcmp(choice_language, "GB") == 0) || 
              (strcmp(choice_language, "gB") == 0) || 
              (strcmp(choice_language, "Gb") == 0)) {
                
        read_line(intro_gb, 3, buffer);
        printf("%s", buffer);
        read_line(intro_gb, 4, buffer);
        printf("%s", buffer);
        scanf("%s", choice);
    }

    char player_role[33];
    strcpy(player_role, choice); 

    // Verification of the player's role
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) || 
        (strcmp(choice_language, "fR") == 0) || 
        (strcmp(choice_language, "Fr") == 0)) {
        if ((strcmp(player_role, "roi") != 0) && 
            (strcmp(player_role, "Roi") != 0) && 
            (strcmp(player_role, "ROI") != 0) && 
            (strcmp(player_role, "reine") != 0) && 
            (strcmp(player_role, "Reine") != 0) && 
            (strcmp(player_role, "REINE") != 0)) {

            read_line(intro_gb, 6, buffer);
            printf("%s", buffer);
            strcpy(player_role, "bouffon"); 
        }
        
    } else if ((strcmp(choice_language, "gb") == 0) || 
              (strcmp(choice_language, "GB") == 0) || 
              (strcmp(choice_language, "gB") == 0) || 
              (strcmp(choice_language, "Gb") == 0)) {
        if ((strcmp(player_role, "king") == 0) && 
            (strcmp(player_role, "King") == 0) && 
            (strcmp(player_role, "KING") == 0) && 
            (strcmp(player_role, "queen") == 0) && 
            (strcmp(player_role, "Queen") == 0) && 
            (strcmp(player_role, "QUEEN") == 0)) {

            read_line(intro_fr, 6, buffer);
            printf("%s", buffer);
            strcpy(player_role, "bouffon"); 
        }
    } 

    // Intro of the game
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) || 
        (strcmp(choice_language, "fR") == 0) || 
        (strcmp(choice_language, "Fr") == 0)) {

        printf("\n");
        read_line(intro_fr, 8, buffer);
        printf("%s", buffer);

    } else if ((strcmp(choice_language, "gb") == 0) || 
              (strcmp(choice_language, "GB") == 0) || 
              (strcmp(choice_language, "gB") == 0) || 
              (strcmp(choice_language, "Gb") == 0)) {

        printf("\n");
        read_line(intro_gb, 8, buffer);
        printf("%s\n\n", buffer);
    }

    // Start of Chapter 1
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) || 
        (strcmp(choice_language, "fR") == 0) || 
        (strcmp(choice_language, "Fr") == 0)) {

        read_line(chapter1_fr, 1, buffer);
        printf("\n\n%s", buffer);
        printf("\n");

    } else if ((strcmp(choice_language, "gb") == 0) || 
              (strcmp(choice_language, "GB") == 0) || 
              (strcmp(choice_language, "gB") == 0) || 
              (strcmp(choice_language, "Gb") == 0)) {

        read_line(chapter1_gb, 1, buffer);
        printf("%s", buffer);
        printf("\n");
    }

    verif = false;
    weapon = 0;

    // Chapter 1 in French
    while (verif == false)
    {
        if ((strcmp(choice_language, "fr") == 0) || 
            (strcmp(choice_language, "FR") == 0) || 
            (strcmp(choice_language, "fR") == 0) || 
            (strcmp(choice_language, "Fr") == 0)) {
                
            read_line(chapter1_fr, 3, buffer);
            printf("%s", buffer);
            read_line(chapter1_fr, 4, buffer);
            printf("%s", buffer);
            read_line(chapter1_fr, 5, buffer);
            printf("%s", buffer);
            read_line(chapter1_fr, 6, buffer);
            printf("%s", buffer);
            scanf("%s", choice_nb);

            if (strcmp(choice_nb, "1") != 0 && 
                strcmp(choice_nb, "2") != 0 && 
                strcmp(choice_nb, "3") != 0) {
                
                read_line(chapter1_fr, 17, buffer);
                printf("%s\n", buffer);

            } else {

                nb = atoi(choice_nb);
                switch (nb)
                {
                case 1:
                    read_line(chapter1_fr, 12, buffer);
                    printf("%s\n", buffer);
                    break;
        
                case 2: 
                    if (strcmp(player_role, "bouffon") == 0) {
                        int random_value = rand() % 2;
                        if (random_value == 0) {
                            read_line(chapter1_fr, 18, buffer);
                            printf("%s\n", buffer);
                        } else {
                            read_line(chapter1_fr, 43, buffer);
                            printf("%s\n", buffer);
                        }
                    } else if (weapon != 0) {
                        read_line(chapter1_fr, 19, buffer);
                        printf("%s\n", buffer);
                    } else {
                        read_line(chapter1_fr, 14, buffer);
                        printf("%s", buffer);
                        scanf("%s", choice_nb);

                        if (strcmp(choice_nb, "1") != 0 && 
                            strcmp(choice_nb, "2") != 0) {
                
                            read_line(chapter1_fr, 17, buffer);
                            printf("%s\n", buffer);

                        } else {

                            nb = atoi(choice_nb);
                            switch (nb)
                            {
                            case 1:
                                read_line(chapter1_fr, 15, buffer);
                                printf("%s\n", buffer);
                                weapon = 1;
                                break;
                            
                            case 2:
                                read_line(chapter1_fr, 16, buffer);
                                printf("%s\n", buffer);
                                weapon = 2;
                                break;
                            }
                        }
                    }
                    break;

                case 3:
                    read_line(chapter1_fr, 21, buffer);
                    printf("%s", buffer);
                    scanf("%s", choice_nb);

                    if (strcmp(choice_nb, "1") != 0 && 
                        strcmp(choice_nb, "2") != 0) {
                
                        read_line(chapter1_fr, 17, buffer);
                        printf("%s\n", buffer);

                    } else {

                        nb = atoi(choice_nb);
                        switch (nb) 
                        {
                        case 1:
                            read_line(chapter1_fr, 25, buffer);
                            printf("%s", buffer);
                            read_line(chapter1_fr, 26, buffer);
                            printf("%s", buffer);
                            read_line(chapter1_fr, 27, buffer);
                            printf("%s", buffer);
                            scanf("%s", choice_nb);

                            if (strcmp(choice_nb, "1") != 0 && 
                                strcmp(choice_nb, "2") != 0) {
                
                                read_line(chapter1_fr, 17, buffer);
                                printf("%s\n", buffer);

                            } else {

                                nb = atoi(choice_nb);
                                switch (nb)
                                {
                                case 1:
                                // Dead
                                    read_line(chapter1_fr, 33, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 67, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 68, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 69, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 70, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 71, buffer);
                                    printf("%s\n\n", buffer);
                                    weapon = 0;
                                    break;
                            
                                case 2:
                                    read_line(chapter1_fr, 35, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter1_fr, 38, buffer);
                                    printf("%s", buffer);
                                    verif = true;
                                    break;
                                }
                            }
                            break;
                        
                        case 2:
                            read_line(chapter1_fr, 23, buffer);
                            printf("%s\n", buffer);
                            break;
                        }
                    }
                    break;
                }
            }

        //Chapter 1 in English
        } else if ((strcmp(choice_language, "gb") == 0) || 
            (strcmp(choice_language, "GB") == 0) || 
            (strcmp(choice_language, "gB") == 0) || 
            (strcmp(choice_language, "Gb") == 0)) {

            read_line(chapter1_gb, 3, buffer);
            printf("%s", buffer);
            read_line(chapter1_gb, 4, buffer);
            printf("%s", buffer);
            read_line(chapter1_gb, 5, buffer);
            printf("%s", buffer);
            read_line(chapter1_gb, 6, buffer);
            printf("%s", buffer);
            scanf("%s", choice_nb);

            if (strcmp(choice_nb, "1") != 0 && 
                strcmp(choice_nb, "2") != 0 && 
                strcmp(choice_nb, "3") != 0) {
                
                read_line(chapter1_gb, 17, buffer);
                printf("%s\n", buffer);

            } else {

                nb = atoi(choice_nb);
                switch (nb)
                {
                case 1:
                    read_line(chapter1_gb, 12, buffer);
                    printf("%s\n", buffer);
                    break;
        
                case 2: 
                    if (strcmp(player_role, "Jester") == 0) {
                        int random_value = rand() % 2;
                        if (random_value == 0) {
                            read_line(chapter1_gb, 18, buffer);
                            printf("%s\n", buffer);
                        } else {
                            read_line(chapter1_gb, 43, buffer);
                            printf("%s\n", buffer);
                        }
                    } else if (weapon != 0) {
                        read_line(chapter1_gb, 19, buffer);
                        printf("%s\n", buffer);
                    } else {
                        read_line(chapter1_gb, 14, buffer);
                        printf("%s", buffer);
                        scanf("%s", choice_nb);

                        if (strcmp(choice_nb, "1") != 0 && 
                            strcmp(choice_nb, "2") != 0) {
                
                            read_line(chapter1_gb, 17, buffer);
                            printf("%s\n", buffer);

                        } else {

                            nb = atoi(choice_nb);
                            switch (nb)
                            {
                            case 1:
                                read_line(chapter1_gb, 15, buffer);
                                printf("%s\n", buffer);
                                weapon = 1;
                                break;
                            
                            case 2:
                                read_line(chapter1_gb, 16, buffer);
                                printf("%s\n", buffer);
                                weapon = 2;
                                break;
                            }
                        }
                    }
                    break;

                case 3:
                    read_line(chapter1_gb, 21, buffer);
                    printf("%s", buffer);
                    scanf("%s", choice_nb);

                    if (strcmp(choice_nb, "1") != 0 && 
                        strcmp(choice_nb, "2") != 0) {
                
                        read_line(chapter1_gb, 17, buffer);
                        printf("%s\n", buffer);

                    } else {

                        nb = atoi(choice_nb);
                        switch (nb)
                        {
                        case 1:
                            read_line(chapter1_gb, 25, buffer);
                            printf("%s", buffer);
                            read_line(chapter1_gb, 26, buffer);
                            printf("%s", buffer);
                            read_line(chapter1_gb, 27, buffer);
                            printf("%s", buffer);
                            scanf("%s", choice_nb);

                            if (strcmp(choice_nb, "1") != 0 && 
                                strcmp(choice_nb, "2") != 0) {
                
                                read_line(chapter1_gb, 17, buffer);
                                printf("%s\n", buffer);

                            } else {

                                nb = atoi(choice_nb);
                                switch (nb)
                                {
                                case 1:
                                    read_line(chapter1_gb, 33, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 67, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 68, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 69, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 70, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 71, buffer);
                                    printf("%s\n\n", buffer);
                                    break;
                            
                                case 2:
                                    read_line(chapter1_gb, 35, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter1_gb, 38, buffer);
                                    printf("%s", buffer);
                                    verif = true;
                                    break;
                                }
                            }
                            break;
                        
                        case 2:
                            read_line(chapter1_gb, 23, buffer);
                            printf("%s\n", buffer);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }

    verif = false;

    // Riddle 1
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) || 
        (strcmp(choice_language, "fR") == 0) || 
        (strcmp(choice_language, "Fr") == 0)) {

        read_line(enigmes_fr, 3, buffer);
        printf("%s\n", buffer);
        read_line(enigmes_fr, 5, buffer);
        printf("%s", buffer);
        read_line(enigmes_fr, 6, buffer);
        printf("%s\n", buffer);
        read_line(enigmes_fr, 8, buffer);
        printf("%s", buffer);

        while (verif == false) {
            scanf("%s", riddle);

            // Check user aswers
            if ((strcmp(riddle, "coffre") == 0) ||
                (strcmp(riddle, "Coffre") == 0) ||
                (strcmp(riddle, "COFFRE") == 0)) {
                // Good Aswer
                verif = true;
                read_line(enigmes_fr, 10, buffer);
                printf("%s", buffer);
            } else {
                // Wrong answer
                read_line(enigmes_fr, 12, buffer);
                printf("%s", buffer);
            }
        } 
     
    } else if ((strcmp(choice_language, "gb") == 0) || 
            (strcmp(choice_language, "GB") == 0) || 
            (strcmp(choice_language, "gB") == 0) || 
            (strcmp(choice_language, "Gb") == 0)) {

        read_line(enigmes_gb, 3, buffer);
        printf("%s\n", buffer);
        read_line(enigmes_gb, 5, buffer);
        printf("%s", buffer);
        read_line(enigmes_gb, 6, buffer);
        printf("%s\n", buffer);
        read_line(enigmes_gb, 8, buffer);
        printf("%s", buffer);

        while (verif == false) {
            scanf("%s", riddle);

            // Check user aswers
            if ((strcmp(riddle, "chest") == 0) ||
                (strcmp(riddle, "Chest") == 0) ||
                (strcmp(riddle, "CHEST") == 0)) {
                // Good Aswer
                verif = true;
                read_line(enigmes_gb, 10, buffer);
                printf("%s", buffer);
            } else {
                // Wrong answer
                read_line(enigmes_gb, 12, buffer);
                printf("%s", buffer);
            }
        } 
    }

    verif = false;
    guard_state = 0;
    health_potion = false;

    // Start of Chapter 2
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) ||
        (strcmp(choice_language, "fR") == 0) ||  
        (strcmp(choice_language, "Fr") == 0)) {

        read_line(chapter2_fr, 1, buffer);
        printf("\n%s", buffer);
        printf("\n");

    } else if ((strcmp(choice_language, "gb") == 0) || 
              (strcmp(choice_language, "GB") == 0) || 
              (strcmp(choice_language, "gB") == 0) || 
              (strcmp(choice_language, "Gb") == 0)) {

        read_line(chapter2_gb, 1, buffer);
        printf("\n%s", buffer);
        printf("\n");
    }

    // Chapter 2 in French
    while (verif == false)
    {
        if ((strcmp(choice_language, "fr") == 0) || 
            (strcmp(choice_language, "FR") == 0) || 
            (strcmp(choice_language, "Fr") == 0) ||
            (strcmp(choice_language, "fR") == 0)) {

            read_line(chapter2_fr, 3, buffer);
            printf("%s", buffer);
            read_line(chapter2_fr, 4, buffer);
            printf("%s", buffer);
            read_line(chapter2_fr, 5, buffer);
            printf("%s", buffer);
            read_line(chapter2_fr, 6, buffer);
            printf("%s", buffer);
            scanf("%s", choice_nb);

            if (strcmp(choice_nb, "1") != 0 && 
                strcmp(choice_nb, "2") != 0 && 
                strcmp(choice_nb, "3") != 0) {
                
                read_line(chapter1_fr, 17, buffer);
                printf("%s\n", buffer);

            } else {

                nb = atoi(choice_nb);
                switch (nb)
                {
                case 1:
                    read_line(chapter2_fr, 13, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_fr, 14, buffer);
                    printf("%s", buffer);

                    if (guard_state == 0) {
                        read_line(chapter2_fr, 15, buffer);
                        printf("%s", buffer);
                        read_line(chapter2_fr, 16, buffer);
                        printf("%s", buffer);
                        read_line(chapter2_fr, 17, buffer);
                        printf("%s", buffer);
                        scanf("%s", choice_nb);

                        if (strcmp(choice_nb, "1") != 0 && 
                            strcmp(choice_nb, "2") != 0) {
                
                            read_line(chapter1_fr, 17, buffer);
                            printf("%s\n", buffer);

                        } else {

                            nb = atoi(choice_nb);
                            switch (nb)
                            {
                            case 1:
                                if (weapon == 1) {
                                    read_line(chapter2_fr, 26, buffer);
                                    printf("%s\n", buffer);
                                    guard_state = 1;
                                } else {
                                    read_line(chapter2_fr, 24, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 67, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 68, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 69, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 70, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 71, buffer);
                                    printf("%s\n\n", buffer);
                                }                   
                                break;

                            case 2:
                                read_line(chapter2_fr, 28, buffer);
                                printf("%s\n", buffer);
                                guard_state = 2;
                                break;
                            }
                        }
                    } else if (guard_state == 1) {
                        read_line(chapter2_fr, 44, buffer);
                        printf("%s\n", buffer);
                    } else {
                        read_line(chapter2_fr, 46, buffer);
                        printf("%s\n", buffer);
                    }
                    break;
                
                case 2: 
                    read_line(chapter2_fr, 33, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_fr, 67, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 68, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 69, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 70, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 71, buffer);
                                    printf("%s\n\n", buffer);
                    break;

                case 3:
                    read_line(chapter2_fr, 35, buffer);
                    printf("%s", buffer);
                    read_line(chapter2_fr, 36, buffer);
                    printf("%s", buffer);
                    read_line(chapter2_fr, 37, buffer);
                    printf("%s", buffer);
                    scanf("%s", choice_nb);

                    if (strcmp(choice_nb, "1") != 0 && 
                        strcmp(choice_nb, "2") != 0) {
                
                        read_line(chapter1_fr, 17, buffer);
                        printf("%s\n", buffer);

                    } else {

                        nb = atoi(choice_nb);
                        switch (nb)
                        {
                        case 1:
                            read_line(chapter2_fr, 42, buffer);
                            printf("%s", buffer);
                            if (guard_state == 1)
                            {
                                read_line(chapter2_fr, 44, buffer);
                                printf("%s\n", buffer); 
                            }
                            else
                            {
                                read_line(chapter2_fr, 44, buffer);
                                printf("%s", buffer); 
                            }
                            break;

                        case 2:
                            read_line(chapter2_fr, 49, buffer);
                            printf("%s\n", buffer);
                            read_line(chapter2_fr, 51, buffer);
                            printf("%s", buffer);
                            read_line(chapter2_fr, 52, buffer);
                            printf("%s", buffer);
                            read_line(chapter2_fr, 53, buffer);
                            printf("%s", buffer);
                            scanf("%s", choice_nb);

                            if (strcmp(choice_nb, "1") != 0 && 
                                strcmp(choice_nb, "2") != 0) {
                
                                read_line(chapter1_fr, 17, buffer);
                                printf("%s\n", buffer);

                            } else {

                                nb = atoi(choice_nb);
                                switch (nb)
                                {
                                case 1:
                                    read_line(chapter2_fr, 58, buffer);
                                    printf("%s\n", buffer);
                                    int random_value = rand() % 5;
                                    if (random_value == 0)
                                    {
                                        health_potion = true;
                                        health_potion_unlocked = true;
                                        read_line(chapter2_fr, 65, buffer);
                                        printf("%s\n", buffer);
                                    }
                                    read_line(chapter2_fr, 62, buffer);
                                    printf("%s", buffer);
                                    verif = true;
                                    armor = true;
                                    break;

                                case 2:
                                    read_line(chapter2_fr, 60, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_fr, 62, buffer);
                                    printf("%s", buffer);
                                    verif = true;
                                    armor = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

        //Chapter 2 in English           
        } else if ((strcmp(choice_language, "gb") == 0) || 
            (strcmp(choice_language, "GB") == 0) || 
            (strcmp(choice_language, "gB") == 0) || 
            (strcmp(choice_language, "Gb") == 0)) {

            read_line(chapter2_gb, 3, buffer);
            printf("%s", buffer);
            read_line(chapter2_gb, 4, buffer);
            printf("%s", buffer);
            read_line(chapter2_gb, 5, buffer);
            printf("%s", buffer);
            read_line(chapter2_gb, 6, buffer);
            printf("%s", buffer);
            scanf("%s", choice_nb);

            if (strcmp(choice_nb, "1") != 0 && 
                strcmp(choice_nb, "2") != 0 && 
                strcmp(choice_nb, "3") != 0) {
                
                read_line(chapter1_gb, 17, buffer);
                printf("%s\n", buffer);

            } else {

                nb = atoi(choice_nb);
                switch (nb)
                {
                case 1:
                    read_line(chapter2_gb, 13, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 14, buffer);
                    printf("%s", buffer);

                    if (guard_state == 0) {
                        read_line(chapter2_gb, 15, buffer);
                        printf("%s", buffer);
                        read_line(chapter2_gb, 16, buffer);
                        printf("%s", buffer);
                        read_line(chapter2_gb, 17, buffer);
                        printf("%s", buffer);
                        scanf("%s", choice_nb);

                        if (strcmp(choice_nb, "1") != 0 && 
                            strcmp(choice_nb, "2") != 0) {
                
                            read_line(chapter1_gb, 17, buffer);
                            printf("%s\n", buffer);

                        } else {

                            nb = atoi(choice_nb);
                            switch (nb)
                            {
                            case 1:
                                if (weapon == 1)
                                {
                                    read_line(chapter2_gb, 26, buffer);
                                    printf("%s\n", buffer);
                                    guard_state = 1;
                                }
                                else
                                {
                                    read_line(chapter2_gb, 24, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 67, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 68, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 69, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 70, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 71, buffer);
                                    printf("%s\n\n", buffer);
                                }                   
                                break;

                            case 2:
                                read_line(chapter2_gb, 28, buffer);
                                printf("%s\n", buffer);
                                guard_state = 2;
                                break;
                            }
                        }
                    } else if (guard_state == 1) {
                        read_line(chapter2_gb, 44, buffer);
                        printf("%s\n", buffer);
                    } else {
                        read_line(chapter2_gb, 46, buffer);
                        printf("%s\n", buffer);
                    }
                    break;
                
                case 2: 
                    read_line(chapter2_gb, 33, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 67, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 68, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 69, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 70, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 71, buffer);
                    printf("%s\n\n", buffer);
                    break;

                case 3:
                    read_line(chapter2_gb, 35, buffer);
                    printf("%s", buffer);
                    read_line(chapter2_gb, 36, buffer);
                    printf("%s", buffer);
                    read_line(chapter2_gb, 37, buffer);
                    printf("%s", buffer);
                    scanf("%s", choice_nb);

                    if (strcmp(choice_nb, "1") != 0 && 
                        strcmp(choice_nb, "2") != 0) {
                
                        read_line(chapter1_gb, 17, buffer);
                        printf("%s\n", buffer);

                    } else {

                        nb = atoi(choice_nb);
                        switch (nb)
                        {
                        case 1:
                            read_line(chapter2_gb, 42, buffer);
                            printf("%s", buffer);
                            if (guard_state == 1)
                            {
                                read_line(chapter2_gb, 44, buffer);
                                printf("%s\n", buffer); 
                            }
                            else
                            {
                                read_line(chapter2_gb, 44, buffer);
                                printf("%s", buffer); 
                            }
                            break;

                        case 2:
                            read_line(chapter2_gb, 49, buffer);
                            printf("%s\n", buffer);
                            read_line(chapter2_gb, 51, buffer);
                            printf("%s", buffer);
                            read_line(chapter2_gb, 52, buffer);
                            printf("%s", buffer);
                            read_line(chapter2_gb, 53, buffer);
                            printf("%s", buffer);
                            scanf("%s", choice_nb);

                            if (strcmp(choice_nb, "1") != 0 && 
                                strcmp(choice_nb, "2") != 0) {
                
                                read_line(chapter1_gb, 17, buffer);
                                printf("%s\n", buffer);

                            } else {

                                nb = atoi(choice_nb);
                                switch (nb)
                                {
                                case 1:
                                    read_line(chapter2_gb, 58, buffer);
                                    printf("%s\n", buffer);
                                    int random_value = rand() % 5;
                                    if (random_value == 0)
                                    {
                                        health_potion = true;
                                        health_potion_unlocked = true;
                                        read_line(chapter2_gb, 65, buffer);
                                        printf("%s\n", buffer);
                                    }
                                    read_line(chapter2_gb, 62, buffer);
                                    printf("%s", buffer);
                                    verif = true;
                                    armor = true;
                                    break;

                                case 2:
                                    read_line(chapter2_gb, 60, buffer);
                                    printf("%s\n", buffer);
                                    read_line(chapter2_gb, 62, buffer);
                                    printf("%s", buffer);
                                    verif = true;
                                    armor = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    verif = false;

    // Riddle 2
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) || 
        (strcmp(choice_language, "fR") == 0) || 
        (strcmp(choice_language, "Fr") == 0)) {

        read_line(enigmes_fr, 17, buffer);
        printf("%s\n", buffer);
        read_line(enigmes_fr, 19, buffer);
        printf("%s\n", buffer);
        read_line(enigmes_fr, 21, buffer);
        printf("%s\n", buffer);

        while (verif == false) {
            scanf("%s", riddle);

            // Check user answers
            if (strcmp(riddle, "XIII") == 0 || strcmp(riddle, "xiii") == 0) {
                // Good Aswer
                verif = true;
                read_line(enigmes_fr, 10, buffer);
                printf("%s", buffer);
            } else {
                // Wrong answer
                read_line(enigmes_fr, 12, buffer);
                printf("%s", buffer);
            }
        } 

    } else if ((strcmp(choice_language, "gb") == 0) || 
                (strcmp(choice_language, "GB") == 0) || 
                (strcmp(choice_language, "gB") == 0) || 
                (strcmp(choice_language, "Gb") == 0)) {

        read_line(enigmes_gb, 17, buffer);
        printf("%s\n", buffer);
        read_line(enigmes_gb, 19, buffer);
        printf("%s\n", buffer);
        read_line(enigmes_gb, 21, buffer);
        printf("%s\n", buffer);
            
        while (verif == false) {
            scanf("%s", riddle);

            // Check user aswers
            if ((strcmp(riddle, "XIII") == 0) || (strcmp(riddle, "xiii") == 0)) {
                // Good Aswer
                verif = true;
                read_line(enigmes_gb, 10, buffer);
                printf("%s", buffer);
            } else {
                // Wrong answer
                read_line(enigmes_gb, 12, buffer);
                printf("%s", buffer);
            }
        }
    }

    // Start of Chapter 3
    if ((strcmp(choice_language, "fr") == 0) || 
        (strcmp(choice_language, "FR") == 0) ||
        (strcmp(choice_language, "fR") == 0) ||  
        (strcmp(choice_language, "Fr") == 0)) {

        read_line(chapter3_fr, 1, buffer);
        printf("\n%s", buffer);
        printf("\n");

    } else if ((strcmp(choice_language, "gb") == 0) || 
              (strcmp(choice_language, "GB") == 0) || 
              (strcmp(choice_language, "gB") == 0) || 
              (strcmp(choice_language, "Gb") == 0)) {

        read_line(chapter3_gb, 1, buffer);
        printf("\n%s", buffer);
        printf("\n");
    }

    verif = false;

    // Chapter 3 choices in French
    while (verif == false)
    {
        if ((strcmp(choice_language, "fr") == 0) || 
            (strcmp(choice_language, "FR") == 0) || 
            (strcmp(choice_language, "Fr") == 0) ||
            (strcmp(choice_language, "fR") == 0)) {

            read_line(chapter3_fr, 3, buffer);
            printf("%s", buffer);
            read_line(chapter3_fr, 4, buffer);
            printf("%s", buffer);
            read_line(chapter3_fr, 5, buffer);
            printf("%s", buffer);
            read_line(chapter3_fr, 6, buffer);
            printf("%s", buffer);
            read_line(chapter3_fr, 7, buffer);
            printf("%s", buffer);
            scanf("%s", choice_nb);

            if (strcmp(choice_nb, "1") != 0 && 
                strcmp(choice_nb, "2") != 0) {
                
                read_line(chapter1_fr, 17, buffer);
                printf("%s\n", buffer);

            } else {

                nb = atoi(choice_nb);
                switch (nb)
                {
                case 1:
                    read_line(chapter3_fr, 12, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_fr, 67, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_fr, 68, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_fr, 69, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_fr, 70, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_fr, 71, buffer);
                    printf("%s\n\n", buffer);
                    break;

                case 2:
                    read_line(chapter3_fr, 14, buffer);
                    printf("%s\n", buffer);
                    verif = true;
                    read_line(chapter3_fr, 16, buffer);
                    printf("%s\n", buffer);
                    if (weapon == 2) {
                        read_line(chapter3_fr, 18, buffer);
                        printf("%s\n", buffer);
                    }
                    break;
                }
            }

        //Chapter 3 choices in English           
        } else if ((strcmp(choice_language, "gb") == 0) || 
            (strcmp(choice_language, "GB") == 0) || 
            (strcmp(choice_language, "gB") == 0) || 
            (strcmp(choice_language, "Gb") == 0)) {

            read_line(chapter3_gb, 3, buffer);
            printf("%s", buffer);
            read_line(chapter3_gb, 4, buffer);
            printf("%s", buffer);
            read_line(chapter3_gb, 5, buffer);
            printf("%s", buffer);
            read_line(chapter3_gb, 6, buffer);
            printf("%s", buffer);
            scanf("%s", choice_nb);

            if (strcmp(choice_nb, "1") != 0 && 
                strcmp(choice_nb, "2") != 0) {
                
                read_line(chapter1_gb, 17, buffer);
                printf("%s\n", buffer);

            } else {

                nb = atoi(choice_nb);
                switch (nb)
                {
                case 1:
                    read_line(chapter3_gb, 12, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 67, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 68, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 69, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 70, buffer);
                    printf("%s\n", buffer);
                    read_line(chapter2_gb, 71, buffer);
                    printf("%s\n\n", buffer);
                    break;

                case 2:
                    read_line(chapter3_gb, 14, buffer);
                    printf("%s\n", buffer);
                    verif = true;
                    read_line(chapter3_gb, 16, buffer);
                    printf("%s\n", buffer);
                    if (weapon == 2) {
                        read_line(chapter3_gb, 18, buffer);
                        printf("%s\n", buffer);
                    }
                    break;
                }
            }
        }
    }

    verif = false;

    int player_health = 10;
    int boss_health = 10;
    bool boss_potion = true;
    bool angry_boss = false;

   // Chapter 3 boss fight in French
   while (verif == false)
   {
       if ((strcmp(choice_language, "fr") == 0) || 
           (strcmp(choice_language, "FR") == 0) || 
           (strcmp(choice_language, "Fr") == 0) ||
           (strcmp(choice_language, "fR") == 0)) {

           read_line(chapter3_fr, 20, buffer);
           printf("%s\n", buffer);

           player_health = 10;
           boss_health = 10;
           boss_potion = true;
           angry_boss = false;
           if (health_potion_unlocked == true) {
               health_potion = true;
           }

           while (verif == false && player_health > 0) 
           {
               read_line(chapter3_fr, 22, buffer);
               printf("%s", buffer);
               read_line(chapter3_fr, 23, buffer);
               printf("%s", buffer);
               read_line(chapter3_fr, 24, buffer);
               printf("%s", buffer);

               if (player_health == 10) {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 25, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 26, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 27, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 28, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 29, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 30, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 31, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 32, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 33, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 34, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 9) {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 35, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 36, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 37, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 38, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 39, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 40, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 41, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 42, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 43, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 44, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 8) {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 45, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 46, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 47, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 48, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 49, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 50, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 51, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 52, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 53, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 54, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 7) {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 55, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 56, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 57, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 58, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 59, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 60, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 61, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 62, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 63, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 64, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 6) {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 65, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 66, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 67, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 68, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 69, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 70, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 71, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 72, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 73, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 74, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 5) {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 75, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 76, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 77, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 78, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 79, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 80, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 81, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 82, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 83, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 84, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 4) {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 85, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 86, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 87, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 88, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 89, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 90, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 91, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 92, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 93, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 94, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 3) {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 95, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 96, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 97, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 98, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 99, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 100, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 101, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 102, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 103, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 104, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 2) {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 105, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 106, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 107, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 108, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 109, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 110, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 111, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 112, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 113, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 114, buffer);
                       printf("%s", buffer);
                   }  
               } else {
                   if (boss_health == 10) {
                       read_line(chapter3_fr, 115, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_fr, 116, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_fr, 117, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_fr, 118, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_fr, 119, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_fr, 120, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_fr, 121, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_fr, 122, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_fr, 123, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_fr, 124, buffer);
                       printf("%s", buffer);
                   }  
               }
               read_line(chapter3_fr, 125, buffer);
               printf("%s", buffer);
               read_line(chapter3_fr, 126, buffer);
               printf("%s", buffer);
               read_line(chapter3_fr, 127, buffer);
               printf("%s", buffer);
               read_line(chapter3_fr, 128, buffer);
               printf("%s", buffer);

               if (weapon == 0) {
                   read_line(chapter3_fr, 129, buffer);
                   printf("%s", buffer);
               } else if (weapon == 1) {
                   read_line(chapter3_fr, 130, buffer);
                   printf("%s", buffer);
               } else {
                   read_line(chapter3_fr, 131, buffer);
                   printf("%s", buffer);
               }
               
               if (health_potion == true) {
                   read_line(chapter3_fr, 132, buffer);
                   printf("%s", buffer);
               }

               read_line(chapter3_fr, 133, buffer);
               printf("%s\n", buffer);
               scanf("%s", choice_nb);

               if (strcmp(choice_nb, "1") != 0 && 
                   strcmp(choice_nb, "2") != 0) {
               
                   read_line(chapter3_fr, 159, buffer);
                   printf("%s\n", buffer);

               } else {

                   nb = atoi(choice_nb);
                   switch (nb)
                   {
                   case 1:
                       if (weapon == 0) {
                           int random_value = rand() % 100;
                           if (random_value == 0) {
                               read_line(chapter3_fr, 136, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 2;
                               if (boss_health <= 0) {
                                   read_line(chapter3_fr, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           } else {
                               read_line(chapter3_fr, 135, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 1;
                               if (boss_health <= 0) {
                                   read_line(chapter3_fr, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           } 
                       } else if (weapon == 1) {
                           int random_value = rand() % 100;
                           if (random_value == 0) {
                               read_line(chapter3_fr, 138, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 4;
                               if (boss_health <= 0) {
                                   read_line(chapter3_fr, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           } else {
                               read_line(chapter3_fr, 137, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 2;
                               if (boss_health <= 0) {
                                   read_line(chapter3_fr, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           }
                       } else {
                           int random_value = rand() % 100;
                           if (random_value == 0) {
                               read_line(chapter3_fr, 140, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 6;
                               if (boss_health <= 0) {
                                   read_line(chapter3_fr, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           } else {
                               read_line(chapter3_fr, 139, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 3;
                               if (boss_health <= 0) {
                                   read_line(chapter3_fr, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           }
                       }
                       break;

                   case 2:
                       if (health_potion == false) {
                           read_line(chapter3_fr, 159, buffer);
                           printf("%s\n", buffer);
                       } else {
                           read_line(chapter3_fr, 141, buffer);
                           printf("%s\n", buffer);
                           player_health += 3;
                           health_potion = false;
                       }
                       break;
                   }
               }

               if (verif == false) {

                   read_line(chapter3_fr, 161, buffer);
                   printf("%s\n", buffer);

                   if (angry_boss == false && boss_health <= 5) {
                       read_line(chapter3_fr, 154, buffer);
                       printf("%s\n", buffer);
                       angry_boss = true;
                   } else if (angry_boss == false) {
                       if (boss_potion == true) {
                           if (boss_health >= 8) {
                               int random_value = rand() % 100;
                               if (random_value <= 59) {
                                   int random_value = rand() % 100;
                                   if (random_value <= 4) {
                                       read_line(chapter3_fr, 146, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_fr, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_fr, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 2;
                                           if (player_health <= 0) {
                                               read_line(chapter3_fr, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   } else {
                                       read_line(chapter3_fr, 145, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_fr, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_fr, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 1;
                                           if (player_health <= 0) {
                                               read_line(chapter3_fr, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   }
                               } else if (random_value >= 60 && random_value <= 84) {
                                   int random_value = rand() % 100;
                                   if (random_value <= 4) {
                                       read_line(chapter3_fr, 150, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_fr, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_fr, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 4;
                                           if (player_health <= 0) {
                                               read_line(chapter3_fr, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   } else {
                                       read_line(chapter3_fr, 149, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_fr, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_fr, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 2;
                                           if (player_health <= 0) {
                                               read_line(chapter3_fr, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   }
                               } else if (random_value >= 85 && random_value <= 94) {
                                   read_line(chapter3_fr, 154, buffer);
                                   printf("%s\n", buffer);
                                   angry_boss = true;
                               } else {
                                   read_line(chapter3_fr, 153, buffer);
                                   printf("%s\n", buffer);
                                   boss_potion = false;
                                   boss_health = 10;
                               }
                           } else {
                               int random_value = rand() % 100;
                               if (random_value <= 39) {
                                   int random_value = rand() % 100;
                                   if (random_value <= 4) {
                                       read_line(chapter3_fr, 146, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_fr, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_fr, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 2;
                                           if (player_health <= 0) {
                                               read_line(chapter3_fr, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   } else {
                                       read_line(chapter3_fr, 145, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_fr, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_fr, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 1;
                                           if (player_health <= 0) {
                                               read_line(chapter3_fr, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   }
                               } else if (random_value >= 40 && random_value <= 59) {
                                   int random_value = rand() % 100;
                                   if (random_value <= 4) {
                                       read_line(chapter3_fr, 150, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_fr, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_fr, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 4;
                                           if (player_health <= 0) {
                                               read_line(chapter3_fr, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   } else {
                                       read_line(chapter3_fr, 149, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_fr, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_fr, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 2;
                                           if (player_health <= 0) {
                                               read_line(chapter3_fr, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   }
                               } else if (random_value >= 60 && random_value <= 69) {
                                   read_line(chapter3_fr, 154, buffer);
                                   printf("%s\n", buffer);
                                   angry_boss = true;
                               } else {
                                   read_line(chapter3_fr, 153, buffer);
                                   printf("%s\n", buffer);
                                   boss_potion = false;
                                   boss_health += 3;
                               }
                           }
                       } else {
                           int random_value = rand() % 100;
                           if (random_value <= 59) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_fr, 146, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 2;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_fr, 145, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 1;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else if (random_value >= 60 && random_value <= 89) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_fr, 150, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_fr, 149, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 2;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else {
                               read_line(chapter3_fr, 154, buffer);
                               printf("%s\n", buffer);
                               angry_boss = true;
                           }
                       }
                   } else {
                       if (boss_potion == true) {
                           int random_value = rand() % 100;
                           if (random_value <= 49) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_fr, 148, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_fr, 147, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 2;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else if (random_value >= 50 && random_value <= 69) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_fr, 152, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 8;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_fr, 151, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else {
                               read_line(chapter3_fr, 153, buffer);
                               printf("%s\n", buffer);
                               boss_potion = false;
                               boss_health += 3;
                           }
                       } else {
                           int random_value = rand() % 100;
                           if (random_value <= 69) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_fr, 148, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_fr, 147, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 2;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_fr, 152, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 8;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_fr, 151, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_fr, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_fr, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_fr, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           }
                       }
                   }
               }
           }

       //Chapter 3 boss fight in English           
       } else if ((strcmp(choice_language, "gb") == 0) || 
           (strcmp(choice_language, "GB") == 0) || 
           (strcmp(choice_language, "gB") == 0) || 
           (strcmp(choice_language, "Gb") == 0)) {

           read_line(chapter3_gb, 20, buffer);
           printf("%s\n", buffer);

           player_health = 10;
           boss_health = 10;
           boss_potion = true;
           angry_boss = false;
           if (health_potion_unlocked == true) {
               health_potion = true;
           }

           while (verif == false && player_health > 0) 
           {
               read_line(chapter3_gb, 22, buffer);
               printf("%s", buffer);
               read_line(chapter3_gb, 23, buffer);
               printf("%s", buffer);
               read_line(chapter3_gb, 24, buffer);
               printf("%s", buffer);

               if (player_health == 10) {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 25, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 26, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 27, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 28, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 29, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 30, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 31, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 32, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 33, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 34, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 9) {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 35, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 36, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 37, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 38, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 39, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 40, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 41, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 42, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 43, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 44, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 8) {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 45, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 46, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 47, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 48, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 49, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 50, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 51, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 52, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 53, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 54, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 7) {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 55, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 56, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 57, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 58, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 59, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 60, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 61, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 62, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 63, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 64, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 6) {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 65, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 66, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 67, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 68, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 69, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 70, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 71, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 72, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 73, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 74, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 5) {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 75, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 76, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 77, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 78, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 79, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 80, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 81, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 82, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 83, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 84, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 4) {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 85, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 86, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 87, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 88, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 89, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 90, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 91, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 92, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 93, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 94, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 3) {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 95, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 96, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 97, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 98, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 99, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 100, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 101, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 102, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 103, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 104, buffer);
                       printf("%s", buffer);
                   }  
               } else if (player_health == 2) {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 105, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 106, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 107, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 108, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 109, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 110, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 111, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 112, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 113, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 114, buffer);
                       printf("%s", buffer);
                   }  
               } else {
                   if (boss_health == 10) {
                       read_line(chapter3_gb, 115, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 9) {
                       read_line(chapter3_gb, 116, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 8) {
                       read_line(chapter3_gb, 117, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 7) {
                       read_line(chapter3_gb, 118, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 6) {
                       read_line(chapter3_gb, 119, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 5) {
                       read_line(chapter3_gb, 120, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 4) {
                       read_line(chapter3_gb, 121, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 3) {
                       read_line(chapter3_gb, 122, buffer);
                       printf("%s", buffer);
                   } else if (boss_health == 2) {
                       read_line(chapter3_gb, 123, buffer);
                       printf("%s", buffer);
                   } else {
                       read_line(chapter3_gb, 124, buffer);
                       printf("%s", buffer);
                   }  
               }
               read_line(chapter3_gb, 125, buffer);
               printf("%s", buffer);
               read_line(chapter3_gb, 126, buffer);
               printf("%s", buffer);
               read_line(chapter3_gb, 127, buffer);
               printf("%s", buffer);
               read_line(chapter3_gb, 128, buffer);
               printf("%s", buffer);

               if (weapon == 0) {
                   read_line(chapter3_gb, 129, buffer);
                   printf("%s", buffer);
               } else if (weapon == 1) {
                   read_line(chapter3_gb, 130, buffer);
                   printf("%s", buffer);
               } else {
                   read_line(chapter3_gb, 131, buffer);
                   printf("%s", buffer);
               }
               
               if (health_potion == true) {
                   read_line(chapter3_gb, 132, buffer);
                   printf("%s", buffer);
               }

               read_line(chapter3_gb, 133, buffer);
               printf("%s\n", buffer);
               scanf("%s", choice_nb);

               if (strcmp(choice_nb, "1") != 0 && 
                   strcmp(choice_nb, "2") != 0) {
               
                   read_line(chapter3_gb, 159, buffer);
                   printf("%s\n", buffer);

               } else {

                   nb = atoi(choice_nb);
                   switch (nb)
                   {
                   case 1:
                       if (weapon == 0) {
                           int random_value = rand() % 100;
                           if (random_value == 0) {
                               read_line(chapter3_gb, 136, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 2;
                               if (boss_health <= 0) {
                                   read_line(chapter3_gb, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           } else {
                               read_line(chapter3_gb, 135, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 1;
                               if (boss_health <= 0) {
                                   read_line(chapter3_gb, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           } 
                       } else if (weapon == 1) {
                           int random_value = rand() % 100;
                           if (random_value == 0) {
                               read_line(chapter3_gb, 138, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 4;
                               if (boss_health <= 0) {
                                   read_line(chapter3_gb, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           } else {
                               read_line(chapter3_gb, 137, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 2;
                               if (boss_health <= 0) {
                                   read_line(chapter3_gb, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           }
                       } else {
                           int random_value = rand() % 100;
                           if (random_value == 0) {
                               read_line(chapter3_gb, 140, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 6;
                               if (boss_health <= 0) {
                                   read_line(chapter3_gb, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           } else {
                               read_line(chapter3_gb, 139, buffer);
                               printf("%s\n", buffer);
                               boss_health -= 3;
                               if (boss_health <= 0) {
                                   read_line(chapter3_gb, 157, buffer);
                                   printf("%s", buffer);
                                   verif = true;
                               }
                           }
                       }
                       break;

                   case 2:
                       if (health_potion == false) {
                           read_line(chapter3_gb, 159, buffer);
                           printf("%s\n", buffer);
                       } else {
                           read_line(chapter3_gb, 141, buffer);
                           printf("%s\n", buffer);
                           player_health += 3;
                           health_potion = false;
                       }
                       break;
                   }
               }

               if (verif == false) {

                   read_line(chapter3_gb, 161, buffer);
                   printf("%s\n", buffer);

                   if (angry_boss == false && boss_health <= 5) {
                       read_line(chapter3_gb, 154, buffer);
                       printf("%s\n", buffer);
                       angry_boss = true;
                   } else if (angry_boss == false) {
                       if (boss_potion == true) {
                           if (boss_health >= 8) {
                               int random_value = rand() % 100;
                               if (random_value <= 59) {
                                   int random_value = rand() % 100;
                                   if (random_value <= 4) {
                                       read_line(chapter3_gb, 146, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_gb, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_gb, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 2;
                                           if (player_health <= 0) {
                                               read_line(chapter3_gb, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   } else {
                                       read_line(chapter3_gb, 145, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_gb, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_gb, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 1;
                                           if (player_health <= 0) {
                                               read_line(chapter3_gb, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   }
                               } else if (random_value >= 60 && random_value <= 84) {
                                   int random_value = rand() % 100;
                                   if (random_value <= 4) {
                                       read_line(chapter3_gb, 150, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_gb, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_gb, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 4;
                                           if (player_health <= 0) {
                                               read_line(chapter3_gb, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   } else {
                                       read_line(chapter3_gb, 149, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_gb, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_gb, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 2;
                                           if (player_health <= 0) {
                                               read_line(chapter3_gb, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   }
                               } else if (random_value >= 85 && random_value <= 94) {
                                   read_line(chapter3_gb, 154, buffer);
                                   printf("%s\n", buffer);
                                   angry_boss = true;
                               } else {
                                   read_line(chapter3_gb, 153, buffer);
                                   printf("%s\n", buffer);
                                   boss_potion = false;
                                   boss_health = 10;
                               }
                           } else {
                               int random_value = rand() % 100;
                               if (random_value <= 39) {
                                   int random_value = rand() % 100;
                                   if (random_value <= 4) {
                                       read_line(chapter3_gb, 146, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_gb, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_gb, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 2;
                                           if (player_health <= 0) {
                                               read_line(chapter3_gb, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   } else {
                                       read_line(chapter3_gb, 145, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_gb, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_gb, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 1;
                                           if (player_health <= 0) {
                                               read_line(chapter3_gb, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   }
                               } else if (random_value >= 40 && random_value <= 59) {
                                   int random_value = rand() % 100;
                                   if (random_value <= 4) {
                                       read_line(chapter3_gb, 150, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_gb, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_gb, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 4;
                                           if (player_health <= 0) {
                                               read_line(chapter3_gb, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   } else {
                                       read_line(chapter3_gb, 149, buffer);
                                       printf("%s\n", buffer);
                                       if (armor == true) {
                                           int random_value = rand() % 2;
                                           if (random_value == 0) {
                                               read_line(chapter3_gb, 143, buffer);
                                               printf("%s\n", buffer);
                                               armor = false;
                                           } else {
                                               read_line(chapter3_gb, 142, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       } else{
                                           player_health -= 2;
                                           if (player_health <= 0) {
                                               read_line(chapter3_gb, 156, buffer);
                                               printf("%s\n", buffer);
                                           }
                                       }
                                   }
                               } else if (random_value >= 60 && random_value <= 69) {
                                   read_line(chapter3_gb, 154, buffer);
                                   printf("%s\n", buffer);
                                   angry_boss = true;
                               } else {
                                   read_line(chapter3_gb, 153, buffer);
                                   printf("%s\n", buffer);
                                   boss_potion = false;
                                   boss_health += 3;
                               }
                           }
                       } else {
                           int random_value = rand() % 100;
                           if (random_value <= 59) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_gb, 146, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 2;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_gb, 145, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 1;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else if (random_value >= 60 && random_value <= 89) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_gb, 150, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_gb, 149, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 2;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else {
                               read_line(chapter3_gb, 154, buffer);
                               printf("%s\n", buffer);
                               angry_boss = true;
                           }
                       }
                   } else {
                       if (boss_potion == true) {
                           int random_value = rand() % 100;
                           if (random_value <= 49) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_gb, 148, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_gb, 147, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 2;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else if (random_value >= 50 && random_value <= 69) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_gb, 152, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 8;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_gb, 151, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else {
                               read_line(chapter3_gb, 153, buffer);
                               printf("%s\n", buffer);
                               boss_potion = false;
                               boss_health += 3;
                           }
                       } else {
                           int random_value = rand() % 100;
                           if (random_value <= 69) {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_gb, 148, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_gb, 147, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 2;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           } else {
                               int random_value = rand() % 100;
                               if (random_value <= 4) {
                                   read_line(chapter3_gb, 152, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 8;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               } else {
                                   read_line(chapter3_gb, 151, buffer);
                                   printf("%s\n", buffer);
                                   if (armor == true) {
                                       int random_value = rand() % 2;
                                       if (random_value == 0) {
                                           read_line(chapter3_gb, 143, buffer);
                                           printf("%s\n", buffer);
                                           armor = false;
                                       } else {
                                           read_line(chapter3_gb, 142, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   } else{
                                       player_health -= 4;
                                       if (player_health <= 0) {
                                           read_line(chapter3_gb, 156, buffer);
                                           printf("%s\n", buffer);
                                       }
                                   }
                               }
                           }
                       }
                   }
               }
           }
       }
   }
   return EXIT_SUCCESS;
}