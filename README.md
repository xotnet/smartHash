# smartHash
simple hash lib on C++. You can use this library if you don't want to use a heavier library (Build weight ~40 kB)

Example usage (you must to put shash return to std::string)
```
#include <iostream>
#include <conio.h>
#include "smartHash.hpp"    // our lovest lib
int main() {
    std::string pass;
    printf("phase for hashing: ");
    std::getline(std::cin,pass);
    std::string hashedPhase = shash(pass);
    std::cout << hashedPhase << "\n";
    getch();
    return 0;
}
```

Return example: ```042906748568921390893210312026750935743449568720333950893019588270676163269119148967673390827718913912707611398248521363012632236988722568713782222005704893331132558902685233115767214922382139892016130104233297162112128709937585890872879739153985891322100``` (if you select 256 bit hash)

```018252895037421319529852122423322587298872249739153721291322100``` (if you select 64 bit hash)

* tested on C++ 13

BitCoin DONATION ☕️: ```bc1q24sqqj6p6htuktap2vht2uzna9u7w3wlk8kfwk```

Monero DONATION ☕️: ```86FBJmZrMPcQvNQJ7fJ1Khg9Z1YMUBE2N6jzPiUbLtaKWQD1sTHbcB5JmCmxmNDkKXXQkic5pezv5hR6BLTvrSvvK7wA5LR```
