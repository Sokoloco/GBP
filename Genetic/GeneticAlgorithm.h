//
// Created by luis on 26/10/17.
//

#ifndef GBP_GENETICALGORITHM_H
#define GBP_GENETICALGORITHM_H

#include "/home/luis/CLionProjects/GBP/Structures/LinkedList.cpp"

class GeneticAlgorithm {
private:
    int size;
    struct specimen{
        double fitness;
        const static int size;
        int* dna;
    };
    LinkedList<specimen> pop;
public:
    explicit GeneticAlgorithm(int size);
    void fitness(specimen indi);
    void crossover(specimen indi1, specimen indi2);
    void mutate(specimen indi);

};

#endif //GBP_GENETICALGORITHM_H
