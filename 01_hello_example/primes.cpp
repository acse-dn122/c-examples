// A simple primes calculator
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    int i = 2;
    int count = 0;
    
    while (count<std::atoi(argv[1])) {
        int j = 2;
        bool flag = true;
        while (j*j<=i) {
            if (i%j==0) {
                flag = false;
                break;
            }
            j++;
        }
        if (flag) {
            std::fstream fs;

            if (count==0) {
                fs.open (argv[2], std::fstream::out);
            } else {
                fs.open (argv[2], std::fstream::app);
            }

            fs << i << "\n";
            fs.close();

            count ++;
        }
        i++;
    }
    return 0;
}