/* Depends on:
 * grim
 * slurp
 * jq
 * wl-clipboard
 *
 * On Arch: sudo pacman -S grim slurp jq wl-clipboard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Combines the commands and executes them
void execute(char *cmd1, char *cmd2)
{
	char final[500];

	strcpy(final, cmd1);
        strcat(final, cmd2);

        system(final);
}


//Takes a screenshow of the whole window
void whole_window(char *cmd2)
{
	char cmd1[] = "grim ";
	execute(cmd1, cmd2);
}


//Allows a screenshot of a selected area to be taken
void select_area(char *cmd2)
{
	char cmd1[] = "grim -g \"$(slurp)\" ";
	execute(cmd1, cmd2);
}


//Allows taking of a screenshot of current focused window/application
void current_window(char *cmd2)
{
	printf("2 seconds to focus the window to picture\n");

	char cmd1[] = "sleep 2 && grim -g \"$(swaymsg -t get_tree | jq -r \'.. | select(.focused?) | .rect | \"\\(.x),\\(.y) \\(.width)x\\(.height)\"\')\" ";
	execute(cmd1, cmd2);
}



//Main logic, takes users input and performs the correct task.
void main(int argc, char *argv[])
{
	system("clear");

	int choice1, choice2;
	char cmd2[300];

	printf("1. Whole screen\n2. Select area\n3. Current window\n\n: ");
	scanf("%d", &choice1);

	if (choice1 < 1 || choice1 > 3)
	{
		printf("You must enter a number between 1 - 3\n");
		exit(0);
	}

	printf("1. Save to clipboard\n2. Save to file\n\n: ");
	scanf("%d", &choice2);

	system("clear");

	if (choice2 == 1)
	{
		char cmd2[] = "- | wl-copy";
	}

	else if (choice2 == 2)
	{
		printf("Enter the file name\n: ");
		scanf("%s", cmd2);
	}

	else
	{
		printf("You must 1 or 2\n");
		exit(0);
	}



	if (choice1 == 1)
	{
		whole_window(cmd2);
	}

	else if (choice1 == 2)
	{
		select_area(cmd2);
	}

	else if (choice1 == 3)
	{
		current_window(cmd2);
	}

	else
	{
		printf("Number out of range\n");
		exit(0);
	}

	system("clear");
}
