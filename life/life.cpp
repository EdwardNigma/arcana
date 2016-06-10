#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int main()
{
	const int width(20), heigh(20); // ������ � ������ �������� ����
	const char livecell('0'), deadcell('.'); // "0" - ����� ������ "." - ������� ������

	int count_of_generations(1000);

	bool cell[width][heigh] = { false }; // ������
	bool secondcell[width][heigh] = { false }; 

	srand((unsigned)time(NULL));
	
	// ������� ��������� ������, ��������� ��� ������ � ���������
	
	for (int y = 0; y < heigh; y++)
		for (int x = 0; x < width; x++)
			cell[x][y] = rand() % 2;
			
	// ����� ���������
	
	for (int g = 0; g < count_of_generations; g++) // ������� ����������� ���������, ���� g ������ count_of_generation
	{
		for (int y = 0; y < heigh; y++)
		{
			for (int x = 0; x < width; x++)
			{
				// ������ �������� ������
				int count = 0;
				// 0..
				// ...
				// ...

				if (((x - 1) >= 0) && ((y - 1) >= 0)) // ��������� �������� ������, ����� ��� ������������ ������� 
				{
					if (cell[x - 1][y - 1]) count++; // ���� ������ �����, �� ����������� �� ���-��
				}

				// .0.
				// ...
				// ...

				if ((y - 1) >= 0)
				{
					if (cell[x][y - 1]) count++;
				}

				// ..0
				// ...
				// ...

				if ((x <= (width - 1)) && ((y - 1) >= 0))
				{
					if (cell[x + 1][y - 1]) count++;
				}

				// ...
				// 0..
				// ...
				if ((x - 1) >= 0)
				{
					if (cell[x - 1][y]) count++;
				}

				// ...
				// ..0
				// ...
				if ((x + 1) <= (width - 1))
				{
					if (cell[x + 1][y]) count++;
				}

				// ...
				// ...
				// 0..
				if (((x - 1) >= 0) && (y + 1) <= (heigh - 1))
				{
					if (cell[x - 1][y + 1]) count++;
				}

				// ...
				// ...
				// .0.
				if ((y + 1) <= (heigh - 1))
				{
					if (cell[x][y + 1]) count++;
				}

				// ...
				// ...
				// ..0
				if (((x + 1) <= (width - 1)) && ((y + 1) <= (heigh - 1)))
				{
					if (cell[x + 1][y + 1]) count++;
				}

				// ����������� ��������� ������� ������

				if ((count < 2) || (count > 3)) 
				{
					secondcell[x][y] = false;
					cout << deadcell;
				}
				else
				{
					if ((!cell[x][y] && (count != 3)))
					{
						secondcell[x][y] = false;
						cout << deadcell;
					}
					else
					{
						secondcell[x][y] = true;
						cout << livecell;
					}
				}

			}

			cout << '\n';
		}
		Sleep(750);
		system("cls");
		
		for (int y = 0; y < heigh; y++)
			for (int x = 0; x < width; x++)
				cell[x][y] = secondcell[x][y];
	}

	return 0;
}