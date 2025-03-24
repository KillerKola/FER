This laboratory exercise was about creating a code that would determine whether or not a graph
with N vertices contained a cycle of length K. If it contained a cycle it was supposed to output
1 and if it didnt it was supposed to output 0. Expected max vertices of a graph was 15 but could 
be higher aswell. The program asks for an input -> the name of the txt file which contains the
numbers N, K and the adjacency matrix of the graph.

The code is based on depth first search. It also uses a helping function to determine if a cycle
of a certain length exists and the main program also has a part which determines if the graph has
a K-cycle based on some simple facts. For example if the graph has 10 vertices and we're looking
for a 9-cycle the output of the program will be 0.
