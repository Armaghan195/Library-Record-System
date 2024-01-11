#include <iostream>
#include <string>

using namespace std;

string tolowercase(const string& str)
{
    string result;
    for (char c : str)
    {
        result += tolower(c);
    }
    return result;
}



// Define a structure named "Book"
struct Book
{
    string title;
    string author;
    int publicationYear;
    string genre;
};
bool checker(const Book books[], int nob);
// Function to input details for six books
void inputBooks(Book books[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter details for Book " << i + 1 << ":" << endl;
        cout << "Title: ";
        getline(cin >> ws, books[i].title); // Allowing spaces in the title

        cout << "Author: ";
        getline(cin >> ws, books[i].author); // Allowing spaces in the author name
        do
        {
            cout << "Publication Year: ";
            cin >> books[i].publicationYear;
            if (books[i].publicationYear > 2024)
            {
                cout << "PLEASE ENTER CORRECT PUBLICATION YEAR!!! " << endl;

            }

        } while (books[i].publicationYear > 2024);

        cout << "Genre: ";
        getline(cin >> ws, books[i].genre); // Allowing spaces in the genre
        cout << endl;
    }
}

// Function to categorize books into fiction and non-fiction arrays
void categorizeBooks(const Book books[], int size, Book fiction[], Book nonFiction[], int& fictionCount, int& nonFictionCount)
{
    fictionCount = nonFictionCount = 0;

    for (int i = 0; i < size; ++i)
    {
        if (tolowercase(books[i].genre) == "fiction")
        {
            fiction[fictionCount++] = books[i];
        }

        else if (tolowercase(books[i].genre) == "nonfiction")
        {
            nonFiction[nonFictionCount++] = books[i];
        }
    }
}

// Function to find the book with the earliest publication year in each category
Book findEarliestBook(const Book books[], int size)
{
    Book earliestBook = books[0];

    for (int i = 1; i < size; ++i)
    {
        if (books[i].publicationYear < earliestBook.publicationYear) {
            earliestBook = books[i];
        }
    }

    return earliestBook;
}

// Function to display details of books and the earliest published books in both categories
void displayBooks(const Book books[], int size, const Book& earliestBook)
{
    for (int i = 0; i < size; ++i)
    {
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

int main()
{
    const int numOfBooks = 6;
    Book books[numOfBooks];
    Book fiction[numOfBooks], nonFiction[numOfBooks];
    int fictionCount, nonFictionCount;
    char opt;

    do {
        cout << "Please Select an option Below: " << endl;
        cout << "(a) Enter Books Data" << endl;
        cout << "(b) Display All books" << endl;
        cout << "(c) Display Fictional books only" << endl;
        cout << "(d) Display Non-Fictional books only" << endl;
        cout << "(e)xit" << endl;
        cout << "> ";
        cin >> opt;
        switch (tolower(opt))
        {// Step 1: Input details for six books
        case 'a':
        { inputBooks(books, numOfBooks);
        // Step 2: Categorize books into fiction and non-fiction arrays
        categorizeBooks(books, numOfBooks, fiction, nonFiction, fictionCount, nonFictionCount);

        // Step 3: Find the book with the earliest publication year in each category
        Book earliestFiction = findEarliestBook(fiction, fictionCount);
        Book earliestNonFiction = findEarliestBook(nonFiction, nonFictionCount);
        break;
        }


        case 'b':
        { // Step 4: Display details of all books and the earliest published books in both categories
            if (checker(books, numOfBooks))
            {
                break;
            }
            Book earliestFiction = findEarliestBook(fiction, fictionCount);
            Book earliestNonFiction = findEarliestBook(nonFiction, nonFictionCount);
            cout << "Fiction Books:" << endl;
            displayBooks(fiction, fictionCount, earliestFiction);

            cout << "Non-Fiction Books:" << endl;
            displayBooks(nonFiction, nonFictionCount, earliestNonFiction);
            break;
        }

        case 'c':
        {

            //display fictional books only
            if (checker(books, numOfBooks))
            {
                break;
            }
            Book earliestFiction = findEarliestBook(fiction, fictionCount);
            Book earliestNonFiction = findEarliestBook(nonFiction, nonFictionCount);
            cout << "Fiction Books:" << endl;
            displayBooks(fiction, fictionCount, earliestFiction);
            break;
        }

        case 'd':
        {  //display non fictional books only
            if (checker(books, numOfBooks))
            {
                break;
            }
            Book earliestFiction = findEarliestBook(fiction, fictionCount);
            Book earliestNonFiction = findEarliestBook(nonFiction, nonFictionCount);
            cout << "Non-Fiction Books:" << endl;
            displayBooks(nonFiction, nonFictionCount, earliestNonFiction);
            break;
        }
        case 'e':
        {
            cout << "thank you for using our Book Sorting System!";
            exit(0);

        }
        default:
            cout << "Invalid Choice!!!";
            

        }
        system("pause");
        system("cls");

    } while (tolower(opt) != 'a' || tolower(opt) != 'b' || tolower(opt) != 'c' || tolower(opt) != 'd');






    return 0;
}

bool checker(const Book books[], int nob)
{
    if (books[0].title.empty())
    {
        cout << "Please enter Book Details By selecting Option (a) in the menu" << endl << endl;
        

        return true;

    }

    return false;
}
