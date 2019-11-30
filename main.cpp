#include <iostream>
#include "Individual.h"
#include <bits/stdc++.h>

using namespace std;

// Number of individuals in each generation
#define POPULATION_SIZE 100

// Driver code
int main(int argc,char * argv[])
{
    string target="null";
    // current generation
    int generation = 0;
    vector<Individual> population;
    bool found = false;
    // create initial population
    for(int i = 0;i<POPULATION_SIZE;i++)
    {
        Individual ind;
        population.push_back(ind);
    }

    while(! found)
    {
        Individual target=///ESCRIBIR CODIGO PARA OBTENER NUEVO TARGET

        //Update weights of each individual

        for (int i=0;i<POPULATION_SIZE;i++) {
            population[i].updateWeights(target);
        }

        // sort the population in increasing order of fitness score
        sort(population.begin(), population.end());

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
