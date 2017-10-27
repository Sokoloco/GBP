//
// Created by luis on 26/10/17.
//

#include "GeneticAlgorithm.h"


void GeneticAlgorithm::crossover(specimen indi1, specimen indi2) {
    specimen new1{};
    specimen new2{};
    for(int i = 0; i<size/2;i++){
        new1.dna[i] = indi1.dna[i];
        new1.dna[i+size/2] = indi2.dna[i+size/2];
        new2.dna[i] = indi2.dna[i];
        new2.dna[i+size/2] = indi1.dna[i+size/2];
    }
    fitness(new1);
    mutate( new1);
    pop.add(new1);
    fitness(new2);
    mutate( new2);
    pop.add(new2);
}

void GeneticAlgorithm::fitness(GeneticAlgorithm::specimen indi) {
    int score = 0;
    for(int i = 0;i<size;i++){
        if(i == indi.dna[i])
            score++;
    }
    indi.fitness = score/size;
}

void GeneticAlgorithm::mutate(GeneticAlgorithm::specimen indi) {
    if((rand() % 100) < 95){
        int indx1 = rand()%(size);
        int indx2 = rand()%(size);
        int temp  = indi.dna[indx2];
        indi.dna[indx2] = indi.dna[indx1];
        indi.dna[indx1] = temp;
    }
}

GeneticAlgorithm::GeneticAlgorithm(int size) {
    this->size = size;
}