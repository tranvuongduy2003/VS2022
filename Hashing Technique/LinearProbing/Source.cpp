#include <iostream>
using namespace std;
#define SIZE 10

int Hash(int key)
{
	return key % 10;
}

int Probe(int HT[], int key)
{
	int index = Hash(key);
	int i = 0;
	while (HT[(index + i) % SIZE] != 0)
		i++;
	return (index + i) % SIZE;
}


void Insert(int HT[], int key)
{
	int index = Hash(key);

	if (HT[index] != 0)
		index = Probe(HT, key);
	
	HT[index] = key;
}

int Search(int HT[], int key)
{
	int index = Hash(key);

	int i = 0;

	while (HT[(index + i) % SIZE] != key)
		i++;

	return (index + i) % SIZE;
}

int main()
{
	int HT[10]{ 0 };

	return 0;
}