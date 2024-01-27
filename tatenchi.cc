#include <unistd.h>
#include <sysexits.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

[[noreturn]] void usage();

int
main(int argc, char *argv[])
{
	const char *fs = "[[:space:]]+";

	int c;
	while ((c = getopt(argc, argv, "F:")) != -1)
		switch (c) {
		case 'F':
			fs = optarg;
			break;
		case '?':
		default:
			usage();
		}

	std::regex fs_re(fs);

	std::vector<std::vector<std::string>> table;
	std::size_t maxCol = 0;
	std::string line;
	while (std::getline(std::cin, line)) {
		table.push_back({});

		auto itr = std::sregex_token_iterator(line.begin(), line.end(), fs_re, -1);
		auto end = std::sregex_token_iterator();
		std::size_t curCol = 0;
		for (; itr != end; curCol++, itr++)
			table.back().push_back(*itr);
		maxCol = std::max(maxCol, curCol);
	}

	for (std::size_t i = 0; i < maxCol; i++) {
		for (std::size_t j = 0; j < table.size(); j++) {
			if (table[j].size() > i)
				std::cout << table[j][i];
			if (j + 1 != table.size())
				std::cout << "\t";
		}
		std::cout << std::endl;
	}

	return 0;
}

[[noreturn]] void
usage()
{
	std::clog << "usage: tatenchi [-F pattern]" << std::endl;
	std::exit(EX_USAGE);
}
