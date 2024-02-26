#правило суммы
def sum_rule (set1, set2):
    num1 = set(set1.split(","))
    num2 = set(set2.split(","))
    return sorted(num1|num2)

#правило произведения
def multi_rule (set1, set2):
    num1 = (set1.split(","))
    num2 = (set2.split(","))
    return len(num1)*len(num2)
