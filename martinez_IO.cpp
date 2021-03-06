// Name: Mario Martinez
// Date: 10/21/15 
// Description: The program reads in a file and modifies that file. The program saves the modified version of the text on to a different file. The program makes changes like making all the letters upper case and it capitalizes the first letter in each word.

#include <iostream>
#include <fstream> //It allows us to pipe files.
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

void clearScreen();

int main()
{
    ifstream fin;
    ofstream fout;
    ofstream fout2;
    ofstream fout3;
    string valA, valB, upperString, firstLetterUpper;
    int averageWord = 0;
    int numberOfWords = 0;
    int numberOfCharacters = 0;
    int wordCount1 = 0, wordCount2 = 0, wordCount3 = 0, wordCount4 = 0, wordCount5 = 0, wordCount6 = 0, wordCount7 = 0, wordCount8 = 0, wordCount9 = 0, wordCount10 = 0, wordCount11AndUp = 0;
    int count = 0;

    
    fin.open("gba.txt");
    fout.open("result.txt");
    fout2.open("capitalize.txt");
    fout3.open("uppercase.txt");
    
    if(fin.fail())
    {
        cout << "error opening input file" << endl;
        exit(1);
    }
    
    if(fout.fail())
    {
        cout << "error opening output file" << endl;
        exit(1);
    }
    

    while(fin >> valA)
    {
        valB = valA;
        valB[0] = toupper(valB[0]);
        firstLetterUpper = firstLetterUpper + valB + " ";
        for(int i = 0; i < valA.length(); i++)
        {
            
            upperString += toupper(valA[i]);
            if(valA[i] == '.' || valA[i] == ',' || valA[i] == '-')
            {
                if(valA[i+1] == '-')
                {
                    valA.erase(i+1, 1);
                }
                valA.erase(i, 1);
            }
        }
        upperString = upperString + " ";
        
        averageWord = averageWord + valA.length();
        numberOfWords++;
        
        
        switch(valA.length())
        {
            case 1:
                wordCount1++;
                count++;
                break;
            case 2:
                wordCount2++;
                count++;
                break;
            case 3:
                wordCount3++;
                count++;
                break;
            case 4:
                wordCount4++;
                count++;
                break;
            case 5:
                wordCount5++;
                count++;
                break;
            case 6:
                wordCount6++;
                count++;
                break;
            case 7:
                wordCount7++;
                count++;
                break;
            case 8:
                wordCount8++;
                count++;
                break;
            case 9:
                wordCount9++;
                count++;
                break;
            case 10:
                wordCount10++;
                count++;
                break;
            default:
                if(valA.length() > 10)
                {
                    wordCount11AndUp++;
                    count++;
                }
                break;
                
        }
    }
    
    fout << "average character per word: " << averageWord / numberOfWords << endl;
    
    fout << wordCount1 << " words of lenght 1" << endl;
    fout << wordCount2 << " words of lenght 2" << endl;
    fout << wordCount3 << " words of lenght 3" << endl;
    fout << wordCount4 << " words of lenght 4" << endl;
    fout << wordCount5 << " words of lenght 5" << endl;
    fout << wordCount6 << " words of lenght 6" << endl;
    fout << wordCount7 << " words of lenght 7" << endl;
    fout << wordCount8 << " words of lenght 8" << endl;
    fout << wordCount9 << " words of lenght 9" << endl;
    fout << wordCount10 << " words of lenght 10" << endl;
    fout << wordCount11AndUp << " words of lenght 11 or longer" << endl;
    fout << "Total number of words: " << numberOfWords << endl;
    
    fout2 << upperString << endl;
    fout3 << firstLetterUpper << endl;
    
    

    fin.close();
    fout.close();
    fout2.close();

    return 0;
}
