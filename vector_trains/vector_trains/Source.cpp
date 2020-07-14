#include <iostream>
#include <fstream>
#include "Railway.h"
#include "Train.h"
using namespace std;

int main()
{
	Railway ra;
	Train t1(123, 51, 20, 25, "wwwwww");
	Train t2(321, 4, 75, 65, "aaaaaa");
	Train t3(88888, 9, 20, 45, "ssdsd");
	Train t4(879879, 2, 10, 63, "zxczxczxc");
	ra.Add_train(t1);
	ra.Add_train(t2);
	ra.Add_train(t3);
	ra.Add_train(t4);

	ra.Information_about_all_train();

	ra.Sort_list_trains_by_time();

	ofstream fout("file.txt");

	fout << ra;

	fout.close();

	Railway ra2;
	ifstream ifs("file.txt");

	ifs >> ra2;

	ifs.close();

	cout << endl;
	cout << endl;
	ra2.Information_about_all_train();

	system("pause");
	return 0;
}