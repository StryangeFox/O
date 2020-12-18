#include"Header.h"

void DataInitialization() {
	ofstream _buf("Buffer.txt");

	if (!_buf)
		cout << "Ошибка создания буферного файла\n";

	_buf.close();
}

void DataEntry() {
	int _id;
	string _name;
	string _author;
	int _year;
	string _genre;
	string _type;
	string _direction;
	int _price;
	string _owner;

	int n;

	cout << "Введите количество данных: ";
	cin >> n;

	ofstream record("Buffer.txt", ios::app);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {

			cout << "Введите ID картины: ";
			cin >> _id;
			record << "ID: " << _id << endl;

			cout << "Введите название катины: ";
			cin >> _name;
			record << _name << endl;

			cout << "Введите имя автора: ";
			cin >> _author;
			record << _author << endl;

			cout << "Введите год: ";
			cin >> _year;
			record << _year << endl;

			cout << "Введите жанр: ";
			cin >> _genre;
			record << _genre << endl;

			cout << "Введите вид: ";
			cin >> _type;
			record << _type << endl;

			cout << "Введите направление: ";
			cin >> _direction;
			record << _direction << endl;

			cout << "Введите цену: ";
			cin >> _price;
			record << _price << endl;

			cout << "Введите местоположения: ";
			cin >> _owner;
			record << _owner << endl;
		}
	}
	else
		cout << "Ошибка открытия файла.\n";
}

void DataReading(string filename) {
	ifstream reading(filename);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			int _id;
			string _name;
			string _author;
			int _year;
			string _genre;
			string _type;
			string _direction;
			int _price;
			string _owner;

			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _id;
				reading >> _name;
				reading >> _author;
				reading >> _year;
				reading >> _genre;
				reading >> _type;
				reading >> _direction;
				reading >> _price;
				reading >> _owner;

				record << _id << endl;
				record << _name << endl;
				record << _author << endl;
				record << _year << endl;
				record << _genre << endl;
				record << _type << endl;
				record << _direction << endl;
				record << _price << endl;
				if (i < n - 1)
					record << _owner << endl;
				else record << _owner;
			}
			cout << "Данные считаны с файла." << endl;
		}
		else
			cout << "Ошибка открытия буфера." << endl;
	}
	else
		cout << "Ошибка открытия файла." << endl;

	reading.close();
	record.close();
}

void Print() {
	ifstream reading("Buffer.txt");

	if (reading) {
		int _id;
		string _name;
		string _author;
		int _year;
		string _genre;
		string _type;
		string _direction;
		int _price;
		string _owner;

		int n;

		reading >> n;
		cout << "Количество картин: " << n << "\n\n";

		cout << "|" << setw(5) << "Номер" << "|" << setw(2) << "ID" << "|" << setw(30) << "Название" << "|" << setw(16) << "Автор" << "|" << setw(4) << "Год" << "|" << setw(11) << "Жанр" << "|" << setw(8) << "Вид" << "|" << setw(11) << "Направление" << "|" << setw(10) << "Цена" << "|" << setw(27) << "Место положения" << "|" << endl;

		for (int i = 0; i < n; i++) {
			//cout << "Картина №" << i + 1 << endl;

			reading >> _id;
			reading >> _name;
			reading >> _author;
			reading >> _year;
			reading >> _genre;
			reading >> _type;
			reading >> _direction;
			reading >> _price;
			reading >> _owner;

			cout << "|" << setw(5) << i + 1 << "|" << setw(2) << _id << "|" << setw(30) << _name << "|" << setw(16) << _author << "|" << setw(4) << _year << "|" << setw(11) << _genre << "|" << setw(8) << _type << "|" << setw(11) << _direction << "|" << setw(10) << _price << "|" << setw(27) << _owner << "|" << endl;

			//cout << "ID: " << _id << endl;
			//cout << "Название: " << _name << endl;
			//cout << "Автор: " << _author << endl;
			//cout << "Год: " << _year << endl;
			//cout << "Жанр: " << _genre << endl;
			//cout << "Вид: " << _type << endl;
			//cout << "Направление: " << _direction << endl;
			//cout << "Цена: " << _price << endl;
			//cout << "Владелец: " << _owner << endl;
			//cout << endl;
		}
		cout << endl;
	}
	else
		cout << "Ошибка открытия файла." << endl;

	reading.close();
}

