#include <iostream>
#include <cstring>
#include <cstdint>
uint16_t hashLenght = 256;
int symToInt(const char sym, const uint8_t textLenght, const uint8_t chunk, char hash[], const char prewiosHash, int u) {
        char symbolsList[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ,.!?/:#$%&*+~`()-[]{}:;_'$<>";
        short int i = 0; while (i != sizeof(symbolsList) || i < hashLenght) {
                if (sym == symbolsList[i]) {break;}
                i++;
        }
        i = (((prewiosHash+chunk+17+textLenght)*i*73*textLenght+prewiosHash-1))-(i*chunk*prewiosHash)*(textLenght-chunk);
        if (hash[u-1] + hash[u-2] == hash[u-3] + hash[u-4]) {
			i = i * textLenght+chunk;
		}
        i = i % 10;
        return std::abs(i);
}
std::string shash(const std::string text) {  // main
		hashLenght++;
        char hash[hashLenght];
        uint8_t chunk = 0;
        short int i = 0; int symInText = 0; while (i != hashLenght) {
                if (sizeof(text) == symInText) {symInText = 0; chunk += 3; continue;}
                else {
					hash[i] = symToInt(text[symInText], sizeof(text), chunk, hash, hash[i-1], i);}
                i++;
                symInText++;
        }
		i = 0; uint16_t u = 1;
        char finhash[hashLenght]; while (i != hashLenght-1) {
                finhash[i] = '0' + hash[hashLenght-u];
                i++;
				u++;
        }
		std::string thash = finhash;
        return thash; 
}
