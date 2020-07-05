#include <iostream>
#include <fstream>

using namespace std;

struct Note
{
	string film;
	int time_sec;
};

Note* read(const string& file, int& n)
{
	Note* notes = new Note[20];
	int index = 0;
	ifstream f(file);
	while (!f.eof())
	{
		f >> notes[index].film;
		f >> notes[index].time_sec;
		index++;
	}
	f.close();
	n = index;
	return notes;
}

void write(Note* notes, const string& file, int n)
{
	ofstream f(file);
	for (int i = 0; i < n; ++i)
	{
		f << notes[i].film << " " << notes[i].time_sec << "\n";
	}
	f.close();
}

void print_one(Note* note)
{
	cout << note->film << " в " << note->time_sec / 3600 << ":" << note->time_sec % 60 << "\n";
}

void print(Note* notes, int n)
{
	for (int i = 0; i < n; ++i)
	{
		print_one(&notes[i]);
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	int count;
	Note* notes = read("notes.txt", count);

	print(notes, count);

	string name;
	int time;

	cout << "Введите название нового фильма: ";
	cin >> name;

	int t;
	cout << "Введите время сеанса (ч м): ";
	cin >> t;
	time = t * 3600;
	cin >> t;
	time += t;


	notes[count].film = name;
	notes[count].time_sec = time;
	count++;

	cout << "Введённый сеанс: \n";
	print_one(&notes[count - 1]);

	write(notes, "notes.txt", count);

	system("pause");
}
