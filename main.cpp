#include "pch.h"
#include <boost/shared_ptr.hpp>
#include <boost/program_options.hpp>

namespace po = boost::program_options;
po::options_description desc("Allowed options");

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	Trie trie;

	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help message")
		("book", po::value<std::string>(), "book to load")
		("directory,d", po::value<std::string>(), "directory to load")
		("search", po::value<std::string>(), "word to search for");
		//flaga save

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if (vm.count("help")) 
	{
		std::cout << desc << "\n";
		return 1;
	}

	if (vm.count("book")) 
	{
		trie.loadBook();
	}

	if (vm.count("directory")) 
	{
		//std::cout << "Directory set to: " << vm["directory, dir"].as<std::string>() << std::endl;
		fs::path dir_path = vm["directory"].as<std::string>();
		trie.setPath(dir_path);
	}

	if (vm.count("search"))
	{
		//std::cout << "Searching for: " << vm["search"].as<std::string>() << std::endl;
		std::string searched = vm["search"].as<std::string>();
		if (trie.searchKey(searched) == true) { trie.searchAndDisplay(searched); }
		else
		{
			std::cout << "Not Exists";
		}
	}

	if (vm.empty())
	{
		std::cout << "No options specified. Exiting..." << std::endl;
		return 1;
	}

	//try {
	//	Trie trie;
	//	trie.setPath("invalid_path"); // Test with an invalid path
	//}
	//catch (const std::exception& e) {
	//	std::cerr << "Unhandled exception: " << e.what() << std::endl;
	//}

	return RUN_ALL_TESTS();
}

