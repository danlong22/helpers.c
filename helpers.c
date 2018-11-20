// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "helpers.h"
#define strcomp
// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if (fraction[0] == '1')
    {
        //printf("fraction[0] %c\n", fraction[0]);
        //printf("fraction[1] %c\n", fraction[1]);
        //printf("fraction[2] %i\n", fraction[2]);

        //why does making denominator an integer multiply denominator by 10?
        float denominator = (int)fraction[2] - 48;

        //printf("line 21 denominator: %d", denominator);
        float duration = 8 / denominator;
        //printf("%f\n", duration);
        return (int)duration;
    }
    if (fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else
    {
        printf("Invalid duration");
        return 0;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char letter = note[0];
    int octave;
    int accidental_value;

    if (strlen(note) == 2)
    {
        octave = (int)note[1];
        accidental_value = 0;
    }
    if (strlen(note) == 3)
    {
        octave = (int)note[2];

        char accidental = (char)note[1];

        if (accidental == '#')
        {
            accidental_value = 1;
        }
        if (accidental == 'b')
        {
            accidental_value = -1;
        }

    }

    //get the numerator value of octave
    octave -= 48;

    //printf("octave: %i\n", (int)octave);

    //calulate A in different octaves
    double C0 = 16.35;
    double octave_exponent = pow(2, (double)octave);
    //printf("octave exponent: %f\n", octave_exponent);
    double octave_frequency = C0 * octave_exponent;
    //printf("Octave frequency: %f\n", octave_frequency);


    //gets the notes place in the alphabet
    //used later as a variable for getting Hertz value
    //letter -= 'A';
    double numerator;
    if (letter == 'C')
    {
        numerator = 0;
    }
    if (letter == 'D')
    {
        numerator = 2;

    }
    if (letter == 'E')
    {
        numerator = 4;
    }
    if (letter == 'F')
    {
        numerator = 5;
    }
    if (letter == 'G')
    {
        numerator = 7;
    }
    if (letter == 'A')
    {
        numerator = 9;
    }
    if (letter == 'B')
    {
        numerator = 11;
    }

    numerator += accidental_value;
    //printf("numerator: %f\n", numerator);
    double exponent = (numerator / 12);
    //printf("exponent: %f\n", exponent);
    double factor = pow(2, exponent);
    //printf("factor: %f\n", factor);


    //final calculation
    double frequency = octave_frequency * factor;

    //round
    frequency = round(frequency);

    return frequency;


}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    string blank = "";
    int comp = strcmp(s, blank);
    if (comp == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*
int main(int argc, string argv[])
{
    string note = argv[1];
    int z = frequency(note);
    printf("return: %d\n", z);
}
*/
