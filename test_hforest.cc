#include "hforest.cc"
#include "htree.cc"
#include <iostream>
#include <cassert>

int main() {
	using tree_ptr_t = std::shared_ptr<const HTree>;
    HForest forest1;


    tree_ptr_t tree1 = std::make_shared<HTree>(1, 101, std::make_shared<HTree>(2, 102, std::make_shared<HTree>(3, 103, nullptr, nullptr), nullptr);

    tree_ptr_t tree2 = std::make_shared<HTree>(4, 104, std::make_shared<HTree>(5, 105, std::make_shared<HTree>(6, 106, nullptr, nullptr), nullptr);

    tree_ptr_t tree3 = std::make_shared<HTree>(7, 107, std::make_shared<HTree>(8, 108, std::make_shared<HTree>(9, 109, nullptr, nullptr), nullptr);

    forest1.add_tree(tree1);
    forest1.add_tree(tree2);
    forest1.add_tree(tree3);
//test the size() function
if (forest1.size() == 3){
	std::cout<<"Size tested"<< "\n";
	}
	else
	{
	std::cout<<"Size failed"<<"\n";
	}

//test the pop_tree by poping and examining the poped off value	
	auto largest = forest1.pop_tree();
    std::cout << largest->get_value() << "\n";
if (largest->get_value() == 109)
{
	std::cout<<"pop_tree() tested"<<"\n";
	}
	else
	{
	std::cout<<"pop_tree() failed";
	}


}
