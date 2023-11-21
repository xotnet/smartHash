#include <iostream>
#include <cstring>
#include <cstdint>
const int hashLenght = 256;
int symToInt(const char sym, const uint8_t textLenght, const uint8_t chunk, short int prewiosHash) {
        char symbolsList[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ,.!?/:#$%&*+~`()-[]{}:;_'$<>";
        short int i = 0; while (i != sizeof(symbolsList) || i < hashLenght) {
                if (sym == symbolsList[i]) {break;}
                i++;
        }
        i = ((prewiosHash+chunk+17)*i*73*textLenght+prewiosHash)-(i*chunk*prewiosHash)-(993-textLenght-chunk);
        if (i == 0) {i += textLenght;}
        i = i % 10;
        return std::abs(i);
}
std::string shash(const std::string text) {  // main
        char hash[hashLenght];
        uint8_t chunk = 0;
        short int i = 0; int symInText = 0; while (i < hashLenght) {
                if (sizeof(text) == symInText) {symInText = 0; chunk++; continue;}
                else {
                        hash[i] = symToInt(text[symInText], sizeof(text), chunk, hash[i-1]);}
                i++;
                symInText++;
        }
        i = 0; char finhash[hashLenght]; while (i < hashLenght-1) {
                finhash[i] = '0' + hash[i];
                i++;
        }
		std::string thash = finhash;
        return thash;
}
