//
// Created by thomas on 29/11/19.
//

#ifndef EXPLORATORIAV2_INDIVIDUAL_H
#define EXPLORATORIAV2_INDIVIDUAL_H
#include <string>
#include "Individual.h"
#include "time.h"
#include <vector>

using namespace std;

class Individual {
public:
    static string genePool;
    vector<int> weight;
    string chromosome;
    int fitness=0;
    Individual();
    Individual(string chromosome);
    Individual(string chromosome,vector<int> weight);
    Individual mate(Individual parent2);
    bool operator<(const Individual &ind2);
    bool operator>(const Individual &ind2);
    char getMutatedGene(int geneNumber);
    static int random_num(int start, int end);
    int calFitness();
    void updateWeights(Individual target);
    string classify();
};

string Individual::genePool="0123";


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
    string newcrom;
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
        float p = random_num(0,100)/100;

        // if prob is less than 0.50, insert gene
        // from parent 1
        if(p < 0.5)
        {
            child_chromosome += chromosome[i];
            child_weight.push_back(weight[i]);
        }
            // if prob is between 0.50, insert gene
            // gene from parent 2
        else
        {
            child_chromosome += par2.chromosome[i];
            child_weight.push_back(par2.weight[i]);
        }
            // insert random genes(mutate),
            // for maintaining diversity
            for (int i=0;i<8;i++)
            {
                int p = random_num(0, 99);
                if (p==0)
                child_chromosome[i] = getMutatedGene(i);
            }
    }

    // create new Individual(offspring) using
    // generated chromosome and weight for offspring
    return Individual(child_chromosome,child_weight);
};

bool Individual::operator<(const Individual &ind2)
{
return this->fitness < ind2.fitness;
};

char Individual::getMutatedGene(int geneNumber)
{
    if (geneNumber<=2)
    {
        return genePool[random_num(0, 1)];
    }
    else
    {
        return genePool[random_num(0, 3)];
    }
};

int Individual::random_num(int start, int end)
{
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
};

int Individual::calFitness() {
    int sum=0;
    for (int i=0;i<8;i++)
    {
        sum=sum+weight[i];
    }
    return sum;
}

void Individual::updateWeights(Individual target) {
    for (int i=0;i<8;i++)
    {
        if (chromosome[i]==target.chromosome[i])
            weight[i]++;
    }
    fitness=calFitness();
}

bool Individual::operator>(const Individual &ind2) {
    return this->fitness > ind2.fitness;
};

ostream &operator<<( ostream &output, const Individual &I ) {
    output << "Cromosoma : " << I.chromosome << " Fitness : " << I.fitness;
    return output;
}

string Individual::classify() {
    int gen1=(int)(chromosome.at(0))-48;
    int gen2=(int)(chromosome.at(1))-48;
    int gen3=(int)(chromosome.at(2))-48;
    int gen4=(int)(chromosome.at(3))-48;
    int gen5=(int)(chromosome.at(4))-48;
    int gen6=(int)(chromosome.at(5))-48;
    int gen7=(int)(chromosome.at(6))-48;
    int gen8=(int)(chromosome.at(7))-48;
    //cout << "dentro de classify()" << endl;
    //cout << "gen1: " << gen1 << ",gen2: " << gen2 << ",gen3: " << gen3 << ",gen4: " << gen4 << ",gen5: " << gen5 << "gen6: " << gen6 << "gen7: " << gen7 << ",gen8: " << gen8 << endl;
    int aux=3*(3*gen2+gen6)+2*(3*gen1+3*gen3+gen7)+gen4+gen5+gen8;
    //cout << "Aux: " <<  aux << endl;
    if(aux>=0 && aux<=2)
        return "Categoria A";
    if(aux>=3 && aux<=6)
        return "Categoria B";
    if(aux>=7 && aux<=11)
        return "Categoria C";
    if(aux>=12 && aux<=20)
        return "Categoria D";
    if(aux>=21 && aux <=45)
        return "Categoria E";
    return "EEROR";
}

#endif //EXPLORATORIAV2_INDIVIDUAL_H
