/*
 * This is a simple Hash Table demo using linear probing.
 */

/* 
 * File:   main.cpp
 * Author: Alex Katrompas
 */

#include "main.h"

int main() {
    srand(time(NULL));
    cout << endl;

    /*
     * Make test data
     * Note this does not guarantee a unique id
     */
    Data testData[TESTDATASIZE];
    char buffer[BUFFERSIZE];
    for (int i = 0; i < TESTDATASIZE; i++) {
        testData[i].id = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        testData[i].data = buffer;
    }

    /*
     * Show test data
     */
    cout << "Showing Test Data..." << endl;
    for (int i = 0; i < TESTDATASIZE; i++) {
        cout << testData[i].id << " : " << testData[i].data << endl;
    }
    cout << endl;

    Hashtable hashtable;

    /*
     * Insert all data to hash table
     */
    cout << "Inserting Test Data..." << endl;
    for (int i = 0; i < TESTDATASIZE; i++) {
        if (hashtable.insertEntry(testData[i].id, testData[i].data)) {
            cout << "success. entry inserted." << endl;
            cout << "There are " << hashtable.getCount() << " entries." << endl << endl;
        } else {
            cout << "failed. table is likely full." << endl;
        }
    }
    cout << endl;

    /*
     * Retrieve all the test data from the table one at time
     */
    cout << "Retrieving Test Data on at a time..." << endl;
    string temp = "";
    for (int i = 0; i < TESTDATASIZE; i++) {
        temp = hashtable.getData(testData[i].id);

        if (temp != "") {
            cout << "success: " << testData[i].id << ": " << temp << endl;
        } else {
            cout << "failed: " << testData[i].id << " is not in the table." << endl;
        }
    }
    cout << endl;


    /*
     * Remove the first, middle, and last of the
     * test data ids and one non-existent id
     */
    cout << "Deleting Test Data..." << endl;

    cout << "Trying: " << testData[0].id << "..." << endl;
    if (hashtable.deleteEntry(testData[0].id)) {
        cout << "  Success: " << testData[0].id << " removed" << endl;
    } else {
        cout << "  Failed " << testData[0].id << " was not removed" << endl;
    }

    cout << "Trying: " << testData[(int) (TESTDATASIZE - 1) / 2].id << "..." << endl;
    if (hashtable.deleteEntry(testData[(int) (TESTDATASIZE - 1) / 2].id)) {
        cout << "  Success: " << testData[(int) (TESTDATASIZE - 1) / 2].id << " removed" << endl;
    } else {
        cout << "  Failed " << testData[(int) (TESTDATASIZE - 1) / 2].id << " was not removed" << endl;
    }

    cout << "Trying: " << testData[TESTDATASIZE - 1].id << "..." << endl;
    if (hashtable.deleteEntry(testData[TESTDATASIZE - 1].id)) {
        cout << "  Success: " << testData[TESTDATASIZE - 1].id << " removed" << endl;
    } else {
        cout << "  Failed " << testData[TESTDATASIZE - 1].id << " was not removed" << endl;
    }

    cout << "Trying: " << MAXID + 1 << "..." << endl;
    if (hashtable.deleteEntry(MAXID + 1)) {
        cout << "  Success: " << MAXID + 1 << " removed" << endl;
    } else {
        cout << "  Failed " << MAXID + 1 << " was not removed" << endl;
    }
    cout << endl;

    /*
     * Printing Table (traverse)
     */
    cout << "Hash Table Traversal..." << endl;
    hashtable.printTable();
    cout << endl;

    cout << endl;
    return 0;
}
