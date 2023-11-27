#include <iostream>
#include <cstring>
#include <cstdint>
uint16_t hashLenght = 256;
int symToInt(const char sym, const uint8_t textLenght, const uint8_t chunk, const char prewiosHash, bool isRepeated, uint16_t u) {
        char symbolsList[] = " abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ,.!?/:#$%&*+~`()-[]{}:;_'$<>";
        int64_t i = 0; while (i != sizeof(symbolsList) || i < hashLenght) {
			if (sym == symbolsList[i]) {break;}
			i++;
        } i = (i+1)*13+chunk*(textLenght-prewiosHash-chunk-i) + ((prewiosHash+chunk)*2) + (i*chunk*prewiosHash*11) + chunk*4 - ((chunk-7)*prewiosHash) - (557/(prewiosHash+1))*u;
        if (isRepeated) {i = 0-(i*(textLenght+prewiosHash+chunk)/7)*u;}
		while (i > 99999) {i = i/11;}
        i = i % 10;
        return std::abs(i);
}
std::string shash(const std::string text) {//     MAIN (Call it like: shash("Phase to hash"))
		hashLenght++;
        char hash[hashLenght];
        uint16_t chunk = 0;
		uint32_t skipSymbolsLength = 0;
		if (text.length() > hashLenght) {
			skipSymbolsLength = text.length()/hashLenght;
			if (text.length() % 2 != 0) {
				skipSymbolsLength = (text.length()-1)/hashLenght;
			}
		}
        uint16_t i = 0; int symInText = 0; while (i < hashLenght) {
			if (text.length() == symInText) {symInText = 0; chunk++; continue;}
			else {
				bool isRepeated = false; if (hash[i-1] + hash[i-2] == hash[i-3] + hash[i-4]) {isRepeated = true;}
				hash[i] = symToInt(text[symInText*skipSymbolsLength], text.length(), chunk, hash[i-1], isRepeated, i);}
			i++;
			symInText++;
        }
		i = 0; char finhash[hashLenght]; while (i < hashLenght-1) {
                finhash[i] = hash[hashLenght-1-i] + '0';
                i++;
        }
		finhash[hashLenght-1] = 0;
		std::string thash = finhash;
        return thash; 
}
