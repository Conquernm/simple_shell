#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints the message "ALX is too hard"
 *              to the standard output.
 * Return: 0 (Success)
 */

int main(void)
{
char message[] = "ALX is too hard\n";
write(1, message, sizeof(message) - 1);
return (0);
}
