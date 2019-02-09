#include<iostream>
#include "Tree.cpp"
using namespace std;
int main()
{
    // Create tree structure
	Tree<string> t;
    
    // Create initializer of Position to get node's position
    // Set position to start a tree's root
	Tree<string>::Position p = t.root();
    
    // Insert "food" at position "p", or root
	t.insert("Food", p);
	p = t.root();
    
    // Insert more nodes under "Food"
    t.insert("fruit", p);
    t.insert("vegetables", p);
    t.insert("grains", p);
    
    // Create an iterator and start from beginning to end of Tree
    for (Tree<string>::PositionList::Iterator iterator = p.children().begin(); iterator != p.children().end(); ++iterator)
    {
        // Create another Position initializer and get reference from "Iterator"
         Tree<string>::Position pos = *iterator;
        
        // If position is at "fruit", then add the following at position of "iterator"
        if (*pos == "fruit")
        {
             t.insert("apple", *iterator);
             t.insert("grape", *iterator);
             t.insert("berry", *iterator);
        }
        
        // If position is at "vegetables", then add the following at position of "iterator"
        if (**iterator == "vegetables")
        {
            t.insert("broccoli", *iterator);
            t.insert("potato", *iterator);
            t.insert("carrot", *iterator);
        }
        
        // If position is at "grains", then add the following at position of "iterator"
        if (**iterator == "grains")
        {
            t.insert("rice", *iterator);
            t.insert("wheat", *iterator);
            t.insert("oat", *iterator);
        }
    }
    
    // Create an initializer of "PositionList"
	Tree<string>::PositionList list  = t.Positions();
    
    // Iterate through list and print each node.
	for (Tree<string>::PositionList::Iterator i = list.begin(); i != list.end(); ++i)
		cout << **i << endl;
}
