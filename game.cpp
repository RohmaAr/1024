#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;
void add(int[][4], int, char);
int yesorno(int[][4], int, char);
void shift(int[][4], int, char);
void random(int[][4], int);
int check(int[][4], int);
void output(int[][4], int);
int main()
{
	int arr[4][4] = { };
	srand(time(0));
	int a, b, c, d, newnum1, newnum2, move, chek = 0;
	char k;
	newnum1 = rand() % 2 + 1;
	newnum2 = rand() % 2 + 1;
	a = rand() % 4;
	b = rand() % 4;
	c = a;
	while (c == a)
	{
		c = rand() % 4;
		d = rand() % 4;
	}
	arr[a][b] = newnum1;
	arr[c][d] = newnum2;
	for (int i = 0; i < 4; i++)
	{
		cout << "_________________________" << endl;
		for (int j = 0; j < 4; j++)
		{
			cout << "|";
			if (arr[i][j] == 0)
				cout << left << setw(5) << " ";
			else
				cout << left << setw(5) << arr[i][j];
		}
		cout << "|" << endl;
	}
	cout << "________________________" << endl;
	while (chek == 0)
	{
		cin >> k;
		move = yesorno(arr, 4, k);
		if (move == 1)
		{
			shift(arr, 4, k);
			add(arr, 4, k);
			shift(arr, 4, k);
			random(arr, 4);
			chek = check(arr, 4);
			system("cls");
			output(arr, 4);
			if (chek == -1)
				cout << "\nGAME OVER";
			else if (chek == 1)
				cout << "\nYOU WIN";
		}
	}
	return 0;
}
void add(int arr[][4], int row, char k)
{
	if (k == 'r')
	{
		for (int i = 0; i < 4; i++)
		{
			if (arr[i][0] == arr[i][1] && arr[i][2] == arr[i][3])
			{
				arr[i][1] = arr[i][1] * 2;
				arr[i][0] = 0;
				arr[i][3] = arr[i][3] * 2;
				arr[i][2] = 0;
			}
			else if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
			{
				arr[i][2] = arr[i][2] * 2;
				arr[i][1] = 0;
			}
			else if (arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3])
			{
				arr[i][3] = arr[i][3] * 2;
				arr[i][2] = 0;
			}
			else
			{
				for (int j = 0; j < 3; )
				{
					if (arr[i][j] == arr[i][j + 1])
					{
						arr[i][j + 1] *= 2;
						arr[i][j] = 0;
						j += 2;
					}
					else
						j++;
				}
			}
		}
	}
	else if (k == 'l')
	{
		for (int i = 0; i < 4; i++)
		{
			if (arr[i][0] == arr[i][1] && arr[i][2] == arr[i][3])
			{
				arr[i][0] = arr[i][0] * 2;
				arr[i][1] = 0;
				arr[i][2] = arr[i][2] * 2;
				arr[i][3] = 0;
			}
			else if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
			{
				arr[i][0] = arr[i][1] * 2;
				arr[i][1] = 0;
			}
			else if (arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3])
			{
				arr[i][1] = arr[i][1] * 2;
				arr[i][2] = 0;
			}
			else
			{
				for (int j = 3; j > 0; )
				{
					if (arr[i][j] == arr[i][j - 1])
					{
						arr[i][j - 1] *= 2;
						arr[i][j] = 0;
						j -= 2;
					}
					else
						j--;
				}
			}
		}
	}
	else if (k == 'u')
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[0][j] == arr[1][j] && arr[2][j] == arr[3][j])
			{
				arr[0][j] = arr[0][j] * 2;
				arr[1][j] = 0;
				arr[2][j] = arr[2][j] * 2;
				arr[3][j] = 0;
			}
			else if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j])
			{
				arr[0][j] = arr[0][j] * 2;
				arr[1][j] = 0;
			}
			else if (arr[1][j] == arr[2][j] && arr[2][j] == arr[3][j])
			{
				arr[1][j] = arr[1][j] * 2;
				arr[2][j] = 0;
			}
			else
			{
				for (int i = 3; i > 0; )
				{
					if (arr[i][j] == arr[i - 1][j])
					{
						arr[i - 1][j] *= 2;
						arr[i][j] = 0;
						i -= 2;
					}
					else
						i--;
				}
			}
		}
	}
	else if (k == 'd')
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[0][j] == arr[1][j] && arr[2][j] == arr[3][j])
			{
				arr[1][j] = arr[1][j] * 2;
				arr[0][j] = 0;
				arr[3][j] = arr[3][j] * 2;
				arr[2][j] = 0;
			}
			else if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j])
			{
				arr[2][j] = arr[2][j] * 2;
				arr[1][j] = 0;
			}
			else if (arr[1][j] == arr[2][j] && arr[2][j] == arr[3][j])
			{
				arr[3][j] = arr[3][j] * 2;
				arr[2][j] = 0;
			}
			else
			{
				for (int i = 0; i < 3; )
				{
					if (arr[i][j] == arr[i + 1][j])
					{
						arr[i + 1][j] *= 2;
						arr[i][j] = 0;
						i += 2;
					}
					else
						i++;
				}
			}
		}
	}
	else
	{
		cout << "INVALID INPUT.USE \'u\' FOR UP,\'d\' FOR DOWN, \'l\' FOR LEFT AND \'r\' FOR RIGHT." << endl;
	}
}
void random(int arr[][4], int row)
{
	int arr2[16];
	int count = 0, d, r;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 0)
			{
				arr2[count] = i * 10 + j;
				count++;
			}
		}
	}
	if (count != 0)
	{
		srand(time(0));
		int newnum = rand() % 2 + 1;
		int pick = rand() % count;
		d = arr2[pick] / 10;
		r = arr2[pick] % 10;
		arr[d][r] = newnum;
	}
}
int check(int arr[][4], int rows)
{
	int count = 0;
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
				count++;
			if (arr[i][j] == arr[i + 1][j])
				count++;
			if (arr[3][j] == arr[3][j + 1])
				count++;
			if (arr[j][3] == arr[j + 1][3])
				count++;
		}
	}
	for (int j = 0; j < 16; j++)
	{
		if (arr[0][j] == 1024)
			return 1;
		if (arr[0][j] == 0)
			return 0;
	}
	if (count > 0)
		return 0;
	else
		return -1;
}
void shift(int arr[][4], int rows, char k)
{
	int key;
	bool stop = false;
	if (k == 'r')
	{
		for (int i = 0; i < 4; i++)
		{
			stop = false;
			for (int j = 3; j > 0; j--)
			{
				if (arr[i][j] == 0)
				{
					key = j;
					while (arr[i][key] == 0)
					{
						key--;
						if (key == 0)
						{
							stop = true;
							break;
						}
					}
					arr[i][j] = arr[i][key];
					arr[i][key] = 0;
				}
				if (stop)
					break;
			}
		}
	}
	if (k == 'l')
	{
		for (int i = 0; i < 4; i++)
		{
			stop = false;
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == 0)
				{
					key = j;
					while (arr[i][key] == 0)
					{
						key++;
						if (key == 3)
						{
							stop = true;
							break;
						}
					}
					arr[i][j] = arr[i][key];
					arr[i][key] = 0;
				}
				if (stop)
					break;
			}
		}
	}
	if (k == 'u')
	{

		for (int j = 0; j < 4; j++)
		{
			stop = false;
			for (int i = 0; i < 3; i++)
			{
				if (arr[i][j] == 0)
				{
					key = i;
					while (arr[key][j] == 0)
					{
						key++;
						if (key == 3)
						{
							stop = true;
							break;
						}
					}
					arr[i][j] = arr[key][j];
					arr[key][j] = 0;
				}
				if (stop)
					break;
			}
		}
	}
	if (k == 'd')
	{

		for (int j = 0; j < 4; j++)
		{
			stop = false;
			for (int i = 3; i > 0; i--)
			{
				if (arr[i][j] == 0)
				{
					key = i;
					while (arr[key][j] == 0)
					{
						key--;
						if (key == 0)
						{
							stop = true;
							break;
						}
					}
					arr[i][j] = arr[key][j];
					arr[key][j] = 0;
				}
				if (stop)
					break;
			}
		}
	}
}
void output(int arr[][4], int rows)
{
	for (int i = 0; i < 4; i++)
	{
		cout << "_________________________" << endl;
		for (int j = 0; j < 4; j++)
		{
			cout << "|";
			if (arr[i][j] == 0)
				cout << left << setw(5) << " ";
			else
				cout << left << setw(5) << arr[i][j];
		}
		cout << "|" << endl;
	}
	cout << "________________________" << endl;
}
int yesorno(int arr[][4], int rows, char k)
{
	int count = 0;
	if (k == 'l')
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (arr[i][j] != 0)
				{
					if (arr[i][j] == arr[i][j - 1] || arr[i][j - 1] == 0)
						count++;
				}
			}
		}
	}
	if (k == 'r')
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] != 0)
				{
					if (arr[i][j] == arr[i][j + 1] || arr[i][j + 1] == 0)
						count++;
				}
			}
		}
	}
	if (k == 'd')
	{

		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (arr[i][j] != 0)
				{
					if (arr[i][j] == arr[i + 1][j] || arr[i + 1][j] == 0)
						count++;
				}
			}
		}
	}
	if (k == 'u')
	{

		for (int j = 0; j < 4; j++)
		{
			for (int i = 3; i > 0; i--)
			{
				if (arr[i][j] != 0)
				{
					if (arr[i][j] == arr[i - 1][j] || arr[i - 1][j] == 0)
						count++;
				}
			}
		}
	}
	if (count == 0)
		return 0;
	else
		return 1;
}
