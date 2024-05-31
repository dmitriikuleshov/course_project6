# Отчет по курсовому проекту 6
## по курсу "Фундаментальная информатика"

Студент группы М80-108Б-23 Кулешов Д.А.

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Обработка последовательной файловой структуры на языке Си.
2. **Цель работы**: Разработка последовательной структуры данных в Си для представления базы данных и работы с файлами. Создание программы выборки данных на основе параметра запроса.
3. **Задание (вариант №35)**: Найти пассажиров, число вещей которых превосходит среднее число вещей не менее чем на `p` штук.
4. **Идея, метод, алгоритм решения задачи**: Решение задачи предполагает разработку структуры для представления данных о пассажирах, создание файла с данными и реализацию функции для обработки запросов выборки на основе параметров командной строки.
5. **Сценарий выполнения работы**:

| Входные данные                  | Ожидаемый результат                                                    | Описание тестируемого случая                                      |
|---------------------------------|-----------------------------------------------------------------------|-------------------------------------------------------------------|
| Бинарный файл с данными         | Таблица с данными из файла                                             | Проверка корректности чтения данных из файла                      |
| Параметр запроса `p`            | Список пассажиров, у которых число вещей больше среднего на `p` штук | Проверка работы алгоритма поиска                                     |
| -f                              | Распечатка содержимого файла                                          | Проверка параметра командной строки для вывода данных файла       |
| -p 3                            | Результат выборки по параметру                                        | Проверка параметра командной строки для фильтрации данных         |

6. **Протокол**: ...

7. Замечания автора по существу работы: Работа позволила познакомиться с методами обработки файловых структур и алгоритмами выборки данных.
8. Выводы: Лабораторная работа показала важность умения работать с файловыми структурами и управлять параметрами командной строки. Полученные навыки будут полезны для разработки более сложных программ, где необходима обработка большого объема данных