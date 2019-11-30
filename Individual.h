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
    string genePool='0123';
public:
    vector weight[8]={0,0,0,0,0,0,0,0};
    string chromosome="";
    int fitness=0;

    Individual();
    Individual(string chromosome);
    Individual(string chromosome,vector weight);
    Individual mate(Individual parent2);
    bool operator<(const Individual &ind1, const Individual &ind2);
    char getMutatedGene(int geneNumber);
    static int random_num(int start, int end);
    int calFitness();
    void updateWeights();
};

Individual::Individual(string chromosome)
{
    this->chromosome = chromosome;
    for(int i = 0;i<8;i++)
    {
        weight.push_back(0);
    }
};

Individual::Individual()
{
    string newcrom = "";
    for(int i = 0;i<8;i++)
    {
        newcrom += getMutatedGene(i);
        weight.push_back(0);
    }
    chromosome=newcrom;
};

Individual::Individual(string chromosome,vector<int> weight)
{
    this->weight=weight;
    this->chromosome = chromosome;
    fitness = calFitness();
};

// Perform mating and produce new offspring
Individual Individual::mate(Individual par2)
{
    // chromosome for offspring
    string child_chromosome = "";
    vector<int> child_weight;
    child_weight.clear();
    for(int i = 0;i<8;i++)
    {
        // random probability
        float p = random_num(0, 100)/100;

        // if prob is less than 0.50, insert gene
        // from parent 1
        if(p < 0.5)
        {
            child_chromosome += chromosome[i];
            child_weight.push_back(weight.at(i));
        }
            // if prob is between 0.50, insert gene
            // gene from parent 2
        else
        {
            child_chromosome += par2.chromosome[i];
            child_weight.push_back(par2.weight.get(i));
        }
            // insert random genes(mutate),
            // for maintaining diversity
            for (int i=0;i<8;i++)
            {
                float p = random_num(0, 100)/100;
                if (p<0.05)
                child_chromosome[i] = getMutatedGene(i);
            }
    }

    // create new Individual(offspring) using
    // generated chromosome for offspring
    return Individual(child_chromosome);
};

bool Individual::operator<(const Individual &ind1, const Individual &ind2)
{
return ind1.fitness < ind2.fitness;
}

char Individual::getMutatedGene(int geneNumber) //Hay que cambiar esta funcion para que devuelva entre rangos distintos dependiendo del gen que se esta mutando
{
    if (geneNumber<=2)
    {
        return genePool[random_num(0, 1);];
    }
    else
    {
        return genePool[random_num(0, 3);];
    }
}

static int Individual::random_num(int start, int end)
{
    srand(time(null));
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}

int Individual::calFitness() {
    int sum=0;
    for (int i=0;i<8;i++)
    {
        sum=sum+weight.at(i);
    }
    return sum;
}

void Individual::updateWeights(Individual target) {
    for (int i=0;i<8;i++)
    {
        if (chromosome[i]==target.chromosome.[i])
            weight[i]++;
    }
}

#endif //EXPLORATORIAV2_INDIVIDUAL_H
