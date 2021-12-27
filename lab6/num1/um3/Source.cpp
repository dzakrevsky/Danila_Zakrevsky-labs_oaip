#include <iostream>
#pragma warning(disable : 4996)

char* strcpy(char* dest, const char* src);
int strcmp(const char* lhs, const char* rhs);
char* strcat(char* dest, const char* src);


int main()
{
    char str1[225];
    std::cout << "Enter string:\n";
    std::cin.getline(str1, 255, '\n');

    char str1_1[] = "first strings";
    char str2[] = "second string";
    char bigstring[255] = "left side - ";
    std::cout << strcmp(str1, str2) << std::endl;
    std::cout << strcpy(str1_1, str1) << std::endl;
    std::cout << strcat(bigstring, "right side") << std::endl;
    return 0;
}

char* strcpy(char* dest, const char* src) {
    char* dest_start = dest;
    while (*src)
        *(dest++) = *(src++);
    *dest = '\0';
    return dest_start;
}
int strcmp(const char* lhs, const char* rhs) {
    while (*lhs && *rhs) {
        if (*lhs < *rhs)
            return -1;
        if (*lhs++ > *rhs++)
            return 1;
    }
    return *lhs == *rhs ? 0 : (*lhs == '\0' ? -1 : 1);
}
char* strcat(char* dest, const char* src) {
    char* dest_start = dest;
    while (*dest) // to the end of dest
        ++dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest_start;
}