# kis_maze_problem

Самсонова Екатерина Андреевна

Задача 2

Запустить решение g++ main.cpp




Для начала я попыталась разобраться как устроен пример. Какие выводы получила?

1) клетки поля нумеруются с 0
2) ось х расположена внизу, ось у расположена слева
3) 
Эти выводы сделала на основе шагов 1-3 (т.е. вначале взгляд Минотавра был направлен вниз, потом вправо, потом известно что движение вперед было возможно). При любом другом положении осей/нумерации клеток поля движение Минотавра невозможно (т.е. ответ на третье действие должен быть 0)

Проиллюстрировала свои рассуждения:
https://miro.com/app/board/uXjVNYfstrA=/?share_link_id=19524073499

Собственно, почему на 4 шаге Минотавр может сделать вывод что обошел лабиринт, мне непонятно. По-хорошему ему нужно еще из стартового положения покрутиться во все стороны и убедиться что во всех кроме 1 находятся стены, аналогично сделать из финального положения.
