# Simulating the use of tcsetattr and tcgetattr in C

class TerminalSettings:
    def __init__(self):
        self._c_lflag = 0b11111111

    @property
    def c_lflag(self):
        # Simulate tcgetattr
        return self._c_lflage

    @c_lflag.setter
    def c_lflag(self):
        # Simulate tcsetattr
        self._c_lflag = new_value
