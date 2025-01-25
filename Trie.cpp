#include "pch.h"

TrieNode::TrieNode() : isWordEnd(false)
{
	
}

Trie::Trie() : root(std::make_shared<TrieNode>())
{
	directory_path = fs::current_path();
}

Trie::~Trie()
{

}

void Trie::loadBook()
{
	std::cout << "Loading book..." << std::endl;
	openFile();
}

void Trie::searchAndDisplay(const std::string& searched)
{
	std::cout << "Called";
	/*std::shared_ptr<TrieNode> current = root;
	int words_to_display = 0;
	if (current->children[searched])
	{
		while (words_to_display < 5)
		{
			std::cout << current->children.;
			current = current->children[word];
			words_to_display++;
		}
	}*/
}

bool Trie::searchKey(const std::string& key)
{
	std::cout << "Search if exists " << key << std::endl;
	std::shared_ptr<TrieNode> current = root;

	std::stringstream ss(key);
	std::string word;

	while (ss >> word)
	{
		if (current->children.find(word) == current->children.end()) 
		{
			std::cout << "not exist";
			return false;
		}
		current = current->children[word];
	}

	std::cout << "Exists " << current->isWordEnd << std::endl;
	return current->isWordEnd;
}

void Trie::setPath(fs::path path)
{
	try {
		directory_path = path;
		if (fs::exists(directory_path))// && fs::is_regular_file(directory_path)
		{
			std::cout << "Path correctly set to: " << directory_path << std::endl;//podwojne backslashe zeby w fstream ze stringiem zadzialalo
			openFile();//wczyta a na run bedzie czekal na slowa i search and display
		}
		else
		{
			throw std::runtime_error(directory_path.generic_string() + " does not exist");
		}
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		std::cout << "Path or file does not exist. Try providing a valid path." << std::endl;
	}
	
}

void Trie::insertWord(const std::string& sentence)
{
	//dodawanie slowa do drzewa
	//na koniec drzewo jest zapisywane do pliku
	std::cout << "Loading text data..." << std::endl;
	std::shared_ptr<TrieNode> current = root;
	std::stringstream ss(sentence);
	std::string word;
	while (ss >> word) 
	{
		std::cout << "Processing word: " << word << std::endl;
		if (current->children.find(word) == current->children.end()) 
		{
			current->children[word] = std::make_shared<TrieNode>();
		}
		current = current->children[word];
	}

	current->isWordEnd = true;
	std::cout << "Text data loaded" << std::endl;
}

void Trie::openFile()
{
	std::cout << "Opening file..." << std::endl;
	std::ifstream file(directory_path.string());
	if (!file.is_open())
	{
		throw std::runtime_error("File not found");//throw ?
	}
	std::cout << "File opened successfully." << std::endl;
	std::string sentence;
	int word_counter = 0;
	while (std::getline(file, sentence, '.'))//bierz sentencje do kropki i dopiero w insercie dzieli na slowa ?
	{
		std::cout << "Processing line: " << sentence << std::endl;
		insertWord(sentence);
		word_counter++;
	}

	std::cout << "Total number of sentences loaded: " << word_counter << std::endl;
}


