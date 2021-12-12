//This is Assignment 7, I used exactly the same program that I wrote last week and just removed the arrays and added a structure instead.
//This Program can read from a file called "BowlingScores.txt", it then takes in the name and scores of each bowler, calculates the average score of each bowler and outputs everything.
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
//const variables to use in arrays/structure these variables are for the input file that has 10 rows and 5 columns
const int numofRows = 10;
const int numofColumns = 5;
//creating the structure for bowlers
struct Bowlers {
    string bowlerName;
    int bowlerScores[numofColumns];
    double averageScore;
};

//Function called GetBowlingData reading and storing array names, and bowlerScores from file "BowlingScores.txt"
bool GetBowlingData(string inFileName, Bowlers bowlers[], int& j) {
    //opening stream to read data
    ifstream fInStream;
    fInStream.open(inFileName);
    //Error message incase file can't be opened that returns false
    if (!fInStream) {
        cout << "Error in opening the file: " << endl;
        return false;
    }

    //two dimensional array that stores bowlers names/scores
    while (fInStream.good()) {
        fInStream >> bowlers[j].bowlerName;
        //two dimensional array that stores the bowling bowlerScores
        for (int x = 0; x < numofColumns; x++)
        {
            fInStream >> bowlers[j].bowlerScores[x];
        }
        j++;
    }

    fInStream.close();
    //returning true if file reading success
    return true;

}

//Function called PrettyPrintResults that outputs the results
void PrettyPrintResults(Bowlers bowlers[], int j)
{
    //outputting title with iomanipulation

    cout << setw(63) << setfill('*') << "*" << endl;
    cout << setw(14) << "*" << "Welcome to my Bowling Score Program" << setw(14) << "*" << endl;
    cout << setw(63) << "*" << endl;
    cout << endl;

    //for loop to output names
    for (int i = 0; i < j; i++)
    {
        cout << bowlers[i].bowlerName << " bowlerScores in numofColumns games were: ";
        //two dimensional loop to output bowlerScores after names
        for (int x = 0; x < numofColumns; x++)
        {
            cout << bowlers[i].bowlerScores[x] << " ";
        }
        //outputting average score after second for loop
        cout << endl << "And their average was: " << bowlers[i].averageScore << endl << endl;



    }
}

//Function GetAverageScore that calculates the average score and writes it to bowling scores, and average
void GetAverageScore(Bowlers bowlers[], int j)
{

    //double total =0;
    //for loop to calculate average score
    for (int i = 0; i < j; i++)
    {
        //setting total to 0 again so that new numofRows gets calculated correct
        double total = 0;
        //for loop to calculate total bowlerScores by numofRows
        for (int x = 0; x < numofColumns; x++)
        {
            //adding bowlerScores to total to get all bowlerScores combined for each numofRows
            total = total + bowlers[i].bowlerScores[x];
        }
        //dividing total bowlerScores to get averageSCore
        bowlers[i].averageScore = (total / numofColumns);
    }

}
int main()
{
    //Bowling structure that has numofRows in it which is a constant so after collecting 10 rows of information it'll stop
    Bowlers bowlers[numofRows];
    int j = 0;
    // Getting Bowling Data by calling function GetBowlingData
    GetBowlingData("BowlingScores.txt", bowlers, j);

    //calculating average score by calling function GetAverageScore
    GetAverageScore(bowlers, j);

    //Printing bowlerName,bowlerScores and average score by calling function PrettyPrintResults
    PrettyPrintResults(bowlers, j);

    cout << endl;
    system("Pause");
    return 0;
}


//What I removed from old program
//int i = 0, x = 0;
//int scores[numofRows][column];
//string names[numofRows];
//double averageScore[numofRows];
//string inFileName = "BowlingScores.txt";
