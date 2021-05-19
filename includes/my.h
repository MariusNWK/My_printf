/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** task 2
*/

typedef struct Ptr
{
    int size_nbr;
    int width;
    int itri;
    int n;
    char *new_s;
    char *nbr;
} Ptr;

typedef struct Main
{
    int i;
    int width;
    int nbr_btw;
    char ltr_btw;
    char flag;
    char *s;
} Main;

typedef struct Value
{
    int k;
    int p;
    int i;
    int n;
    int f;
    int nbr_btw;
    int width;
    int widthbis;
    int zeros;
    int ascii;
    unsigned int size_new_str;
    char ltr_btw;
    char flag;
    char c;
    char *new_str;
    char *new_s;
    char *nbr;
    char *str;
} Value;

typedef struct Ulong
{
    int k;
    int p;
    int i;
    long long unsigned int n;
    int f;
    int nbr_btw;
    int width;
    int widthbis;
    int zeros;
    char ltr_btw;
    char flag;
    char c;
    char *new_s;
    char *nbr;
    char *str;
} Ulong;

char *print_pointer(char *, ...);
void minor_resolver_int(Value *);
void minor_resolver_hexa(Ulong *);
void minor_resolver_long(Ulong *);
char *converter_percent_big_s(int);
int width_finder(char *, int);
char flag_finder(char *, int);
char lenght_modifier(char *, int);
char *s_without_between2(char *, int);
char *s_without_between(char *, int);
char *s_without_flag(char *, int);
char *s_without_width(char *, int);
char *print_string_octal(char *, ...);
char *print_hexadecimal(char *, ...);
char *print_decimal(char *, ...);
long long unsigned int length_converter_int_u(long long unsigned int, char);
char *print_octal(char *, ...);
char *print_binary(char *, ...);
char *print_char_nbr(char *, ...);
char *print_long_u(char *, ...);
long long unsigned int length_converter_long_u(long long unsigned int, char);
int precision(char *, int);
char *print_string(char *, ...);
void print_int_four(Value *);
void print_int_five(Value *);
void print_int_six(char *, Value *);
char *print_int(char *, ...);
char *length_converter_int(int, char);
char *print_char(char *, ...);
char *u_long_to_str_converter(unsigned long);
char *binary_converter(long long unsigned int);
char *hexa_converter(long long unsigned int, char);
long long unsigned int base_converter(long long unsigned int, int);
void *my_printf(char *, ...);
char *int_to_str_converter(int);
void my_putchar(char);
char *my_strstr(char *, char const *);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_put_nbr_u(unsigned int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char const *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);
