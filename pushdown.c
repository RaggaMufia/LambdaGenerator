#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pushDownAutomata(char word[], FILE *output){
	char stack[10] = {'_'};
	int i = 0, top = 1, flag = 0, size = strlen(word);

	// Initial symbol
	stack[top] = 'E';

	while(i < size && flag == 0){
		switch(stack[top]){
			case 'E':
			    switch(word[i]){
    				case'0':
    					stack[top] = '0';
    				break;
    				case'1':
    					stack[top] = '1';
    				break;
    				case'x':
    					stack[top] = 'x';
    				break;
    				case'y':
    					stack[top] = 'y';
    				break;
    				case'[':
    					stack[top] = ']';
    					stack[++top] = 'E';
    					stack[++top] = '<';
    					stack[++top] = 'X';
    					stack[++top] = '[';
    				break;
    				case'(':
    					stack[top] = 'E';
    					stack[++top] = ')';
    					stack[++top] = 'E';
    					stack[++top] = '(';
    				break;
    				case'l':
    					stack[top] = 'E';
    					stack[++top] = '.';
    					stack[++top] = 'X';
    					stack[++top] = 'l';
    				break;
    				case'|':
    					stack[top] = 'E';
    					stack[++top] = '|';
    				break;
    				default:
    					flag = 1;
				}
				break;
			case 'X':
			    switch(word[i]){
    			    case 'x':
    			    	stack[top] = 'x';
    				break;
    				case 'y':
    					stack[top] = 'y';
    				break;
    				default:
    					flag = 1;
    		    }
				break;
			default:
				if(word[i] == stack[top]){
					top--;
					i++;
				}else{
					flag = 1;
				}
		}
	}

	if(top == 0 && flag == 0){
		fprintf(output,"%s\n", word);
	}
}

int main(int argc, char** argv){

    FILE *input = fopen("result.txt","r");
    FILE *output = fopen("output.txt","w");

    if(input != NULL || output != NULL){
        char word[10] = {""};
        while(fscanf(input,"%[^\n]\n", word) != EOF){
        	pushDownAutomata(word,output);
        }

        fclose(input);
        fclose(output);

    }else{
        printf("Error when opening files.\n");
    }
}
