#include <stdio.h>
#include <stdint.h>

char *soDonVi[] = {"Khong", "Mot", "Hai", "Ba", "Bon", "Lam", "Sau", "Bay", "Tam", "Chin"};
char *soTuNhien[] = {"Khong", "Mot", "Hai", "Ba", "Bon", "Nam", "Sau", "Bay", "Tam", "Chin"};

void stringConnect(char *dest, char* src) {
    while (*dest) {
        dest++;
    }
    while(*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void numberToWord(uint64_t num, char *words) {
    words[0] = '\0';


    if (num < 0 || num > 1000000000000) {
        stringConnect(words, "So ngoai pham vi !!!");
    }


    int ty, trieu, nghin, donVi;
    int flag = 0;
   
        ty = num / 1000000000;
        num = num % 1000000000;
        trieu = num / 1000000;
        num = num % 1000000;
        nghin = num / 1000;
        num = num % 1000;
        donVi = num;


        if (ty > 0) {
            printf("%d\n", ty);
            threeUnit(ty, words, flag);
            stringConnect(words, " Ty ");
            flag = 1;
        }
        if (trieu > 0) {
            threeUnit(trieu, words, flag);
            stringConnect(words, " Trieu ");
            flag = 1;
        }
        if (nghin > 0) {
            threeUnit(nghin, words, flag);
            stringConnect(words, " Nghin ");
            flag = 1;
        }
        if (donVi > 0) {
            threeUnit(donVi, words, flag);
        }
}

void threeUnit(int num, char *word, int flag) {
    int tram, chuc, donVi;

    tram = num / 100;
    num = num % 100;
    chuc = num / 10;
    num = num % 10;
    donVi = num;

    if (num >= 100 || flag == 1) {
            if (chuc == 0 && donVi == 0) {
                stringConnect(word, soTuNhien[tram]);
                stringConnect(word, " Tram");
            } else if (chuc > 0 && donVi == 0) {
                stringConnect(word, soTuNhien[tram]);
                stringConnect(word, " Tram ");
                stringConnect(word, soTuNhien[chuc]);
                stringConnect(word, " Muoi");
            } else if (chuc > 0 && donVi > 0) {
                stringConnect(word, soTuNhien[tram]);
                stringConnect(word, " Tram ");
                stringConnect(word, soTuNhien[chuc]);
                stringConnect(word, " Muoi ");
                stringConnect(word, soDonVi[donVi]);
            } else if (chuc == 0 && donVi > 0) {
                stringConnect(word, soTuNhien[tram]);
                stringConnect(word, " Tram");
                stringConnect(word, " Le ");
                stringConnect(word, soDonVi[donVi]);
            }
            return;
    } else {
        if (chuc > 1) {
            stringConnect(word, soTuNhien[chuc]);
            stringConnect(word, " Muoi ");
            if (donVi != 0) {
                stringConnect(word, soDonVi[donVi]);
            } else {
                stringConnect(word, "");
            }
        } else if (chuc == 1) {
            stringConnect(word, "Muoi ");
            if (donVi != 0) {
                stringConnect(word, soDonVi[donVi]);
            } else {
                stringConnect(word, "");
            }
        } else if (chuc == 0) {
            stringConnect(word, soTuNhien[donVi]);
        }
    }
}


void removeExtraSpace(char *str) {
    int i = 0;
    int j = 0;


    while (str[i] != '\0') {
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}


int main() {
    uint64_t num;
    char words[1000];
    scanf("%lld", &num);
    numberToWord(num, words);
    removeExtraSpace(words);
    printf("%s", words);
}

