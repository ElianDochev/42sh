/*
** EPITECH PROJECT, 2022
** headed for lib
** File description:
** func prototybe
*/

#include <stdarg.h>

#ifndef PRINTF_H
    #define PRINTF_H

//def of boolean datatype
typedef enum {pf_false, pf_true} pf_bool;
//shorten syntax for long long int
typedef long long int big_int_t;
//used for my_printf first args
typedef struct {
    int index;
    char buf[4096];
} mypt_buffer_t;
//selfexcpanatory
int my_strlen(char const *str);
//selfexcpanatory
int my_compute_power_rec(int nb, int p);
//mallocs a new string contaning the char + '\0'
char *pf_convert_to_str(char ch);
//converts an int to string (signed)
char *int_to_str(int scr);
//converts an int to string (unsigned)
char *int_to_str_unsigned(unsigned int scr);
//converts dex to hex
char *pf_int_to_hex(long long number);
//converts a float to str
char *pf_float_to_strx(float x);
//converst letters to uppercase
char *str_upcase(char *str);
//reverses a string with know size
void rev_buff(char *buff, int size);
//set the values of the chars to '\0'
void pf_init_b(char *buff, int size);
//flag %s
void pf_flag_s(char *args, va_list *ap);
//flag %c
void pf_flag_c(char *args, va_list *ap);
//flag %d
void pf_flag_d(char *args, va_list *ap);
//flag %i
void pf_flag_i(char *args, va_list *ap);
//flag %%
void pf_flag_percent(char *args, va_list *ap);
//flag %u
void pf_flag_u(char *args, va_list *ap);
//flag %b
void pf_flag_b(char *args, va_list *ap);
//flag %B
void pf_flag_capital_b(char *args, va_list *ap);
//flag %x
void pf_flag_x(char *args, va_list *ap);
//flag %X
void pf_flag_capital_x(char *args, va_list *ap);
//flag %o
void pf_flag_o(char *args, va_list *ap);
//flag %O
void pf_flag_capital_o(char *args, va_list *ap);
//flag %p
void pf_flag_p(char *args, va_list *ap);
//flag %S
void pf_flag_capital_s(char *args, va_list *ap);
//display error
void pf_error(char *args, va_list *ap);
#endif
