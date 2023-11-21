# smartHash
simple hash lib on C++

Example usage
```
#include <iostream>
#include "smartHash.cpp"
int main() {
    std::string pass;
    printf("phase for hashing: ");
    std::cin >> pass;
    std::string hashedPhase = shash(pass);
    std::cout << hashedPhase << "\n";
}
```
