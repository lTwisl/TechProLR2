# Лабораторная работа №3

Диспицлина: "Профилировка универсальной навигационной комплексной системы"

Группа:
М3О-406С-19

Работу выполнили:
- Александров В. С.
- Белов А.С.
- Федосеев В. А.
- Деревянченко К. А.

https://github.com/lTwisl/TechProLR2

Задание:

"Профилировка универсальной навигационной комплексной системы"

1). Создайте на GitHub репозиторий TechProLR3 (в нашем случае добавили ЛР3 в репозиторий ЛР2).

2). Разработайте программу, в которой будет реализован следующий функционал:

3). Создайте класс profiler в конструкторе, которого должно засекать время при помощи
steady_clock::time_point start_time_ = steady_clock::now();, а в деструкторе выводится в консоль длительность существования
класса.

4). Соберите программу через консоль PowerShell используя компилятор
установленный через MinGW. При компиляции обязательно
использовать флаги -Wall и -Werror.

5). Напишите Makefile для сборки проекта.

6). Для проверки используйте следующий код:
```
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;
using namespace chrono;
using namespace literals;
int main() {
cout << "Ожидание 5 сек..."s << endl;
Profiler sleep_guard;
this_thread::sleep_for(5s);
cout << "Ожидание завершено"s << endl;
}
```

7). Проведите профилировку методов класса навигационной комплексной системы. Какие методы выполняются дольше всего, быстрее всего.
(Если методы выполняются слишком быстро выполните несколько одинаковых операций подряд)

8). Опишите процесс разработки программы в отчете, включая разделение задач, принятые решения и выводы, о том, что вы освоили в процессе
работы.

На защиту предъявляете репозиторий, историю коммитов, и отчет в формате
readme.md


Выполнение работы:
Далее, для удобства участников работы будем упоминать по именам. В профиле Вячеслава на GitHub в репозитории с именем *TechProLR2*, добавляем файлы для работы с ЛР3.

Далее создаем класс "Profiler", в котором реализованы конструктор, в котором засекается время работы программы и деструктор, в котром 
выводится время работы программы.
```
#include <iostream>
#include <chrono>

using namespace std;


class Profiler
{
private:
    chrono::steady_clock::time_point start_time;
    string name;

public:
    Profiler(string name)
    {
        start_time = chrono::steady_clock::now();
        this->name = name;
    }

    ~Profiler()
    {
        auto end_time = chrono::steady_clock::now();
        auto delta_time = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        cout << name << ": " << delta_time << endl;
    }
};
```
Редактируем main.cpp:
```
int main(int argc, char* argv[])
{
    Profiler pp("main");
    IntegratedNavigationSystem ins;
    Acceleration a("accelerometr");
    Acceleration a1;
    Gyroscop g;
    Position p;

    ins.add_sensor(a);
    ins.add_sensor(a1);
    ins.add_sensor(g);
    ins.add_sensor(p);

    for(auto value : ins.measure_acc())
    {
        cout << "acc: ";
        cout << value << " " << a1.measurement_unit << endl;
    }

    for(auto value : ins.measure_gyro())
    {
        cout << "gyro: ";
        cout << value << " " <<  g.measurement_unit << endl;
    }

    for(auto value : ins.measure_position())
    {
        cout << "pos: ";
        cout << value << " " << p.measurement_unit << endl;
    }
    cout <<"---------------------------------------------------"<<endl;
    ins.list_sensors();
    return 0;
}
```
И редактируем классы самих дачиков (Гироскопа,  Акселерометра, Датчика позиции):
```
#include "./Profiler.cpp"

using namespace std;

Position::Position()
{
    name = "Position";
    measurement_unit = "Meters";
    minValue = 0;
    maxValue = 15;
}

Position::Position(string name_init)
{
    name = name_init;
    measurement_unit = "Meters";
    minValue = 0;
    maxValue = 15;
}
double Position::measure()
{
    Profiler pro("Time pos::measure");
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(minValue, maxValue);
    return dist(e2);
}
```
Собираем программу через консоль PowerShell используя компилятор установленный через MinGW. При компиляции 
используем флаги -Wall и -Werror.
```
Time acc::measure: 818
Time acc::measure: 20
time ins::measure_acc: 1564
acc: 0.640795 m/c^2
acc: 0.332499 m/c^2
Time gyro::measure: 19
time ins::measure_gyro: 283
gyro: 0.26956 rad/sec
Time pos::measure: 18
time ins::measure_position: 218
pos: 11.9039 Meters
---------------------------------------------------
accelerometr
Acceleration
Gyroscop
Position
main: 10855
```
В данном фрагменте работы программы последние строчки показывают время работы каждого профилируемого cpp файла

Написали свой "Makefile", в котором добавили в сборку файл "Profiler.cpp":
```
all:
	g++ -Wall -Werror main.cpp Sensor.cpp Acceleration.cpp Gyroscop.cpp Position.cpp IntegratedNavigationSystem.cpp Profiler.cpp -o TestMake
```
Провели профилировку созданных нами во второй лабораторной работе классов Навигационной системы, результаты вывели в консоль:
```
Time acc::measure: 818
Time acc::measure: 20
time ins::measure_acc: 1564

Time gyro::measure: 19
time ins::measure_gyro: 283

Time pos::measure: 18
time ins::measure_position: 218
---------------------------------------------------
accelerometr
Acceleration
Gyroscop
Position
main: 10855
```
В данном отрывке видно, видно время работы различных методов класса Интегральной навигационной системы. В результате профилировки можно заметить, что быстрее всего выполняются методы датчиков (measure), а дольше всего выполнялся метод main, который является точкой входа в программу. В нем используются все возможности Навигационной системы, поэтому данный метод является самым нагруженным.

Вывод:
В ходе лабараторной работы мы приобрели и отработали новые навыки, такие как:
1. Повысили навыки совместной работы в команде 
2. Повысили навыки использования системы контроля версий и редактора VSCode
3. Изучили термин "Профайлинг"
4. Научились использовать профайлинг для анализа созданных проектов
