#include <map>
#include <vector>
#include <memory>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace fs = std::filesystem;

struct TrieNode
{
	std::map<std::string, std::shared_ptr<TrieNode>> children;
	std::vector<std::string> words;
	bool isWordEnd;
	TrieNode();
};

class Trie
{
public:
	Trie();
	~Trie();

	void loadBook();//uruchamia petle ktora bedzie wczytywac drzewo z pliku//uruchomi plik z dysku i wczyta do ramu
	void setPath(fs::path);
	void searchAndDisplay(const std::string&);//wyszukuje slowo w drzewie i wyswietla na konsole (5 najbli¿szych)
	bool searchKey(const std::string&);

private:
	void insertWord(const std::string&);
	void openFile();
	std::shared_ptr<TrieNode> root;
	fs::path directory_path;
};



