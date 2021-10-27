// June 2019
// William Mori

#include <iostream>
#include <vector>
using namespace std;
#include "movies.h"

void test_insert();
void test_count();
void test_findDepth();
void test_getTitle_HR();
void test_getRating_HR();
void RunAll();

int main() {
	RunAll();
	return 0;
}

void RunAll() {

	cout << "Test insert: " << endl;
	test_insert();
	cout << endl;

	cout << "Test count: " << endl;
	test_count();
	cout << endl;

	cout << "Test findDepth: " << endl;
	test_findDepth();
	cout << endl;

	cout << "Test getTitle_HR: " << endl;
	test_getTitle_HR();
	cout << endl;

	cout << "Test getRating_HR: " << endl;
	test_getRating_HR();
	cout << endl;

}

void test_insert() {
	BST movies;

	movies.insert("test1", 1.1);
	movies.insert("test2", 2.2);
	movies.insert("test3", 3.3);

	if (movies.count() == 3) {
		cout << "PASSED";
	}
	else {
		cout << "FAILED";
	}
}

void test_count() {
	BST movies;

	movies.insert("test1", 1.1);
	movies.insert("test2", 2.2);
	movies.insert("test3", 3.3);
	movies.insert("test4", 4.4);

	if (movies.count() == 4) {
		cout << "PASSED";
	}
	else {
		cout << "FAILED";
	}
}

void test_findDepth() {
	BST movies;

	movies.insert("Atest", 1.1);
	movies.insert("Btest", 2.2);
	movies.insert("Ctest", 3.3);
	movies.insert("Dtest", 1.1);
	movies.insert("Etest", 2.2);
	movies.insert("Ftest", 3.3);

	if (movies.findDepth("Btest") == 1) {
		cout << "PASSED";
	}
	else {
		cout << "FAILED";
	}
}

void test_getTitle_HR() {
	BST movies;

	movies.insert("the Atest", 1.1);
	movies.insert("Btest", 2.2);
	movies.insert("the Ctest", 8.9);
	movies.insert("Dtest", 1.1);
	movies.insert("Etest", 2.2);
	movies.insert("the Ftest", 3.3);

	if (movies.getTitle_HR("the") == "the Ctest") {
		cout << "PASSED";
	}
	else {
		cout << "FAILED";
	}
}

void test_getRating_HR() {
	BST movies;

	movies.insert("the Atest", 1.1);
	movies.insert("Btest", 2.2);
	movies.insert("the Ctest", 8.9);
	movies.insert("Dtest", 1.1);
	movies.insert("Etest", 2.2);
	movies.insert("the Ftest", 3.3);

	if (movies.getRating_HR("the") == 8.9) {
		cout << "PASSED";
	}
	else {
		cout << "FAILED";
	}
}
























