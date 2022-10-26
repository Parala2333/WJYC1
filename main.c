#include <stdio.h>
#include "key.h"
#include <string.h>

#define N 1000


char *punc_pos(char *words) {
    char *punc_pos = words;
    while (*(punc_pos + 1) != '\0') {
        punc_pos++;
    }
    return punc_pos;
}


int main() {

    /******** Here implements the opening of text file ********/

    char fileName[100] = {0};
    printf("Please input the name of text file :\n");
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open file failed!\n");
        return 0;
    }

    /*********** Here implements the separatation of the paragraph ***********/

    char fileContent[N] = {0};
    fgets(fileContent, N, fp);
    char *wordsStorage[N] = {0};

    wordsStorage[0] = strtok(fileContent, " ");
    for (int i = 1; wordsStorage[i - 1] != NULL; i++) {
        wordsStorage[i] = strtok(NULL, " ");
    }

    fclose(fp);

    /************ Here implements the determination of punc and keywords **********/

    int column_num = 0;
    int flag = 0;

    for (int i = 0; wordsStorage[i] != NULL; ++i) {
        int deter_punc = 0;
        int deter_keywords = 0;

        for (int j = 0; j < 25; ++j) {          //Deter of keywords
            if (strcmp(key_word[j], wordsStorage[i]) == 0) {
                deter_keywords = 1;
                //flag = 1;
            }
        }

        for (int j = 0; j < 4; ++j) {             //Deter of punc
            if (*(punc_pos(wordsStorage[i])) == key_mark[j]) {
                deter_punc = 1;
                //flag = 1;
            }
        }

        if (deter_punc == 1) {            // Deter if punc and keyword co-exist
            int length = 0;
            char temp[20] = {0};
            strcpy(temp, wordsStorage[i]);
            length = strlen(wordsStorage[i]);
            temp[length - 1] = '\0';

            for (int j = 0; j < 25; ++j) {
                if (strcmp(key_word[j], temp) == 0) {
                    deter_keywords = 1;
                }
            }
        }


        if (deter_punc == 1 && deter_keywords == 1 && flag != 1) {      //output
            printf("\n%s\n", wordsStorage[i]);
            flag = 1;
            column_num += 2;
            goto here;
        }
        if (deter_keywords == 1 || deter_punc == 1) {
            printf("%s\n", wordsStorage[i]);
            column_num++;
        } else {
            printf("%s ", wordsStorage[i]);
            flag = 0;
        }
        here:;
    }

    printf("\nThe total number of lines is %d. \n", column_num);

    return 0;
}
