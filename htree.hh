/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#pragma once

#include <memory>
#include <list>

using key_t = int;
using value_t = uint64_t;

class HTree {
 public:
  using tree_ptr_t = std::shared_ptr<const HTree>;
  enum class Direction { LEFT, RIGHT };
  using path_t = std::list<Direction>;

  // Initialize with a key and a value:
  HTree(int key,
        uint64_t value,
        tree_ptr_t left = nullptr,
        tree_ptr_t right = nullptr);
  ~HTree();

  int get_key() const;  // Return key in current node
  uint64_t get_value() const;      // Return value in current node

  // Return the child of this node indicated by dir.
  // If the child is nullptr (current node is a leaf), returns nullptr.
  tree_ptr_t get_child(Direction dir) const;

  // Return a list of directions from root to a node of a given key.
  // Crashes (with an assert) if key not contained in this tree
  path_t path_to(int key) const;
bool compare_trees(tree_ptr_t test1, tree_ptr_t test2);

 private:
  key_t key_;
  value_t value_;
  tree_ptr_t left_;
  tree_ptr_t right_;
  bool find(key_t key) const;
};
