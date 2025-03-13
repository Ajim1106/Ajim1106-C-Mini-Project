#include<iostream>
#include <string>
using namespace std;
class Book {
private:
    string name;
    string category;
    float rating;
    float deposite;
public:
    Book(string n = "", string c = "", float r = 0.0, float d = 0.0) {
        name = n;
        category = c;
        rating = r;
        deposite = d;
    }
    // Setters
    void setName(string n) {
        name = n;
	}
    void setCategory(string c) {
        category = c;
    }
    void setRating(float r) {
        rating = r;
    }
    void setDeposite(float d) {
        deposite = d;
    }
    // Getters
    string getName() {
        return name;
    }
    string getCategory() {
        return category;
    }
    float getRating() {
        return rating;
    }
    float getDeposite() {
        return deposite;
    }
    // Display Books Info
    void displayBook() {
        cout << "Book Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Rating: " << rating << endl;
        cout << "Deposite : Rs" << deposite << endl;
    }
};
class LibrarySystem {
private:
    Book books[5]; // Max enter 5  Books
    int bookCount;
public:
    // Constructor
    LibrarySystem() {
        bookCount = 0;
    }
    // Create: Add a new Book
    void addBook() {
        if (bookCount < 5) {
            string name, category;
            float rating, deposite;

            cout << "Enter Book Name: " << endl;
            cin>>name;

            cout << "Enter Book Category: ";
            cin>>category;

            cout << "Enter Book Rating: ";
            cin >> rating;

            cout << "Enter Book Deposite: ";
            cin >> deposite;

            // Create the Book object and add it to the array
            books[bookCount] = Book(name, category, rating, deposite);
            bookCount++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Cannot add more Books. Limit reached!" << endl;
        }
    }
    void deleteBook() {
    if (bookCount == 0) {
        cout << "No books available to delete!" << endl;
        return;
    }

    string nameToDelete;
    cout << "Enter the name of the book to delete: ";
	cin>>nameToDelete;

    // Search for the book
    int index = -1;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getName() == nameToDelete) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Book not found!" << endl;
        return;
    }

    // Shift the remaining books to fill the gap
    for (int i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }

    bookCount--; // Decrement the count of books
    cout << "Book deleted successfully!" << endl;
}

    // Read: View all Books
    void viewBook() {
        if (bookCount == 0) {
            cout << "No Books available!" << endl;
            return;
        }
        for (int i = 0; i < bookCount; i++) {
            cout << "\nBook " << i + 1 << " details:" << endl;
            books[i].displayBook();
        }
    }

    void showMenu() {
        int choice;
        do {
            cout << "\nLibrary System Menu:\n"
                 << "1. Add Book\n"
                 << "2. View Books\n"
                 << "3. Delete Books\n"
                 << "4. Exit\n"
                 << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addBook();
                    break;
                case 2:
                    viewBook();
                    break;
                case 3:
                    deleteBook();
                    break;
                case 4:
                    cout << "Exiting the system." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);  // Fixed the while loop condition
    }
};
int main() {
    LibrarySystem system;
    system.showMenu();
    return 0;
}