void DataChange() {
	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			int _id;
			string _name;
			string _author;
			int _year;
			string _genre;
			string _type;
			string _direction;
			int _price;
			string _owner;

			int n, _n;

			reading >> n;

			cout << "Выберете картину данные которой вы хотите изменить(от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {
				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _id;
						reading >> _name;
						reading >> _author;
						reading >> _year;
						reading >> _genre;
						reading >> _type;
						reading >> _direction;
						reading >> _price;
						reading >> _owner;

						record << _id << endl;
						record << _name << endl;
						record << _author << endl;
						record << _year << endl;
						record << _genre << endl;
						record << _type << endl;
						record << _direction << endl;
						record << _price << endl;
						if (i < n - 1)
							record << _owner << endl;
						else record << _owner;
					}
					else {
						int temp_id;
						string temp_name;
						string temp_author;
						int temp_year;
						string temp_genre;
						string temp_type;
						string temp_direction;
						int temp_price;
						string temp_owner;

						reading >> _id;
						reading >> _name;
						reading >> _author;
						reading >> _year;
						reading >> _genre;
						reading >> _type;
						reading >> _direction;
						reading >> _price;
						reading >> _owner;

						temp_id = _id;
						temp_name = _name;
						temp_author = _author;
						temp_year = _year;
						temp_genre = _genre;
						temp_type = _type;
						temp_direction = _direction;
						temp_price = _price;
						temp_owner = _owner;

						int answer=999;
						while (answer != 0) {

							cout << "Что вы хотите изменить? введите номер пункта: \n"
								<< "Выбранная вами картина:\n\n"

								<< "1. ID: " << temp_id << ";\n"
								<< "2. Название: " << temp_name << ";\n"
								<< "3. Авор: " << temp_author << ";\n"
								<< "4. Год: " << temp_year << ";\n"
								<< "5. Жанр: " << temp_genre << ";\n"
								<< "6. Вид: " << temp_type << ";\n"
								<< "7. Направление: " << temp_direction << ";\n"
								<< "8. Цена: " << temp_price << ";\n"
								<< "9. Владелец: " << temp_owner << ";\n"
								<< "0. Завершить изменение.\n\n"

								<< ">>> "; cin >> answer;

							switch (answer)
							{
							case 1:
								cout << "Введите ID: "; 
								cin >> temp_id;
							
								system("cls");
								break;
							case 2:
								cout << "Введите название: ";
								cin >> temp_name;
							
								system("cls");
								break;
							case 3:
								cout << "Введите автора: ";
								cin >> temp_author;
							
								system("cls");
								break;
							case 4:
								cout << "Введите год: ";
								cin >> temp_year;
							
								system("cls");
								break;
							case 5:
								cout << "Введите жанр: ";
								cin >> temp_genre;
								
								system("cls");
								break;
							case 6:
								cout << "Введите вид: ";
								cin >> temp_type;
						
								system("cls");
								break;
							case 7:
								cout << "Введите направление: ";
								cin >> temp_direction;

								system("cls");
								break;
							case 8:
								cout << "Введите цену: ";
								cin >> temp_price;
						
								system("cls");
								break;
							case 9:
								cout << "Введите место положения: ";
								cin >> temp_owner;
								
								system("cls");
								break;
							}
						}

						record << temp_id << endl;
						record << temp_name << endl;
						record << temp_author << endl;
						record << temp_year << endl;
						record << temp_genre << endl;
						record << temp_type << endl;
						record << temp_direction << endl;
						record << temp_price << endl;
						if (i < n - 1)
							record << temp_owner << endl;
						else record << temp_owner;
					}
				}
				cout << "Данные изменены." << endl;
			}
			else
				cout << "Номер введён не верно." << endl;
		}
		else
			cout << "Ошибка открытия файла." << endl;
	}
	else 
		cout << "ошибка открытия буфера." << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy() {

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			int _id;
			string _name;
			string _author;
			int _year;
			string _genre;
			string _type;
			string _direction;
			int _price;
			string _owner;

			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _id;
				reading >> _name;
				reading >> _author;
				reading >> _year;
				reading >> _genre;
				reading >> _type;
				reading >> _direction;
				reading >> _price;
				reading >> _owner;

				record << _id << endl;
				record << _name << endl;
				record << _author << endl;
				record << _year << endl;
				record << _genre << endl;
				record << _type << endl;
				record << _direction << endl;
				record << _price << endl;
				if (i < n - 1)
					record << _owner << endl;
				else record << _owner;
			}
		}
		else
			cout << "Ошибка открытия файла." << endl;
	}
	else
		cout << "Ошибка открытия буфера." << endl;

	reading.close();
	record.close();
}

