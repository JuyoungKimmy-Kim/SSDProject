#pragma once

#include <iostream>
#include <string>
using namespace std;

class SSDDevice {
public:
    void read(const int address) {
        cout << "Reading from LBA: " << address << endl;
        // ���� �б� �۾� ����
    }

    void write(const int address, const string& data) {
        cout << "Writing data to LBA: " << address << endl;
        // ���� ���� �۾� ����
    }
};