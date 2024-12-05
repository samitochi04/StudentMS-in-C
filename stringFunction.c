#include <stdio.h>
#include <string.h>


int main(){
    char string1[] = "Bro";
    char string2[] = "code";

    // strlwr(string1);
    // printf("%s\n", string1);
    // printf("%s\n\n", string2);

    // strupr(string2);
    // printf("%s\n", string1);
    // printf("%s\n\n", string2);
    
    // strcat(string1, string2); // add string2 to string1
    // printf("%s\n\n", string1);

    // strncat(string1, string2, 1); // add n characters of string2 to string1
    // printf("%s\n\n", string1);

    // strcpy(string1, string2); // copy string2 to string1
    // printf("%s\n\n", string1);

    // strncpy(string1, string2, 1); // copy n characters of string2 to string1
    // printf("%s\n\n", string1);

    // strset(string1, "?"); // sets all characters of a string to a given character
    // strnset(string1, 'x', 1); // sets first n characters of a string to a given character
    // strrev(string1); // reverses a string

    int result = strlen(string1);
    printf("%d\n\n", result);

    result = strcmp(string1, string2); // string compare all characters
    printf("%d\n\n", result);

    result = strncmp(string1, string2, 1); // string compare n characters
    printf("%d\n\n", result);

    result = strcmpi(string1, string1); // string compare all (ignore case)
    printf("%d\n\n", result);

    result = strnicmp(string1, string1, 1); // string compare n characters (ignore case)
    printf("%d\n\n", result);
    
    

}