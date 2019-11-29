//
// Created by thomas on 29/11/19.
//

#ifndef EXPLORATORIAV2_INDIVIDUAL_H
#define EXPLORATORIAV2_INDIVIDUAL_H
#include <string>
#include "Individual.h"
#include "time.h"
#inclyde "Vector.h"
using namespace std;
class Individual {
    string genePool='0123';
public:
    Vector weight[8]={0,0,0,0,0,0,0,0};
    string chromosome;
    int fitness;
    Individual(string chromosome);
    Individual mate(Individual parent2);
    int cal_fitness();
    bool operator<(const Individual &ind1, const Individual &ind2);
    char getMutatedGene(int geneNumber);
    static int random_num(int start, int end);
};

Individual::Individual(string chromosome)
{
    this->chromosome = chromosome;
    fitness = cal_fitness();
    for(int i = 0;i<8;i++)
    {
        gnome += getMutatedGene(i);
        weight.add(0);
    }
};

Individual::Individual()
{
    this->chromosome=Chromosome c;
    string gnome = "";
    for(int i = 0;i<8;i++)
    {
        gnome += getMutatedGene(i);
        weight.add(0);
    }

};

Individual::Individual(string chromosome,Vector<int> weight)
{
    this->weight=weight;
    this->chromosome = chromosome;
    fitness = cal_fitness();
    for(int i = 0;i<8;i++)
    {
        gnome += getMutatedGene(i);
        weight.push_back(weight.get(i));
    }
};

// Perform mating and produce new offspring
Individual Individual::mate(Individual par2)
{
    // chromosome for offspring
    string child_chromosome = "";
    Vector<int> child_weight;
    for(int i = 0;i<8;i++)
    {
        // random probability
        float p = random_num(0, 100)/100;

        // if prob is less than 0.50, insert gene
        // from parent 1
        if(p < 0.5)
            child_chromosome += chromosome[i];
            child_weight.push_back(weight.get(i));
            // if prob is between 0.50, insert gene
            // gene from parent 2
        else
            child_chromosome += par2.chromosome[i];
            child_weight.push_back(par2.weight.get(i));
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
int range = (end-start)+1;
int random_int = start+(rand()%range);
return random_int;
}

string Individual::create_gnome()
{

}


#endif //EXPLORATORIAV2_INDIVIDUAL_H
