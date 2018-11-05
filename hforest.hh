
#pragma once

#include <memory>
#include <list>
#include "htree.cc"
#include <vector>
#include "htree.hh"
#include <algorithm>

class HForest {
 public:
	using tree_ptr_t = std::shared_ptr<const HTree>;
	using tree_list = std::vector<tree_ptr_t>;	
	HForest();
	~HForest();
	int size() const;
//	bool compare_trees(tree_ptr_t t1, tree_ptr_t t2);

	tree_list get_trees() const;

	void add_tree(tree_ptr_t tree);
	tree_ptr_t pop_tree();



 private:
	tree_list trees;
	

};
