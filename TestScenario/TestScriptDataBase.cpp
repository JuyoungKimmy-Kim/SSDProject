#include "TestScriptDataBase.h"
#include "TestScript.h" //todo: split to TestScript Factory
#include "../TestShellApp/IScenario.h"


TestScriptDataBase::TestScriptDataBase() {
	IScenario* tscObj = nullptr;
	tscObj = new TestScriptReadAndCompare;
	tscObj->setName("ReadAndCompare");
	m_TestScriptDB.push_back(tscObj);
}


TestScriptDataBase& TestScriptDataBase::getInstance() {
	static TestScriptDataBase testScriptDBInsatnce;
	return testScriptDBInsatnce;
}

IScenario* TestScriptDataBase::GetTestScriptCase(string TestScriptName) {
	for (IScenario* testScriptCasetIter : m_TestScriptDB) {
		if (testScriptCasetIter->getName() == TestScriptName) {
			return testScriptCasetIter;
		}
	}
	return nullptr;
}

vector<string> TestScriptDataBase::getScenarioList() {
	vector<string> retStrVector;
	for (IScenario* testScriptCasetIter : m_TestScriptDB) {
		retStrVector.push_back(testScriptCasetIter->getName());
	}
	return retStrVector;
}

