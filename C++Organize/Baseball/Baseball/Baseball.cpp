#include <iostream>

using namespace std;

int main()
{
	srand(time(0));//현재 시간값에 맞춰서 시드를 변환하여 계속 랜덤한 값이 나오도록 함.
	cout << "규칙: 중복되지 않은 숫자를 입력해서 같은 자리 같은숫자= 스트라이크, 같은 숫자 다른자리 = 볼, 아니면 아웃" << endl;
	int randNum[3];
	int userInput[3];
	int playerCount = 10;
	

	while (true) //중복 없이 랜덤 숫자 뽑기
	{
		randNum[0] = rand() % 9 + 1;
		randNum[1] = rand() % 9 + 1;
		randNum[2] = rand() % 9 + 1;

		if (randNum[0] != randNum[1] && randNum[0] != randNum[2] && randNum[1] != randNum[2])
			break;
	}


	for (auto i : randNum)
	{
		cout << i << endl;
	}

	while (playerCount > 0)
	{
		CheckState(&randNum[3], &userInput[3]);
		playerCount--;
	}


	return 0;
}

void CheckState(int randNum[],int userInput[])
{
	int ballCount = 0;
	int strikeCount = 0;
	int outCount;
	for (int i = 0; i < 3; i++)
	{
		cin >> userInput[i];

		if (userInput[i] == randNum[i])
		{
			cout << "스트라이크" << endl;
			strikeCount++;
		}
		for (int j = 0; j < 3; j++)
		{
			if (i != j)
			{
				if (userInput[i] == randNum[j])
				{
					cout << "볼" << endl;
					ballCount++;
					break;
				}
			}
		}
	}
	outCount = 3 - ballCount - strikeCount;
	cout << strikeCount << "스트라이크 " << ballCount << "볼 " << outCount << "아웃 입니다." << endl;
}