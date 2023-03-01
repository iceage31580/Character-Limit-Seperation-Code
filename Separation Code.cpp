#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int CHUNK_SIZE = 2700;

int main() {
    char filename[100];
    cout << "Enter the name of the file: ";
    cin.getline(filename, 100);

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    char buffer[CHUNK_SIZE];
    int chunk_number = 0;
    int characters_read = 0;
    while (!input_file.eof()) {
        chunk_number++;
        string chunk_filename = "Study Chunk_" + to_string(chunk_number) + ".txt";
        ofstream output_file(chunk_filename);
        if (!output_file.is_open()) {
            cout << "Error opening file" << endl;
            return 1;
        }

        characters_read = 0;
        while (characters_read < CHUNK_SIZE && !input_file.eof()) {
            input_file.get(buffer[characters_read]);
            if (!isspace(buffer[characters_read])) {
                characters_read++;
            }
        }
        buffer[characters_read] = '\0';
        output_file.write(buffer, characters_read);
        output_file.close();
    }

    cout << "Total characters read: " << characters_read << endl;
    cout << "Chunks created: " << chunk_number << endl;
    input_file.close();
    return 0;
}
