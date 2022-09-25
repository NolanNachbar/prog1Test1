#include <iostream>
#include <fstream>
#include "timer.h" 
#include "myList.h"
#include "node.h"


using namespace std;
using std::cout;

//functions
string cleanWord(string wordD);
bool compareString(string word);
void readDict();
void readBook();
void writeMisspelled();

myList<string> dictionaryList;
myList<string> bookList;


int main()
{

    Timer tim;
    
 
    //reading the dictionary
    int dictionarySize = 0;
    string tmp;
    ifstream dictFile;
    dictFile.open("dict.txt");
    
    while(dictFile >> tmp)
    {
        tmp = cleanWord(tmp);
        dictionaryList.insert(tmp);
        dictionarySize++;
    }




    //starting the time
    tim.Start();
    


    //reading the book file and comparing to the dictionary
    string btmp;
    ifstream bookFile;

    bookFile.open("book.txt");
    int misspelled = 0;
    int matchNum = 0;
    int comp;

    while(bookFile >> btmp) 
    {
        btmp = cleanWord(btmp);
        comp = dictionaryList.find(btmp);
        
        if(comp == 1)
        {
            matchNum++;
        }
        else
        {
            misspelled++;
            bookList.insert(btmp);
        }
        
    }

    tim.Stop();

    cout << "dictionary Size: " << dictionarySize;
    cout << " Finished in time: " << setprecision(2) << tim.Time() << "\n";
    cout << " The number of matches: " << matchNum << "\n";
    cout << " The number of misspelled: " << misspelled << "\n"; 

    dictionaryList.~myList();
    bookList.~myList();

    
    //writing to the misspelled file
    ofstream missFile;
    missFile.open("misspelled.txt");
    
    
    while(!bookList.isEmpty())
    {
        missFile << bookList.frontMod();
    }

    missFile.close();

}

string cleanWord(string word)
{
    string cleanW = "";
    for(int i =0; i< word.size(); i++)
    {
        if(isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        if(isalnum(word[i]))
        {
            cleanW = cleanW + word[i];
        }
        else if(word[i] == '\'')
        {
            cleanW = cleanW + word[i];
        }
    }
    
    //return word;
    return cleanW;
};

bool compareString(string word)
{
    bool returnVal = dictionaryList.find(word);
    return returnVal;
};
