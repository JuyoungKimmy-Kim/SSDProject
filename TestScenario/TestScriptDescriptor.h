
//TODO: split Test script descriptoer on every TestScript

//ReadAndCompare descriptor
//#include "TestScriptDescriptor_ReadAndCompare.h"
#include <iostream>

using std::cout;

TEST_SCRIPT_DESC_STRAT(ReadAndCompare)
TEST_SCRIPT_DESC_COMMAND("read 3 0x33333333")
TEST_SCRIPT_DESC_COMMAND("write 5 0x55555555")
TEST_SCRIPT_DESC_COMMAND("read 5")
TEST_SCRIPT_DESC_RUN({ cout << "ReadAndCompare\n"; })
TEST_SCRIPT_DESC_END()

TEST_SCRIPT_DESC_STRAT(testapp1)
TEST_SCRIPT_DESC_COMMAND("fullread")
TEST_SCRIPT_DESC_RUN({ cout << "testapp1\n"; })
TEST_SCRIPT_DESC_END()

#undef TEST_SCRIPT_DESC_STRAT
#undef TEST_SCRIPT_DESC_COMMAND
#undef TEST_SCRIPT_DESC_RUN
#undef TEST_SCRIPT_DESC_END