#pragma once
class Start
{
private:
	enum startButton { newGame = 1, lastGame, Rank, exitGame };

public:
	Start();
	~Start();

	void print() const;
	void printGameName() const;
	void printStartButton() const;
	void printInStartButton(int buttonNo) const;
};