#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

void printHelp(const std::string& prog) {
    std::cout << "Использование:\n";
    std::cout << "  " << prog << " -o summa ЧИСЛО1 ЧИСЛО2 [ЧИСЛО3] [ЧИСЛО4]\n";
    std::cout << "  " << prog << " --operation subtract ЧИСЛО1 ЧИСЛО2 [ЧИСЛО3] [ЧИСЛО4]\n\n";
    std::cout << "Операции:\n";
    std::cout << "  summa    — суммирование всех операндов\n";
    std::cout << "  subtract — вычитание из первого операнда всех остальных\n\n";
    std::cout << "Операндов: от 2 до 4\n";
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printHelp(argv[0]);
        return 0;
    }

    std::string operation;
    std::vector<double> numbers;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-o" || arg == "--operation") {
            if (i + 1 >= argc) {
                std::cerr << "Ошибка: после " << arg << " должно идти имя операции\n";
                return 1;
            }
            operation = argv[++i];
        } else {
            try {
                numbers.push_back(std::stod(arg));
            } catch (...) {
                std::cerr << "Ошибка: '" << arg << "' не является числом\n";
                return 1;
            }
        }
    }

    if (operation.empty()) {
        std::cerr << "Ошибка: не указана операция. Используйте -o summa или --operation subtract\n";
        return 1;
    }

    if (numbers.size() < 2 || numbers.size() > 4) {
        std::cerr << "Ошибка: нужно от 2 до 4 операндов. Введено: " << numbers.size() << "\n";
        return 1;
    }

    if (operation == "summa") {
        double result = 0;
        for (double n : numbers) result += n;
        std::cout << "Сумма: " << result << "\n";
    } else if (operation == "subtract") {
        double result = numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) result -= numbers[i];
        std::cout << "Разность: " << result << "\n";
    } else {
        std::cerr << "Ошибка: неизвестная операция '" << operation << "'\n";
        std::cerr << "Доступно: summa, subtract\n";
        return 1;
    }

    return 0;
}
