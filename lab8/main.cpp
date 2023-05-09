#define QUANTITY_SHOW_LIMIT 10

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;

class Book
{
public:
    string title;
    vector<string> authors;
    unsigned int year;
    string publisher;
    unsigned int numPages;
};

class CatalogBook : public Book
{
public:
    unsigned int id;
    unsigned int quantity;
    unsigned int instances;
    vector<pair<string, time_t>> picked;

    CatalogBook()
    {
        id = 0;
        quantity = 0;
        instances = 0;
    }

    CatalogBook(unsigned int _id, const Book &book, unsigned int _quantity) : Book(book), id(_id), quantity(_quantity), instances(_quantity) {}

    void lendBook(string &readerName);
    void returnBook(string &readerName);
    bool isOverdue(const string &readerName, const time_t &dueDate) const;
};

vector<CatalogBook> catalog;
vector<string> readers;

void CatalogBook::lendBook(string &readerName)
{
    if (instances > 0)
    {
        instances--;
        picked.push_back(make_pair(readerName, time(nullptr)));
    }
}

void CatalogBook::returnBook(string &readerName)
{
    auto it = find_if(picked.begin(), picked.end(),
                      [&](const pair<string, time_t> &p)
                      {
                          return p.first == readerName;
                      });
    if (it != picked.end())
    {
        instances++;
        picked.erase(it);
    }
}

bool CatalogBook::isOverdue(const string &readerName, const time_t &dueDate) const
{
    auto it = find_if(picked.begin(), picked.end(),
                      [&](const pair<string, time_t> &p)
                      {
                          return p.first == readerName;
                      });
    if (it != picked.end())
    {
        time_t now = time(nullptr);
        return now > dueDate;
    }
    return false;
}

vector<unsigned int> findBookByTitle(const string &title)
{
    vector<unsigned int> result;
    for (unsigned int i = 0; i < catalog.size(); i++)
    {
        if (catalog[i].title == title)
        {
            result.push_back(catalog[i].id);
        }
    }
    return result;
}

vector<unsigned int> findBookByAuthor(const string &author)
{
    vector<unsigned int> result;
    for (unsigned int i = 0; i < catalog.size(); i++)
    {
        for (auto j : catalog[i].authors)
        {
            if (j == author)
            {
                result.push_back(catalog[i].id);
            }
        }
    }
    return result;
}

unsigned int getNextId()
{
    static unsigned int nextId = 1;
    return nextId++;
}

void addBookToCatalog()
{
    CatalogBook book;
    book.id = getNextId();
    cout << "Enter book title: ";
    getline(cin, book.title);
    getline(cin, book.title);
    cout << "Enter author names separated by commas: ";
    string authorNames;
    getline(cin, authorNames);
    string delimiter = ",";
    size_t pos = 0;
    while ((pos = authorNames.find(delimiter)) != string::npos)
    {
        book.authors.push_back(authorNames.substr(0, pos));
        authorNames.erase(0, pos + delimiter.length());
    }
    book.authors.push_back(authorNames);
    cout << "Enter year of publication: ";
    cin >> book.year;
    cin.ignore(); // ignore newline
    cout << "Enter publisher: ";
    getline(cin, book.publisher);
    cout << "Enter number of pages: ";
    cin >> book.numPages;
    cout << "Enter quantity: ";
    cin >> book.quantity;
    book.instances = book.quantity;
    catalog.push_back(book);
    cout << "Book added to catalog with ID " << book.id << endl;
}

void removeBookFromCatalog()
{
    cout << "Enter book ID: ";
    unsigned int bookId;
    cin >> bookId;
    auto it = find_if(catalog.begin(), catalog.end(),
                      [&](const CatalogBook &book)
                      {
                          return book.id == bookId;
                      });
    if (it != catalog.end())
    {
        catalog.erase(it);
        cout << "Book removed from catalog." << endl;
    }
    else
    {
        cout << "Book not found in catalog." << endl;
    }
}

