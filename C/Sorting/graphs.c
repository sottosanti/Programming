/*

set of nodes that are connected in an atypical way

Different types of graphs:
directed
undirected
weighted

Cyclic - a graph with a cycle in it 
Acyclic - a graph without a cycle in it
Disconnected - when a vertex had no edge from it to any other point in the graph or from a point to it
    creating an account and not adding any friends. You are there but not connected to anything 
    - also if there is one graph but two graphs that don't connect to each other within the graph 

Depth first search - traverse the graph and find every single vertex within the graph
    use a stack to move your way back 
    keep an already visited boolean variable
    look for all unvisited node
    no importance for which one you choose
    choose one, add it to the stack, mark it as visited
    if there are no unvisited nodes then pop from the stack and move back one, check again
    repeat
Breadth first search
    capture all nodes as you visit them
    use a queue
    pick starting node
    add to output
    pop it off

    find all of its children 
    add them to the queue
    mark F as visited
    pop from the queue
    print it
    add all invisited children to the queue
    mark it as visited 
    repeat

runtime is O(V + E)
*/