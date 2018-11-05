# hw6
hw6: Can't see the forest for the trees

HTree.hh
	header file for htrees, it defines the types and the functions.

HTree.cc
	the mainbody that defines what the functions of htrees actually do. 
	Since key, value, and children are private properties, htrees ultilize the get functions to return these values.
	These functions are all const to make sure no change is made to these values.
	




	path_to function finds the path to a key recursively. It returns a list of Direction objects.
	find function makes sure the key is indeed in the subtree. a bool function.

HForest.hh
	defines an hforest. The trees are stored in a vector. And make_heap rearranges the vector into a heap.

HForest.cc
	the hforest removes and adds trees by directly adding them to the vector and rearranging with make_heap each time to maintain the heap structure.
