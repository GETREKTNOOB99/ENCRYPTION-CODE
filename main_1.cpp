#include <iostream>
#include <cctype>
#include <limits>

using namespace std;

string caesarCipher(const string& text, int shift, bool encrypt) {
    string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            char base = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';
            int offset = encrypt ? shift : 26 - shift;  // Adjust for encryption or decryption
            result += (ch - base + offset + 26) % 26 + base;
        } else {
            result += ch;
        }
    }

    return result;
}

void displayMenu() {
    cout << "Caesar Cipher Menu:\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "3. Reverse Text\n";
    cout << "4. Uppercase Text\n";
    cout << "5. Lowercase Text\n";
    cout << "6. Exit\n";
}

int getKey() {
    int key;
    while (true) {
        cout << "Enter the shift value for the Caesar cipher (1-25): ";
        cin >> key;

        if (cin.fail() || key < 1 || key > 25) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter a valid shift value.\n";
        } else {
            break;
        }
    }
    return key;
}

int main() {
    string user_input;
    int choice;
    int shift;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
            case 2:
                cout << "Enter the English sentence or Caesar cipher text: ";
                getline(cin, user_input);
                shift = getKey();
                cout << (choice == 1 ? "Encrypted" : "Decrypted") << " Text:\n" << caesarCipher(user_input, shift, choice == 1) << "\n";
                break;

            case 3:
                cout << "Enter the text to reverse: ";
                getline(cin, user_input);
                cout << "Reversed Text:\n" << string(user_input.rbegin(), user_input.rend()) << "\n";
                break;

            case 4:
                cout << "Enter the text to convert to uppercase: ";
                getline(cin, user_input);
                cout << "Uppercase Text:\n" << caesarCipher(user_input, 0, true) << "\n";
                break;

            case 5:
                cout << "Enter the text to convert to lowercase: ";
                getline(cin, user_input);
                cout << "Lowercase Text:\n" << caesarCipher(user_input, 0, false) << "\n";
                break;

            case 6:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
