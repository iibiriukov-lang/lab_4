#include <iostream>
//потрібно для std::numeric_limits
#include <limits>
#include <windows.h>

void Proc47();
void Proc33();
void Integer33();

int main()
{
	//додаємо підтримку UTF-8 для консолі
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	Proc47();
	Proc33();
	Integer33();
	return 0;
}

double PowerInt(double x, int n)
{
	//обчислюємо x^n. N може бути від'ємним.
	double result = 1;

	if (n >= 0)
	{
		for (int i = 0; i < n; ++i)
		{
			result *= x;
		}
	}
	else
	{
		for (int i = 0; i > n; --i)
		{
			result /= x;
		}
	}

	return result;
}

int Quarter(double x, double y)
{
	//визначаємо номер координатної чверті для точки з ненульовими координатами.
	if (x > 0 && y > 0)
		return 1;
	if (x < 0 && y > 0)
		return 2;
	if (x < 0 && y < 0)
		return 3;
	if (x > 0 && y < 0)
		return 4;

	return 0;
}

void Proc47()
{
	std::cout << "Proc47. Описати функцію PowerInt(X, n) дійсного типу, яка обчислює степінь X ^ n цілого числа n(n може бути від'ємним). За допомогою цієї функції обчислити степені для трьох пар даних чисел X та n.";
	for (int i = 1; i <= 3; ++i)
	{
		//вводемо x та n
		double x;
		int n;
		std::cout << "Пара " << i << " — введіть дійсне X та ціле n: ";
		//перевіряємо
		if (!(std::cin >> x >> n))
		{
			std::cerr << "Некоректне введення. Введіть дійсне X та ціле n.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}

		if (x == 0 && n < 0)
		{
			std::cout << "Нуль не можна підносити до від'ємного степеня.\n";
			continue;
		}
		//обчислюємо та виводимо
		std::cout << "PowerInt(" << x << ", " << n << ") = "
			<< PowerInt(x, n) << '\n';
	}
}

void Proc33()
{
	std::cout << "Proc33. Описати функцію Quarter (x, y) цілого типу, яка визначає номер координатної чверті, в якій знаходиться точка з ненульовими дійснимикоординатами(x, y).За допомогою цієї функції знайти номери координатних чвертей для трьох точок з даними ненульовими координатами.";
	for (int i = 1; i <= 3; ++i)
	{
		double x, y;
		//вводимо
		std::cout << "Точка " << i << " — введіть координати x та y: ";
		//перевіряємо
		if (!(std::cin >> x >> y))
		{
			std::cerr << "Некоректне введення координат.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}

		if (x == 0 || y == 0)
		{
			std::cout << "Координати мають бути ненульовими.\n";
			--i;
			continue;
		}
		//виводимо результат
		std::cout << "Точка (" << x << ", " << y << ") знаходиться у "
			<< Quarter(x, y) << "-й чверті.\n";
	}
}

//функції
bool Input33(int& totalMinutes)
{
	std::cout << "Введіть кількість хвилин: ";
	//перевіряємо введення
	if (!(std::cin >> totalMinutes) || totalMinutes < 0)
	{
		std::cerr << "Некоректне значення. Введіть невід'ємне ціле число.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}

	return true;
}

//обчислюємо
void Calculate33(int totalMinutes, int& hours, int& minutes)
{
	hours = totalMinutes / 60;
	minutes = totalMinutes % 60;
}

//виводимо
void Output33(int hours, int minutes)
{
	std::cout << "Минуло: " << hours << " год. і " << minutes << " хв.\n";
}

void Integer33()
{
	std::cout << "Integer33. Дано кількість хвилин, що минуло з певного моменту часу. Визначити кількість повних минувших годин і хвилин після останньої години.";
	//вводимо
	int totalMinutes;
	int hours;
	int minutes;

	if (!Input33(totalMinutes))
		return;

	Calculate33(totalMinutes, hours, minutes);
	Output33(hours, minutes);
}
