/*
** EPITECH PROJECT, 2022
** HEADER FILE
** File description:
** Main Header File
*/

#ifndef MAIN_H
    #define MAIN_H

    #include "utilities.h"

/*###########################################################################
######################BEGINING OF BUFFER SIZE################################
#############################################################################*/
    #define KB (1 << 10)
    #define MB (1 << 20)
    #define GB (1 << 30)
/*###########################################################################
#######################END OF BUFFER SIZE####################################
-----------------------------------------------------------------------------*/



/*###########################################################################
######################BEGINING OF SEP FUNCTIONS##############################
#############################################################################*/
//returns 1 if the char is a space otherwise 0 used in callback
int sep_sp_tab(char ch);
//returns 1 if the char is a space or / otherwise 0 used in callback
int sep_spacedash(char ch);
//returns 1 if the char is not a letter otherwise 0 used in callback
int sep_alpha(char ch);
//returns 1 if the char is colon(:) otherwise retuns 0 used in callback
int sep_colon(char ch);
//return 1 if the char is an opp >, <, >>, <<, |, : otherwise returns 0
int sep_opps(char ch);
// same as sep_sp_tab but in reverse (0 for space and tab)
int sep_sp_tab_rev(char c);
/*###########################################################################
#######################END OF SEP FUNCTIONS##################################
-----------------------------------------------------------------------------*/


/*###########################################################################
#######################BEGINING OF ENV SEGMENT#########################
#############################################################################*/
    #define FREE_VAR (1 << 0)
    #define FREE_VALUE (1 << 1)
typedef struct env_s {
    char *var;
    char *value;
    int malloced;
    struct env_s *next;
} env_t;

//returns the ardress of the env, which char*var matches linked list
//returns NULL if the variable is not found
env_t *find_var(char *var, env_t *env);
////////////////////////////////////////////////////////////
/// \brief adds a new variable to the env or updates the value
/// if overwtite is not 0
///
/// \param env           the address of the env
/// \param var           the variable name
/// \param value         the value of the variable
/// \param overwrite     if 0, the value will not be updated
/// if 1, the value will be updated
/// if 2, the value will be updated and the new value will be mark as malloced
/// if 3, the value will be updated and the new value will be mark as malloced
/// and the var name will be marked as malloced
/// \return  returns 0 if the variable is added or updated
///          returns 1 if the variable is not added or updated
///
///////////////////////////////////////////////////////////
int add_to_env(env_t **env, char *var, char *value, int overwrite);
//removes the variable var from the env linked list
void remove_from_env(env_t **env, char *var);

/*###########################################################################
#######################END OF ENV SEGEMENT#############################
-----------------------------------------------------------------------------*/

/*###########################################################################
#######################BEGINING OF PIPES_SIGANLS  SEGMENT####################
#############################################################################*/
//cathes sigint exits with 137
int signal_sigint(int sig);
//empties pipe and closes it
void empty_pipe(int *pipefd);

/*###########################################################################
#######################END OF PIPES_SIGAN SEGEMENT###########################
-----------------------------------------------------------------------------*/


/*###########################################################################
######################BEGINING OF COMMAND FUNCS##############################
#############################################################################*/
//error msg when it cant find theprogram
    #define STD_ERR_MSG "Error has ocurred"
    #define STATUS "STATUS"
    #define ERR_STATUS "1"
    #define SUCCESS_STATUS "0"
static const char *dir_bin_default = "ls";
static const char *dir_bin = "/bin/";
//functions like pwd bash
void my_pwd(char *args, env_t **env);
//functions like cd bash
void my_cd(char *args, env_t **env);
//executes a binary
void exec_bin(char *args, env_t **env);
//fucntions like setenv bash
void my_setenv(char *args, env_t **env);
//functions like unsetenv bash
void my_unsetenv(char *args, env_t **env);
//functions like env bash
void print_env(char *args, env_t **env);
//functions like echo bash
void echo(char *args, env_t **env);
    #define INX_LEFT_ASSOS 5
static const char *bools[] = {"false", "true"};
static const char *opps[] = {";", ">>", ">", "&&", "||", "|", "<<", "<", NULL};
static const void (*fnc_arr[])(char *, env_t **) = {&my_cd, &my_pwd, &my_setenv,
&my_unsetenv, &echo, &exec_bin};
/*###########################################################################
#######################END OF COMMAND FUNCS##################################
-----------------------------------------------------------------------------*/



/*###########################################################################
######################BEGINING OF CONTROL FUNCs##############################
#############################################################################*/
//reads input and returns 1 if it is empty otherwise 0
int read_input(char *args);
// retuns of the index of the command that needs to be executed
int get_command(char *args);
// this is the main loop of the program
void input_manager(env_t **env);
//controls the flow of the program
void control_flow(char *args, env_t **env, int *running);
////////////////////////////////////////////////////////////
/// \brief crops the args getting rid of the second or the first
/// arg depending on the opp
///
/// \param args       the adress of the args
/// \param is_second  0 if you want the first arg, > 0 if you want the second
/// \param sep        callback function that determines if the char is a sep
/// (should retunr 0 if it is a sep and 1 otherwise)
/// \return         the address of the cropped arg
///
///////////////////////////////////////////////////////////
char *parser(char **args, int is_second, int (*sep)(char));
/*###########################################################################
#######################END OF CONTROL FUNCs##################################
-----------------------------------------------------------------------------*/



/*###########################################################################
######################BEGINING OF SUPPORT FUNCS##############################
#############################################################################*/
//finds if the string is in a word_array return 0 on success
//and then gives the rest until it reaches the end returns 1 on falier
int str_in_word_arr(char *dest, char **word_arr, char *sub_arr);
////////////////////////////////////////////////////////////
/// \brief splits a string into an word array ending in null using a callback
/// (uses the first occurence of the sep)
///
/// \param scr     the string to split
/// \param sep     the callback function to use to split the string
/// (return 1 if it is a sep otherwise return 0)
///
/// \return malloced 2d array of strings ending in null or null on failure
///
///////////////////////////////////////////////////////////
char **split_str_single(char *scr, int (*sep)(char));
/*###########################################################################
#######################END OF SUPPORT FUNCS##################################
-----------------------------------------------------------------------------*/
#endif
