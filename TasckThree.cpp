#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

const int MAX_ATTEMPTS = 5; // Максимальна кількість невдалих спроб

int main() {
    // Матриця слів
    static const std::vector<std::vector<char>> WORDS = {
        {'t', 'h', 'i', 's'}, // Змінено слово
        {'i', 's'},
        {'a'},
        {'w', 'o', 'r', 'd'}
    };

    // Ініціалізація випадкового вибору
    std::srand(std::time(0));
    int randomIndex = std::rand() % WORDS.size(); // Випадкове слово
    const std::vector<char>& chosenWord = WORDS[randomIndex];

    // Ініціалізація слова зі зірочками
    std::vector<char> hiddenWord(chosenWord.size(), '*');

    int attempts = 0; // Лічильник невдалих спроб
    bool isGuessed = false;

    std::cout << "Гра 'Вгадай Слово' починається!\n";
    std::cout << "Слово: ";
    for (char c : hiddenWord) {
        std::cout << c;
    }
    std::cout << "\n";

    while (attempts < MAX_ATTEMPTS && !isGuessed) {
        char letter;
        int position;

        // Введення літери і позиції
        std::cout << "\nВведіть літеру: ";
        std::cin >> letter;
        std::cout << "Введіть позицію (1-" << chosenWord.size() << "): ";
        std::cin >> position;

        // Перевірка правильності вводу
        if (position < 1 || position > chosenWord.size()) {
            std::cout << "Неправильна позиція. Спробуйте ще раз.\n";
            continue;
        }

        // Зміщення позиції (користувач вводить від 1, а індекси починаються з 0)
        int actualPosition = position - 1;

        // Перевірка чи літеру вгадано
        if (chosenWord[actualPosition] == letter) {
            hiddenWord[actualPosition] = letter; // Замінюємо зірочку на вгадану літеру
            std::cout << "Правильно! Слово: ";
        } else {
            attempts++;
            std::cout << "Неправильно. Невдалих спроб: " << attempts << "/" << MAX_ATTEMPTS << "\n";
        }

        // Вивід поточного стану слова
        for (char c : hiddenWord) {
            std::cout << c;
        }
        std::cout << "\n";

        // Перевірка чи слово вгадано повністю
        isGuessed = (hiddenWord == chosenWord);
    }

    // Завершення гри
    if (isGuessed) {
        std::cout << "\nВи виграли! Слово: ";
        for (char c : chosenWord) {
            std::cout << c;
        }
        std::cout << "\n";
    } else {
        std::cout << "\nВи програли. Слово було: ";
        for (char c : chosenWord) {
            std::cout << c;
        }
        std::cout << "\n";
    }

    return 0;
}
