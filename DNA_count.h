#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
/*this header file will contain the names of the methods we will utilize
& it references the cclasses containing the input, etc */
class DNA_count
{
  public: // makes the info initialized in the class able to be used in other classes
    DNA_count();
    ~DNA_count(); // destructor
    // begins to initiazlize every public variable / method that will be referenced
    double lines;
    double sum;
    double mean;
    double variance;
    double stdv;
    string line;
    double sumOfBigrams;
    double testBigram;
    int length;

    string test;
    string yesOrno;                                                                                                

    double a;
    double b;
    double c;
    int d;
    string gausPrint;
    double rnum;
    double pi;

    double probGA;
    double probGT;
    double probGC;
    double probGG;

    double probAT;
    double probAC;
    double probAA;
    double probAG;

    double probTC;
    double probTT;
    double probTG;
    double probTA;

    double probCC;
    double probCG;
    double probCA;
    double probCT;

    double probA;
    double probT;
    double probG;
    double probC;

    double num_of_A;
    double num_of_T;
    double num_of_C;
    double num_of_G;

    double num_of_AA;
    double num_of_AT;
    double num_of_AC;
    double num_of_AG;

    double num_of_GA;
    double num_of_GT;
    double num_of_GC;
    double num_of_GG;

    double num_of_TA;
    double num_of_TT;
    double num_of_TC;
    double num_of_TG;

    double num_of_CA;
    double num_of_CT;
    double num_of_CC;
    double num_of_CG;

    double sumGet();
    double meanGet();
    double varianceGet();
    double stdvGet();

    double getA();
    double getT();
    double getG();
    double getC();

    double getAA();
    double getAC();
    double getAG();
    double getAT();

    double getTA();
    double getTC();
    double getTG();
    double getTT();

    double getGA();
    double getGC();
    double getGG();
    double getGT();

    double getCA();
    double getCC();
    double getCG();
    double getCT();
    string getGaus();

    void calculateEverything();
    void stdd();
    void getProbability();
    void gaussian(ofstream&);
};
