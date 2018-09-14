#include "DNA_count.h" // allows for references to the public instance variables defined in the header file
#include <fstream>
#include <string>

#include <math.h> // lets me use the pow & sqrt functions
using namespace std; //this allows for me to use RAND_MAX in gaussian()
//this is the actual implementation file

DNA_count::DNA_count(){}
DNA_count::~DNA_count() //destructor
{
  cout<<"object deleted"<<endl; // proves that the memory has been disposed of
}

    double DNA_count::meanGet() // these first 4 methods reference the void calculateEverything() method (allows for cleaner print staements in the main)
    {
      return mean;
    }
    double DNA_count::sumGet()
    {
      return sum;
    }
    double DNA_count::varianceGet()
    {
      return variance;
    }
    double DNA_count::stdvGet()
    {
      return stdv;
    }
    double DNA_count::getAA() // these next 21 methods reference the void getProbability() method (allows for cleaner print staements in the main)
    {
      return probAA;
    }
    double DNA_count::getAT()
    {
      return probAT;
    }
    double DNA_count::getAC()
    {
      return probAC;
    }
    double DNA_count::getAG()
    {
      return probAG;
    }

    double DNA_count::getTA()
    {
      return probTA;
    }
    double DNA_count::getTT()
    {
      return probTT;
    }
    double DNA_count::getTC()
    {
      return probTC;
    }
    double DNA_count::getTG()
    {
      return probTG;
    }

    double DNA_count::getCA()
    {
      return probCA;
    }
    double DNA_count::getCT()
    {
      return probCT;
    }
    double DNA_count::getCC()
    {
      return probCC;
    }
    double DNA_count::getCG()
    {
      return probCG;
    }

    double DNA_count::getGA()
    {
      return probGA;
    }
    double DNA_count::getGT()
    {
      return probGT;
    }
    double DNA_count::getGC()
    {
      return probGC;
    }
    double DNA_count::getGG()
    {
      return probGG;
    }

    double DNA_count::getA()
    {
      return probA;
    }
    double DNA_count::getT()
    {
      return probT;
    }
    double DNA_count::getG()
    {
      return probG;
    }
    double DNA_count::getC()
    {
      return probC;
    }

    string DNA_count::getGaus() // allows for a clean print of the 1000 new strings we generated in the void gaussian() method
    {
      return gausPrint;
      //return "this should be the new strands";
    }

  void DNA_count::calculateEverything()
  {
    // helpful references to run through each line of a file found at
    // https://stackoverflow.com/questions/41456245/is-it-possible-to-iterate-through-a-text-file-lines-and-use-stringstream-to-pars
      ifstream DNAfile(test);  //take the name of file !!!!!!!! do that                            
      if (DNAfile)
      {
        // adding individual lengths of string help found at http://www.cplusplus.com/reference/string/string/length/ + stackoverflow
        while (getline(DNAfile,line))
        {
          sum += line.length(); //adds the length of every single line in the test file to add to the sum
          lines++; // total number of lines in the txt file
          testBigram = (sum-lines); // calculates the total number of bigrams in the file, no matter how they touch (ATC >>> AT & TC)
          for (int i =0; i < line.length(); i++) //loops through the file and sees if there exists an A, if so it adds to the A count for a single nucleotide
                                                 //and then checks the second index for the second letter in the bigram and adds to that count
          {
            if (line[i] == 'A' || line[i] == 'a') // not the most efficient way but this checks for case sensitive nucleotides (lower and upper). it does this check for EVERY SINGLE NUCLEOTIDE
            {
              num_of_A++; // countys the single nucleotide A, then goes into another if/else if block to ckeck the bigram. does this for every letter
              if(line[i+1] == 'A' || line[i+1] == 'a')
              {
                num_of_AA++;
              }
              else if(line[i+1] == 'C' || line[i+1] == 'c')
              {
                num_of_AC++;
              }
              else if(line[i+1] == 'T' || line[i+1] == 't')
              {
                num_of_AT++;
              }
              else if(line[i+1] == 'G'|| line[i+1] == 'g')
              {
                num_of_AG++;
              }
            }
            else if (line[i] == 'C' || line[i] == 'c')//loops through the file and sees if there exists an C, if so it adds to the A count for a single nucleotide
                                                      //and then checks the second index for the second letter in the bigram and adds to that count
            {
              num_of_C++;
              if(line[i+1] == 'A' || line[i+1] == 'a')
              {
                num_of_CA++;
              }
              else if(line[i+1] == 'C'|| line[i+1] == 'c')
              {
                num_of_CC++;
              }
              else if(line[i+1] == 'T' || line[i+1] == 't')
              {
                num_of_CT++;
              }
              else if(line[i+1] == 'G' || line[i+1] == 'g')
              {
                num_of_CG++;
              }
            }
            else if (line[i] == 'G' || line[i] == 'g')//loops through the file and sees if there exists an G, if so it adds to the A count for a single nucleotide
                                                      //and then checks the second index for the second letter in the bigram and adds to that count
            {
              num_of_G++;
              if(line[i+1] == 'A' || line[i+1] == 'a')
              {
                num_of_GA++;
              }
              else if(line[i+1] == 'C' || line[i+1] == 'c')
              {
                num_of_GC++;
              }
              else if(line[i+1] == 'T' || line[i+1] == 't')
              {
                num_of_GT++;
              }
              else if(line[i+1] == 'G' || line[i+1] == 'g')
              {
                num_of_GG++;
              }
            }
            else if (line[i] == 'T' || line[i] == 't')//loops through the file and sees if there exists an T, if so it adds to the A count for a single nucleotide
                                                      //and then checks the second index for the second letter in the bigram and adds to that count
            {
              num_of_T++;
              if(line[i+1] == 'A'|| line[i+1] == 'a')
              {
                num_of_TA++;
              }
              else if(line[i+1] == 'C'|| line[i+1] == 'c')
              {
                num_of_TC++;
              }
              else if(line[i+1] == 'T' || line[i+1] == 't')
              {
                num_of_TT++;
              }
              else if(line[i+1] == 'G' || line[i+1] == 'g')
              {
                num_of_TG++;
              }
            }
          }
        }
        mean = sum/lines; //math for the mean (calulated in the while loop above)
      }
      else
      {
        cout <<"Error Reading File. "<<endl;
      }
      DNAfile.close(); //closes the test file so that it does not keep executing
  }
  void DNA_count::stdd()
  {
    // i learned how to loop through each line in the file on stackoverflow, specifically
    //https://stackoverflow.com/questions/41456245/is-it-possible-to-iterate-through-a-text-file-lines-and-use-stringstream-to-pars
    ifstream DNAfile(test);
    if (DNAfile) // checks to see if we are testing the correct file for DNA strands
    {
      //input check                                                                                                        *****************************************
      // adding individual lengths of string help found at http://www.cplusplus.com/reference/string/string/length/ + stackoverflow
      while (getline(DNAfile,line)) // runs through each line in the test file
      {
        stdv += pow (line.length() - mean , 2.0); //does this math for each individual line in the test file and adds each value to the value of stdv
      }
      stdv = sqrt(stdv/lines);   // once again updates the value of stdv according to the standard deviation formula
      variance = pow(stdv, 2.0); // uses the value we obtained from the standard deviation formula (stdv), finds the variance
    }
    else
      cout << "bad file";
  }
  void DNA_count::getProbability() // calculates the probability of getting every single possible combination of bigrams & single nucleotides.
                                   // all the variables used below are defined and solved for in the void methods above
  {
    probA = num_of_A/sum;
    probT = num_of_T/sum;
    probG = num_of_G/sum;
    probC = num_of_C/sum;

    probTT = num_of_TT/testBigram;
    probTC = num_of_TC/testBigram;
    probTG = num_of_TG/testBigram;
    probTA = num_of_TA/testBigram;

    probAT = num_of_AT/testBigram;
    probAC = num_of_AC/testBigram;
    probAG = num_of_AG/testBigram;
    probAA = num_of_AA/testBigram;


    probCT = num_of_CT/testBigram;
    probCC = num_of_CC/testBigram;
    probCG = num_of_CG/testBigram;
    probCA = num_of_CA/testBigram;

    probGT = num_of_GT/testBigram;
    probGC = num_of_GC/testBigram;
    probGG = num_of_GG/testBigram;
    probGA = num_of_GA/testBigram;
  }

  void DNA_count::gaussian(ofstream& endfile) // this method creates the 1000 new DNA nucleotides
  {
      for (int k = 0; k < 1000; k++) //loops around for 1000 values
      {
        pi = M_PI; // using  math.h in the #include brackets, we can get a default pi value
        a = rand() / (double)RAND_MAX+1.0; // a and b represent the 2 random values in the gaussian formula
        b = rand() / (double)RAND_MAX+1.0; // divide a random number by a LARGE random number to get a probability to compare below
        c = sqrt(( (-2) * (log(a)) )*(cos(2*pi*b))); // uses the box-muller transform to compute the variable c
        d = (int)((stdv*(c)) + mean); //plug in the value we got for c to the standard gaussian formula
        endfile << '\n' ;
        // i watched the khan academy vid about gaussian distribution
        // got help understanding generating random numbers w/ rand max on http://www.cplusplus.com/forum/beginner/73642/ + stackoverflow
        // helpful information regarding box-muller found at https://en.cppreference.com/w/cpp/numeric/random/normal_distribution
                               // this is the length we are testing gainst below


        // finds the value to test againt the probability of getting each A, T, G, or C
        for (int e = 0 ; e < d; e++) // makes each new DNA string a different length
        {
          rnum = rand() / (double)RAND_MAX;
          gausPrint = " "; //creates an empty string to nicely append the 1000 new strands to
          if (rnum <= probA) // if the random number generated falls under one of the probabilities listed below, that nucleotide
                            // is appended to the empty gausPrint string
          {
            //gausPrint+= "A";
            endfile << "A" ;
          }

          else if (rnum > probA && rnum <= (probA+probT))
          {
            //gausPrint+= "T";
            endfile << "T" ;
          }
          else if (rnum > (probA+probT) && rnum <= (probA+probT+probG))
          {
            //gausPrint+= "G";
            endfile << "G" ;
          }
          else
          {
            //gausPrint+= "C";
            endfile << "C" ;
          }
        }
      }
  }
