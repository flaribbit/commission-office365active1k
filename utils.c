#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *fp=fopen("click.cmd","r");
    FILE *out=fopen("click.h","w");
    while(!feof(fp)){
        unsigned char c=fgetc(fp);
        fprintf(out,"\\x%02x",c);
    }
    fclose(fp);
    fclose(out);
}