#include"Header.h"

void DataInitialization() {
	ofstream _buf("Buffer.txt");

	if (!_buf)
		cout << "������ �������� ��������� �����\n";

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

	cout << "������� ���������� ������: ";
	cin >> n;

	ofstream record("Buffer.txt", ios::app);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {

			cout << "������� ID �������: ";
			cin >> _id;
			record << "ID: " << _id << endl;

			cout << "������� �������� ������: ";
			cin >> _name;
			record << _name << endl;

			cout << "������� ��� ������: ";
			cin >> _author;
			record << _author << endl;

			cout << "������� ���: ";
			cin >> _year;
			record << _year << endl;

			cout << "������� ����: ";
			cin >> _genre;
			record << _genre << endl;

			cout << "������� ���: ";
			cin >> _type;
			record << _type << endl;

			cout << "������� �����������: ";
			cin >> _direction;
			record << _direction << endl;

			cout << "������� ����: ";
			cin >> _price;
			record << _price << endl;

			cout << "������� ��������������: ";
			cin >> _owner;
			record << _owner << endl;
		}
	}
	else
		cout << "������ �������� �����.\n";
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
			cout << "������ ������� � �����." << endl;
		}
		else
			cout << "������ �������� ������." << endl;
	}
	else
		cout << "������ �������� �����." << endl;

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
		cout << "���������� ������: " << n << "\n\n";

		cout << "|" << setw(5) << "�����" << "|" << setw(2) << "ID" << "|" << setw(30) << "��������" << "|" << setw(16) << "�����" << "|" << setw(4) << "���" << "|" << setw(11) << "����" << "|" << setw(8) << "���" << "|" << setw(11) << "�����������" << "|" << setw(10) << "����" << "|" << setw(27) << "����� ���������" << "|" << endl;

		for (int i = 0; i < n; i++) {
			//cout << "������� �" << i + 1 << endl;

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
			//cout << "��������: " << _name << endl;
			//cout << "�����: " << _author << endl;
			//cout << "���: " << _year << endl;
			//cout << "����: " << _genre << endl;
			//cout << "���: " << _type << endl;
			//cout << "�����������: " << _direction << endl;
			//cout << "����: " << _price << endl;
			//cout << "��������: " << _owner << endl;
			//cout << endl;
		}
		cout << endl;
	}
	else
		cout << "������ �������� �����." << endl;

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

			cout << "�������� ������� ������ ������� �� ������ ��������(�� 1 �� " << n << "): ";
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

							cout << "��� �� ������ ��������? ������� ����� ������: \n"
								<< "��������� ���� �������:\n\n"

								<< "1. ID: " << temp_id << ";\n"
								<< "2. ��������: " << temp_name << ";\n"
								<< "3. ����: " << temp_author << ";\n"
								<< "4. ���: " << temp_year << ";\n"
								<< "5. ����: " << temp_genre << ";\n"
								<< "6. ���: " << temp_type << ";\n"
								<< "7. �����������: " << temp_direction << ";\n"
								<< "8. ����: " << temp_price << ";\n"
								<< "9. ��������: " << temp_owner << ";\n"
								<< "0. ��������� ���������.\n\n"

								<< ">>> "; cin >> answer;

							switch (answer)
							{
							case 1:
								cout << "������� ID: "; 
								cin >> temp_id;
							
								system("cls");
								break;
							case 2:
								cout << "������� ��������: ";
								cin >> temp_name;
							
								system("cls");
								break;
							case 3:
								cout << "������� ������: ";
								cin >> temp_author;
							
								system("cls");
								break;
							case 4:
								cout << "������� ���: ";
								cin >> temp_year;
							
								system("cls");
								break;
							case 5:
								cout << "������� ����: ";
								cin >> temp_genre;
								
								system("cls");
								break;
							case 6:
								cout << "������� ���: ";
								cin >> temp_type;
						
								system("cls");
								break;
							case 7:
								cout << "������� �����������: ";
								cin >> temp_direction;

								system("cls");
								break;
							case 8:
								cout << "������� ����: ";
								cin >> temp_price;
						
								system("cls");
								break;
							case 9:
								cout << "������� ����� ���������: ";
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
				cout << "������ ��������." << endl;
			}
			else
				cout << "����� ����� �� �����." << endl;
		}
		else
			cout << "������ �������� �����." << endl;
	}
	else 
		cout << "������ �������� ������." << endl;

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
			cout << "������ �������� �����." << endl;
	}
	else
		cout << "������ �������� ������." << endl;

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

			cout << "������� ����� �������, ������� �� ������� ������� (�� 1 �� " << n << "): ";
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
				cout << "������ �������." << endl;
			}
			else
				cout << "����� ����� �������." << endl;
		}
		else
			cout << "������ �������� �����." << endl;
	}
	else
		cout << "������ �������� ������." << endl;

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
		cout << "������ �������� ������." << endl;

	if (record) {
		record << endl;

		cout << "������� ID �������: ";
		cin >> _id;
		record << _id << endl;

		cout << "������� �������� ������: ";
		cin >> _name;
		record << _name << endl;

		cout << "������� ��� ������: ";
		cin >> _author;
		record << _author << endl;

		cout << "������� ���: ";
		cin >> _year;
		record << _year << endl;

		cout << "������� ����: ";
		cin >> _genre;
		record << _genre << endl;

		cout << "������� ���: ";
		cin >> _type;
		record << _type << endl;

		cout << "������� �����������: ";
		cin >> _direction;
		record << _direction << endl;

		cout << "������� ����: ";
		cin >> _price;
		record << _price << endl;

		cout << "������� ����� ���������: ";
		cin >> _owner;
		record << _owner << endl;
	}
	else
		cout << "������ �������� �����." << endl;

	record.close();
	record_.close();
}

int AmountOfData() {
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf)
		_buf >> n;
	else cout << "������ �������� ������." << endl;

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
			cout << "������ ��������� � ���� " << fileName << "." << endl;
		}
		else
			cout << "������ �������� ������." << endl;
	}
	else
		cout << "������ �������� �����." << endl;

	record.close();
	reading.close();
}

bool DataCleaning() {
	bool clear = false;

	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
		cout << "������ �������� ������." << endl;

	_buf.clear();

	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}