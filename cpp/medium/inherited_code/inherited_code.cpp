#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;


// Created the class to be used within the code
class BadLengthException : exception {
    uint8_t str_len;
public:
    
    // Constructor
    BadLengthException(uint8_t n) {
        str_len = n;
    }
    
    // const qualified function to return the string length
    auto what() -> const string {
        return std::to_string(str_len);
    }
};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
