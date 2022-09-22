/*
** EPITECH PROJECT, 2022
** utility function
** File description:
** function that returns the square root of a float
*/

#include "utilities.h"

//guesses the value for sqre
static float retry_guess(float j, float k)
{
    return ((k + j / k) / 2);
}

//checks if the guess is correct
static int is_match(float a, float b, float precision)
{
    return ((ABS((a - b)) < precision) ? 1 : 0);
}

//recusively check if the sqrt is found else try a better guess
static float run_test(float x, float g, float precision)
{
    if (is_match(x / g, g, precision))
        return g;
    else
        return run_test(x, retry_guess(x, g), precision);
}

//use this to init
float get_square_root(float nb, int precision)
{
    float precision_f = (float) 1 / my_compute_power_rec(10, precision);

    return run_test(nb, 1, precision_f);
}
