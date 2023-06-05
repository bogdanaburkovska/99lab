#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkParentheses(char* str) {
    int openRound = 0, closeRound = 0; // лічильники відкритих і закритих круглих дужок
    int openSquare = 0, closeSquare = 0; // лічильники відкритих і закритих квадратних дужок
    
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(')
            openRound++;
        else if (str[i] == ')')
            closeRound++;
        else if (str[i] == '[')
            openSquare++;
        else if (str[i] == ']')
            closeSquare++;
    }
    
    if (openRound == closeRound && openSquare == closeSquare)
        return 1; // кількість дужок співпадає
    else
        return 0; // кількість дужок не співпадає
}

void removeTextInParentheses(char* str) {
    int len = strlen(str);
    char result[len + 1];
    int pos = 0;
    int openParentheses = 0; // лічильник відкритих дужок
    
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            openParentheses++;
            continue;
        }
        
        if (str[i] == ')') {
            if (openParentheses > 0) {
                openParentheses--;
                continue;
            }
        }
        
        if (openParentheses == 0) {
            result[pos] = str[i];
            pos++;
        }
    }
    
    result[pos] = '\0'; // додаємо завершуючий нуль-символ
    
    printf("Рядок після видалення тексту в круглих дужках: %s\n", result);
}

int main() {
    char str[1000];
    
    printf("Введіть рядок тексту: ");
    fgets(str, sizeof(str), stdin);
    
    // Видаляємо символ нового рядка, який fgets() залишає у введеному рядку
    str[strcspn(str, "\n")] = '\0';
    
    // Перевірка кількості дужок
    if (checkParentheses(str))
        printf("Кількість відкритих і закритих дужок співпадає.\n");
    else
        printf("Кількість відкритих і закритих дужок не співпадає.\n");
    
    // Видалення тексту в круглих дужках
    removeTextInParentheses(str);
    
    return 0;
}
