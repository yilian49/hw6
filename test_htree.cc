#include<iostream>
#include "htree.cc"

int main()
{
	HTree::tree_ptr_t root = new HTree(1, 1, nullptr, nullptr);
	root->get_child(HTree::Direction::LEFT) = new HTree(6, 0, new HTree(7, 0, nullptr, nullptr), new HTree(8,0,nullptr,nullptr));
	root->get_child(HTree::Direction::RIGHT) = new HTree(2, 0, new HTree(4, 0, new HTree(8, 0, nullptr, nullptr), new HTree(1, 0, nullptr, nullptr)), new HTree(7, 0, new HTree(5, 0, nullptr, nullptr), nullptr));
	root->get_child(HTree::Direction::LEFT)->get_child(HTree::Direction::LEFT)->get_child(HTree::Direction::LEFT) = new HTree(2,0,nullptr,nullptr);
	root->get_child(HTree::Direction::LEFT)->get_child(HTree::Direction::RIGHT)->get_child(HTree::Direction::LEFT) = new HTree(4,0,nullptr,nullptr);

	std::cout<<"\n";	
	if(root->find(2) == true
		and root->get_child(HTree::Direction::LEFT)->find(5) == false
		and root->get_child(HTree::Direction::RIGHT)->find(2) == true
		and root->find(10) == false)
	{	std::cout<<"find tested";}
	else{ std::cout<<"find failed";}
	std::cout<<"\n";
	if(root->path_to(4) == HTree::path_t {HTree::Direction::LEFT, HTree::Direction::RIGHT, HTree::Direction::LEFT} and
		root->path_to(1) == HTree::path_t {}and
		root->path_to(2) == HTree::path_t {HTree::Direction::LEFT, HTree::Direction::LEFT, HTree::Direction::LEFT}and
		root->path_to(5) == HTree::path_t {HTree::Direction::LEFT, HTree::Direction::RIGHT, HTree::Direction::LEFT})
	{	std::cout<<"path_to tested";}
	else{ 	std::cout<<"path_to failed";}
	std::cout<<"\n";
/*	if(root->node_at("LL").get_key() == 7 and
		root->node_at("").get_key() == 1 and
		root->node_at("RRL").get_key() == 5 and
		root->node_at("R").get_key() == 2 and
		root->node_at("RLR").get_key() == 1)
	{ 	std::cout<<"node_at tested";}
	else{	std::cout<< "node_at failed";}
	
*/	
		HTree::tree_ptr_t tree1 = root;
		HTree::tree_ptr_t tree2 = root->get_child(HTree::Direction::LEFT);
		HTree::tree_ptr_t tree3 = root->get_child(HTree::Direction::LEFT)->get_child(HTree::Direction::LEFT);
		HTree::tree_ptr_t tree4 = root->get_child(HTree::Direction::LEFT)->get_child(HTree::Direction::LEFT)->get_child(HTree::Direction::LEFT);
		HTree::tree_ptr_t tree5 = root->get_child(HTree::Direction::RIGHT)->get_child(HTree::Direction::LEFT)->get_child(HTree::Direction::LEFT);
		root->~HTree();
	std::cout<<"\n";	
	if (tree1==nullptr and
		tree2==nullptr and
		tree3==nullptr and
		tree4==nullptr and
		tree5==nullptr)
	{	std::cout<<"destroy_tree tested";}
	else
	{	std::cout<<"destroy_tree failed";}
	
	}

		

