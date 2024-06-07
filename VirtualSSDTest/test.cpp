#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/DataBuffer.cpp"
#include "../Project1/ReadCommand.cpp"
#include "../Project1/WriteCommand.cpp"
#include "../Project1/FileManager.cpp"
#include "../Project1/NANDDevice.cpp"
#include "../Project1/Invoker.h"

using namespace std;
using namespace testing;

class DataBufferFixture : public testing::Test
{
public:
	DataBuffer& dataBuffer = DataBuffer::getInstance();
};

class MockNANDDevice : public NANDDevice {
public:
	MOCK_METHOD(void, read, (const int address), (override));
	MOCK_METHOD(void, write, (const int address, const string& data), (override));
};

class CommandTestFixture : public testing::Test {
public:
	MockNANDDevice mockDevice;
	const int address = 7;
	const string data = "0x12345678";
};

class FileManagerFixture : public testing::Test {
public:
	FileManager& fileManager = FileManager::getInstance();
	
	void initData()
	{
		fileManager.setFilePath();
	}
};
class CommandFixture : public testing::Test {
public:
	NANDDevice device;
	Invoker invoker;
};

TEST_F(CommandTestFixture, Read) {
	EXPECT_CALL(mockDevice, read)
		.Times(1);

	ReadCommand readCmd(&mockDevice, address);
	readCmd.execute();
}

TEST_F(CommandTestFixture, Write) {
	EXPECT_CALL(mockDevice, write)
		.Times(1);

	WriteCommand writeCmd(&mockDevice, address, data);
	writeCmd.execute();
}


TEST_F(FileManagerFixture, WriteNandAndResult) {
	initData();

	int addr = 1;
	vector<string> ret =  fileManager.readFromNand();
	ret[addr] = "0x22222222";
	fileManager.writeToNand(ret);

	vector<string> ret2 = fileManager.readFromNand();
	fileManager.writeToResult(ret2[addr]);

	EXPECT_EQ(ret2, ret);
}

TEST_F(FileManagerFixture, WriteBufferData) {
	initData();

	int addr = 4;
	string data = "0x44422222";
	
	//vector<string> nandRet = fileManager.readFromNand();
	string ret = "";

	fileManager.writeBufferData(addr, data);
	bool result = fileManager.readBufferData(addr, ret);

	EXPECT_EQ(data, ret);
}



