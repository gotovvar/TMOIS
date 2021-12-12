#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	vector <int> univ(35);        //заполнение универсума
	for (int i = 1; i <= 35; i++) {
		univ[i - 1] = i;
	}
	vector <int> a, b;
	
	int c;     //выбор способа задания мн-ва
	cout << "1) Метод перечисления" << endl << "2) Методом высказывания" << endl;
	cout << "Высказывания используемые для заполнения множеств:" << endl;
	cout << "Для А: x in N | x=k*2-1, где k изменяется от 1 до мощности множества А" << endl;
	cout << "Для В: y in N | y=r*3-1, где r изменяется от 1 до мощности множества В" << endl;
	cout << "Выберете способ задания множества - ";
	cin >> c;
	switch (c) {
	case 1: {
		int size1, size2;
		cout << "Введите мощность множества А" << endl;         //ввод мощности мн-ва А
		cin >> size1;
		if (size1 > 10) {
			cout << "Ошибка" << endl;
			return 0;
		}
		cout << "Введите элементы множества А" << endl;         //ввод элементов в мн-во А
		for (int i = 0; i < size1; i++) {
			int el1;
			cin >> el1;
			if (el1 > 30) {
				cout << "Ошибка" << endl;
				return 0;
			}
			a.push_back(el1);
		}
		cout << "Введите мощность множества В" << endl;    //ввод мощности мн-ва В
		cin >> size2;
		if (size2 > 10) {
			cout << "Ошибка" << endl;
			return 0;
		}
		cout << "Введите элементы множества В" << endl;    //ввод элементов в мн-во В
		for (int i = 0; i < size2; i++) {
			int el2;
			cin >> el2;
			if (el2 > 30) {
				cout << "Ошибка" << endl;
				return 0;
			}
			b.push_back(el2);
		}
		break;
	}

	case 2: {
		int size1, size2;
		cout << "Введите мощность множества А" << endl;   //ввод мощности мн-ва А
		cin >> size1;
		cout << "Введите мощность множества В" << endl;  //ввод мощности мн-ва В
		cin >> size2;
		if (size1 > 10 || size2 > 10) {
			cout << "Ошибка" << endl;
			return 0;
		}
		for (int k = 0; k <= size1; ++k) {        //заполнение мн-ва А элементами согласно высказыванию
			int x;
			x = k * 2 - 1;
			if (x >= 1 && x <= 30) {
				a.push_back(x);
			}
		}
		cout << "A={";                         //вывод мн-ва А на экран
		for (int i = 0; i < size1; i++) {
			cout << a[i];
			if (i != a.size() - 1) {
				cout << ",";
			}
		}
		cout << "}" << endl;
		for (int r = 0; r <= size2; ++r) {         //заполнение мн-ва В элементами согласно высказыванию
			int y;
			y = r * 3 - 1;
			if (y >= 1 && y <= 30) {
				b.push_back(y);
			}
		}
		cout << "B={";                          //вывод мн-ва В на экран
		for (int i = 0; i < size2; i++) {
			cout << b[i];
			if (i != b.size() - 1) {
				cout << ",";
			}
		}
		cout << "}";
		break;
	}
	default: {
		cout << "Ошибка" << endl;
		return 0;
	}
}

	cout << endl << "Выберете операцию которую хотите выполнить" << endl;        //выбор операции
	cout << "1) Операция объединения " << endl << "2) Операция пересечения" << endl << "3) Разность множеств А и В" << endl << "4) Разность мнеожеств В и А " << endl;
	cout << "5) Симметрическая разность" << endl << "6) Дополнение над множеством А" << endl << "7) Дополнение над множеством В" << endl << "8) Декартового произведения А и В" << endl;
	cout << "9) Декартового произведения В и А" << endl;
	cin >> c;
	switch (c) {
	case 1: {
		vector<int> c;                            // Создаем мн-во С которое будет результатом операции объеденения
		for (size_t i = 0; i < a.size(); i++)      // записываем элементы мн-ва А в мн-во С
		{
			c.push_back(a[i]);
		}
		for (size_t i = 0; i < b.size(); i++)  // выбираем 1, 2,..., el2 элемент В
		{
			if (find(a.begin(), a.end(), b[i]) == a.end())  // выбираем 1, 2,..., p2 элемент А, если выбранные элементы B встречается в А,
			{
				c.push_back(b[i]);                          // Выбранный элемент В записывается в С
			}
		}
		cout << "C={";                                     // Вывод мн-ва С
		for (size_t i = 0; i < c.size(); i++) 
		{
			cout << c[i];
			if (i != c.size() - 1)
			{
				cout << ',';
			}
		}
		cout << '}' << endl;

		break;
	}
	case 2: {
		vector<int> d;         // создаем мн-во D которое будет служить результатом операции пересечения
		for (size_t i = 0; i < a.size(); i++)     //выбираем 1, 2,..., el1 элемент A
		{
			if (find(a.begin(), a.end(), b[i]) != a.end())  //выбираем 1, 2,..., el2 элемент В, если выбранные элементы B встречается в А,то
			{ 
				d.push_back(b[i]);                           //выбранный элемент B записывается в D
			}
		}
		cout << "D={";                                  //вывод мн-ва D
		for (size_t i = 0; i < d.size(); i++) 
		{
			cout << d[i];
			if (i != d.size() - 1)
			{
				cout << ',';
			}
		}
		cout << '}' << endl;
		break;
	}
	case 3: {
		vector <int> e;                 // создаем мн-во Е которое будет служить результатом операции разности
		for (size_t i = 0; i < a.size(); i++) {                  //выбираем 1, 2,..., el1 элемент A
			if (find(b.begin(), b.end(), a[i]) == b.end()) {      //выбираем 1, 2,..., el2 элемент В, если выбранные элементы B не встречается в А,то
				e.push_back(a[i]);                                //выбранный элемент А записывается в Е
			} 
		}
		cout << "E={";             //вывод мн-ва Е
		for (size_t i = 0; i < e.size(); i++) {
			cout << e[i];
			if (i < e.size() - 1) {
				cout << ",";
			}
		}
		cout << "}";
		break;
	}
	case 4: {
		vector <int> f;                     // создаем мн-во F которое будет служить результатом операции разности
		for (size_t i = 0; i < b.size(); i++) {   //выбираем 1, 2,..., el1 элемент B
			if (find(a.begin(), a.end(), b[i]) == a.end()) {  //выбираем 1, 2,..., el2 элемент A, если выбранные элементы A не встречается в B,то
				f.push_back(b[i]);            //выбранный элемент B записывается в F
			}
		}
		cout << "F={";                  //вывод мн-ва F
		for (size_t i = 0; i < f.size(); i++) {
			cout << f[i];
			if (i < f.size() - 1) {
				cout << ",";
			}
		}
		cout << "}";
		break;
	}
	case 5: {
		vector <int> g;           // создаем мн-во G которое будет служить результатом операции симметрической разности
		for (size_t i = 0; i < a.size(); i++) {     //выбираем 1, 2,..., el1 элемент A
			if (find(b.begin(), b.end(), a[i]) == b.end()) {  //выбираем 1, 2,..., el2 элемент В, если выбранные элементы B не встречается в А,то
				g.push_back(a[i]);          //выбранный элемент А записывается в G
			}
		} 
		for (size_t i = 0; i < b.size(); i++) {      //выбираем 1, 2,..., el1 элемент B
			if (find(a.begin(), a.end(), b[i]) == a.end()) { //выбираем 1, 2,..., el2 элемент A, если выбранные элементы A не встречается в B,то
				g.push_back(b[i]);           //выбранный элемент B записывается в G
			}
		}
		cout << "G={";              //вывод мн-ва G
		for (size_t i = 0; i < g.size(); i++) {
			cout << g[i];
			if (i < g.size() - 1) {
				cout << ",";
			}
		}
		cout << "}";
		break;
	}
	case 6: {
		vector <int> h;    // создаем мн-во H которое будет служить результатом операции дополнения
		for (size_t i = 0; i < univ.size(); i++) {    //выбираем 1, 2,..., el1 элемент U
			if (find(a.begin(), a.end(), univ[i]) == a.end()) {   //выбираем 1, 2,..., el2 элемент A, если выбранные элементы A не встречается в U,то       
				h.push_back(univ[i]);      //выбранный элемент U записывается в H
			}
		}
		cout << "H={";       //вывод мн-ва H
		for (size_t i = 0; i < h.size(); i++) {
			cout << h[i];
			if (i < h.size() - 1) {
				cout << ",";
			}
		}
		cout << "}";
		break;

	}
	case 7: {
		vector <int> i;          // создаем мн-во I которое будет служить результатом операции дополнения
		for (size_t j = 0; j < univ.size(); j++) {  //выбираем 1, 2,..., el1 элемент U
			if (find(b.begin(), b.end(), univ[j]) == b.end()) {  //выбираем 1, 2,..., el2 элемент B, если выбранные элементы B не встречается в U,то       
				i.push_back(univ[j]);   //выбранный элемент U записывается в I
			}
		}
		cout << "I={";           //вывод мн-ва I
		for (size_t j = 0; j < i.size(); j++) {
			cout << i[j];
			if (j < i.size() - 1) {
				cout << ",";
			}
		}
		cout << "}";
		break;
	}
	case 8: {
		vector <pair<int, int>> j;  // создаем мн-во J которое будет служить результатом операции декартового произведения
		for (size_t i = 0; i < a.size(); i++) {     //выбираем 1, 2,..., el1 элемент A
			for (size_t k = 0; k < b.size(); k++) { //выбираем 1, 2,..., el2 элемент B      
				j.push_back(make_pair(a[i],b[k]));  //записываем элемент мн-ва А и элемент мн-ва В в кортеж и записываем кортеж в мн-во J
			}
		}
		cout << "J={";           //вывод мн-ва J
			for (size_t i = 0; i < j.size(); i++) {
				cout << '<' << j[i].first << ',' << j[i].second << '>';
				if (i != j.size() - 1) {
					cout << ",";
				}
			}
			cout << "}";
			break;

	}
	case 9: {
		vector <pair<int, int>> k;  // создаем мн-во K которое будет служить результатом операции декартового произведения
		for (size_t i = 0; i < b.size(); i++) {      //выбираем 1, 2,..., el1 элемент B
			for (size_t j = 0; j < a.size(); j++) {  //выбираем 1, 2,..., el1 элемент A
				k.push_back(make_pair(b[i], a[j])); //записываем элемент мн-ва B и элемент мн-ва A в кортеж и записываем кортеж в мн-во J
			}
		}
		cout << "K={";       //вывод мн-ва K
		for (size_t i = 0; i < k.size(); i++) {
			cout << '<' << k[i].first << ',' << k[i].second << '>';
			if (i != k.size() - 1) {
				cout << ",";
			}
		}
		cout << "}";
		break;

	}
	
	default: {
		cout << "Ошибка";
		return 0;
	}

	}

}