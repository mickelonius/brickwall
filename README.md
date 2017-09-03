Dynamic Programming solution to brick wall combinatorial problem

Prompt
-------------------------------------------------------------------------------------
In building a MxN brick wall out of 2x1 and 3x1 bricks, where bricks cannot directly
overlap for structural integrity, how many permutations are possible?


Solve the sub problem first
-------------------------------------------------------------------------------------
First, we need to solve the issue of enumerating all permutations of one layer and
how these permutations can be combined "legally", without any cracks.

To calculate the number of permutations and their enumerations (i.e. where the cracks are in
each permutation), I used a vector and a map (tree) in a "walk-forward" type of algorithm.

For example, in a 32 wide wall, at each point there is a unique permutation that could cause
you to arrive there: if I'm at point 7, then I could've arrived from point 5 or point 4.
Each of these represents a unique permutation.

Therefore, the number of unique permutations that give me a "sub-wall"of 7 is the sum of
the number of permutations of a 5-wall and 4-wall.  If we start at the beginning, there is
only one permutation that gives a 0-wall, then work our way forwards, accumulating the number
of permutations at each step, we get the number of permutations at each step up to 32.

As we are looping, we accumulate, for example the number of permutations for the 5-wall and
4-wall and combining them to get the 7-wall result.  If we associate these with the 7-wall
in a tree, we can use that tree to store the actual configurations of all of the permutations.

Now, we have not only the number of permutations, but their configurations too.


Solving sub-problem repeatedly
-------------------------------------------------------------------------------------
Once we have the configurations of all permutations, we generate a matrix that tells
us whether two permutations are compatible (can they be stacked on top of each other).

We then multiply this matrix by a one's vector as many times as the wall height and sum
that resulting vector to obtain the number of ways to build a height x 32 wall.
