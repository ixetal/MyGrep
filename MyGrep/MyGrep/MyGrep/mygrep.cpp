//Lauri Tanhuanp‰‰
//My Grep -projekti
#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

int main(int argc, char* argv[]) {
	// Jos komentoriviargumentteja ei ole, k‰ytet‰‰n alkuper‰ist‰ toimintoa
	if (argc == 1) {
	string largeString, searchString; 

	//pyydet‰‰n k‰ytt‰j‰lt‰ suurimerkkijono, josta etsit‰‰n pient‰ merkkijonoa
	cout << "Give a string from which to search for: ";
	getline(cin, largeString);

	cout << "Give search string: ";
	getline(cin, searchString);

	//etsint‰komento jolla etsitt‰v‰ merkkijono etsit‰‰n isosta merkkijonosta
	size_t position = largeString.find(searchString);

	//tulosten tulostaminen
	if (position != string::npos) {
		cout << "\"" << searchString << "\" found in \"" << largeString << "\" in position " << position << "\n";
	}
	else {
		cout << "\"" << searchString << "\" NOT found in\"" << largeString << "\"\n";
	}

}
	// Jos ohjelmalle annetaan kaksi komentoriviargumenttia, k‰ytet‰‰n tiedoston lukua
	else if (argc == 3) {
		string searchString = argv[1];
		string fileName = argv[2];
		ifstream file(fileName);

		if (!file) {
			cerr << "Error: Could not open file \"" << fileName << "\".\n";
			return 1;
		}
		string line;
		while (getline(file, line)) {
			if (line.find(searchString) != string::npos) {
				cout << line << "\n";
			}
		}

		file.close();
	}
	else {
		cerr << "Usage: ./mygrep [search_string filename] or run without arguments for interactive mode.\n";
		return 1;
	}

	return 0;
}
