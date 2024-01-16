#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printhelp()
{
	printf("Usage: caesar_cipher [text] [rotation]\n");
	printf("For example: ./caesar_cipher \"hello world\" 13, would rotate the string 'hello world' by 13\n");
}

int main(int argc, char** argv)
{
	int rotationAmount = 0;
	int textLength = 0;
	char* text = argv[1];

	/* Parse arguments */
	if (argc > 1)
	{
		if (strcmp(argv[1], "--help") == 0)
		{
			printhelp();
			return 0;
		}

		if (argc == 3)
		{
			/* Read the text */
			textLength = strlen(argv[1]) + 1;

			/* Read the rotation amount */
			rotationAmount = atoi(argv[2]);
		}
		else
		{
			printf("Missing or too many arguments, check --help\n");
			return 1;
		}
	}
	else
	{
		printf("Missing arguments\n");
		return 1;
	}

	/* Process the text */
	for (int i = 0; i < textLength - 1; i++)
	{
		/* Handle uppercase letters */
		if (text[i] > 64 && text[i] < 91)
		{
			/* Check if should wrap around */
			if (text[i] + rotationAmount > 90)
			{
				int wrap = (text[i] + rotationAmount) - 90;
				text[i] = 64 + wrap;
				continue;
			}
			else if (text[i] + rotationAmount < 65)
			{
				int wrap = 65 - (text[i] + rotationAmount);
				text[i] = 91 - wrap;
				continue;
			}

			text[i] += rotationAmount;
		}

		/* Handler lowercase letters */
		if (text[i] > 96 && text[i] < 123)
		{
			/* Check if should wrap around */
			if (text[i] + rotationAmount > 122)
			{
				int wrap = (text[i] + rotationAmount) - 122;
				text[i] = 96 + wrap;
				continue;
			}
			else if (text[i] + rotationAmount < 97)
			{
				int wrap = 97 - (text[i] + rotationAmount);
				text[i] = 123 - wrap;
				continue;
			}

			text[i] += rotationAmount;
		}
	}

	/* Print the result */
	printf("%s\n", text);
}
