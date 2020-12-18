#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

void DataInitialization();
void DataEntry();
void DataReading(string filename);
void Print();
bool DataCleaning();
void DataChange();
void Copy();
int AmountOfData();
void DeleteData();
void AddData();
void SaveData(string fileName);