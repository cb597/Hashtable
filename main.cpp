#include "Hashtable.h"
#include <iostream>

int main()
{

	// some test code for Hashtable
	Hashtable<double> my_hashtable(10);

	// fill some elements
	for (int i = 0; i < 42*2; ++i)
	{
		my_hashtable.insert(i, i / 42.);
	}

	// demo "get"
	std::cout << my_hashtable.get(40) << std::endl;

	// demo "remove"
	my_hashtable.remove(40);


	return 0;
}