#include<iostream>
#include "hforest.hh"

HForest::HForest()
{
	std::make_heap(trees.begin(), trees.end(), HTree::compare_trees);
}
/*
bool HForest::compare_trees(tree_ptr_t test1, tree_ptr_t test2) 
{
    return test1->get_value() < test2->get_value();
}
*/
HForest::~HForest(){
}

int HForest::size()
{
	return trees.size();
}

HForest::tree_list get_trees() const{
	return HForest->trees;
}

void HForest::add_tree(tree_ptr_t tree)
{
	auto it = trees.begin();
	trees.insert(it, tree);
	std::make_heap(trees.begin(), trees.end(), HTree::compare_trees);
}

tree_ptr_t HForest::pop_tree()
{
	trees.erase(trees.begin() );
	std::make_heap(trees.begin(), trees.end(), HTree::compare_trees);
	retrun trees.at(0);
}	
