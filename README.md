# Задание 15
Цель задания кластеризация и визуализация результата.

На подготовительном этапе следует подключить библиотеку `dlib` к своему
сборочному окружению. Библиотека находится в пакете `libdlib-dev`. Для
работы потребуется библиотека линейной алгебры, которая в свою очередь
находится в пакете `libopenblas-dev`.
Установка дополнительного репозитория рассматривалась на первом
занятии:
```
echo "deb http://archive.ubuntu.com/ubuntu xenial main universe" \
| sudo tee -a /etc/apt/sources.list
```
В качестве основы необходимо взять пример http://dlib.net/kkmeans_ex.cpp.html
и собрать из него действующее приложение.
На основе этого примера необходимо разработать приложение, принимающее
на вход строки вида
```
x1;y1\n
x2;y2\n
x3;y3\n
```
где пары `xn` и `yn` - это координаты точек в пространстве. На выходе
приложения должны формироваться строки вида:
```
x1;y1;cluster1\n
x2;y2;cluster2\n
x3;y3;cluster3\n
```
где пары `xn` и `yn` - идентичны входным, `clustern` - номер кластера, к
которому относится соответствующая пара.
Подготовить набор входных данных идентичных примеру (учитывая
случайность величин один из возможных вариантов).
Подготовить набор входных данных “звездное небо” состоящее из `200`
случайных точек координаты которых в диапазоне от `-100` до `100`
включительно.
Наборы данных должны быть включены в состав пакета.
Приложение должно запускаться командой:
```
cat kkmeans_ex.txt | kkmeans n
```
где `n` - количество кластеров.
Приложить результат визуализации “звездного неба” пузырьковой
диаграммой.
Опционально - предоставить последовательность действий для быстрой
визуализации из командной строки (генерация изображения).
Требования к реализации
Результатом работы должен стать исполняемый файл `kkmeans` и находиться
в пакете `kkmeans`.
Результат работы должен быть опубликован на bintray.
### Проверка
Задание считается выполненным успешно, если после установки пакета
и запуска с тестовыми данными удается визуализировать результат
пузырьковой диаграммой.
