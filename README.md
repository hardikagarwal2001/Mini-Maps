# Mini-Maps

Using Google Maps to travel around has become a very handy method and finding the shortest route to go from one place to another has undoubtedly reduced the travel time by a significant amount. Almost everyone now relies on such methods whenever they travel to any new place or just want to plan out their schedule by figuring out the estimated time it will take for them to reach their destination.

This project will help the user to find the shortest path and estimated time amount (ETA) to from one destination to another. It tells the user the cities and states he should go through in order to reach its destination. The user can also ask for the next best alternate route in case they don’t want to take the route that takes the least amount of time.

# Data structures/tools used:
## ▫ STL:VECTORS
Vectors are same as dynamic arrays with the ability to
resize itself automatically when an element is inserted or
deleted, with their storage being handled automatically by
the container. Vector elements are placed in contiguous
storage so that they can be accessed and traversed using
iterators.
## ▫ GRAPH
A graph can be defined as group of vertices and edges that are used to
connect these vertices. A graph can be seen as a cyclic tree, where the
vertices (Nodes) maintain any complex relationship among them instead
of having parent child relationship.
## ▫ K-ARY TREE
The K-ary tree is a rooted tree, where each node can hold at
most k number of children.
## ▫ STL: STACK
Stacks are a type of container adaptors with LIFO(Last In First Out) type
of working, where a new element is added at one end and (top) an
element is removed from that end only.
## ▫ RECURSSION
Recursion is the process of repeating items in a self- similar
way. In programming languages, if a program allows you to call
a function inside the same function, then it is called a recursive
call of the function.Stl: List
Lists are sequence containers that allow non-contiguous
memory allocation. As compared to vector, list has slow
traversal, but once a position has been found, insertion and
deletion are quick. Normally, when we say a List, we talk about
doubly linked list. For implementing a singly linked list, we use
forward list.
## Stl: queue
Queues are a type of container adaptors which operate in a first
in first out (FIFO) type of arrangement. Elements are inserted at
the back (end) and are deleted from the front.
## Linked List
A linked list is a linear dynamic data structure to store data
items. We have already seen arrays in our previous topics on
basic C++. We also know that arrays are a linear data structure
that store data items in contiguous locations. Unlike arrays, the
linked list does not store data items in contiguous memory
locations. A linked list consists of items called “Nodes” which
contain two parts. The first part stores the actual data and the
second part has a pointer that points to the next node. This
structure is usually called “Singly linked list”.
## Function overloading
Two or more functions can have the same name but different
parameters; such functions are called function overloading. C++
has many features, and one of the most important features is
function overloading. It is a code with more than one function
with the same name having various types of argument lists.Algorithm/technology used
# Greedy algorithm: Flyod Warshall Algorithm
We are given a directed graph G in which every edge has a
nonnegative weight attached: In other words, G is a directed
network. Our problem is to find a path from one vertex v to another
w such that the sum of the weights on the path is as small as
possible. We call such a shortest path path a shortest path, even
though the weights may represent costs, time, or some quantity
other than distance. We can think of G as a map of airline routes, for
example, with each vertex representing a city and the weight on
each edge the cost of flying from one city to the second. Our
problem is then to find a routing from city v to city w such that the
total cost is a minimum. Consider the directed graph shown in
vertex 2 and has a total cost of 4, compared to the cost of 5 for the
edge directly from 0 to 1 and the cost of 8 for the path via vertex 4.It turns out that it is just as easy to solve the more general problem
of starting source at one vertex, called the source, and finding the
shortest path to every other vertex, instead of to just one
destination vertex. In our implementation, the source vertex will
be passed as a parameter. Our problem then consists of finding the
shortest path from vertex source to every vertex in the graph. We
require that the weights are all nonnegative.
# Method
The algorithm operates by keeping a set S of those vertices
whose shortest distance from source is known.
Initially, source is the only vertex in S. At each step, we add 468
to S a remaining vertex for which the shortest path from source
has been found. The problem is to determine which vertex to
add to S at each step.
Let us think of the vertices already in S as having been labeled with
some color, and think of the edges making up the shortest paths
from source to these vertices as also colored. We shall maintain a
table distance that gives, for each vertex v, the distance distance
table from source to v along a path all of whose edges are colored,
except possibly the last one.
That is, if v is in S, then distance[v] gives the shortest distance to v
and all edges along the corresponding path are colored. If v is not in
S, then distance[v] gives the length of the path from source to some
vertex w in S plus the weight of the edge from w to v, and all the
edges of this path except the last one are coloured. The tabledistance is initialized by setting distance[v] to the weight of the edge
from source to v if it exists and to infinity if not. greedy algorithm
To determine what vertex to add to S at each step, we apply the
greedy criterion of choosing the vertex v with the smallest distance
recorded in the table distance, such that v is not already in S. We
must prove that, for this vertex v, the distance verification recorded
in distance really is the length of the shortest path from source to v.
For suppose that there were a shorter path from source to v, such as
shown in Figure 12.9. This path first leaves S to go to some vertex x,
then goes on to v (possibly even re- entering S along the way). But if
this path is shorter than the coloured path to v, then its initial
segment from source to x is also shorter, so that the greedy criterion
would have chosen x rather than v as the next vertex to add to S,
since end of proof we would have had distance[x] < distance[v].
Detailed Design
The program opens up with “Welcome to Mini Maps” being
displayed. It then shows a list of all the available places that the user
can use for the inputs. The user is then prompted to enter a source
point, followed by a destination point. The program then displays the
total distance between the two points (using the shortest route) and
total time that will be taken at an avg speed of 60km/h. Then the
shortest route is displayed along with the cummulative distance of
each intermediate place in the route.
It also tracks the user history and displays it when the user
asks to display it.
