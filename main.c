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



    /** modify the following for your input strings **/

char *str1[8];
char *str2[8];
char *str3[8];
char *str4[8];

str1[0] = "aaa";
str1[1] = "bbaa";
str1[2] = "aaba";
str1[3] = "aabaa";
str1[4] = "bbb";
str1[5] = "bbab";
str1[6] = "aabbab";
str1[7] = "bbabba";

str2[0] = "bab";
str2[1] = "babb";
str2[2] = "abab";
str2[3] = "baabab";
str2[4] = "aaa";
str2[5] = "bb";
str2[6] = "baa";
str2[7] = "bababa";

str3[0] = "bb";
str3[1] = "bba";
str3[2] = "ca";
str3[3] = "baba";
str3[4] = "aaa";
str3[5] = "cbb";
str3[6] = "bcbcb";
str3[7] = "abc";

str4[0] = "caca";
str4[1] = "bc";
str4[2] = "baba";
str4[3] = "bbb";
str4[4] = "acb";
str4[5] = "abb";
str4[6] = "cbb";
str4[7] = "abc";







for(int i =0; i<8; i++) {
    if (FMS1(str1[i])) printf("FMS1: %s is valid\n", str1[i]);
    else printf("FMS1: %s is invalid\n", str1[i]);
}


for(int i = 0; i<8; i++) {
    if(FMS2(str2[i])) printf("FMS2: %s is valid\n", str2[i]);
    else printf("FMS2: %s is invalid\n", str2[i]);
}

for(int i = 0; i<8; i++) {
    if (FMS3(str3[i])) { printf("FMS3: %s is valid\n", str3[i]); }
    else { printf("FMS3: %s is invalid\n", str3[i]); }
}

for(int i = 0; i<8; i++) {
    if(FMS4(str4[i])) { printf("FMS4: %s is valid\n", str4[i]); }
    else                { printf("FMS4: %s is invalid\n", str4[i]); }
}

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

       else  if(curr_statem == S3) {

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

            if(str[cnt] == 'a'){
                curr_statem = S0;
            }
            else {
                curr_statem = S1;

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
                    curr_state = S1;
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

