#include <iostream>
#include <fstream>
#include "Individual.h"
using namespace std;

/*void create(string namefile)
{
    // file pointer
    fstream fout;
    // opens an existing csv file or creates a new file.
    string name="/home/matias/dev/exploratoriav2/contribuyentes/"+namefile+".csv";
    fout.open(name, ios::out | ios::app);
    int i;
    // Read the input
    for (i = 0; i < 40; i++) {

        // Insert the data to file
        fout << rand()%4 << ", "
             << rand()%4 << ", "
             << rand()%2 << ", "
             << rand()%4 << ", "
             << rand()%2 << ", "
             << rand()%4 << ", "
             << rand()%2 << ", "
             << rand()%4 << ", "
             << "\n";
    }
}

/*
void read_record()
{
    // File pointer
    fstream fin;
    // Open an existing file
    fin.open("reportcard.csv", ios::in);
    // Get the roll number
    // of which the data is required
    int rollnum, roll2, count = 0;
    cout << "Enter the roll number "
         << "of the student to display details: ";
    cin >> rollnum;
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;
    while (fin >> temp) {
        row.clear();
        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
        // used for breaking words
        stringstream s(line);
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ', ')) {
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
        // convert string to integer for comparision
        roll2 = stoi(row[0]);
        // Compare the roll number
        if (roll2 == rollnum) {
            // Print the found data
            count = 1;
            cout << "Details of Roll " << row[0] << " : \n";
            cout << "Name: " << row[1] << "\n";
            cout << "Maths: " << row[2] << "\n";
            cout << "Physics: " << row[3] << "\n";
            cout << "Chemistry: " << row[4] << "\n";
            cout << "Biology: " << row[5] << "\n";
            break;
        }
    }
    if (count == 0)
        cout << "Record not found\n";
}



int main()
{
    cout << "Hello world!" << endl;
    string name="";
    for(int i=1;i<9;i++){
        name = "contribuyente0" +to_string(i);
        create(name);
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

// Number of individuals in each generation
#define POPULATION_SIZE 100

// Valid Genes
const string GENES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP"\
"QRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}";

// Target string to be generated
string TARGET = "default target";

// create chromosome or string of genes
string create_gnome()
{
    int len = TARGET.size();
    string gnome = "";
    for(int i = 0;i<len;i++)
        gnome += mutated_genes();
    return gnome;
}

// Driver code
int main(int argc,char * argv[])
{
    string t=argv[1];
    TARGET=t;
    srand((unsigned)(time(0)));

    // current generation
    int generation = 0;

    vector<Individual> population;
    bool found = false;

    // create initial population
    for(int i = 0;i<POPULATION_SIZE;i++)
    {
        Individual i;
        population.push_back(i);
    }

    while(! found)
    {
        // sort the population in increasing order of fitness score
        sort(population.begin(), population.end());

        // if the individual having lowest fitness score ie.
        // 0 then we know that we have reached to the target
        // and break the loop
        if(population[0].fitness <= 0)
        {
            found = true;
            break;
        }

        // Otherwise generate new offsprings for new generation
        vector<Individual> new_generation;

        // Perform Elitism, that mean 10% of fittest population
        // goes to the next generation
        int s = (10*POPULATION_SIZE)/100;
        for(int i = 0;i<s;i++)
            new_generation.push_back(population[i]);

        // From 50% of fittest population, Individuals
        // will mate to produce offspring
        s = (90*POPULATION_SIZE)/100;
        for(int i = 0;i<s;i++)
        {
            int len = population.size();
            Individual::random_num(0, 50);
            Individual parent1 = population[r];
            r = random_num(0, 50);
            Individual parent2 = population[r];
            Individual offspring = parent1.mate(parent2);
            new_generation.push_back(offspring);
        }
        population = new_generation;
        cout<< "Generation: " << generation << "\t";
        cout<< "String: "<< population[0].chromosome <<"\t";
        cout<< "Fitness: "<< population[0].fitness << "\n";

        generation++;
    }
    cout<< "Generation: " << generation << "\t";
    cout<< "String: "<< population[0].chromosome <<"\t";
    cout<< "Fitness: "<< population[0].fitness << "\n";
}
