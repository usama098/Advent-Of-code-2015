/*
start from floor 0, if encounter "(" increase the floor by 1, if encounter ")" decrease the floor by 1
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>  // C++17 standard library header

using namespace std;
using namespace filesystem; // Use the filesystem namespace for convenience

string readFileContent(const string& filePath) {
    ifstream myfile(filePath);
    if (myfile.is_open()) {
        stringstream buffer;
        buffer << myfile.rdbuf(); // Read the entire file into the buffer.
        myfile.close();
        return buffer.str(); // Return the contents of the file as a single string.
    } else {
        cerr << "Unable to open file: " << filePath << endl;
        return ""; // Return empty string or handle the error as needed.
    }
}

int main(){
    cout << "Current path is: " << current_path() << endl; // Print the current working directory
    string fileContent = readFileContent("../datasets/DayOneInput.txt");
    cout << fileContent << endl;
}