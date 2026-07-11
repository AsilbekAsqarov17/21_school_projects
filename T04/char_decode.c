#include<stdio.h>
#include<string.h>

int main(){

int operation_mode;
char str[100];

printf("Enter Operation Mode(0-encoding or 1-decoding): ");
if(scanf("%d", &operation_mode) != 1){
printf("Wrong Input!\n");
return 1;
}

while(getchar() != '\n');

if(operation_mode == 0){

printf("Enter word with spaces in between:");
fgets(str, sizeof(str), stdin);
str[strcspn(str, "\n")] = '\0';

printf("Encoding HEX: ");
	for(int i = 0; str[i] != '\0'; i++){

	if(str[i] != ' ' && str[i] != '\n'){
		printf("%X ", str[i]);
	}

	}
printf("\n");
}

else if(operation_mode == 1){

printf("Enter numbers with spaces in between:");
fgets(str, sizeof(str), stdin);
str[strcspn(str, "\n")] = '\0';

printf("Decoding HEX: ");

	for(int i = 0; str[i] != '\0';){
	if(str[i] == ' '){
		i++;
		continue;
	}
	if(str[i+1] != '\0'){
		char pair[3];
		pair[0] = str[i];
		pair[1] = str[i+1];
		pair[2] = '\0';
		unsigned int hex_val;
		sscanf(pair, "%x", &hex_val);
		printf("%c ", (char)hex_val);
		i += 2;	
	}
	else{
		break;
	}
}
printf("\n");
}
else{
printf("Wrong Input\n");
}

return 0;
}
