# I - черта, ^ - пятка, P - петля веревки
# ? - кувшинка, ! - палец, J - жаба(личинка),H - человек

#перевод из египт. СС в десятичную
def egyptian_converter_to_dec(word: str):
    result = 0

    for i in range(len(word)):
        if word[i] in words_values:
            result += words_values[word[i]]

    return result

#перевод из десятичной в египт. СС
def dec_converter_to_egyptian(num: int):
    result = ''
    temp_num = num
    value_index = 1

    while temp_num > 0:
        temp = temp_num % 10
        temp_num //= 10
        for i in range(temp):
            result += list(words_values.keys())[list(words_values.values()).index(value_index)]
        value_index *= 10

    if result == '':
        return '0'
    else:
        return result[::-1]

#проверка для всех СС
alph = '0123456789ABCDEFI^P?!JH'

def correct(num : str, radix : int):
    is_correct = True
    if radix <= 16:
        for i in range(len(num)):
            temp = False
            for j in range(radix):
                if num[i] == alph[j]:
                    temp = True
                    break
            if temp == False:
                is_correct = False
    elif radix == 17:
        for i in range(len(num)):
            temp = False
            for j in range(16, 23):
                if num[i] == alph[j]:
                    temp = True
                    break
            if temp == False:
                is_correct = False
    if is_correct == True:
        return True
    else:
        return False
