#правило суммы
def sum_rule (set1, set2):
    num1 = set(set1.split(","))
    num2 = set(set2.split(","))
    return sorted(num1|num2)

#result_set = sum_rule("7,3","5,5")
#print(*result_set, sep=", ")

#правило произведения
def multi_rule (set1, set2):
    num1 = (set1.split(","))
    num2 = (set2.split(","))
    return len(num1)*len(num2)

#print(multi_rule("1,1","1,2"))