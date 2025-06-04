#include <termios.h>
#include <unistd.h>

void enableRawMode() {
	struct termios raw; // raw: instance of struct termios
        
	// get the current terminal settings and copy them into raw struct
	tcgetattr(STDIN_FILENO, &raw); // tcgetattr: terminal control get attr
				       // STDIN_FILENO: standard input, keyboard
				       // &raw: address where to store

        // stop showing what I type on screen
	raw.c_lflag &= ~(ECHO); // c_lflag: control local flags
				// ECHO: bitflag 
				// ~(ECHO): NOT ECHO filp the bits
				// &=: bitwise AND then store the result back

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
