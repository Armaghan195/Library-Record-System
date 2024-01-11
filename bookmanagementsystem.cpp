#include <iostream>
#include <string>

using namespace std;

// Define a structure named "Book"
struct Book {
    string title;
    string author;
    int publicationYear;
    string genre;
};

// Function to input details for six books
void inputBooks(Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Enter details for Book " << i + 1 << ":" << endl;
        cout << "Title: ";
        getline(cin >> ws, books[i].title); // Allowing spaces in the title
        cout << "Author: ";
        getline(cin >> ws, books[i].author); // Allowing spaces in the author name
        cout << "Publication Year: ";
        cin >> books[i].publicationYear;
        cout << "Genre: ";
        getline(cin >> ws, books[i].genre); // Allowing spaces in the genre
        cout << endl;
    }
}

// Function to categorize books into fiction and non-fiction arrays
void categorizeBooks(const Book books[], int size, Book fiction[], Book nonFiction[], int& fictionCount, int& nonFictionCount) {
    fictionCount = nonFictionCount = 0;

    for (int i = 0; i < size; ++i) {
        if (books[i].genre == "Fiction") {
            fiction[fictionCount++] = books[i];
        } else if (books[i].genre == "Non-Fiction") {
            nonFiction[nonFictionCount++] = books[i];
        }
    }
}

// Function to find the book with the earliest publication year in each category
Book findEarliestBook(const Book books[], int size) {
    Book earliestBook = books[0];

    for (int i = 1; i < size; ++i) {
        if (books[i].publicationYear < earliestBook.publicationYear) {
            earliestBook = books[i];
        }
    }

    return earliestBook;
}

// Function to display details of books and the earliest published books in both categories
void displayBooks(const Book books[], int size, const Book& earliestBook) {
    for (int i = 0; i < size; ++i) {
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publication Year: " << books[i].publicationYear << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << endl;
    }

    cout << "Earliest Published Book:" << endl;
    cout << "Title: " << earliestBook.title << endl;
    cout << "Author: " << earliestBook.author << endl;
    cout << "Publication Year: " << earliestBook.publicationYear << endl;
    cout << "Genre: " << earliestBook.genre << endl;
}

int main() {
    const int numOfBooks = 6;
    Book books[numOfBooks];
    Book fiction[numOfBooks], nonFiction[numOfBooks];
    int fictionCount, nonFictionCount;

    // Step 1: Input details for six books
    inputBooks(books, numOfBooks);

    // Step 2: Categorize books into fiction and non-fiction arrays
    categorizeBooks(books, numOfBooks, fiction, nonFiction, fictionCount, nonFictionCount);

    // Step 3: Find the book with the earliest publication year in each category
    Book earliestFiction = findEarliestBook(fiction, fictionCount);
    Book earliestNonFiction = findEarliestBook(nonFiction, nonFictionCount);

    // Step 4: Display details of all books and the earliest published books in both categories
    cout << "Fiction Books:" << endl;
    displayBooks(fiction, fictionCount, earliestFiction);

    cout << "Non-Fiction Books:" << endl;
    displayBooks(nonFiction, nonFictionCount, earliestNonFiction);

    return 0;
}
