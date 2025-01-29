#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
	private:
		string isbn, title, author, edition, publication;
	public:
		// Constructor
		Book(){
			isbn = "no isbn";
			title = "no title";
			author = "no author";
			edition = "no edition";
			publication = "no publication";
		}
		
		Book(string a, string b, string c, string d, string e){
			setIsbn(a);
			title = b;
			author = c;
			edition = d;
			publication = e;
		};
		
		// Getter Functions
		string getIsbn() const {
			return isbn;
		};
		string getTitle() const {
			return title;
		};
		string getAuthor() const {
			return author;
		};
		string getEdition() const {
			return edition;
		};
		string getPublication() const {
			return publication;
		}
		
		// Set Functions
		void setIsbn(string a){
			isbn = a;
		}
};


vector<Book> library;

// Add book 
void addBook(vector<Book>& library){
	string isbn, title, author, edition, publication;
	cout << "Enter ISBN: ";
	cin >> isbn;
	cout << "Enter Title: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter Author: ";
	getline(cin, author);
	cout << "Enter Edition: ";
	getline(cin, edition);
	cout << "Enter Publication: ";
	getline(cin, publication);
	
	Book newBook(isbn, title, author, edition, publication);
	library.push_back(newBook);
	cout << "Book added successfully!\n";
}

// Delete book
void deleteBook(vector<Book>& library){
	if (library.empty()){
		cout << "The library is empty. No books to delete.\n";
		return;
	}
}

// Edit book
void editBook(vector<Book>& library){
	if (library.empty()){
		cout << "The library is empty. No books to edit.\n";
		return;
	}
}

// Search book
void searchBook(const vector<Book>& library){
	if (library.empty()){
		cout << "No books in the library.\n";
		return;
	}
}

// View all books
void viewBooks(const vector<Book>& library){
	for(const auto& book : library){
		cout << "ISBN: " << book.getIsbn() << "\n"
             << "Title: " << book.getTitle() << "\n"
             << "Author: " << book.getAuthor() << "\n"
             << "Edition: " << book.getEdition() << "\n"
             << "Publication: " << book.getPublication() << "\n\n";
	}
	if (library.empty()){
		cout << "No books in the library.\n";
	}
}


// Menu Functionality
int main(){
	int choice;
	
	while(true){
		cout << "\nLIBRARY MANAGEMENT SYSTEM\n"
			 << "[1] ADD BOOK\n"
			 << "[2] DELETE BOOK\n"
			 << "[3] EDIT BOOK\n"
			 << "[4] SEARCH BOOK\n"
			 << "[5] VIEW ALL BOOKS\n"
			 << "[6] QUIT\n\n";
		
		cout << "ENTER CHOICE: ";
		cin >> choice;
		
		switch(choice){
			case 1: addBook(library); 
				break;
			case 2: deleteBook(library); 
				break;
			case 3: editBook(library); 
				break;
			case 4: searchBook(library); 
				break;
			case 5: viewBooks(library);
				break;
			case 6:
				cout << "Exiting program...\n";
				return 0;
			default:
				cout << "Invalid choice. Try again.\n";
		}
	}
	
	
}

