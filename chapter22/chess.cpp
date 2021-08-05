/*********************************************************
*
* Answer to exercise 2 in chapter 22 
*
* Exercise from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

enum squareColor { black, white };
enum direction { diagonal, jump, rankfile };

class DiagonalMove
{
public:
	DiagonalMove() { } 
	DiagonalMove(int newMax) { setDiagonalMaxMoves(newMax); }
	~DiagonalMove() { } 

	// how many moves are possible?
	int getDiagonalMaxMoves() { return maxMoves; }
	void setDiagonalMaxMoves(int newMax); 

	// along what color diagonal squares?
	squareColor getSquareColor() { return color; }
	void setSquareColor(squareColor newColor) { color = newColor; }
	
private:
	int maxMoves;
	squareColor color;
};

void DiagonalMove::setDiagonalMaxMoves(int newMax)
{
	if (newMax >= 0 && newMax <= 13)
	{
		maxMoves = newMax;
	}
	else
	{
		cout << "Cannot set more than 13 or less than 0 moves\n";
	} 
}

class JumpMove
{
public:
	JumpMove() { }  
	JumpMove(int newMax) { setJumpMaxMoves(newMax); }
	~JumpMove() { } 
	
	// how many moves are possible?
	int getJumpMaxMoves() { return maxMoves; }
	void setJumpMaxMoves(int newMax);

private:
	int maxMoves;
};

void JumpMove::setJumpMaxMoves(int newMax)
{
	if (newMax >= 0 && newMax <= 8)
	{
		maxMoves = newMax;
	}
	else
	{
		cout << "Cannot have more than 8 or less than 0 moves\n";
	}
}

class RankFileMove
{
public:
	RankFileMove() { } 
	RankFileMove(int newMax) { setRankFileMaxMoves(newMax); }
	~RankFileMove() { } 

	// how many moves are possible?
	int getRankFileMaxMoves() { return maxMoves; }
	void setRankFileMaxMoves(int newMax);

private:
	int maxMoves;
};

void RankFileMove::setRankFileMaxMoves(int newMax)
{
	if (newMax >= 0 && newMax <= 14)
	{
		maxMoves = newMax;
	}
	else
	{
		cout << "More than 14 or less than 0 moves\n";
	}
};

class Pawn : public RankFileMove, public DiagonalMove
{
public:
	Pawn() { } 
	Pawn(int maxRankFileMoves, int maxDiagonalMoves):
		RankFileMove(maxRankFileMoves), DiagonalMove(maxDiagonalMoves)
		{ }
	~Pawn() { } 

	void move(int numberSquares, direction whichMove);
}; 

void Pawn::move(int numberSquares, direction whichMove)
{
	switch(whichMove)
	{
	case 0: // diagonal move
		if (numberSquares <= getDiagonalMaxMoves())
		{
			cout << "Moving Pawn " << numberSquares 
				<< " squares\n"; 
		}
		else
		{
			cout << "Cannot move Pawn " << numberSquares 
				<< " because max is "
				<< getDiagonalMaxMoves() << "\n";
		}
		break;
	case 2: // rankfile move
		if (numberSquares <= getRankFileMaxMoves())
		{
			cout << "Moving Pawn " << numberSquares
				<< " squares\n"; 
			if (numberSquares % 2 != 0) // changed color 
			{
				if (getSquareColor() == black)
					setSquareColor(white);
				else if (getSquareColor() == white)
					setSquareColor(black);
			}   
		}
		else
		{
			cout << "Cannot move Pawn " << numberSquares 
				<< " because max is "
				<< getRankFileMaxMoves() << "\n";
		}
		break;
	default:
		cout << "Not a valid Pawn move direction\n";
		break;
	}
}

class Rook : public RankFileMove
{
public:
	Rook() { } 
	Rook(int maxRankFileMoves): RankFileMove(maxRankFileMoves) { }
	~Rook() { } 

	void move(int numberSquares);
};

void Rook::move(int numberSquares)
{
	if (numberSquares <= getRankFileMaxMoves())
	{
		cout << "Moving Rook " << numberSquares << "\n";
	}
	else
	{
		cout << "Cannot move Rook " << numberSquares 
			<< " because max is "
			<< getRankFileMaxMoves() << "\n";
	}
}

class Bishop : public DiagonalMove 
{
public:
	Bishop() { } 
	Bishop(int maxDiagonalMoves): DiagonalMove(maxDiagonalMoves) { }
	~Bishop() { } 

	void move(int numberSquares);
};

void Bishop::move(int numberSquares)
{
	if (numberSquares <= getDiagonalMaxMoves())
	{
		cout << "Moving Bishop " << numberSquares
			<< " squares\n"; 
	}
	else
	{
		cout << "Cannot move Bishop " << numberSquares
			<< " because max is "
			<< getDiagonalMaxMoves() << "\n";
	}
}

class Knight : public JumpMove 
{
public:
	Knight() { } 
	Knight(int maxJumpMoves): JumpMove(maxJumpMoves) { }
	~Knight() { } 

	void move();
};

void Knight::move()
{
	if (getJumpMaxMoves())
	{
		cout << "Moving Knight\n";
	}
	else
	{
		cout << "Cannot move Knight" 
			<< " because max is "
			<< getJumpMaxMoves() << "\n";
	}
}

class Queen : public DiagonalMove, public RankFileMove 
{
public:
	Queen() { } 
	Queen(int maxRankFileMoves, int maxDiagonalMoves):
		RankFileMove(maxRankFileMoves),
		DiagonalMove(maxDiagonalMoves)
		{ }
	~Queen() { } 

	void move(int numberSquares, direction whichMove);
};

void Queen::move(int numberSquares, direction whichMove)
{
	switch(whichMove)
	{
	case 0: // diagonal move
		if (numberSquares <= getDiagonalMaxMoves())
		{
			cout << "Moving Queen " << numberSquares 
				<< " squares\n"; 
		}
		else
		{
			cout << "Cannot move Queen " << numberSquares 
				<< " because max is "
				<< getDiagonalMaxMoves() << "\n";
		}
		break;
	case 2: // rankfile move
		if (numberSquares <= getRankFileMaxMoves())
		{
			cout << "Moving Queen " << numberSquares
				<< " squares\n"; 
			if (numberSquares % 2 != 0) // changed color 
			{
				if (getSquareColor() == black)
					setSquareColor(white);
				else if (getSquareColor() == white)
					setSquareColor(black);
			}   
		}
		else
		{
			cout << "Cannot move Queen " << numberSquares 
				<< " because max is "
				<< getRankFileMaxMoves() << "\n";
		}
		break;
	default:
		cout << "Not a valid Queen move direction\n";
		break;
	}
}

class King : public DiagonalMove, public RankFileMove 
{
public:
	King() { } 
	King(int maxRankFileMoves, int maxDiagonalMoves):
		RankFileMove(maxRankFileMoves),
		DiagonalMove(maxDiagonalMoves)
		{ }
	~King() { } 

	void move(direction whichMove);
};

void King::move(direction whichMove)
{
	switch(whichMove)
	{
	case 0: // diagonal move
		if (getDiagonalMaxMoves())
		{
			cout << "Moving King\n";
		}
		else
		{
			cout << "Cannot move King " 
				<< " because max is "
				<< getDiagonalMaxMoves() << "\n";
		}
		break;
	case 2: // rankfile move
		if (getRankFileMaxMoves())
		{
			cout << "Moving King\n";
			// square color changed
			if (getSquareColor() == black)
				setSquareColor(white);
			else if (getSquareColor() == white)
				setSquareColor(black);
		}
		else
		{
			cout << "Cannot move King " 
				<< " because max is "
				<< getRankFileMaxMoves() << "\n";
		}
		break;
	default:
		cout << "Not a valid King move direction\n";
		break;
	}
}

int main()
{
	Pawn allPawns[8];

	// set max moves and alternate square colors 
	for (short i = 0; i < 8; i++)
	{
		allPawns[i] = Pawn(2, 0); // 2 rankfile max and 0 diagonal max
		if (i % 2 == 0)
			allPawns[i].setSquareColor(black);
		else
			allPawns[i].setSquareColor(white);

	}

	Rook rightRook(7), leftRook(7);

	Knight rightKnight(2), leftKnight(2);

	Bishop darkBishop(7), lightBishop(7);
	darkBishop.setSquareColor(black);
	lightBishop.setSquareColor(white);

	Queen theQueen(7, 7);
	theQueen.setSquareColor(white);

	King theKing(1, 1);
	theKing.setSquareColor(black);

	// make some moves	
	for (short i = 0; i < 8; i++)
	{
		allPawns[i].move(1, rankfile);
		allPawns[i].setRankFileMaxMoves(1);
	}

	rightRook.move(6);
	rightRook.setRankFileMaxMoves(9);

	leftKnight.move();
	leftKnight.setJumpMaxMoves(0);

	darkBishop.move(5);
	darkBishop.setDiagonalMaxMoves(13);
	
	theQueen.move(7, diagonal);
	theQueen.setDiagonalMaxMoves(3);

	theKing.move(rankfile);
	theKing.setRankFileMaxMoves(0);

	// try some illegal stuff
	allPawns[0].move(1, diagonal);
	allPawns[0].move(2, rankfile);

	leftKnight.move();

	leftRook.move(8);
	
	lightBishop.move(9);

	theQueen.move(4, diagonal);
	
	theKing.move(rankfile);
} 
