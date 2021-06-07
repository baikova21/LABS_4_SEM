#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;


__interface IComputer_software
{
public:
	virtual void Vivod() = 0;
};

class computer_software: public IComputer_software {
protected:
	char* brand = NULL; // Бренд
	int work_speed; // Скорость работы
	int version; // Версия
	int type; // Тип
	int series_number; // Серийный номер

public:
	computer_software(); // Конструктор по умолчанию
	computer_software(char* Brand, int Speed, int Version, int Type, int Series_number); // Конструктор с параметрами
	computer_software(const computer_software& s); // Копирующий конструктор
	~computer_software(); // Деструктор
	void copy(const computer_software& s); // Функция копирования полей одного объекта в другой

	int get_work_speed() const; // Функция, которая возвращает значение поля work_speed
	void set_software(); // Изменение всех полей объекта

	computer_software& operator=(const computer_software& s); // перегрузка оператора присваивания
	bool operator>(const computer_software& s); // перегрузка оператора "больше"
	friend ostream& operator<<(ostream& out, const computer_software& s); // перегрузка оператора вывода


	virtual void Vivod();// ф-ция вывода

};

void computer_software::Vivod() { // ф-ция вывода

	cout << "Brand : " << brand << endl;

	cout << "Speed : " << work_speed << endl;

	cout << "Version : " << version << endl;

	cout << "Type : " << type << endl;

	cout << "Series_number : " << series_number << endl;

}



template <class T>
class conteiner {
protected:
	int capacity = 0; // Вместимость вектора
	T* mas = NULL; // Сам вектор

public:
	~conteiner(); // Деструктор
	conteiner(int Capacity); // Конструктор с параметром
	void enter_vector(); // Изменение элементов вектора
	void AddElement(int index, T elem); // Добавить новый элемент в вектор
	T GetElement(int index);
	void get_vector() const; // Вывод элементов вектора

	void search() const; // Поиск
	void compare() const; // Сравнение
	void sort(); // Сортировка

};

// Класс наследник
// Начало
// в первом классе заменил private на protected
class propietary_software : public computer_software {
public:
	propietary_software();

	propietary_software(char* Brand, int Speed, int Version, int Type, int Series_number, float Price);

	float GetPrice();

	void Vivod();

protected:
	float price; // цена
};

propietary_software::propietary_software() : computer_software() {
	char def[] = "default";
	brand = new char[strlen(def) + 1];
	strcpy_s(brand, strlen(def) + 1, def);

	work_speed = 0;
	version = 0;
	type = 0;
	series_number = 0;

	price = 0;
}

propietary_software::propietary_software(char* Brand, int Speed, int Version, int Type, int Series_number, float d) : computer_software(Brand, Speed, Version, Type, Series_number)
{
	price = d;
}

float propietary_software::GetPrice() {
	return this->price;
}


void propietary_software::Vivod() { // наследование вывода
	computer_software::Vivod();
	cout << "Цена: " << price << endl;
}

class antivirus : public propietary_software {
public:
	antivirus() : propietary_software(), programm_size(0) {};

	antivirus(char* Brand, int Speed, int Version, int Type, int Series_number, float price, float Programm_size) : propietary_software(Brand, Speed, Version, Type, Series_number, price), programm_size(Programm_size) {};

	void Vivod();

protected:
	float programm_size; // размер программы
};

class skaner : public antivirus {
public:
	skaner() : antivirus(), scan_time(0) {};

	skaner(char* Brand, int Speed, int Version, int Type, int Series_number, float price, float Programm_size, float Scan_time) : antivirus(Brand, Speed, Version, Type, Series_number, price, programm_size), scan_time(Scan_time) {};

	void Vivod();

protected:
	float scan_time; // время сканирования
};





computer_software::computer_software()
{
	char def[] = "default";
	brand = new char[strlen(def) + 1];
	strcpy_s(brand, strlen(def) + 1, def);

	work_speed = 0;
	version = 0;
	type = 0;
	series_number = 0;
}

computer_software::computer_software(char* Brand, int Speed, int Version, int Type, int Series_number)
{
	brand = new char[strlen(Brand) + 1];
	strcpy(brand, Brand);

	work_speed = Speed;
	version = Version;
	type = Type;
	series_number = Series_number;
}

computer_software::computer_software(const computer_software& s)
{
	copy(s);
}

computer_software::~computer_software()
{
	if (brand != NULL) delete[] brand;
}

void computer_software::copy(const computer_software& s)
{
	if (brand != NULL) delete[] brand;
	if (s.brand != 0) {
		brand = new char[strlen(s.brand) + 1];
		strcpy_s(brand, strlen(s.brand) + 1, s.brand);
	}
	work_speed = s.work_speed;
	version = s.version;
	type = s.type;
	series_number = s.series_number;
}

int computer_software::get_work_speed() const
{
	return work_speed;
}

void computer_software::set_software()
{
	char str[25];
	cout << "Введите бренд: "; cin >> str;
	if (brand != NULL) delete[] brand;
	brand = new char[strlen(str) + 1];
	strcpy_s(brand, strlen(str) + 1, str);

	work_speed = rand() % 100;
	version = rand() % 100;
	type = rand() % 100;
	series_number = rand() % 100;
}

computer_software& computer_software::operator=(const computer_software& s)
{
	if (this != &s) {
		copy(s);
	}
	return *this;
}

bool computer_software::operator>(const computer_software& s)
{
	return work_speed > s.work_speed;
}

template <class T>
conteiner<T>::~conteiner()
{
	delete[] mas;
}

template <class T>
conteiner<T>::conteiner(int Capacity)
{
	if (Capacity > 0) {
		capacity = Capacity;
		mas = new T[capacity];
	}
	else {
		cout << "Ошибка создания!\n";
	}
}

