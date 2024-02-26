from comb_chekunova import *
from some_comb import *
from comb_vanina import *

print("Введите номер комбинаторной схемы:\n"
      "1 - правило суммы\n"
      "2 - правило произведения\n"
      "3 - размещение с повторениями\n"
      "4 - размещение без повторений\n"
      "5 - сочетания с повторениями\n"
      "6 - сочетания без повторений\n"
      "7 - перестановки с повторениями\n"
      "8 - перестановки без повторений\n")
num_comb = int(input())

fun_map = {
    1: sum_rule,
    2: multi_rule,
    3: placements_with_repetitions,
    4: placements_without_repetitions,
    5: combinations_rep,
    6: combinations,
    7: permut,
    8: permut
}
if num_comb == 1 or num_comb == 2:
    print("Введите первое множество через запятую:")
    set1 = input()
    print("Введите второе множество через запятую:")
    set2 = input()
    print(fun_map[num_comb](set1, set2))
elif 2 < num_comb < 7:
    print("Введите n и k через пробел:")
    n, k = map(int, input().split())
    print(len(fun_map[num_comb](n, k)))
elif num_comb == 7 or num_comb == 8:
    print("Введите  список, содержащий информацию о количестве i-го объекта, через запятую\n"
          "В случае, если повторений нет, список имеет вид 1, 1, 1, ..., 1 - n единиц")
    cnt = [int(num) for num in input().split(",")]
    print(len(fun_map[num_comb](cnt)))
else:
    print("Неправильный номер(")
