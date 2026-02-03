#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
constexpr int max = {100};

int next(int start, char direction, int turn)
{
	if (direction == 'R')
		return ((turn % max) + start) % 100;

	if (direction == 'L')
	{
		if( (turn % max) > start)
				{
				return max - std::abs((start - (turn % max)));
				}
		else
		{
		return start - (turn % max);
		}
	}
	return start;

}
//function to track zeroes returns number of zeroes crossed or landed on after instruction is calculated
void zeroes(int start, int turn, char direction, int& zeroCount)
{
	zeroCount+= turn/max;
//	if(turn%max == 0)
//		return;
	switch(direction)
	{
		case('R'):
			if( (turn%max)+start >=max)
				zeroCount++;
			break;
		case('L'):
			if( turn%max >= start && start !=0)
				++zeroCount;
					
			break;
		default:
			std::cout << "invalid argument";
			break;


	}

}

int main()
{
int zeroCount = {0};
std::ifstream inf{"input.txt"};
std::string strInput{};

if(!inf)
{
	std::cerr << "failure to open file\n";
	return 1;
}

int position = {50};

while (std::getline(inf, strInput))
{
	if(strInput.empty()) continue;

	char direction = strInput[0];
	int value = std::stoi(strInput.substr(1));
	zeroes(position, value, direction, zeroCount);
	position = next(position, direction, value);

/**	if(position == 0)
	{
		zeroCount++;
	}**/
	
}

std::cout << "number of zeroes: " <<zeroCount;
return 0;
}

