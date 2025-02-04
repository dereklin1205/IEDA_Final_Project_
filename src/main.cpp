#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "MBFFOptimizer.h"
using namespace std;
int main(int argc, char **argv)
{
    fstream input, output;
    if (argc == 3)
    {
        input.open(argv[1], ios::in);
        // output.open(argv[2], ios::out);
        if (!input)
        {
            cerr << "Cannot open the input file \"" << argv[1]
                 << "\". The program will be terminated..." << endl;
            exit(1);
        }
        if (!output)
        {
            cerr << "Cannot open the output file \"" << argv[2]
                 << "\". The program will be terminated..." << endl;
            exit(1);
        }
    }
    else
    {
        cerr << "Usage: ./fm <input file> <output file>" << endl;
        exit(1);
    }

    MBFFOptimizer *optimizer = new MBFFOptimizer(input, argv[2]);
    cout << "check" << endl;
    // optimizer->printInput();
    // optimizer->placement();

    // optimizer->check_disjoint_set();
    optimizer->init_occupied();

    // cout << "123444\n";
    // optimizer->printPlacement();
    // optimizer->printWeight();
    optimizer->algorithm();
    // optimizer->print_ff_change();
    cout << "total runtime: " << (double)clock() / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
