The third laboratory exercise consisted of again, having to type in the name of the txt file you wanted to read.
From the file you had to read the number of vertices of a graph, N, the number of colors, K, and the adjacency matrix.
You had to determine whether or not you could color all the vertices with K or less colors in a way so that 
no color is next to itself / two adjacent vertices aren't the same color.

The code was written based on my own idea where i thought it would work if i went through all the vertices according
to their degrees, from highest to lowest degree vertex, the degree of a vertex being the number of neighbors it has.
Later on i looked up different ways of coloring a graph's vertices and came across the Welsh–Powell Algorithm which
came out to be the exact same thing that I did. It guarantees a coloring with at most one more color than the graph's max degree.
After deciding the order in which i was going to go through them i made a function which would "color" a vertex by
assigning a number to a vertex, the numbers ranging from 1 to K. In the main program i also implemented some tests
to instantly determine if the graph could be colored with K colors or not, for example if K was larger or equal than
thee highest degree of a vertex and the graph wasn't a full graph or if K was just larger than the highest degree of
a vertex then the program would output 1 meaning the graph was colorable by K colors. 

Note: the function doesn't work for ALL graphs. From my experience it fails on some complicated graphs.
In a failed version of the code I also implemented a failsafe which did the following: if the function which colored
a vertex determined it couldn't assign a color to the vertex in the main program it would go back to the last vertex
which could be colored differently and color it that way and then see if it could color the failed one again. It repeated
this until it went through all possible options, but eventually I settled with this because i couldn't make it work.
