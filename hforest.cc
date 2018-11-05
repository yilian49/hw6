#include<iostream>
#include "hforest.hh"
#pragma once


using tree_ptr_t = std::shared_ptr<const HTree>;

HForest::HForest()
{
	std::make_heap(trees.begin(), trees.end(), compare_trees);
}

bool compare_trees(tree_ptr_t test1, tree_ptr_t test2) 
{
    return test1->get_value() < test2->get_value();
}

HForest::~HForest(){
}

int HForest::size() const
{
	return trees.size();
}

HForest::tree_list HForest::get_trees() {
	return trees;
}

void HForest::add_tree(tree_ptr_t tree)
{
	auto it = trees.begin();
	trees.insert(it, tree);
	std::make_heap(trees.begin(), trees.end(), compare_trees);
}

tree_ptr_t HForest::pop_tree()
{
	tree_ptr_t largest = trees.at(0);
	trees.erase(trees.begin() );
	std::make_heap(trees.begin(), trees.end(), compare_trees);
	return largest;
}	
