#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// lil class to hold each makeup shade's info
class Shade {
public:
    string brand;
    string product;
    string hex;
    float saturation;
    float brightness;

    // constructor to store everything at once
    Shade(string b, string p, string h, float s, float v)
        : brand(b), product(p), hex(h), saturation(s), brightness(v) {}

    // function to show it all nice
        void display() const {

        cout << "Brand: " << brand << "\n"
             << "Product: " << product << "\n"
             << "Hex Code: #" << hex << "\n"
             << "Saturation (S): " << saturation << "\n"
             << "Brightness (V): " << brightness << "\n"
             << "---------------------------\n";
    }
};

// just splits the line into separate parts based on commas
vector<string> splitCSVLine(const string& line) {
    vector<string> result;
    stringstream ss(line);
    string token;

    while (getline(ss, token, ',')) {
        result.push_back(token);
    }

    return result;
}

int main() {
    // open the CSV file
    ifstream file("shades.csv");
    if (!file.is_open()) {
        cerr << "Error: shades.csv not found :(\n";
        return 1;
    }

    string line;
    getline(file, line); // skip the header row

    vector<Shade> shades;
    int count = 0;

    // read up to 10 shades from the file
    while (getline(file, line) && count < 10) {
        vector<string> fields = splitCSVLine(line);

        // just making sure there’s enough data in the row
        if (fields.size() >= 8) {
            string brand = fields[0];
            string product = fields[2];
            string hex = fields[4];
            float saturation = stof(fields[6]); // S
            float brightness = stof(fields[7]); // V

            // add the shade to our list
            Shade s(brand, product, hex, saturation, brightness);
            shades.push_back(s);
            count++;
        }
    }

    file.close();

    // print all the shades we loaded
    for (const Shade& s : shades) {
        s.display();  // updated ver

    }

    return 0;
}
// last save test