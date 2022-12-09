# Лабораторная работа №2

Диспицлина: "Технологии программирования"

Группа:
М3О-406С-19

Работу выполнили:
- Александров В. С.
- Белов А.С.
- Федосеев В. А.
- Деревянченко К. А.

https://github.com/lTwisl/TechProLR2

Задание:

"Разработка универсальной
навигационной комплексной
системы"

1). Создайте на GitHub репозиторий TechProLR2.

2). Разработайте программу в которой будут реализован следующий
функционал:

3). Есть класс комплексной навигационной системы которая включает
себя:
коллекция датчиков – возможны разные реализации, но к
навигационной системе может быть привязано несколько разных
датчиков
add_sensor – метод добавляющий датчик к навигационной системе
measure_acc – метод возвращающий измерения от всех акселерометров
measure_gyro – метод возвращающий измерения от всех гироскопов
measure_position – метод возвращающий измерения от всех датчиков
положения
list_sensors – выводит имена датчиков входящих в состав
навигационной системы
Каждый датчик - это отдельный объект. Датчик обладает следующими
свойствами и методами
name – содержит имя датчика,
measurement_unit – единицей измерения того что он измеряет
Min, Max – пара минимального и максимального измеряемого
значения
measure – метод генерирующий случайное значение с плавающей
точкой в диапазоне значений измерителя.

4). Соберите программу через консоль PowerShell используя компилятор
установленный через MinGW. При компиляции
использовать флаги -Wall и -Werror.

5). Напишите Makefile для сборки проетка.

6). Опишите процесс разработки программы в отчете, включая разделение задач, принятые решения и выводы, о том, что вы освоили в процессе работы.
На защиту предъявляете репозиторий, историю коммитов, и отчет в формате
readme.md

Выполнение работы:
Далее, для удобства участников работы будем упоминать по именам. В профиле Вячеслава на GitHub создали репозиторий с именем *TechProLR2*.

1) Устанавливаем компилятор g++ и редактор кода VSCode, для этого воспользуемся инструкцией по установке предоставленной в папке с лабораторной работой.
2) Создаем репозиторий TechProLR2 и добавляем туда всех участников разработки, в нём же создаем папки HeaderFiles SourceFile, в которых будут храниться заголовочные и исполнительные файлы нашего проекта.
3) Реализация проекта и его архитектуры: 
a)	Будет создан класс “Сенсор” на основе  которого далее будут созданы три датчика “Гироскоп”, “Акселерометр”  и “Позиции”. Каждым датчиком занимается определенный участник. Позиционный датчик - Виктор, Гироскоп - Кирилл, Акселерометр - Александр. Вячеслав является тимлидом группы и создает программу для подключения датчиков и .h файл для инициализации 
входных значений датчиков.
```
Sensor::Sensor()
{
    name = "Sensor";
    measurement_unit = "null";
    minValue = 0;
    maxValue = 10;
}

Sensor::Sensor(string name_init)
{
    name = name_init;
    measurement_unit = "null";
    minValue = 0;
    maxValue = 10;
}

double Sensor::measure()
{
    cout << "Number" << endl;
    return 0;
}
```
```
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
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(minValue, maxValue);
    return dist(e2);
}
```
b)	Далее создаем класс “Навигационной системы “, в котором будут храниться наши созданные датчики, а также будет реализован разный функционал позволяющий добавлять и выводить информацию.
```
void IntegratedNavigationSystem::add_sensor(Sensor& sensor)
{
    _allSensors.push_back(&sensor);
}

vector<double> IntegratedNavigationSystem::measure_acc()
{
   vector<double> measures;

   for(size_t i = 0; i < _allSensors.size(); ++i)
   {
        if(typeid(*_allSensors[i]) == typeid(Acceleration))
        {
            Acceleration* a = static_cast<Acceleration*>(_allSensors[i]);
            measures.push_back(a->measure());
        }
   }

   return measures;
}

vector<double> IntegratedNavigationSystem::measure_position()
{
   vector<double> measures;
   for(size_t i = 0; i < _allSensors.size(); ++i)
   {
           // cout <<"vfff"<<endl;
             //       cout <<typeid(*_allSensors[i]).name()<<endl;
                //    cout <<typeid(Position*).name()<<endl;
       if (typeid(*_allSensors[i]) == typeid(Position))
       {
            Position* a = static_cast<Position*>(_allSensors[i]);
            measures.push_back(a->measure());
       }
   }

   return measures;
}

vector<double> IntegratedNavigationSystem::measure_gyro()
{
    vector<double> measures;
    for(size_t i = 0; i < _allSensors.size(); ++i)
    {
        if (typeid(*_allSensors[i]) == typeid(Gyroscop))
        {
            Gyroscop* a = static_cast<Gyroscop*>(_allSensors[i]);
            measures.push_back(a->measure());
        }
    }

    return measures;
}

void IntegratedNavigationSystem::list_sensors()
{
    for(size_t i = 0; i < _allSensors.size(); ++i)
    {
        std::cout << _allSensors[i]->name << std::endl;
    }
}
```
c) Напишем реализацию  функции “main”.
```
int main(int argc, char* argv[])
{
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
4) Формируем Makefile.
```
g++ -Wall -Werror main.cpp Sensor.cpp Acceleration.cpp Gyroscop.cpp Position.cpp IntegratedNavigationSystem.cpp -o TestMake
```
5) Собираем и компилируем проект.
Результат вывода собранного проекта:
```
acc: 0.213226 m/c^2
acc: 0.725858 m/c^2
gyro: 0.986003 rad/sec
pos: 4.4061 Meters
---------------------------------------------------
Acceleration
Acceleration
Gyroscop
Position
```
Вывод:
В ходе лабараторной работы мы приобрели и отработали новые навыки, такие как:
1. Повысили навыки совместной работы в команде 
2. Повысили навыки использования системы контроля версий 
3. Изучили навыки использования PowerShell, VSCode и компилятора g++ , а также сборщика Chocolatey
4. Научились компилировать проекты с помощью  Makefile.