template <class T>
void conteiner<T>::enter_vector()
{
	for (int i = 0; i < capacity; i++) {
		mas[i].set_software();
	}
}

template <class T>
void conteiner<T>::get_vector() const
{
	for (int i = 0; i < capacity; i++) {
		cout << mas[i];
	}
}

template <class T>
void conteiner<T>::AddElement(int index, T elem)
{
	if (this->capacity > index && index >= 0) {
		this->mas[index] = elem;
	}
	else throw "Ошибка добавления элемента в контейнер" ;
}

template <class T>
T conteiner<T>::GetElement(int index)
{
	if (this->capacity > index && index >= 0) {
		return this->mas[index];
	}
	else throw "Ошибка получения элемента из контейнера";
}

template <class T>
void conteiner<T>::search() const
{
	int speed;
	cout << "ПОИСК\nВведите скорость работы: "; cin >> speed;
	for (int i = 0; i < capacity; i++) {
		if (mas[i].get_work_speed() == speed) cout << mas[i];
	}
}

template <class T>
void conteiner<T>::compare() const
{
	int speed;
	cout << "СРАВНЕНИЕ\nВведите скорость работы: "; cin >> speed;
	for (int i = 0; i < capacity; i++) {
		if (mas[i].get_work_speed() >= speed) cout << mas[i];
	}
}

template <class T>
void conteiner<T>::sort()
{
	for (int i = 0; i < capacity - 1; i++) {
		for (int j = i + 1; j < capacity; j++) {
			if (mas[i] > mas[j]) {
				T tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
			}
		}
	}
}

ostream& operator<<(ostream& out, const computer_software& s)
{
	out << "______________________________\n";
	out << "Бренд: " << s.brand << endl;
	out << "Скорость работы: " << s.work_speed << endl;
	out << "Версия: " << s.version << endl;
	out << "Тип: " << s.type << endl;
	out << "Серийный номер: " << s.series_number << endl;
	return out;
}

void antivirus::Vivod()
{
	propietary_software::Vivod();
	cout << "Размер программы: " << programm_size << endl;
}

void skaner::Vivod()
{
	antivirus::Vivod();
	cout << "Время сканирования: " << scan_time << endl;
}


//Новые классы
class Shareware : public computer_software, public propietary_software {
protected:
	/// <summary>
	/// Количество рекламных объявлений.
	/// </summary>
	int ads_count;
public:
	//Конструкторы
	Shareware();
	Shareware(char* Brand, int Speed, int Version, int Type, int Series_number, int Ads_count);
	void Vivod();
};


class SubShareware : public Shareware, public propietary_software {
protected:
	/// <summary>
	/// Срок действия подписки
	/// </summary>
	int sub_duration;
public:
	//Конструкторы
	SubShareware();
	SubShareware(char* Brand, int Speed, int Version, int Type, int Series_number, float price, 
		int Ads_count, int sub_duration);
	//Вывод информации
	void Vivod();
};


class PhotoEditor : public SubShareware {
private:
	/// <summary>
	/// Количество поддерживаемых форматов
	/// </summary>
	int formats_count;
public:
	PhotoEditor();
	PhotoEditor(char* Brand, int Speed, int Version, int Type, int Series_number, float price,
		int Ads_count, int sub_duration, int formats_count);
	void Vivod();
};




int main() {
	setlocale(LC_ALL, "rus");
	string name = "Название";
	char name_char[10];
	strcpy(name_char, name.c_str());
	PhotoEditor photoshop(name_char,100,12,13,12323151,1200,2,12,48);
	conteiner<PhotoEditor> cont(2);
	try {

		cont.AddElement(0, photoshop);
		cont.GetElement(1).Vivod();
	}
	catch (const char* ex) {
		cout << "Исключение: " << ex << endl;
	}
	
	system("pause");
	return 0;
}

//Реализация методов класса Shareware
Shareware::Shareware() : computer_software() {
	ads_count = 0;
}

Shareware::Shareware(char* Brand, int Speed, int Version, int Type, int Series_number, int Ads_count)
:computer_software(Brand, Speed, Version, Type, Series_number)
{
	this->ads_count = Ads_count;
}

void Shareware::Vivod() {
	computer_software::Vivod();
	cout << "Ads_count: " << ads_count << endl;
}

//Реализация методов SubShareware

SubShareware::SubShareware() : Shareware(), propietary_software()
{
	sub_duration = 0;
}

SubShareware::SubShareware(char* Brand, int Speed, int Version, int Type, int Series_number, float price,
	int Ads_count, int sub_duration) : Shareware(Brand, Speed, Version, Type, Series_number,
		Ads_count), propietary_software(Brand, Speed, Version, Type, Series_number,
			price)
{
	this->sub_duration = sub_duration;
}

void SubShareware::Vivod()
{
	Shareware::Vivod();
	cout << "price: " << propietary_software::GetPrice() << endl;
	cout << "sub_duration: " << sub_duration << endl;
}


//Реализация методоа класса PhotoEditor

PhotoEditor::PhotoEditor() : SubShareware()
{
	formats_count = 0;
}

PhotoEditor::PhotoEditor(char* Brand, int Speed, int Version, int Type,
	int Series_number, float price, int Ads_count, int sub_duration, 
	int formats_count) : SubShareware(Brand,  Speed,  Version,  Type,
		 Series_number,  price,  Ads_count,sub_duration)
{
	this->formats_count = formats_count;
}

void PhotoEditor::Vivod()
{
	SubShareware::Vivod();
	cout << "formats_count: " << this->formats_count << endl;
}
