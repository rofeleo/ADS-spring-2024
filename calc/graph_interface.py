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

    # result = "Ответ"
    if not correct(num1, ss1) or not correct(num2, ss2) or ss_ans > 17 or num2 == "0":
        # result = "Ошибка"
        messagebox.showinfo('Результат', f'Ошибка')
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
window.geometry('900x400')

frame = Frame(window, padx=10, pady=10)
frame.pack(expand=True)

# I - черта, ^ - пятка, P - петля веревки
# ? - кувшинка, ! - палец, J - жаба(личинка),H - человек
note0 = tk.Label(frame, text="Используйте системы счисления со 2-й по 16-ю\n"
                             "17 сс считается за египетскую",
                 justify='left', font=("Arial", 12))
note1 = tk.Label(frame, text="\n\n"
                             "I\n"
                             "^\n"
                             "P\n"
                             "?\n"
                             "!\n"
                             "J\n"
                             "H\n",
                 font=("Arial", 12))
note2 = tk.Label(frame, text="Египетская сс:\n\n1\n"
                             "10\n"
                             "100\n"
                             "1 000\n"
                             "10 000\n"
                             "100 000\n"
                             "1 000 000\n", justify='left', font=("Arial", 12))
note3 = tk.Label(frame, text="\n\nчерта\n"
                             "пятка\n"
                             "петля веревки\n"
                             "кувшинка\n"
                             "палец\n"
                             "жаба(личинка)\n"
                             "человек\n", justify='left', font=("Arial", 12))
note0.grid(row=0, column=0)
note1.grid(row=0, column=1)
note2.grid(row=0, column=2)
note3.grid(row=0, column=3)

num1 = Label(frame, text="Первое число:", font=("Arial", 12))
num2 = Label(frame, text="Второе число:", font=("Arial", 12))
ss1 = Label(frame, text="СС первого числа:", font=("Arial", 12))
ss2 = Label(frame, text="СС второго числа:", font=("Arial", 12))
ss_ans = Label(frame, text="СС ответа:", font=("Arial", 12))

ss1.grid(row=1, column=0)
num1.grid(row=1, column=2)
ss2.grid(row=2, column=0)
num2.grid(row=2, column=2)
ss_ans.grid(row=3, column=0)

operation_label = tk.Label(frame, text="Выберите операцию:", font=("Arial", 12))
operation_label.grid(row=4, column=0)

input_var = tk.StringVar()
radio_var1 = tk.StringVar(value=10)
radio_var2 = tk.StringVar(value=10)
operation_var = tk.StringVar()

operation_option = tk.OptionMenu(frame, operation_var, "+", "-", "*", "/")
# operation_option.config(width=10)
operation_option.config(bg='lightgrey')
operation_option.grid(row=4, column=1)

win_ss1 = Entry(frame)
win_num1 = Entry(frame)
win_ss2 = Entry(frame)
win_num2 = Entry(frame)
win_ss_ans = Entry(frame)

win_ss1.config(bg='lightgrey')
win_num1.config(bg='lightgrey')
win_ss2.config(bg='lightgrey')
win_num2.config(bg='lightgrey')
win_ss_ans.config(bg='lightgrey')

win_ss1.grid(row=1, column=1, pady=0)
win_num1.grid(row=1, column=3, pady=3)
win_ss2.grid(row=2, column=1, pady=2)
win_num2.grid(row=2, column=3, pady=2)
win_ss_ans.grid(row=3, column=1, pady=2)

answer = Button(frame, text='Рассчитать', command=calculate, font=("Arial", 12))
answer.grid(row=6, column=2)

window.mainloop()
