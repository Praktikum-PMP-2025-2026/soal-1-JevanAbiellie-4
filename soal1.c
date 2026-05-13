/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 - Foundation of Algorithm
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Jevan Abiellie (13224056)
 *   Nama File           : soal1.c
 *   Deskripsi           : generate all parenthesis
 * 
 */

#include <stdio.h>
#define MAX_SIZE 100

void _printParenthesis(int pos, int n, int open, int close);

void printParenthesis(int n){
    if (n > 0){
        _printParenthesis(0, n, 0, 0);
        return;
    }
}
void _printParenthesis(int pos, int n, int open, int close){
    static char str[MAX_SIZE];
    if (close == n){    
        printf("%s \n", str);
        return;
    }
    else {
        if (open < n){
            str[pos] = '(';
            _printParenthesis(pos + 1, n, open+1, close);
        }

        if (open > close){
            str[pos] = ')';
            _printParenthesis(pos+1, n, open, close+1);
        }

        
    }
}

int faktorial(int n){
    int total = 1;
    for (int i = 1; i <= n; i++){
        total *= i;
    }
    return total;
}
int kombinasiitung(int n){
    int kombinasi = faktorial(2*n)/(faktorial(n)*faktorial(n));
    return (kombinasi/(n+1));
}

int main(){
    int n;
    scanf("%d", &n);
    printParenthesis(n);
    getchar();
    printf("TOTAL %d", kombinasiitung(n));
    return 0;

}

//referensi : https://prepinsta.com/c-program/generate-all-combinations-of-balanced-parentheses/
