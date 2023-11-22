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

Return example: ```149692921290121690163858383816908024246440600242442422622064408010141454527816965678527670767832868064086806228208062228408848087832183436107234147454963096787064468842808886088262668662202260123634783892389696703092785274308882048626640406066062262026640``` (if you select 256 bit hash)

```149692343474721238121296127034100484628004026462246228084848482``` (if you select 64 bit hash)

* tested on C++ 13

BitCoin DONATION ☕️: bc1q24sqqj6p6htuktap2vht2uzna9u7w3wlk8kfwk
Monero DONATION ☕️: 86FBJmZrMPcQvNQJ7fJ1Khg9Z1YMUBE2N6jzPiUbLtaKWQD1sTHbcB5JmCmxmNDkKXXQkic5pezv5hR6BLTvrSvvK7wA5LR
