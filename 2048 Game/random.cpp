/* 
* @Author: yannherklotz
* @Date:   2016-02-01 17:47:47
* @Last Modified by:   yannherklotz
* @Last Modified time: 2016-02-04 15:08:05
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	srand(time(NULL));
	cout << rand() % 1000 << endl;
	cout << rand() % 1000 << endl;
	cout << rand() % 1000 << endl;
	cout << rand() % 1000 << endl;
	cout << rand() % 1000 << endl;
	cout << rand() % 1000 << endl;
	cout << rand() % 1000 << endl;
    return 0;
}