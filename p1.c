#include <stdio.h>
#include <string.h>

void interpret(char program[]) {

    int index = 0;
    int state = 0;
    int digCount = 0;
    char var;
    char dig;
    char full[32];
    char digit[30];
    char table[26][32];
    for (int row = 0; row < 26; row++) {
	for (int col = 0; col < 32; col++) {
	    table[row][col] = 0;
	}
    }
    while (program[index] != 0) {
	char c = program[index];
	switch(state) {
	    case 0 :
		if (c >= 97 && c <= 122) {
		    var = c;
		    state++;
		}
		else {
		
		}
		index++;
		break;

	    case 1 :
		if (c == 61) {
		    state++;
		}
		else {
		
		}
		index++;
		break;

	    case 2 : 
		if (c >= 48 && c <= 57) {
		    dig = c;
		    digit[digCount] = dig;
		    digCount++;
		    state++;
		}
		else {
		
		}
		index++;
		break;

	    case 3 :
		if (c == 59) {
		    int notZero = 0;
		    int pos = 0;
		    while (digit[pos] != 0) {
			if (digit[pos] != 48) {
			    notZero++;
			}
			pos++;
		    }
		    if (notZero > 0) {
		        full[0] = var;
		        full[1] = ':';
		        for (int i = 2; i < digCount + 2; i++) {
			    full[i] = digit[i - 2];
		        }
		        int a = 0;
		        if (table[var - 97][0] != 0) {
			    for (int i = 0; i < 32; i++) {
			        table[var - 97][i] = 0;
			    }
		        }
		        while (full[a] != 0) {
			    table[var - 97][a] = full[a];
			    a++;
		        }
		        state = 0;
		        for (int i = 0; i < a; i++) {
			    full[i] = 0;
		        }
		        for (int i = 0; i < digCount + 1; i++) {
			    digit[i] = 0;
		        }
		        a = 0;
		        digCount = 0;
		    }
		    state = 0;
		    digCount = 0;
		}
		else if (c >= 48 && c <= 57) {
		    digit[digCount] = c;
		    digCount++;
		}
		else {
		
		}
		index++;
		break;
	}
    }
    for (int row = 0; row < 26; row++) {
	for (int col = 0; col < 32; col++) {
	    if (table[row][col] != 0) {
		printf("%c", table[row][col]);
	    }
	    else {
		if (col != 0) {
		    printf("\n");
		}
		col = 32;
	    }
	}
    }
}

int main(int argc, char* argv[]) {

    interpret(argv[1]);

    return 0;
}
