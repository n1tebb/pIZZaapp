#include <iostream>
#include <Windows.h>

const int pizza_count = 7;
const int snack_count = 4;
const int drink_count = 5;
const double skidka_all = 2000; //порорг суммы заказа для скидки в 15%
const double skidka_drink = 100; //порог на напиток
const double skidka_pizza = 5; //каждая 5 пицца подарок

double pizza_price[pizza_count] = { 400, 450, 500, 420, 480, 390, 430 };
double snack_price[snack_count] = { 150, 120, 200, 250 }; 
double drink_price[drink_count] = { 100, 90, 95, 70, 120 };

void showpizzamenu()
{
	std::cout << "Меню пицц:\n";
	for (int i = 0; i < pizza_count; i++)
	{
		std::cout << i + 1 << ". Пицца " << i + 1 << " - " << pizza_price[i] << " руб.\n";
	}
}

int choice_pizza(int pizzaCount)
{
	int choice, total_pizza = 0;
	do
	{
		std::cout << "Выберите пиццу (0 - завершить выбор): ";
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
	std::cout << "Меню закусок: \n";
	for (int i = 0; i < snack_count; i++)
	{
		std::cout << i + 1 << ". Закуска " << i + 1 << " - " << snack_price[i] << " руб.\n";
	}
}

double choice_snack(int snackCount)
{
	int choice, total_snack = 0;
	do
	{
		std::cout << "Выберите закуску (0 - завершить выбор): ";
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
	std::cout << "Меню напитков:\n";
	for (int i = 0; i < drink_count; i++)
	{
		std::cout << i + 1 << ". Напиток " << i + 1 << " - " << drink_price[i] << " Руб.\n";
	}
}

double choice_drink(int drinkCount)
{
	int choice, total_drink = 0;
	do
	{
		std::cout << "Выберите напиток (0 - завершить выбор): ";
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

	//скидка пицца
	if (pizzaCount >= skidka_pizza)
	{
		int freePizza = pizzaCount / skidka_pizza;
		total -= freePizza * pizza_price[0]; //бесплатная пицца будет самая дешевая
		std::cout << freePizza << " пицца в подарок (- " << freePizza * pizza_price[0] << " руб.\n";
	}

	//скидка напитки (1 бесплатно при покупке больше 4 и их цена >= 100
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
			std::cout << "Один напиток в подарок! (-" << freeDrink << " Руб.\n";
		}
	}

	//скидка на весь заказ 15%
	if (total > skidka_all)
	{
		double skidka = total * 0.15;
		total -= skidka;
		std::cout << "Скидка на весь заказ 15% (-" << skidka << " Руб.)\n";
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
		std::cout << "Итого к оплате " << total << " Руб.\n";


		system("pause");
	}

	return 0;

}