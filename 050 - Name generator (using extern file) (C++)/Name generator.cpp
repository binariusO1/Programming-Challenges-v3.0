/*
2020-04-02 binariusO1
Programing challenge
Name generator
Generator using file from Medieval 2 Total War - descr_names.txt
*/

#include <iostream>
#include <fstream>	//fstream
#include <string>
#include <time.h>	//time, srand
#include <vector>

using namespace std;

bool counter(string& line, const char* name);
int generator(vector<pair <int, int> >& vec );
void pre_read(vector<pair <int, int> >& vec1 , vector<pair <int, int> >& vec2, vector<pair <int, int> >& vec3 , string & filename);

void read_line(int line, string & fl);

int main()
{
	cout << "Name generator basic on Medieval 2 Total War file descr_names.txt\n";

	//<begin,end>
	vector<pair <int, int> > v_name;
	vector<pair <int, int> > v_wname;
	vector<pair <int, int> > v_surname;

	string filename = "descr_names.txt";

	pre_read(v_name, v_wname, v_surname, filename);

	while (1)
	{
		char m = NULL;
		cout << "-------------------\n";
		cout << "\nMALE/FEMALE [m/f] ?\n";

		while (m != 'm' && m != 'f') {
			cin >> m;
			if (m == 'x') break;
		}
		if (m == 'x') break;
		if (m == 'm') {
			read_line(generator(v_name), filename);
		}
		else {
			read_line(generator(v_wname), filename);
		}
		cout << " ";
		read_line(generator(v_surname), filename);

		cout << "\n\npress x to close...\n";

	}
}
void pre_read(vector<pair <int, int> >& v_name, vector<pair <int, int> >& v_wname, vector<pair <int, int> >& v_surname, string& filename)
{
	ifstream file(filename);

	string line;
	int line_number = 1;

	//get positions
	bool wm = false;
	bool nm = false;
	bool sr = false;

	while (!file.eof())
	{
		getline(file, line);
		if (counter(line, "characters")) {
			v_name.push_back(make_pair(line_number + 1, 0));
			nm = true;
		}
		if (counter(line, "surnames")) {
			v_surname.push_back(make_pair(line_number + 1, 0));
			v_name[v_name.size() - 1].second = (line_number - 2);
			sr = true;
			nm = false;
		}
		if (counter(line, "women"))
		{
			v_wname.push_back(make_pair(line_number + 1, 0));
			if (sr == true) {
				v_surname[v_surname.size() - 1].second = (line_number - 2);
				sr = false;
			}
			wm = true;
			if (nm == true) {
				v_name[v_name.size() - 1].second = (line_number - 2);
				nm = false;
			}

		}
		else if (line.size() <= 1 && wm == true) {
			v_wname[v_wname.size() - 1].second = (line_number);
			wm = false;
		}
		line_number++;
	}
	file.close();
}
bool counter(string& line,const char * name)
{
	if (line.size() >= strlen(name)) {
		string* ptr = new string(line, 1, strlen(name));
		string* ptr2 = new string(name);
		if (*ptr == *ptr2) {
			delete ptr, ptr2;
			return 1;
		}
	}
	return 0;
}

int generator(vector<pair <int, int> >& vec)
{
	/* initialize random seed: */
	srand(time(NULL));
	int * rand_0 = new int(rand() % vec.size() + 0);
	int * temp = new int (vec[*rand_0].second - vec[*rand_0].first);
	int * rand_vec = new int ( rand() % *temp + vec[*rand_0].first);
	return *rand_vec;
	delete rand_0, temp, rand_vec;
}

void read_line(int line, string & fl)
{
	fstream file(fl);
	string* text = new string;
	int* nmb = new int(0);
	while (!file.eof())
	{
		getline(file, *text);
		if (*nmb == line) {
			string* temp = new string;
			for (auto i = 0; i < (*text).size(); i++)
			{
				if ((*text)[i] != '\t' && (*text)[i] != ' ') {
					if((*text)[i] == '_' ) *temp += ' ';
					else  *temp += (*text)[i];
				}
			}
			cout << *temp;;
			delete temp;
			break;
		}
		(*nmb)++;
	}
	file.close();
	delete nmb, text;
}
