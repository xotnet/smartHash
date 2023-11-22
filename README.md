# smartHash
simple hash lib on C++. You can use this library if you don't want to use a heavier library (Build weight ~40 kB)

Example usage (you must to put shash return to std::string)
```
#include <iostream>
#include "smartHash.hpp"
int main() {
    std::string pass;
    printf("phase for hashing: ");
    std::cin >> pass;
    std::string hashedPhase = shash(pass);
    std::cout << hashedPhase << "\n";
}
```

Return example: ```7818474767438369810121281812989878105218818149292181852181892369898652986529015865294986529876721078360707834323070363614149278745412541254109941254168383029832109230923085496106161092306107854587258725874529630727258729456167032347034725083470123470323478``` (if you select 256 bit hash)

```6725872563019257587257256301187623234703296076187034723470189478``` (if you select 64 bit hash)

* tested on C++ 13

BitCoin DONATION ☕️: ```bc1q24sqqj6p6htuktap2vht2uzna9u7w3wlk8kfwk```

Monero DONATION ☕️: ```86FBJmZrMPcQvNQJ7fJ1Khg9Z1YMUBE2N6jzPiUbLtaKWQD1sTHbcB5JmCmxmNDkKXXQkic5pezv5hR6BLTvrSvvK7wA5LR```
