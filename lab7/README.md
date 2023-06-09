# Описание программы

Программа создает несколько объектов классов GRM, DOC, MUS, наследованных от базового класса Man, и моделирует их взаимодействие путем вызова метода `doing()` одного объекта на другом случайным образом. 

Класс Man имеет поля name (имя), age (возраст) и point (очки). Конструктор Man принимает возраст и имя объекта и инициализирует поля. Метод `doing()` выводит строку "Я ничего не делаю" для объекта базового класса.

Класс GRM (готовит пирожки), DOC (лечит пациента), MUS (играет на скрипке) унаследованы от базового класса Man. Конструктор каждого класса изменяет значение поля point. Метод `doing()` каждого класса изменяет значения point у объектов классов GRM, DOC, MUS.

Функция main создает вектор указателей на объекты классов GRM, DOC, MUS и производит вызов метода `doing()` на объектах этого вектора, пока в векторе не останется только один объект с ненулевыми очками. 

# Как использовать программу

1. Скачайте программу из репозитория.
2. Запустите программу с помощью компилятора C++.
3. Результат работы программы будет выведен в консоль.

# Объяснение кода

В строках 1-6 подключаются необходимые заголовочные файлы и пространство имен std.

В строке 8 определяется базовый класс Man с полями name, age, point. В строках 11-17 определяется конструктор класса Man, который принимает возраст и имя объекта, инициализирует поля и присваивает значение point 50. В строках 19-23 определяется метод `doing()`, который выводит строку "Я ничего не делаю" для объекта базового класса.

В строках 25-27 определяется класс GRM, унаследованный от базового класса Man. В строках 28-32 определяется конструктор класса GRM, который вызывает конструктор базового класса Man и присваивает значение point 30. В строках 34-38 определяется метод `doing()`, который выводит строку "Я готовлю пирожки для <name>" и изменяет значения point у объектов классов GRM и Man.

Аналогично определяются классы DOC и MUS.

В строках 42-44 определяется функция main. В строке 45 устанавливается локаль для вывода сообщений на русский язык. В строках 47-51 создается вектор указателей на объекты классов GRM, DOC, MUS. 

В строка