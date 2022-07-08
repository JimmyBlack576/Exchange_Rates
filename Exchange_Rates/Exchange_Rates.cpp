#include <iostream>

using namespace std;

void monthDispay(int a) {
    switch (a) {
    case 1: cout << " Январь: \n";
        break;
    case 2: cout << " Февраль: \n";
        break;
    case 3: cout << " Март: \n";
        break;
    case 4: cout << " Апрель: \n";
        break;
    case 5: cout << " Май: \n";
        break;
    case 6: cout << " Июнь: \n";
        break;
    case 7: cout << " Июль: \n";
        break;
    case 8: cout << " Август: \n";
        break;
    case 9: cout << " Сентябрь: \n";
        break;
    case 10: cout << " Октябрь: \n";
        break;
    case 11: cout << " Ноябрь: \n";
        break;
    case 12: cout << " Декабрь: \n";
        break;
    default: cout << "Нет такого месяца! \n";
        break;

    }
}

void choice(int month) {
    do {
        cout << "Выбрать другой месяц?  1-да/2-нет: \n";
        cin >> month;
        if (month == 1) { break; }
        else if (month == 2) {
            cout << "До свидания!\n";
            exit(0);
        }
        else { cout << "Указано неверное значение!\n"; }
    } while (month != 1 && month != 2);
}

int main()
{
    setlocale(LC_ALL, "ru");

    const int MONTH = 12;
    double rates[MONTH], percent[MONTH];
    int deposite,month=0;
    double withdrawal;
    cout << "Какая сумма в евро была внесена на депозит изначально? \n";
    cin >> deposite;
    //Цикл ввода данных в массив
    cout << "Введите курс доллара по отношению к евро за все месяцы года: \n";
    for (int i = 0; i < MONTH; i++) {
        monthDispay(i + 1);
        cin >> rates[i];
        cout << "Укажите ставку в этом месяце в % : \n";
        cin >> percent[i];
        
        
    }
    //Цикл расчёта и вывода в консоль
    for (int i = 0; i < MONTH; i++) {
        cout << "Введите номер месяца что бы узнать доступную для снятия сумму в нём: \n";
        cin >> i;
        if (i > 12||i<=0) {
            monthDispay(i);
            break;
        }
        withdrawal = deposite * percent[i-1] / 100;
        monthDispay(i);
        if (withdrawal * rates[i-1] / 2 < 500) {
            cout << "Доступно для снятия в этом месяце: ";
            cout << withdrawal * rates[i-1]<<" $ ";
        }
        else {
            cout << "Доступно для снятия в этом месяце: ";
            cout << withdrawal * rates[i-1] / 2 << " $ \n";
        }
        //Условие для продолжения цикла после вывода 12ой итерации
        if (i == 12)
        {
            i = 0;
        }
        choice(month);
    }

    return 0;
}
