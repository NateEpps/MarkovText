/******************************************************************************
 *  Name:    Nathanael Epps
 *  NetID:   nepps
 *  Precept: P01A
 ******************************************************************************/

Which partner is submitting the program files?

Programming Assignment 7: Markov Model

Hours to complete assignment (optional): 

/**********************************************************************
 * Describe the type parameters of your symbol table (i.e., what is   *
 * the key type and what is the value type). How did you use the      *
 * symbol table to implement the random() method.                     *
 **********************************************************************/

The parameters of my symbol tables were, for the first one, String and
Integer. The second symbol table had type parameters String and int[].

Here's how I implemented the random() method:

public char random(String kgram)
{
    if (arrayTable.contains(kgram))
        return (char) StdRandom.discrete(arrayTable.get(kgram));
    else
        throw new IllegalArgumentException("Table doesn't contain k-gram: " + kgram);
}


/**********************************************************************
 * The main() method we provide in the checklist does not test your   *
 * random() method. Describe how you tested it.                       *
 **********************************************************************/

To test the random() method, I used the first markov model and tested
weather random("na") returns 'n' or 'b'. I used a loop that runs 100000
times, and print out the percentages.

/**********************************************************************
 * Paste two of your favorite, not too long, output fragments here.   *
 * In addition to the pseudo-random text, indicate the order of your  *
 * model and what text file you used.                                 *
 **********************************************************************/

For the first one, I used a slightly modified pearl_jam.txt file. I
took out some of the titles so that the text would be more based on
the song lyrics

$ java-introcs TextGenerator 8 100 < pearl_jam.txt
Large fingerprints are slowly raising
Me you woman enough to be my man?
Bandaged hand in hand.

Black lining

Part two, apparently Trump "has to come crashing down."

$ java-introcs TextGenerator 7 150 < trump-clinton1.txt

LESTER HOLT: Good luck. We wish you a list or a no-fly lists. And you've...

(CROSSTALK)

TRUMP: Well, I have to come crashing down.

HOLT: Please just have 


/**********************************************************************
 * Did you receive help from classmates, past COS 126 students, or    *
 * anyone else?  Please list their names.  ("A Sunday lab TA" or      *
 * "Office hours on Thursday" is ok if you don't know their name.)    *
 **********************************************************************/

I got help from my preceptor, Lawrence.

/**********************************************************************
 * Describe any serious problems you encountered.                     *
 **********************************************************************/

The Markov Model class took awhile to get right, but I got it
eventually.

/**********************************************************************
 *  List any other comments here.                                     *
 **********************************************************************/