void DeleteData() {
	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			int _id;
			string _name;
			string _author;
			int _year;
			string _genre;
			string _type;
			string _direction;
			int _price;
			string _owner;

			int n, _n;

			reading >> n;
			int b = n - 1;

			cout << "Введите номер картины, который вы желаете удалить (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n) {
				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _id;
						reading >> _name;
						reading >> _author;
						reading >> _year;
						reading >> _genre;
						reading >> _type;
						reading >> _direction;
						reading >> _price;
						reading >> _owner;

						record << _id << endl;
						record << _name << endl;
						record << _author << endl;
						record << _year << endl;
						record << _genre << endl;
						record << _type << endl;
						record << _direction << endl;
						record << _price << endl;
						if (i < n - 1)
							record << _owner << endl;
						else record << _owner;
					}
					else {
						reading >> _id;
						reading >> _name;
						reading >> _author;
						reading >> _year;
						reading >> _genre;
						reading >> _type;
						reading >> _direction;
						reading >> _price;
						reading >> _owner;
					}
				}
				cout << "Данные удалены." << endl;
			}
			else
				cout << "Номер введён неверно." << endl;
		}
		else
			cout << "Ошибка открытия файла." << endl;
	}
	else
		cout << "Ошибка открытия буфера." << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void AddData() {
	int _id;
	string _name;
	string _author;
	int _year;
	string _genre;
	string _type;
	string _direction;
	int _price;
	string _owner;

	int n = AmountOfData() + 1;

	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_)
		record_ << n << endl;
	else
		cout << "Ошибка открытия буфера." << endl;

	if (record) {
		record << endl;

		cout << "Введите ID картины: ";
		cin >> _id;
		record << _id << endl;

		cout << "Введите название катины: ";
		cin >> _name;
		record << _name << endl;

		cout << "Введите имя автора: ";
		cin >> _author;
		record << _author << endl;

		cout << "Введите год: ";
		cin >> _year;
		record << _year << endl;

		cout << "Введите жанр: ";
		cin >> _genre;
		record << _genre << endl;

		cout << "Введите вид: ";
		cin >> _type;
		record << _type << endl;

		cout << "Введите направление: ";
		cin >> _direction;
		record << _direction << endl;

		cout << "Введите цену: ";
		cin >> _price;
		record << _price << endl;

		cout << "Введите место положения: ";
		cin >> _owner;
		record << _owner << endl;
	}
	else
		cout << "Ошибка открытия файла." << endl;

	record.close();
	record_.close();
}

int AmountOfData() {
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf)
		_buf >> n;
	else cout << "Ошибка открытия буфера." << endl;

	_buf.close();

	return n;
}

void SaveData(string fileName) {
	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading) {
		if (record) {
			int _id;
			string _name;
			string _author;
			int _year;
			string _genre;
			string _type;
			string _direction;
			int _price;
			string _owner;

			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _id;
				reading >> _name;
				reading >> _author;
				reading >> _year;
				reading >> _genre;
				reading >> _type;
				reading >> _direction;
				reading >> _price;
				reading >> _owner;

				record << _id << endl;
				record << _name << endl;
				record << _author << endl;
				record << _year << endl;
				record << _genre << endl;
				record << _type << endl;
				record << _direction << endl;
				record << _price << endl;
				if (i < n - 1)
					record << _owner << endl;
				else record << _owner;
			}
			cout << "Данные сохранены в файл " << fileName << "." << endl;
		}
		else
			cout << "Ошибка открытия буфера." << endl;
	}
	else
		cout << "Ошибка открытия файла." << endl;

	record.close();
	reading.close();
}

bool DataCleaning() {
	bool clear = false;

	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
		cout << "Ошибка открытия буфера." << endl;

	_buf.clear();

	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}