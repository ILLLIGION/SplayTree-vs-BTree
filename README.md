# HeapsComparison [![Build Status](https://travis-ci.org/ILLLIGION/SplayTree-vs-BTree.svg?branch=master)](https://travis-ci.org/ILLLIGION/SplayTree-vs-BTree)

Программа предназначена для сравнения скорости работы двух деревьев: splay tree и B tree.

## Сборка

```ShellSession
$ git clone https://github.com/ILLLIGION/SplayTree-vs-BTree
$ cd SplayTree-vs-BTree
$ mkdir build
$ cd build
$ cmake .. && make
```

## Запуск тестов

```ShellSession
$ ./Tests -s -r compact
```

## Использование

```ShellSession
$ ./main inputFile outputFile
```

На вход программы подаются 2 текстовых файла. В первом файле `inputFile` (должен находиться в директории `/SplayTree-vs-BTree/tests/`) содержится вид структуры данных (одним словом: splay или b) и список команд для неё. Аргументы каждой команды следует отделить пробелом от названия команды и друг друга. Второй файл `outputFile` создает программа и записывает туда результаты своей работы (результаты работы приведенных в первом файле команд, если у таковых предусмотрен вывод), а также время, за которое она отработала, в микросекундах.

## Шаблоны команд

```ShellSession
$ insert [key] [data] - Вставка в дерево элемента с ключом `key` и данными `data`
$ find [key] - Поиск в дереве элемента с ключом `key`
$ delete [key] - Удаление из дерева элемента с ключом `key`
$ min - Получение данных элемента с наименьшим ключом из дерева
$ max - Получение данных элемента с наибольшим ключом из дерева
$ print - Отображение внутреннего строения* дерева
```

## *Формат вывода команды `print`

```ShellSession
    Элементы выводятся в виде дерева, повернутого на 90 градусов против часовой стрелки. Количество штрихов отображает глубину, на которой находится узел.
```
