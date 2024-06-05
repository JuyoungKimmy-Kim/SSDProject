#pragma once
#include <vector>
#include <string>

using namespace std;

const string DATA_DIR = "./Result";
const string NAND_FILE = DATA_DIR + "/nand.txt";
const string RESULT_FILE = DATA_DIR + "/result.txt";
const string DEFAULT_DATA = "0x00000000";
const int START_LBA = 0;
const int END_LBA = 100;

class FileManager{
public:
	static FileManager& getInstance()
	{
		static FileManager instance{};
		return instance;
	}
	void setFilePath();
	vector<string> readFromNand();
	void writeToNand(vector<string> dataBuf);
	void writeToResult(string data);


private:
	FileManager() {}
	vector<string> Files = { NAND_FILE , RESULT_FILE };

	void getNandData(ifstream& file, vector<string>& ret);
	void createOutputFiles();
};