#include <iostream>
#include <cstring>
#include <cstdint>
uint16_t hashLenght = 256;
int symToInt(const char sym, const uint8_t textLenght, const uint8_t chunk, const char prewiosHash, bool isRepeated) {
        char symbolsList[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ,.!?/:#$%&*+~`()-[]{}:;_'$<>";
        int64_t i = 0; while (i != sizeof(symbolsList) || i < hashLenght) {
			if (sym == symbolsList[i]) {break;}
			i++;
        }
        i = ((prewiosHash+chunk+17+textLenght)*i*73*textLenght+prewiosHash-chunk)*chunk-(i*chunk*prewiosHash)*(textLenght-chunk);
        if (isRepeated) {
			i = (i*textLenght+chunk)*2;
		}
		std::cout << std::to_string(chunk) << "\n";
        i = i % 10;
        return std::abs(i);
}
std::string shash(const std::string text) {  // main
		hashLenght--;
        char hash[hashLenght];
        uint16_t chunk = 0;
        uint16_t i = 0; int symInText = 0; while (i < hashLenght) {
			if (text.length() == symInText) {symInText = 0; chunk++; continue;}
			else {
				bool isRepeated = false; if (hash[i-1] + hash[i-2] == hash[i-3] + hash[i-4]) {isRepeated = true;}
				hash[i] = symToInt(text[symInText], sizeof(text), chunk, hash[i-1], isRepeated);}
			i++;
			symInText++;
        }
		i = 0;
        char finhash[hashLenght]; while (i < hashLenght-1) {
                finhash[i] = hash[hashLenght-i] + '0';
                i++;
        }
		std::string thash = finhash;
        return thash; 
}
