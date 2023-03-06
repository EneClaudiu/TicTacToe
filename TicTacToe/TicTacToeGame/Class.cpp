#include "Class.h"



char Class::displayOption(Options o) {
	if (o == X)
		return 'X';
	if (0 == O)
		return 'O';
	return ' ';
}
void Class::makeChoice(int row, int column) {
	if (currentPlayer)
		gameMatrix[(row - 1) * (column - 1)] = X;
	else
		gameMatrix[(row - 1) * (column - 1)] = O;
}

std::ostream& operator<< (std::ostream& out, Class c)
{
	out << c.displayOption(c.gameMatrix[0]) << " | " << c.displayOption(c.gameMatrix[1]) << " | " << c.displayOption(c.gameMatrix[2]) << "\n";
	out << "--+---+--\n";
	out << c.displayOption(c.gameMatrix[3]) << " | " << c.displayOption(c.gameMatrix[4]) << " | " << c.displayOption(c.gameMatrix[5]) << "\n";
	out << "--+---+--\n";
	out << c.displayOption(c.gameMatrix[6]) << " | " << c.displayOption(c.gameMatrix[7]) << " | " << c.displayOption(c.gameMatrix[8]) << "\n";
	return out;
}
