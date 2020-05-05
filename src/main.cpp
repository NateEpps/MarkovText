//
// main.cpp
// Nathanael Epps
//

#include <iostream>
#include "Markov.hpp"
#include "Util.hpp"

static int launch(std::vector<std::string> args)
{
    using std::cout;
    
    bool isDebug = std::find(args.begin(), args.end(), "--debug") != args.end() ||
                   std::find(args.begin(), args.end(), "-d") != args.end();
    
    if (args.size() < 3) {
        std::cerr << "Usage: " << args[0] << " (order) (size of output)\n";
        return EXIT_FAILURE;
    }
    
    // read input, and check order
    const string input = readAll(std::cin);
    const size_t order = (size_t) stringToInt(args[1]);
    
    if (order > input.length()) {
        std::cerr << "Error: order > input.length()\n";
        return EXIT_FAILURE;
    }
    
    // create model
    Markov mark (input, order);
    if (isDebug)
        cout << "\n" << mark.toString() << "\n";
    
    // output N characters, including seed
    const int N = stringToInt(args[2]);
    if (N < 0) {
        std::cerr << args[0] << ": Cannot output negative amount of characters\n";
        return EXIT_FAILURE;
    }

    string kgram = input.substr(0, order);
    
    if (isDebug)
        cout << "\nMarkov model (order " << order << ", " << N << " characters):\n";

    // edge case
    if (N < order) {
        cout << kgram.substr(0, N) << "\n";
        return 0;
    }

    cout << kgram;

    // print characters
    for (int x = order; x < N; x++)
    {
        // get next character
        char next = mark.next(kgram);
        
        // print it
        cout << next;
        std::flush(cout);
        
        // add it to kgram
        kgram += next;
        
        // chop off first character
        kgram = kgram.substr(1);
    }
    
    cout << "\n";
    
    return 0;
}

int main(int argc, const char** argv)
{
    try {
        std::vector<std::string> args (argv, argv + argc);
        
        return launch(args);
    }
    catch (std::runtime_error& err) {
        std::cerr << "\nRuntime error:\n\t" << err.what() << "\n";
        return -1;
    }
    catch (std::exception& ex) {
        std::cerr << "\nException:\n\t" << ex.what() << "\n";
        return -2;
    }
    catch (...) {
        std::cerr << "\nUnknown error type:\n\tUnknown Error!\n";
        return -3;
    }
    
    return -4;
}
