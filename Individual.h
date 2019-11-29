//
// Created by thomas on 29/11/19.
//

#ifndef EXPLORATORIAV2_INDIVIDUAL_H
#define EXPLORATORIAV2_INDIVIDUAL_H
#include <string>
#include "Individual.h"
#include "time.h"
using namespace std;
class Individual {
public:
    string chromosome;
    int fitness;
    Individual(string chromosome);
    Individual mate(Individual parent2);
    int cal_fitness();
    bool operator<(const Individual &ind1, const Individual &ind2);
};

Individual::Individual(string chromosome)
{
    this->chromosome = chromosome;
    fitness = cal_fitness();
};

// Perform mating and produce new offspring
Individual Individual::mate(Individual par2)
{
    // chromosome for offspring
    string child_chromosome = "";

    int len = chromosome.size();
    for(int i = 0;i<len;i++)
    {
        time.srand
        // random probability
        float p = random_num(0, 100)/100;

        // if prob is less than 0.45, insert gene
        // from parent 1
        if(p < 0.45)
            child_chromosome += chromosome[i];

            // if prob is between 0.45 and 0.90, insert
            // gene from parent 2
        else if(p < 0.90)
            child_chromosome += par2.chromosome[i];

            // otherwise insert random gene(mutate),
            // for maintaining diversity
        else
            child_chromosome += mutated_genes();
    }

    // create new Individual(offspring) using
    // generated chromosome for offspring
    return Individual(child_chromosome);
};

Individual::bool operator<(const Individual &ind1, const Individual &ind2);
{
return ind1.fitness < ind2.fitness;
}


#endif //EXPLORATORIAV2_INDIVIDUAL_H
