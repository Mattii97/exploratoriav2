#include <iostream>
#include "Individual.h"
#include <bits/stdc++.h>
#include "CSVManager.h"

using namespace std;

string RELATIVE_FILE_PATH="../contribuyentes/contribuyente01_v2.csv";

// Number of individuals in each generation
#define POPULATION_SIZE 1000

bool comparator(Individual a, Individual b){
    return a>b;
}

// Driver code
int main(int argc,char * argv[])
{
    vector<Individual> contrib_targets;
    vector<vector<int>> aux=CSVManager::readFile(RELATIVE_FILE_PATH); ///Codigo para testear lo del archivo nomas.
    vector<vector<int>>::iterator it=aux.begin();
    while(aux.end()!=it){
        string chromosome_target;
        vector<int>::iterator it2=it->begin();
        while(it->end()!=it2){
            //cout << *it2 << "\t";
            chromosome_target+=to_string(*it2);
            it2++;
        }
        Individual newtarget(chromosome_target);
        contrib_targets.push_back(newtarget);
        cout<<newtarget.chromosome;
        cout << endl;
        it++;
    }
                                     //Este es el codigo que hay que ejecutar una vez por cada enter
                                     //hay algun problema con las generaciones
    // current generation
    int generation = 0;
    vector<Individual> population;

    // create initial population
    for(int i = 0;i<POPULATION_SIZE;i++)
    {
        Individual ind;
        population.push_back(ind);
    }

    while(generation<contrib_targets.size())
    {
        string in;
        //cout<<"Presione cualquier tecla para continuar con la generación "<<generation<<"\n";

        Individual target=contrib_targets[generation];

        //Update weights of each individual

        for (int i=0;i<POPULATION_SIZE;i++) {
            population[i].updateWeights(target);
        }

        // sort the population in increasing order of fitness score
        sort(population.begin(), population.end(),comparator);

        cout<<"Esta es la poblacion"<<endl;
        for (int i=0;i<POPULATION_SIZE;i++)
            cout<<population[i]<<endl;

        // Otherwise generate new offsprings for new generation
        vector<Individual> new_generation;

        // Perform Elitism, that mean 10% of fittest population
        // goes to the next generation
        int s = 0.1*POPULATION_SIZE;
        for(int i = 0;i<s;i++)
            new_generation.push_back(population[i]);

        // From 50% of fittest population, Individuals
        // will mate to produce offspring
        s = POPULATION_SIZE-s;
        for(int i = 0;i<s;i++)
        {
            int r = Individual::random_num(0, POPULATION_SIZE*0.5);
            Individual parent1 = population.at(r);
            r = Individual::random_num(0, POPULATION_SIZE*0.5);
            Individual parent2 = population.at(r);
            Individual offspring = parent1.mate(parent2);
            new_generation.push_back(offspring);
        }
        population = new_generation;
        cout<< "Generation: " << generation << "\t";
        cout<< "Best individual: "<< population.at(0).chromosome <<"\t";
        cout<< "Fitness: "<< population.at(0).fitness << "\n";

        generation++;
    }
}
