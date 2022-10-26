/***********************************************************************
The header file name:Key.h
Author's name:Jingyi Wang
The contents of this header file:Create a header file containing the C
keyword and the given 4 punctuation marks to include in the C program.
Pay attention:The header file must be placed in the same folder as the
source file .
************************************************************************/
#ifndef KEY_H_
#define KEY_H_

char *key_word[25] =/*Declare a character array to store C keywords*/
        {/*Custom C language keywords, meet the number of C keywords in the text file is greater than 1, less than 32*/
                "int",
                "float",
                "double",
                "char",
                "void",
                "if",
                "else",
                "for",
                "do",
                "while",
                "switch",
                "case",
                "break",
                "continue",
                "return",
                "goto",
                "struct",
                "union",
                "default",
                "typedef",
                "sizeof",
                "auto",
                "unsigned",
                "static",
                "volatile",
        };

char key_mark[4] = /*Declare a char array to store punctuation*/
        {/*Customize punctuation so that punctuation marks in text files include commas, periods, question marks, and exclamation points*/
                ',',
                '.',
                '?',
                '!'
        };



#endif //KEY_H_
