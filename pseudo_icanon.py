# Aim: Turning off ECHO & canonical mode for editor
# Also, simulating the C code snippet logic and structure

class TerminalSettings():
    def __init__(self):
        self.c_lflag = 0


orig_termios = TerminalSettings()
orig_termios.c_lflag = 0b11111111


def disable_raw():
    print("Original setting:\n")
    print(orig_termios.c_lflag)


def enable_raw():
    # Copy
    raw = TerminalSettings()
    raw.c_lflag = orig_termios.c_lflag

    ECHO = 1234
    ICANON = 5678

    raw.c_lflag &= ~(ECHO | ICANON)

    print(raw.c_lflag)
    print("Terminal setting is changed now!")


enable_raw()
disable_raw()
