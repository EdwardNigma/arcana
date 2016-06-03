#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int main()
{
	const int width(20), heigh(20); // ширина и высота игрового поля
	const char livecell('0'), deadcell('.'); // "0" - живые клетки "." - мертвые клетки

	int count_of_generations(1000);

	bool cell[width*heigh] = { false }; // массив
	bool secondcell[width*heigh] = { false };

	srand((unsigned)time(NULL));

	for (int y = 0; y < heigh; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (cell[x + y * width])
			{
				cout << livecell;
			}
			else
			{
				cout << deadcell;
			}
		}
		cout << '\n';
	}

	cout << '\n';

	// создаем рандомный массив

	for (int y = 0; y < heigh; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cell[x + y * width] = rand() % 2;
			if (cell[x + y * width])
			{
				cout << livecell;
			}
			else
			{
				cout << deadcell;
			}
		}
		cout << '\n';
	}
	cout << '\n';
	cout << '\n';

	// вывод поколений
	for (int g = 0; g < count_of_generations; g++)
	{
		for (int y = 0; y < heigh; y++)
		{
			for (int x = 0; x < width; x++)
			{
				// анализ соседних клеток
				static int count(0);
				// 0..
				// ...
				// ...

				if (((x - 1) >= 0) && ((y - 1) >= 0))
				{
					if (cell[(x - 1) + (y - 1) * width]) count++;
				}

				// .0.
				// ...
				// ...

				if ((y - 1) >= 0)
				{
					if (cell[x + (y - 1) * width]) count++;
				}

				// ..0
				// ...
				// ...

				if ((x <= (width - 1)) && ((y - 1) >= 0))
				{
					if (cell[(x + 1) + (y - 1) * width]) count++;
				}

				// ...
				// 0..
				// ...
				if ((x - 1) >= 0)
				{
					if (cell[(x - 1) + y * width]) count++;
				}

				// ...
				// ..0
				// ...
				if ((x + 1) <= (width - 1))
				{
					if (cell[(x + 1) + y * width]) count++;
				}

				// ...
				// ...
				// 0..
				if (((x - 1) >= 0) && (y + 1) <= (heigh - 1))
				{
					if (cell[x - 1 + (y + 1) * width]) count++;
				}

				// ...
				// ...
				// .0.
				if ((y + 1) <= (heigh - 1))
				{
					if (cell[x + (y + 1) * width]) count++;
				}

				// ...
				// ...
				// ..0
				if (((x + 1) <= (width - 1)) && ((y + 1) <= (heigh - 1)))
				{
					if (cell[x + 1 + (y + 1) * width]) count++;
				}

				// определение состояния

				if ((count < 2) || (count > 3))
				{
					secondcell[x + y * width] = false;
					cout << deadcell;
				}
				else
				{
					if ((!cell[x + y * width]) && (count != 3))
					{
						secondcell[x + y * width] = false;
						cout << deadcell;
					}
					else
					{
						secondcell[x + y * width] = true;
						cout << livecell;
					}
				}

				count = 0;
			}

			cout << '\n';
		}
		Sleep(1200);
		system("cls");
		for (int i = 0; i < (width * heigh); i++)
		{
			cell[i] = secondcell[i];
		}
	}

	return 0;
}