#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout<<"Введите количество бактерий (1-100): ";
    int bio;
    std::cin>>bio;

    std::cout<<"Введите количество антибиотика (1-14): ";
    int antiBioDrops;
    std::cin>>antiBioDrops;

    //каждый час количество бактерий увеличивается вдвое
    //каждый час добавляют каплю антибиотика
    //каждый час эффективность каждой капли антибиотика уменьшается на 1
    //последняя капля антибиотика будет действовать еще 10 часов

    int hour;

    int maxHour=antiBioDrops+10;

    int antiBioEffect=10;

    int i=1;
    if (bio>0 && antiBioDrops>0 && bio<=100 && antiBioDrops <= 14) {
        for (hour = 1; hour <= maxHour; hour++) {
            bio *= 2;
            bio = bio - antiBioEffect;
            antiBioEffect = antiBioEffect + 10 * i - hour;
            --antiBioDrops;
            if (antiBioDrops <= 0) {
                i = 0;
            }

            if (bio <= 0) {
                bio = 0;
                break;
            }
            std::cout << "После " << hour << " часа осталось  " << bio << " бактерий\n";
        }
        if (bio == 0) {
            std::cout << "После " << hour << " часа осталось  " << 0 << " бактерий\n";
        }
        if (antiBioEffect == 0) {
            std::cout << "Антибиотик прекратил свое воздействие\n";
        }
    } else if ( bio<=0 || antiBioDrops<=0){
        std::cout << "Введите ненулевые параметры для корректного расчёта";
    } else {
        std::cout << "Параметры за пределами допустимых диапазонов";
    }


}
