#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class day {
	string stud[15];
	string pres[30];
	int cnt;
public:
	day(){ cnt = 0; }
	~day(){
        cout<<"Вызван деструктор"<<endl;
    }
	void load(string fname);
	void show();
	void write();
	void add(string n, string pr);
};
void day::load(string fname){
	int i = 0;
	ifstream fin("2019_09_13.csv");
	string str;
	string pr;
if (!fin.is_open()){
    cout << "Файл не может быть открыт"<<endl; 
}
else if(!str.find(fname) != 0)
	cout<<"Обучающийся не найден"<<endl;
else
	while (!fin.eof() && str.find(fname) != 0)
		getline(fin, str);
	while (str[i] != ',')
		i++;
		pr = str[i + 1];
		add(fname, pr);
}
void day::show(){
	int i = 0;
while (i != cnt){
	cout<<stud[i]<<' '<<pres[i]<<endl;
	i++;
}
}
void day::write(){
	ofstream fout("Tabel.txt");
    fout << stud << pres <<endl;
    fout.close();
    system("pause");
}
void day::add(string n, string pr){
	stud[cnt] = n;
	pres[cnt] = pr;
	cnt++;
}
int main(){
	string name;
	cout << "Введите фамилию обучающегося" << endl;
	cin >> name;
day a;
a.load(name);
a.show();
a.write();
}