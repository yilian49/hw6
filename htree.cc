#include <iostream>
#include "htree.hh"

tree_ptr_t HTree::HTree(int key, unit64_t value, 
		tree_ptr_t left = nullptr, tree_ptr_t right = nullptr)
{
	key_ = key;
	value_t = value;
	left_ = left;
	right_ = right;
	Direction
	return this;
}	

int HTree::get_key() const
{
	return key_;
}

uint_64t HTree::get_value() const
{
	return value_;
}

tree_ptr_t HTree::get_child(Direction dir) const
{
	if (left_ && dir == Direction::LEFT)
	{
		return left_;
	}
	if (right_ && dir == Direction::RIGHT)
	{
		return right_;
	}
	return nullptr;
}

bool HTree:find(key_t key) const
{
	if (key_ == key) return true;
	if (left_ && left_->find(key)) return true;
       	if (right_ && right_->find(key)) return true;
	return false;
}	

path_t HTree::path_to(int key) const
{
	if (this->find(key
