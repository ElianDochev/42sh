/*
** EPITECH PROJECT, 2022
** HEADER FILE
** File description:
** Header file for utilities
*/

#ifndef UTIL_H
    #define UTIL_H

    #include <stdlib.h>

    #define EXIT_ERR_EPI 84
//gives the alsolute value
    #define ABS(x) (x < 0 ? -x : x)
//returns the smallest value
    #define MIN(x, y) (x < y ? x : y)
//functions like prin_f
void my_printf(char *args, ...);
//selfexcpanatory
int my_compute_power_rec(int nb, int p);
/*cacls the square_root of a unsigned float
(precision is the number of digits after the decimal)*/
float get_square_root(float nb, int precision);
//selfexcpanatory
int my_strlen(char const *str);
//converts a string into an int
int str_to_int(const char *str);
//returns an error msg
void error (char *str);
//converts an int to string (signed)
char *int_to_str(int scr);
//converts an int to string (unsigned)
char *int_to_str_unsigned(unsigned int scr);
//converst letters to uppercase
char *str_upcase(char *str);
//reverses a string with know size
void rev_buff(char *buff, int size);
//copies a string
void copy_str(char *dest, char const *src);
//dublicates a string
char *my_strdup(char const *src);
//compares two strings
int str_cmp(char const *str_one, char const *str_two);
//opens a file and puts its contents into a string
char *open_file(char const *filepath);
//prints a help msg form a path given
void print_help(char *path);
//compares two strings
int str_ncmp(char const *str_one, char const *str_two, int length);
//checks if any of the sub arrays are in the begining of the str
//retrun the index of the subarray if match is found otherwise returns
//the length of sub_aarays; !!!sub_arrays must end on NULL
int str_contains(char *scr, char **sub_arrays, int (*sup)(char));
//joins two string into one (mallocs)
char *str_join(char const *str_one, char const *str_two);
/*print this when there is an error with the num of args
(last one is for the correct number)*/
void print_bad_args(int ac , char *binary_name, int req_args);
//makes the buff null put size - 1
void null_buffer(char *buffer, size_t size);
//gets the length of 2d string array terminated by NULL
int get_len_two_d(char **w_arr);
//destroys and frees a 2d string array
void delete_two_d_string(char **w_arr);
////////////////////////////////////////////////////////////
/// \brief removes the separator from the string from both sides
/// using a callback
///
/// \param str     the string to remove the separators from
/// \param sep     callback function to use to remove the separators
/// (return 1 if it is a sep otherwise return 0)
/// \param is_malloced  put 1 if the string is malloced put 0 for static string
/// (if it is malloced it will be freed and reallocated with the new size)
///
///////////////////////////////////////////////////////////
void remove_sep(char **str, int (*sep)(char), int is_malloced);
// same as copy_str but has a size limit n
void copyn_str(char *dest, char const *src, int n);
//same as my_strdup but has a size limit n
char *my_strndup(char const *src, int n);
//same as copyn_str but doesnt null terminate the string
void copy_nexact_str(char *dest, char const *src, int n);

/*###########################################################################
######################BEGINING OF HASH TABLE#################################
#############################################################################*/
//inits an empty hash table (all null)
char **init_table_hash(size_t table_size);
//main hash function returns an index from data from 0 to table_size
size_t hash_data(char *str, size_t table_size);
//incerts a str (pointer) in the table
int incert_table_hash(char **table, char *str, size_t table_size);
//looks up if an item is in the hash table(returns null on falier)
char *lookup_table(char **table, char *str, size_t table_size);
//deletes a note from the hash_table (doesnt remove the data)
void hash_note_del(char **table, char *str, size_t table_size);
/*###########################################################################
#######################END OF HASH TABLE#####################################
-----------------------------------------------------------------------------*/



/*###########################################################################
#########################BEGINING OF LIST####################################
#############################################################################*/
//struct for list
typedef struct list {
    char *value;
    struct list *next;
} node_t ;
//incerts a node in the list give the pointer
node_t *list_incert(node_t *list, void *value);
//starts from 0 peeks the node fron the list at the specified index
node_t *peek_index(node_t *list, int index);
//destroys the list but not the eles whitin it
void destroy_list(node_t **list);
/*###########################################################################
#######################END OF LIST###########################################
-----------------------------------------------------------------------------*/
#endif
