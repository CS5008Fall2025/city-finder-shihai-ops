# Report
Fill out these report questions. 


1. What is the difference between a directed and undirected graph?

  The edges of an undirected graph do not have direction. The edge can works in both ways. If an edge connects Vertex A and Vertex B, you can traverse from A to B and from B to A. On the other hand, directed graph's edge has a specific direction You can go from A to B, but cannot move from B to A without another edge with the opposite direction.

2. What is the Big O of Dijkstra's algorithm.... 
 * Assuming you used an array (or list) to store the vertices.

   
     The Big O complexity of Dijkstra using array or list to store the vertices is $O(V^2)$.
   
   * Assuming you used a heap / priority queue to store the vertices.
     
     The Big O complexity of Dijkstra using heap / priority queue to store the vertices is $O(E \log V)$.
     

3. Explain in your own words what that means for larger graphs when trying to find the shortest distance. 

  If we need to find the shortest distance in a very large and sparse graph, using a Heap/Priority Queue is the best choice since  ($E \approx V$) at this case, the time complexity is close to $O(V \log V)$. If the graph is very dense, in this situation, the  ($E \approx V^2$). The time complexity using heap is close to $O(V^2 \log V)$. In a dense graph, using array with time complexity of $O(V^2)$ could be a better solution. 


## Deeper Thinking
4. For this assignment, you didn't need the most "efficient" set of data structures (for example, a heap wasn't required). However, think on the scale of google/apple maps - they have to deal with millions of vertices and edges. What data structures would you use to store the graph? Why? Somethings to consider - would you be able to store the entire graph at a time? Could you break it up into smaller pieces? How would you do that? Would there be advantages to caching/memoization of paths? You are free to explore your thoughts on this subject/reflect on various ideas. Other than a realization of some scalability of problems, there isn't a wrong answer. 

The best solution I can think about right now is when you zoom out to a very large scale such as zooming out to countries or the state level, the graph becomes dense, then we use array. When we zoom in to city, town, street level, we use a heap as the diagram becomes more sparse. 


## Future Understanding
5. Related to shortest distance, is a problem called the "messenger" or "traveling sales person" problem commonly abbreviated to TSP. This problem is to find the shortest path that visits **every** vertex in a graph. Another way to look at it, is you are an delivery driver, and you have a series of packages to deliver. Can you find an optimal path for your deliveries that minimizes the total distance traveled? Imagine if you had 5 stops. How many different paths are there?  There are 120 possible paths to look at! (assuming fully connected routes). 
   * How many possible paths are there if you have 6 stops?

    It has 720 paths ($6!$)
   
   * How many possible paths are there if you have 10 stops?
     
     It has 3628800 paths ($10!$)
     
6. What type of growth is this problem? 

It is factorial growth $O(n!)$. 

7. Take some time to research TSP problems. It falls under a certain classification of problems? What is it? 

It falls under the classification of NP-Hard problems.

8. Provide some examples of fields / problems that use TSP.

    Package Delivery, to optimize and find out the best route for delivery man to deliver things efficiently.
   
    Ubereats, to optimize the distance between restaurants, passengers, available cars and destinations in a good sequence and pick the right car to fulfill these orders to achieve the highest efficiency. 

> [!TIP]
> We are having you explore TSP, so you can see the terms used for problem classification that are often the foundation of computer science theory. You will not be asked to know about TSP outside of this assignment or even problem classification. Computer Science is often about dealing with problems considered "too hard" or "impossible", and finding ways to make them possible! As such, knowing topics such as N, NP, NP-Complete, etc. is important to understand the limits (to break).


## Technical Interview Practice Questions
For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

   Discuss what a binary tree is. What is a full and what is a complete binary tree?

    A binary Tree is a hierarchical data structure in which each node has at most two children: a left child and a right child. It begins with a root. In a full binary tree, every node except the bottom has 2 children, and the bottom of the tree has 0 children. A complete binary tree has 2 children, except for the bottom and the bottom could have 2, 1, or 0 children. The left branch must be filled before going to the right. You strictly cannot start a new row until the previous one is full, and you cannot skip a spot in the current row. For example, you cannot have only 1 child in a left side node and still have a child at more right side of the tree.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 
