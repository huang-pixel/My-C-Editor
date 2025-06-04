#include <stdlib.h>
#include <termios.h>
#include <unistd.h>


struct termios orig_termios;

void disableRawMode() {
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
	// get the current terminal settings and copy them into raw struct
	// tcgetattr: terminal control get attr
	// STDIN_FILENO: standard input, keyboard
	// &: address where to store
	tcgetattr(STDIN_FILENO, &orig_termios);
	atexit(disableRawMode);

        // stop showing what I type on screen
	// c_lflag: control local flags
	// ECHO: bitflag 
	// ~(ECHO): NOT ECHO filp the bits
	// &=: bitwise AND then store the result back
	struct termios raw = orig_termios;
	raw.c_lflag &= ~(ECHO);

        // apply modified settings
	// tcsetattr: terminal control set attr
	// TCSAFLUSH: apply changes and flush input buffer
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
	enableRawMode();
	
	char c;
	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
	return 0;
}
