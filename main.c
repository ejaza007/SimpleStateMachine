#include <stdio.h>

void helpful_code(); // delete this before submission

// Prototypes for the four functions that will implement the state machines.
int FMS1(char *str);
int FMS2(char *str);
int FMS3(char *str);
int FMS4(char *str);

// enum representing the different states, this will be used
// by your state machines to specify the current state.
enum STATE {
    S0, S1, S2, S3
};

// global variables representing the input alphabet
// this will be used by your state machines
char a = 'a';
char b = 'b';
char c = 'c';

int main() {

    char *input_str = NULL;

    /** modify the following for your input strings **/

    input_str = "aaa";

    if(FMS1(input_str)) printf("FMS1: %s is valid\n", input_str);
    else printf("FMS1: %s is invalid\n", input_str);

    if(FMS2(input_str)) printf("FMS2: %s is valid\n", input_str);
    else printf("FMS2: %s is invalid\n", input_str);

    if(FMS3(input_str)) { printf("FMS3: %s is valid\n", input_str); }
    else                { printf("FMS3: %s is invalid\n", input_str); }

    if(FMS4(input_str)) { printf("FMS4: %s is valid\n", input_str); }
    else                { printf("FMS4: %s is invalid\n", input_str); }

    return 0;
}

int FMS1(char *str) {

    enum STATE curr_statem = S0;

  int cnt = 0;

  while(str[cnt]){

if(curr_statem == S0) {

    if (str[cnt] == 'a') {
        curr_statem = S1;
    } else {
        curr_statem = S0;
    }
}

    else if(curr_statem == S1){

        if(str[cnt] == 'a'){
            curr_statem = S2;
        }
        else {
            curr_statem = S0;

        }
    }

    else if(curr_statem == S2){

    if(str[cnt] == 'a'){
        curr_statem = S2;
    }
    else {
        curr_statem = S1;

    }

    }

    cnt++;
  }
if (curr_statem == S2){
    return 1;
}
    return 0;
}


int FMS2(char *str) {

    enum STATE curr_statem = S0;

    int cnt = 0;

    while(str[cnt]){

        if(curr_statem == S0) {

            if (str[cnt] == 'a') {
                curr_statem = S0;
            } else {
                curr_statem = S3;
            }
        }

        if(curr_statem == S3) {

            if (str[cnt] == 'a') {
                curr_statem = S2;
            } else {
                curr_statem = S0;
            }
        }

        else if(curr_statem == S1){

            if(str[cnt] == 'a'){
                curr_statem = S0;
            }
            else {
                curr_statem = S1;

            }
        }

        else if(curr_statem == S2){

            if(str[cnt] == 'b'){
                curr_statem = S1;
            }
            else {
                curr_statem = S0;

            }

        }

        cnt++;
    }

    if(curr_statem == S1){
        return 1;
    }
    return 0;
}



int FMS3(char *str) {


    enum STATE curr_state = S0;

    int cnt = 0;

    while(str[cnt]){

        switch(curr_state){
            case S0:
                if(str[cnt] == 'a'){
                    curr_state = S0;
                }
                if(str[cnt] == 'b'){
                    curr_state = S1;
                }
                if(str[cnt] == 'c'){
                    curr_state = S2;
                }
                break;
            case S1:
                if(str[cnt] == 'a'){
                    curr_state = S1;
                }
                if(str[cnt] == 'b'){
                    curr_state = S2;
                }
                if(str[cnt] == 'c'){
                    curr_state = S0;
                }
                break;
            case S2:
                if(str[cnt] == 'a'){
                    curr_state = S2;
                }
                if(str[cnt] == 'b'){
                    curr_state = S0;
                }
                if(str[cnt] == 'c'){
                    curr_state = S1;
                }
                break;

        }
        cnt++;
    }

    if(curr_state == S2){
        return 1;
    }
    return 0;
}

int FMS4(char *str) {


    enum STATE curr_state = S0;

    int cnt = 0;

    while(str[cnt]){

        switch(curr_state){
            case S0:
                if(str[cnt] == 'a'){
                    curr_state = S1;
                }
                if(str[cnt] == 'b'){
                    curr_state = S3;
                }
                if(str[cnt] == 'c'){
                    curr_state = S0;
                }
                break;
            case S1:
                if(str[cnt] == 'a'){
                    curr_state = S3;
                }
                if(str[cnt] == 'b'){
                    curr_state = S2;
                }
                if(str[cnt] == 'c'){
                    curr_state = S1;
                }
                break;
            case S2:
                if(str[cnt] == 'a'){
                    curr_state = S0;
                }
                if(str[cnt] == 'b'){
                    curr_state = S3;
                }
                if(str[cnt] == 'c'){
                    curr_state = S2;
                }
                break;
            case S3:
                if(str[cnt] == 'a'){
                    curr_state = S2;
                }
                if(str[cnt] == 'b'){
                    curr_state = S0;
                }
                if(str[cnt] == 'c'){
                    curr_state = S3;
                }
                break;

        }
        cnt++;
    }

    if(curr_state == S3){
        return 1;
    }
    return 0;
}

/***
 * The following function is example code to get you started.
 *
 * Delete this code before you submit this assignment.
*/
void helpful_code() {
    char *str2 = "This is a string.";  // this is a literal string stored as read-only
    char str1[18];                     // an array to copy the literal into

    for(int cnt = 0; cnt < 18; cnt++) { // the mechanism for copying the string
        str1[cnt] = str2[cnt];
    }

    puts(str2);  // these are system calls that will print a string
    puts(str1);

    putchar(str2[10]); // prints character at element 5
    puts("\n"); // prints a newline

    str1[6] = '\0'; // modifying the copied string with a null terminator

    puts(str1); // print the new string to show it is truncated

    switch (str2[4]) {
        case ' ':
            puts("location 4 is a space");
            break;
        case 't':
            puts("location 4 is a space");
            break;
        default:
            puts("I do not know");
    }

    if(str1[0] == 'T')
        puts("That is a T.");

    if(*(str2 + 11) == 't')
        puts("That is definitely a t.");

}