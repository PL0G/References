#include <iostream>
template <typename T>
void pswap(T* p1, T* p2){
	T tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
template <typename T>
void ref_swap(T& ref1,T& ref2){
	T tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}

int MX[10][2];

int& scnd_el(int index) {
	return MX[index][1];


}
int main() {
	setlocale(LC_ALL, "Russian");
	int n,m;


	//Ссылки на переменные
	
	int& refn=n;//Ссылка refn ассоциирующаяся с переменной n
	std::cout <<"refn = "<< refn << "\n";
	refn++;
	std::cout <<"refn = "<< refn << "\n";
	std::cout <<"n = "<< n << "\n";
	//Ссылки не могут быть обьявленны несвязанными с обьектом
	//Не имют аналога нейтрального указателя
	//Не существует операторов осуществляющих действие над самими ссылками
	//Так как ссылка - второе имя объекта
	//В стандарте с++ не описан механизм реализации ссылок
	// каждый компилятор делает это по-своему
	

	//Ссылки и функции
	
	n = 10; m = 15;
	std::cout << n << " " << m << " \n";
	//pswap(&n, &m);//Работает но неудобно, т.к. нужно передавать адреса
	ref_swap(n, m);
	std::cout << n << " " << m << " \n";
	

	//Задание "Параллельный массив"
	std::cout << "Заполнение массива.\n";
	for (int i = 0; i < 10; i++) {
		std::cout << "Введите значение " << i + 1 << " элемента ->";
		std::cin >> MX[i][0];
		scnd_el(i) = MX[i][0];
	}
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < 10; i++)
		std::cout << MX[i][0] << "\t" << scnd_el(i) << "\n";


	return 0;
}