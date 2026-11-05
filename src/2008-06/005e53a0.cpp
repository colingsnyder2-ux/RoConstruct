// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_transferlocalsbcf5270f5c28e1ee.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
struct Item;struct Destination{int reserved;std::vector<Item*>items;};struct Source{int reserved;std::vector<Item*>items;};struct Item{Destination*object;};
extern "C" void __cdecl detach(std::vector<Item*>*,Item**);
void __cdecl transfer(Source*source,Destination*destination){while(source->items.size()!=0){Item*item=*(source->items.end()-1);Destination*old=item->object;if(old){Item*owner=item;detach(&old->items,&owner);item->object=0;}if(destination){Item*value=item;destination->items.push_back(value);item->object=destination;}}}
