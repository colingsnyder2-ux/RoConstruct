// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_selection_collector_db598200248d75c7.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
struct NativeGridNodeView { char prefix[0xa4]; std::vector<NativeGridNodeView*> children; };
struct NativeSelectionCollectorView {
 char prefix[4];
 std::vector<NativeGridNodeView*> values;
 void operator()(NativeGridNodeView* node);
};
void NativeSelectionCollectorView::operator()(NativeGridNodeView* node) {
 values.push_back(node);
 std::for_each(node->children.begin(),node->children.end(),boost::bind(&NativeSelectionCollectorView::operator(),this,_1));
}

