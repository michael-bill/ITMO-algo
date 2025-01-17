# ITMO-algo

Репозиторий с решёнными задачами (лабораторными работами) по дисциплине Алгоритмы и структуры данных за семестр 4 (весна-2024) в Университете ИТМО.

## Задачи

- [A. Агроном-любитель](./ycontest/task_A)
- [B. Зоопарк Глеба](./ycontest/task_B)
- [C. Конфигурационный файл](./ycontest/task_C)
- [D. Профессор Хаос](./ycontest/task_D)
- [E. Коровы в стойла](./ycontest/task_E)
- [F. Число](./ycontest/task_F)
- [G. Кошмар в замке](./ycontest/task_G)
- [H. Магазин](./ycontest/task_H)
- [I. Машинки](./ycontest/task_I)
- [J. Гоблины и очереди](./ycontest/task_J)
- [K. Менеджер памяти-1](./ycontest/task_K)
- [L. Минимум на отрезке](./ycontest/task_L)
- [M. Цивилизация](./ycontest/task_M)
- [N. Свинки-копилки](./ycontest/task_N)
- [O. Долой списывание!](./ycontest/task_O)

## Использование

Зависимости:
- g++
- python3

Установка зависимостей для тестера:
```bash
pip3 install -r requirements.txt
```

Чтобы протестировать задачу, выполните:
```bash
cd ycontest/_task_example
make test
```

Чтобы запустить задачу без тестирования, выполните:
```bash
cd ycontest/_task_example
make run
```

## Работа с автотестером

Например, у вас есть задача, к которой вы хотите добавить автотестирование:

```bash
cp -r ycontest/_task_example ycontest/task_<task_name>
```

В отдельной задаче следующая структура файлов:

```bash
ycontest/task_<task_name>
├── main.cpp            # Непосредственно ваше решение
├── makefile            # Компиляционный файл
└── tests               # Директория с тестами
    ├── input           # Директория с входными данными, добавляйте сколько нужно
    │   ├── 1.txt
    │   ├── 2.txt
    │   └── 3.txt
    ├── main            # Исполняемый файл
    └── output          # Директория с ожидаемыми результатами
        ├── 1.txt
        ├── 2.txt
        └── 3.txt
```

## Предупреждение

Уважаемые коллеги по университету, если вы хотите что-нибудь взять отсюда, то берите, пожалуйста, аккуратно. Антиплаг всё-таки реально мощный.
