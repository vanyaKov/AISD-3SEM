#include <iostream>
#include <Windows.h>

void hanoiTower(int n, int strart, int finish, int support) {
    if (n == 1) {
        std::cout << "Переместить диск 1 с " << strart << " на " << finish << " стержень" << std::endl;
        return;
    }

    hanoiTower(n - 1, strart, support, finish);
    std::cout << "Переместить диск " << n << " с " << strart << " на " << finish << " стержень" << std::endl;
    hanoiTower(n - 1, support, finish, strart);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int disks_amount, rod_amount;
    std::cout << "Введите количество дисков: ";
    std::cin >> disks_amount;
    std::cout << "Введите количество стержней: ";
    std::cin >> rod_amount;

    if (disks_amount < 1 || rod_amount < 3) {
        std::cout << "Неправильный ввод. Количество дисков должно быть больше 0, и количество стержней должно быть больше 2." << std::endl;
        return 1;
    }

    hanoiTower(disks_amount, 1, rod_amount, 2);

    return 0;
}
