#include <iostream>
#include <Windows.h>

const int pizza_count = 7;
const int snack_count = 4;
const int drink_count = 5;
const double skidka_all = 2000; //������ ����� ������ ��� ������ � 15%
const double skidka_drink = 100; //����� �� �������
const double skidka_pizza = 5; //������ 5 ����� �������

double pizza_price[pizza_count] = { 400, 450, 500, 420, 480, 390, 430 };
double snack_price[snack_count] = { 150, 120, 200, 250 }; 
double drink_price[drink_count] = { 100, 90, 95, 70, 120 };

void showpizzamenu()
{
	std::cout << "���� ����:\n";
	for (int i = 0; i < pizza_count; i++)
	{
		std::cout << i + 1 << ". ����� " << i + 1 << " - " << pizza_price[i] << " ���.\n";
	}
}

int choice_pizza(int pizzaCount)
{
	int choice, total_pizza = 0;
	do
	{
		std::cout << "�������� ����� (0 - ��������� �����): ";
		std::cin >> choice;
		if (choice > 0 && choice <= pizza_count)
		{
			pizzaCount++;
			total_pizza += pizza_price[choice - 1];
		}
	} while (choice != 0);
	return total_pizza;
}

void showsnackmenu()
{
	std::cout << "���� �������: \n";
	for (int i = 0; i < snack_count; i++)
	{
		std::cout << i + 1 << ". ������� " << i + 1 << " - " << snack_price[i] << " ���.\n";
	}
}

double choice_snack(int snackCount)
{
	int choice, total_snack = 0;
	do
	{
		std::cout << "�������� ������� (0 - ��������� �����): ";
		std::cin >> choice; 
		if (choice > 0 && choice <= snack_count)
		{
			total_snack += snack_price[choice - 1];
		}
	} while (choice != 0);
	return total_snack;
}

void showdrinkmenu()
{
	std::cout << "���� ��������:\n";
	for (int i = 0; i < drink_count; i++)
	{
		std::cout << i + 1 << ". ������� " << i + 1 << " - " << drink_price[i] << " ���.\n";
	}
}

double choice_drink(int drinkCount)
{
	int choice, total_drink = 0;
	do
	{
		std::cout << "�������� ������� (0 - ��������� �����): ";
		std::cin >> choice;
		if (choice > 0 && choice <= drink_count)
		{
			total_drink += drink_price[choice - 1];
		}
	} while (choice != 0);
	return total_drink;
}

double calculateTotal(int total_pizza, int total_snack, int total_drink, int pizzaCount, int drinkCount)
{
	double total = total_pizza + total_snack + total_drink;

	//������ �����
	if (pizzaCount >= skidka_pizza)
	{
		int freePizza = pizzaCount / skidka_pizza;
		total -= freePizza * pizza_price[0]; //���������� ����� ����� ����� �������
		std::cout << freePizza << " ����� � ������� (- " << freePizza * pizza_price[0] << " ���.\n";
	}

	//������ ������� (1 ��������� ��� ������� ������ 4 � �� ���� >= 100
	if (drinkCount > 4)
	{
		double freeDrink = 0;
		for (int i = 0; i < drink_count; i++)
		{
			if (drink_price[i] > skidka_drink)
			{
				freeDrink = drink_price[i];
				break;
			}
		}
		if (freeDrink > 0)
		{
			total -= freeDrink;
			std::cout << "���� ������� � �������! (-" << freeDrink << " ���.\n";
		}
	}

	//������ �� ���� ����� 15%
	if (total > skidka_all)
	{
		double skidka = total * 0.15;
		total -= skidka;
		std::cout << "������ �� ���� ����� 15% (-" << skidka << " ���.)\n";
	}
	return total;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		system("cls");

		int pizzaCount = 0, drinkCount = 0, snackCount = 0;
		int total_pizza = 0, total_snack = 0, total_drink = 0;

		showpizzamenu();
		total_pizza = choice_pizza(pizzaCount);

		showsnackmenu();
		total_snack = choice_snack(snackCount);

		showdrinkmenu();
		total_drink = choice_drink(drinkCount);


		double total = calculateTotal(total_pizza, total_snack, total_drink, pizzaCount, drinkCount);
		std::cout << "����� � ������ " << total << " ���.\n";


		system("pause");
	}

	return 0;

}