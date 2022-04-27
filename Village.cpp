#include <iostream>
#include <fstream>
#include <string>

const std::string  fileName = "village.txt";

// --------------------------- site ----------------------------------------
struct site
{
	int area;
	int registration_number;
	int number_of_buildings;
	std::string name;
};
//
site add_site()
{
	site result{ 0 };
	std::cin.ignore();
	std::cout << "Введите название участка: ";
	std::getline(std::cin, result.name);
	std::cout << "Введите регистрационный номер участка: ";
	std::cin >> result.registration_number;
	std::cout << "Введите количество домов на участке: ";
	std::cin >> result.number_of_buildings;
	std::cout << "Введите площадь участка в квадратных метрах: ";
	std::cin >> result.area;
	return result;
}
//
void save_site(std::ofstream& file, site  value)
{
	if (file.is_open())
	{
		file << value.name;
		file << "\n";
		file << value.registration_number;
		file << "\n";
		file << value.number_of_buildings;
		file << "\n";
		file << value.area;
		file << "\n";
	}
}
// --------------------------- village -------------------------------------
struct village
{
	int area;
	std::string name;
};
//
village add_village()
{
	village result{0};
	std::cin.ignore();
	std::cout << "Введите название поселка: ";
	std::getline(std::cin, result.name);
	std::cout << "Введите площадь поселка в квадратных метрах: ";
	std::cin >> result.area;
	return result;
}
//
void save_village(std::ofstream& file, village value)
{
	if (file.is_open())
	{
		file << value.name;
		file << "\n";
		file << value.area;
		file << "\n";
	}
}
// --------------------------- room ----------------------------------------
struct  room
{
	bool balcony;
	std::string name;
	int area;
	double height_of_ceiling;
};
room add_room()
{
	room result{ 0 };
	int temp;
	std::cin.ignore();
	std::cout << "Введите название комнаты: ";
	std::getline(std::cin, result.name);
	std::cout << "Введите площадь комнаты в квадратных метрах: ";
	std::cin >> result.area;
	std::cout << "Введите высоту потолка в комнате в метрах: ";
	std::cin >> result.height_of_ceiling;
	std::cout << "В этой комнате есть балкон ? [1 - да / 0 - нет]: ";
	std::cin >> temp;
	if (temp == 0) result.balcony = false;
	else  result.balcony = true;
	return result;
}
//
void save_room(std::ofstream& file, room  value)
{
	if (file.is_open())
	{
		file << value.name;
		file << "\n";
		file << value.area;
		file << "\n";
		file << value.height_of_ceiling;
		file << "\n";		
		file << value.balcony;
		file << "\n";
	}
}
// -------------------------- flat -----------------------------------------
struct flat
{
	int floor;
	int number_of_rooms;
	int area;
};
//
flat add_flat()
{
	flat result{ 0 };
	std::cout << "Введите этаж квартиры: ";
	std::cin >> result.floor;
	std::cout << "Введите площадь квартиры в квадратных метрах: ";
	std::cin >> result.area;
	std::cout << "Введите количество комнат в квартире: ";
	std::cin >> result.number_of_rooms;
	return result;
}
//
void save_flat(std::ofstream& file, flat  value)
{
	if (file.is_open())
	{
		file << value.floor;
		file << "\n";
		file << value.area;
		file << "\n";
		file << value.number_of_rooms;
		file << "\n";
	}
}
// ------------------------ buildings --------------------------------------
struct buildings
{
	int height_of_buildings;
	int area;
	int storeys;
	bool lift;
	int apartments;
	std::string name;
};
//
void save_buildings(std::ofstream& file, buildings  value)
{
	if (file.is_open())
	{
		file << value.name;
		file << "\n";
		file << value.area;
		file << "\n";
		file << value.height_of_buildings;
		file << "\n";
		file << value.storeys;
		file << "\n";
		file << value.apartments;
		file << "\n";
		file << value.lift;
		file << "\n";
	}
}
//
buildings add_buildings()
{
	buildings result{ 0 };
	int temp;
	std::cin.ignore();
	std::cout << "Введите название здания: ";
	std::getline(std::cin, result.name);
	std::cout << "Введите площадь здания в квадратных метрах: ";
	std::cin >> result.area;
	std::cout << "Введите высоту здания в метрах: ";
	std::cin >> result.height_of_buildings;
	std::cout << "Введите количество этажей в здании: ";
	std::cin >> result.storeys;
	std::cout << "Введите количество квартир в здании: ";
	std::cin >> result.apartments;
	std::cout << "В здании есть лифт? [1 - да / 0 - нет]: ";
	std::cin >> temp;
	if (temp == 0) result.lift = false;
	else  result.lift = true;
	return result;
}
// -------------------------------------------------------------------------
bool answer()
{
	int temp;
	bool done = true;
	std::cout << "\nПродолжить работу с программой? [1 - да / 0 - нет]: ";
	std::cin >> temp;
	if (temp == 0) done = false;
	return done;
}
// ----------------------------------------------------------------------------
//
// ------------------------------- Main Program -------------------------------
//
// ----------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");
	
	bool done = true;
	std::cout << "Добро пожаловать в русскую версиию \"Электронной Таблицы\" для председателей поселковых администраций!" << std::endl;

	std::ofstream file_out(fileName, std::ios::app);
	if (!file_out.is_open()) {
		std::cout << "Неосвещенный файл или файл отсутствует!" << std::endl;
		return 2;
	}
	else
	{
		do {
			std::cout << "Нажмите клавишу \"ВВОД\" для продолжения ... \n";
			village level1 = add_village();
			site level2 = add_site();
			save_village(file_out, level1);
			save_site(file_out, level2);
			for (int i = 0; i < level2.number_of_buildings; i++)
			{
				buildings level3 = add_buildings();
				save_buildings(file_out, level3);
				for (int j = 0; j < level3.apartments; j++)
				{
					flat level4 = add_flat();
					save_flat(file_out, level4);
					for (int k = 0; k < level4.number_of_rooms; k++)
					{
						room level5 = add_room();
						save_room(file_out, level5);
					}
				}
			}

			done = answer();
		} while (done);

	}
		
	std::cout <<  std::endl;
	file_out.close();
	system("pause");
	return 0;

}