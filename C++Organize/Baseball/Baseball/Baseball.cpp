#include <iostream>

using namespace std;

int main()
{
	srand(time(0));//���� �ð����� ���缭 �õ带 ��ȯ�Ͽ� ��� ������ ���� �������� ��.
	cout << "��Ģ: �ߺ����� ���� ���ڸ� �Է��ؼ� ���� �ڸ� ��������= ��Ʈ����ũ, ���� ���� �ٸ��ڸ� = ��, �ƴϸ� �ƿ�" << endl;
	int randNum[3];
	int userInput[3];
	int playerCount = 10;
	

	while (true) //�ߺ� ���� ���� ���� �̱�
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
			cout << "��Ʈ����ũ" << endl;
			strikeCount++;
		}
		for (int j = 0; j < 3; j++)
		{
			if (i != j)
			{
				if (userInput[i] == randNum[j])
				{
					cout << "��" << endl;
					ballCount++;
					break;
				}
			}
		}
	}
	outCount = 3 - ballCount - strikeCount;
	cout << strikeCount << "��Ʈ����ũ " << ballCount << "�� " << outCount << "�ƿ� �Դϴ�." << endl;
}