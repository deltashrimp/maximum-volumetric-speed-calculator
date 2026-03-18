#include <iostream>
#include <limits> 
using namespace std;

// Функция расчёта объёмной скорости (mm³/s)
float calculate(float layer_height, float line_width, float print_speed) {
	return layer_height * line_width * print_speed;
}


float safeInput(const string& prompt) {
	float value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail() || value <= 0) {
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка! Введите положительное число (больше 0).\n";
		} else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
	}
}

int main() {
	cout << "=== Расчёт максимальной объёмной скорости печати (volumetric speed) ===\n";

	char choice;
	
	do {
		float layer_height = safeInput("Введите высоту слоя (layer_height): ");
		float line_width   = safeInput("Введите ширину линии (line_width): ");
		float print_speed  = safeInput("Введите скорость печати (print_speed): ");
		float result = calculate(layer_height, line_width, print_speed);

		cout << "\n Объёмная скорость: " << result << " mm³/s\n\n";
		cout << "Хотите выполнить ещё один расчёт? (y/n): ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
	} 
		while (choice == 'y' || choice == 'Y');

	cout << "Хорошей печати.\n";
	return 0;
}
