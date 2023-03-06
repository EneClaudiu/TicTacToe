#pragma once
#include <array>
#include <iostream>

class ITicTacToe { //in h diferit
	//virtual function = 0;
	//virtual destructor = default;
};
class Class : public ITicTacToe
{
public:
	enum Options
	{
		X,
		O,
		None
	};
	
	bool currentPlayer;
	std::array<Options, 9> gameMatrix;

	Class() {
		gameMatrix = {None,None,None,None,None,None,None,None,None};
		currentPlayer = 0;
	}


	char displayOption(Options o); //override;
	void makeChoice(int,int);
	friend std::ostream& operator<< (std::ostream&, Class);

};
