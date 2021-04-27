# include <stdio.h>

#define MAXLINE 1000

char letterAddition(char c, char key);
void vegenereCipher(char s[], char key[]);

int main(){
    printf("%d\n", 'O');
    printf("The result is: %c\n", letterAddition('e', 'k'));
    vegenereCipher("sendmoremenandmunition", "key");
    
}

char letterAddition(char c, char key){
    if(c + key - 'a' >= 'a' && c + key - 'a' <= 'z')
        return c + key - 97;
    else if (c+key-'a'> 'z')
        return c + key - 123;
     
}

void vegenereCipher(char s[], char key[]){
    for (int i=0; s[i]!='\0'; i++){
        printf("%c", letterAddition(s[i], key[(i%3)]));
    }
    printf("\n");
}
