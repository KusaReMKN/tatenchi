#
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

/**
 * 入力の要件:
 *
 *      foo_1   bar_1
 *      foo_2   bar_2
 *        :       :
 *        :       :
 */

int
main(int argc, char *argv[])
{
	std::vector<std::string> foo, bar;

	bool isfoo = true;
	std::string t;
	while (std::cin >> t) {
		(isfoo ? foo : bar).push_back(t);
		isfoo = !isfoo;
	}

	std::copy(foo.cbegin(), foo.cend(),
			std::ostream_iterator<std::string>(std::cout, "\t"));
	std::cout << std::endl;
	std::copy(bar.cbegin(), bar.cend(),
			std::ostream_iterator<std::string>(std::cout, "\t"));
	std::cout << std::endl;

	return 0;
}
