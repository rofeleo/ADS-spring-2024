from tkinter import *
from tkinter import messagebox
import tkinter as tk
from change_number_system import *
from egyptian_number_system import *


def calculate():
    ss1 = int(win_ss1.get())
    num1 = str(win_num1.get())
    ss2 = int(win_ss2.get())
    num2 = str(win_num2.get())
    ss_ans = int(win_ss_ans.get())

    if not correct(num1, ss1) or not correct(num2, ss2) or ss_ans > 17:
        result = "Ошибка"
    else:
        if ss1 == 17:
            num1_dec = egyptian_converter_to_dec(num1)
        else:
            num1_dec = to_dec(num1, ss1)
        if ss2 == 17:
            num2_dec = egyptian_converter_to_dec(num2)
        else:
            num2_dec = to_dec(num2, ss2)

        operation = operation_var.get()
        if operation == "+":
            result = num1_dec + num2_dec
        elif operation == "-":
            result = max(num1_dec, num2_dec) - min(num1_dec, num2_dec)
        elif operation == "*":
            result = num1_dec * num2_dec
        elif operation == "/":
            result = num1_dec / num2_dec

        if ss_ans != 17:
            result = dec_to_other(result, ss_ans)
        else:
            result = dec_converter_to_egyptian(result)
    messagebox.showinfo('Результат', f'Ответ = {result}')


window = Tk()
window.title('Калькулятор')
window.geometry('700x300')

frame = Frame(window, padx=10, pady=10)
frame.pack(expand=True)

# I - черта, ^ - пятка, P - петля веревки
# ? - кувшинка, ! - палец, J - жаба(личинка),H - человек
note = tk.Label(frame, text="Используйте системы счисления со 2-й по 16-ю\n\n"
                            "17 сс считается за египетскую:\n"
                            "I     1               черта\n"
                            "^   10              пятка\n"
                            "P   100            петля веревки\n"
                            "?    1 000         кувшинка\n"
                            "!     10 000       палец\n"
                            "J     100 000    жаба(личинка)\n"
                            "H   1 000 000  человек",
                justify='left')
note.grid(row=0, column=1)

num1 = Label(frame, text="Первое число:")
num2 = Label(frame, text="Второе число:")
ss1 = Label(frame, text="СС первого числа:")
ss2 = Label(frame, text="СС второго числа:")
ss_ans = Label(frame, text="СС ответа:")

ss1.grid(row=1, column=0)
num1.grid(row=1, column=2)
ss2.grid(row=2, column=0)
num2.grid(row=2, column=2)
ss_ans.grid(row=3, column=0)

operation_label = tk.Label(frame, text="Выберите операцию:")
operation_label.grid(row=4, column=0)

input_var = tk.StringVar()
radio_var1 = tk.StringVar(value=10)
radio_var2 = tk.StringVar(value=10)
operation_var = tk.StringVar()

operation_option = tk.OptionMenu(frame, operation_var, "+", "-", "*", "/")
operation_option.grid(row=4, column=1)

win_ss1 = Entry(frame)
win_num1 = Entry(frame)
win_ss2 = Entry(frame)
win_num2 = Entry(frame)
win_ss_ans = Entry(frame)

win_ss1.grid(row=1, column=1, pady=0)
win_num1.grid(row=1, column=3, pady=3)
win_ss2.grid(row=2, column=1, pady=2)
win_num2.grid(row=2, column=3, pady=2)
win_ss_ans.grid(row=3, column=1, pady=2)

answer = Button(frame, text='Рассчитать', command=calculate)
answer.grid(row=6, column=2)

window.mainloop()
