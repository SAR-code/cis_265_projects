/*
* SCRIPT: locale.c
* PURPOSE: Write a program that obtains the name of 
*          a locale from the command line and then 
*          displays the values stored in the lconv structure
* AUTHOR: D.M
* DATE: 07MAY25
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define USER_INPUT 100

// function prototypes
void display_locale_group(const char* label, const char* grouping);

int main()
{
    // Declare variables for user input
	char input[USER_INPUT];

    while (1) {
        // Prompt the user for a locale name
        printf("Enter a locale name (example: fi_FI) or 'q' to quit: ");
        if (!fgets(input, sizeof(input), stdin))
            break;

        // Removes the newline character from the input
        input[strcspn(input, "\n")] = '\0';

        // Checks to see if the user wants to quit
        if (strcmp(input, "q") == 0 || strcmp(input, "quit") == 0) {
			printf("Exiting the program.\n");
			break;
        }

        // Set the locale from the user input
        if (!setlocale(LC_ALL, input)) {
            printf("Invalid locale: %s\n", input);
            continue;
        }

        // Display the locale name
        struct lconv* lc = localeconv();


		// Display the locale information
        printf("\ndecimal point = \"%s\"\n", lc->decimal_point);
        printf("thousands sep = \"%s\"\n", lc->thousands_sep);
        display_locale_group("grouping", lc->grouping);
        printf("mon_decimal_point = \"%s\"\n", lc->mon_decimal_point);
        printf("mon_thousands_sep = \"%s\"\n", lc->mon_thousands_sep);
        display_locale_group("mon_grouping", lc->mon_grouping);
        printf("positive sign = \"%s\"\n", lc->positive_sign);
        printf("negative sign = \"%s\"\n", lc->negative_sign);
        printf("currency symbol = \"%s\"\n", lc->currency_symbol);
        printf("frac_digits = %d\n", lc->frac_digits);

        printf("p_cs_precedes = %d\n", lc->p_cs_precedes);
        printf("n_cs_precedes = %d\n", lc->n_cs_precedes);
        printf("p_sep_by_space = %d\n", lc->p_sep_by_space);
        printf("n_sep_by_space = %d\n", lc->n_sep_by_space);
        printf("p_sign_posn = %d\n", lc->p_sign_posn);
        printf("n_sign_posn = %d\n", lc->n_sign_posn);

        printf("int_curr_symbol = \"%s\"\n", lc->int_curr_symbol);
        printf("int_frac_digits = %d\n", lc->int_frac_digits);
        printf("int_p_cs_precedes = %d\n", lc->p_cs_precedes);
        printf("int_n_cs_precedes = %d\n", lc->n_cs_precedes);
        printf("int_p_sep_by_space = %d\n", lc->p_sep_by_space);
        printf("int_n_sep_by_space = %d\n", lc->n_sep_by_space);
        printf("int_p_sign_posn = %d\n", lc->p_sign_posn);
        printf("int_n_sign_posn = %d\n", lc->n_sign_posn);

        printf("\n");
    }
    return 0;
}

/*********************************************************************
*                                                                    *
* void display_locale_group(const char* label, const char* grouping);*
* Purpose : Displays the grouping information for a locale.          *
*                                                                    *
**********************************************************************/
void display_locale_group(const char* label, const char* grouping)
{
    // Display the label
    printf("%s", label);

    // Check if the grouping is NULL or empty
    if (!grouping || grouping[0] == '\0')
    {
        // No grouping info available
		printf("No grouping info available\n");
        return;
    }

    // Display the grouping information
    for (int i = 0; grouping[i] != '\0'; i++)
    {
        if (i > 0) printf(",");
        printf("%d", grouping[i] - '0');
    }
	printf("\n");
}
