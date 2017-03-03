#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

class Person {
    protected:
        string firstName;
        string lastName;
        int id;
    public:
        Person(string firstName, string lastName, int identification){
            this->firstName = firstName;
            this->lastName = lastName;
            this->id = identification;
        }
        void printPerson(){
            cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
        }
};

class Student : public Person{
    private:
        vector<int> testScores;
    public:
        /*
         * A Student class constructor, which has  parameters:
         * A string, firstName.
         * A string, lastName.
         * integer id.
         * vector or Array of integers contains Student score
         */
        // initializing Data
        Student(string firstName  , string lastName , int id  , vector<int> score): Person(firstName , lastName , id){
            testScores = score ;
        }
        /*
         * A char calculate() method that calculates a Student object's average
         * returns the grade character representative of their calculated average.
         * https://www.hackerrank.com/challenges/30-inheritance
         */
        char calculate(){
            int sum = 0 , average ;
            for(int i = 0 ; i < testScores.size() ; i++)
                sum += testScores[i] ;
            average = sum / (int)testScores.size() ;
            if(average >= 90) return 'O' ;
            if(average >= 80) return 'E' ;
            if(average >= 70) return 'A' ;
            if(average >= 55) return 'P' ;
            if(average >= 40) return 'D' ;
            return 'T' ;
        }
};

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    string firstName;
    string lastName;
    int id;
    int numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for(int i = 0; i < numScores; i++){
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student* s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";


    return 0 ;
}
