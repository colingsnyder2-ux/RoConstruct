// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_boxselect2008layout1dfd3854114f125f.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include "v8datamodel/Selection.h"
#include <algorithm>
namespace RBX {
class BoxSelectCommand {char prefix[28];ServiceClient<Selection> selection;char gap[12];std::set<Instance*> previousItemsInBox;public:void selectAnd(const std::set<Instance*>&);void selectReverse(const std::set<Instance*>&);};
template<int Action> class SelectionOutput:public std::_Outit {Selection* selection;public:SelectionOutput(Selection* s):selection(s){}SelectionOutput& operator*(){return *this;}SelectionOutput operator++(int){return *this;}SelectionOutput& operator++(){return *this;}SelectionOutput& operator=(Instance* i){if(Action==0)selection->addToSelection(i);else if(Action==1)selection->removeFromSelection(i);else selection->toggleSelection(i);return *this;}};

void BoxSelectCommand::selectAnd(const std::set<Instance*>& n){std::set_difference(n.begin(),n.end(),previousItemsInBox.begin(),previousItemsInBox.end(),SelectionOutput<0>(selection));std::set_difference(previousItemsInBox.begin(),previousItemsInBox.end(),n.begin(),n.end(),SelectionOutput<1>(selection));previousItemsInBox=n;}
void BoxSelectCommand::selectReverse(const std::set<Instance*>& n){std::set_difference(n.begin(),n.end(),previousItemsInBox.begin(),previousItemsInBox.end(),SelectionOutput<2>(selection));std::set_difference(previousItemsInBox.begin(),previousItemsInBox.end(),n.begin(),n.end(),SelectionOutput<2>(selection));previousItemsInBox=n;}
}
