#include <iostream>
#include <cstring>
#include <cstdint>
uint16_t hashLenght = 256;
int symToInt(const char sym, const uint8_t textLenght, const uint8_t chunk, const char prewiosHash, bool isRepeated, const char hash[], uint16_t u) {
        char symbolsList[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ,.!?/:#$%&*+~`()-[]{}:;_'$<>";
        int64_t i = 0; while (i != sizeof(symbolsList) || i < hashLenght) {
			if (sym == symbolsList[i]) {break;}
			i++;
        }
		if (i%2==0) {i = i*24;} else {i = i*13;}
		uint16_t prewSumOfHashChunk = 0;
		if (hash[u-textLenght] != 0) {prewSumOfHashChunk = hash[u-textLenght] + hash[u-textLenght-1] + hash[u-textLenght-2] + hash[u-textLenght-3];}
        i = ((i+1)*73+chunk*(textLenght-prewiosHash-chunk+prewSumOfHashChunk)) + (prewSumOfHashChunk+prewiosHash-chunk*2) + (i*chunk*prewiosHash*91) + chunk*4 - ((prewSumOfHashChunk-chunk-7)*prewiosHash) - (557/(prewiosHash+1));
        if (isRepeated) {
			i = 0-(i*textLenght+prewiosHash+chunk/7)*3;
		}
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
				hash[i] = symToInt(text[symInText], sizeof(text), chunk, hash[i-1], isRepeated, hash, i);}
			i++;
			symInText++;
        }
		i = 0;
        char finhash[hashLenght]; while (i < hashLenght) {
                finhash[i] = hash[hashLenght-i] + '0';
                i++;
        }
		std::string thash = finhash;
        return thash; 
}
