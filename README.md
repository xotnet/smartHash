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

Example file hashing
```
#include <iostream>
#include <conio.h>
#include <fstream>
#include "smartHash.hpp"    // our lovest lib

std::string hashing(std::string filepath) {
	std::ifstream file(filepath);
	char buffer[4096];
	if (file.is_open()) {
		file.read(buffer,4096);
		file.close();
		std::string fileHash = shash(buffer);
		return fileHash;
	}
	else {printf("file cant be readed\n"); return "incorrect";}
}

int main() {
    std::string filepath;
	std::string response;
	while (true) {
		printf("file for hashing: ");
		std::getline(std::cin,filepath);
		response = hashing(filepath);
		if (response != "incorrect") {break;}
	}
	std::cout << response << "\n";
    getch();
    return 0;
}
```

Return example: ```6084461197753165478545549237694554940051908446113604285703014507454723455492448600844611360426654721455495472145549244684864224486008440576945547703414507270053308446119775342247614501167069698365446848642244860644224769616365698145074916860644224684208644``` (if you select 256 bit hash)

```9199149420842703119193698197755034942245549244607692840047278644``` (if you select 64 bit hash)

* tested on C++ 13

BitCoin DONATION ☕️: ```bc1q24sqqj6p6htuktap2vht2uzna9u7w3wlk8kfwk```

Monero DONATION ☕️: ```86FBJmZrMPcQvNQJ7fJ1Khg9Z1YMUBE2N6jzPiUbLtaKWQD1sTHbcB5JmCmxmNDkKXXQkic5pezv5hR6BLTvrSvvK7wA5LR```
