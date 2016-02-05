#include <iostream>
#include <string>
#include "KeyValueStore.h"

int main() {
	KeyValueStore<int> store;
	int a = 16;
	int b = 17;
	int c = 18;
	int* value = &a;
	int* val1 = &b;
	int* val2 = &c;
	
	store.Store(value, sizeof(value));
	int* retValue = store.Load(1314514469);
	cout << *retValue << endl;

	store.Store(val1, sizeof(val1));
	retValue = store.Load(4264404756);
	cout << *retValue << endl;
	store.Store(val2, sizeof(val2));
	retValue = store.Load(4004668487);
	cout << *retValue << endl;

	retValue = store.Load(1314514469);
	cout << *retValue << endl;

	retValue = store.Load(4264404756);
	cout << *retValue << endl;
	retValue = store.Load(4004668487);
	cout << *retValue << endl;
	
	store.Erase(4004668487);
	
	retValue = store.Load(4264404756);
	cout << *retValue << endl;

	cout << "new shitsss" << endl;
	store.Store(val2, sizeof(val2));
	try {
		bool resu = retValue = store.Load(4004668480);
	}
	catch (exception& e) {
		cout << "Load result" << e.what() << endl;
	}
	
	cout << *retValue << endl;
	//std::cout << store.Load(std::string("test"));
	/*store.write(4, 4, 200);*/
	/*int* retValue = store.Load(1314514469);
	cout << *retValue << endl;*/
	system("PAUSE");
	return 0;
}