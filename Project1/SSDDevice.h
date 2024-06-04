#pragma once

#include <iostream>
#include <string>
using namespace std;

class SSDDevice {
public:
    virtual void read(const int address) {
        cout << "Reading from LBA: " << address << endl;
        // ���� �б� �۾� ����
    }

    virtual void write(const int address, const string& data) {
        cout << "Writing data to LBA: " << address << endl;
        // ���� ���� �۾� ����
    }
};