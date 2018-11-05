
#pragma once

#include <memory>
#include <list>
#include "htree.cc"
#include <vector>
#include "htree.hh"
#include <algorithm>


	using tree_ptr_t = std::shared_ptr<const HTree>;
bool compare_trees(tree_ptr_t t1, tree_ptr_t t2);



class HForest {
 public:
	using tree_list = std::vector<tree_ptr_t>;	
	HForest();
	~HForest();
	int size() const;
	tree_list get_trees();

	void add_tree(tree_ptr_t tree);
	tree_ptr_t pop_tree();



 private:
	tree_list trees;
	

};