void printBookInfo(const CatalogBook &book)
{
    cout << "Title: " << book.title << endl;
    cout << "Authors: ";
    for (unsigned int i = 0; i < book.authors.size(); i++)
    {
        cout << book.authors[i];
        if (i != book.authors.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Year of publication: " << book.year << endl;
    cout << "Publisher: " << book.publisher << endl;
    cout << "Number of pages: " << book.numPages << endl;
    cout << "Quantity: " << book.quantity << endl;
    cout << "Instances: " << book.instances << endl;
    if (book.picked.empty())
    {
        cout << "No readers have borrowed this book." << endl;
    }
    else
    {
        cout << "Readers who have borrowed this book:" << endl;
        for (const auto &pair : book.picked)
        {
            cout << "- " << pair.first << " (borrowed on " << ctime(&pair.second) << ")";
        }
    }
}

void printReaderInfo(const string &readerName, const CatalogBook &book)
{
    auto it = find_if(book.picked.begin(), book.picked.end(),
                      [&](const pair<string, time_t> &p)
                      {
                          return p.first == readerName;
                      });
    if (it != book.picked.end())
    {
        cout << readerName << " borrowed this book on " << ctime(&it->second) << endl;
    }
    else
    {
        cout << readerName << " has not borrowed this book." << endl;
    }
}

void printReadersWithOverdueBooks(CatalogBook &book)
{
    cout << "Readers with overdue books:" << endl;
    for (const auto &book : catalog)
    {
        for (const auto &pair : book.picked)
        {
            if (book.isOverdue(pair.first, pair.second))
            {
                cout << "- " << pair.first << " (book ID: " << book.id << ", title: " << book.title << ")" << endl;
            }
        }
    }
}

void lendBookToReader(CatalogBook &book) // delete this
{
    cout << "Enter book ID: ";
    unsigned int bookId;
    cin >> bookId;
    auto it = find_if(catalog.begin(), catalog.end(),
                      [&](const CatalogBook &book)
                      {
                          return book.id == bookId;
                      });
    cin >> book.numPages;
    catalog.push_back(book);
    cout << "Book added to catalog with ID " << book.id << "." << endl;
}



void showReaders(bool block=true){
    cout << "Readers:" << endl;
    int k = 0;
    if (readers.size() == 0)
        cout << "No readers";
    else
        for (auto i: readers){
                k++;
                cout << k << ": " << i << endl;
                if (k == QUANTITY_SHOW_LIMIT-1 && block && (readers.size()-k) != 0){
                    cout << ". . . (" << readers.size()-k << " more readers)" << endl;
                    break;
                }
        }
    cout << endl;
}

void showBooks(bool block=true){
    cout << "Books:" << endl;
    int k = 0;
    if (catalog.size() == 0)
        cout << "No books";
    else
        for (auto i: catalog){
            k++;
            cout << "id: " << i.id << "\t title: " << i.title << "\tcnt: " << i.instances << "\t year: " << i.year  << "\t publisher: " << i.publisher << endl;
            if (k == QUANTITY_SHOW_LIMIT-1 && block && (catalog.size()-k) != 0){
                cout << ". . . (" << catalog.size()-k << " more books)" << endl;
                break;
            }
        }
    cout << endl;
}

int menu()
{   
    showReaders();
    cout << endl;
    showBooks();
    cout << endl << "MENU:" << endl;
    cout << "1. Add/Del reader" << endl;
    cout << "2. Add/Del book in catalog" << endl;
    cout << "3. Get info of book finded by id" << endl;
    cout << "4. Find book (name/author)" << endl;
    cout << "5. Take book" << endl;
    cout << "6. Return book" << endl;
    cout << "7. Show list readers (who dont return in 1 year)" << endl;
    cout << "8. Show all readers" << endl;
    cout << "9. Show all books" << endl;
    cout << "10. Exit" << endl;
    cout << "[Your choice (1-10)]: ";
    int x;
    cin >> x;
    system("cls");
    return x;
}

void makeAction(int x, bool &done, vector<CatalogBook> &catalog)
{
    tm time_in = {};
    string title, reader;
    unsigned int id, id_b, id_r;
    switch (x)
    {
    case 1:
        showReaders();
        cout << "1. Add reader" << endl;
        cout << "2. Del reader" << endl;
        cout << "3. Skip" << endl;
        cout << "[Your choice (1-3)]: ";
        cin >> x;
        if (x == 1){
            cout << "Input name of reader" << endl;
            cout << "[Name]: ";
            cin >> reader;
            readers.push_back(reader);
        }
        if (x == 2){
            if (readers.size() == 0)
                cout << "No readers!!!" << endl;
            else{
                cout << "Input id of reader (1-" << readers.size() << ")" << endl;
                cout << "[id]: ";
                cin >> id;
                readers.erase(readers.begin()+id-1);
            }
        }
        break;
    case 2:
        showBooks();
        cout << "1. Add book in catalog" << endl;
        cout << "2. Del book from catalog" << endl;
        cout << "3. Skip" << endl;
        cout << "[Your choice (1-3)]: ";
        cin >> x;
        if (x == 1)
            addBookToCatalog();
        if (x == 2)
            removeBookFromCatalog();
        break;
    case 3:
        cout << "Input id of book" << endl;
        cout << "[id]: ";
        cin >> id;
        for (auto i : catalog) // Цикл лишний, но без него auto конфликтует в case
        {
            auto it = find_if(catalog.begin(), catalog.end(),
                                [&](const CatalogBook &book)
                                {
                                    return book.id == id;
                                });
                    printBookInfo(*it);
            cout << endl;
            break;
        }
        system("pause");
        break;
    case 4:
        cout << "1. Find book in catalog by title" << endl;
        cout << "2. Find book in catalog by author" << endl;
        cout << "3. Skip" << endl;
        cout << "[Your choice (1-3)]: ";
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "[Input title]: ";
            getline(cin, title);
            getline(cin, title);
            vector<unsigned int> val = findBookByTitle(title);
            cout << "CNT\t" << val.size() << endl;
            system("pause");
            system("cls");
            for (auto i : val)
            {
                auto it = find_if(catalog.begin(), catalog.end(),
                                  [&](const CatalogBook &book)
                                  {
                                      return book.id == i;
                                  });
                printBookInfo(*it);
                cout << endl;
            }
        }
        if (x == 2)
        {
            string author;
            cout << "[Input title]: ";
            getline(cin, author);
            getline(cin, author);
            vector<unsigned int> val = findBookByAuthor(author);
            cout << "CNT\t" << val.size() << endl;
            system("pause");
            system("cls");
            for (auto i : val)
            {
                auto it = find_if(catalog.begin(), catalog.end(),
                                  [&](const CatalogBook &book)
                                  {
                                      return book.id == i;
                                  });
                printBookInfo(*it);
                cout << endl;
            }
        }
        system("pause");
        break;
    case 5:
        showReaders();
        cout << endl;
        showBooks();
        cout << endl;
        cout << "Put id the reader: " << endl;
        cout << "[Id]: ";
        cin >> id_r;
        cout << "Put id the book: " << endl;
        cout << "[Id]: ";
        cin >> id_b;
        catalog[id_b-1].lendBook(readers[id_r-1]);
        break;
    case 6:
        showReaders();
        cout << endl;
        showBooks();
        cout << endl;
        cout << "Put id the reader: " << endl;
        cout << "[Id]: ";
        cin >> id_r;
        cout << "Put id the book: " << endl;
        cout << "[Id]: ";
        cin >> id_b;
        catalog[id_b-1].returnBook(readers[id_r-1]);
        break;
    case 7:
        
        time_in.tm_year = 101;  // 2001 year (since 1900)
        time_in.tm_mon = 7;     // August (0-based)
        time_in.tm_mday = 28;
        time_in.tm_hour = 0;
        time_in.tm_min = 0;
        time_in.tm_sec = 0;
        catalog[0].picked[0].second = mktime(&time_in);
            for (auto i : catalog)
            {
                printReadersWithOverdueBooks(i);
            }
            system("pause");
        break;
    case 8:
        showReaders(0);
        system("pause");
        break;
    case 9:
        showBooks(0);
        system("pause");
        break;
    case 10:
        done = false;
        break;
    }
    system("cls");
}

int main()
{

    // struct reader rdr;
    // rdr.name = "Vasya";
    // rdr.date = "01.01.2020";
    // readers.push_back(rdr);
    // rdr.name = "Alesha";
    // rdr.date = "05.02.2020";
    // readers.push_back(rdr);
    int x;
    bool done = true;
    do
    {
        x = menu();
        makeAction(x, done, catalog);
    } while (done);
    return 0;
}