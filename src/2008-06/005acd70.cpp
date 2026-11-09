// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_associationthreadnative83c3e4e952e4a3d7.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Association.h"
#include <boost/shared_ptr.hpp>
namespace RBX {class Instance;namespace Lua {class ThreadRef {public:class Node;};}}
extern unsigned int associationCounter;
template<class T> unsigned int typeIndex(){static unsigned int index=associationCounter++;return index;}
namespace RBX {
template<class A> Association<A>::Item::~Item(){}
template<class A> template<class T> Association<A>::TItem<T>::TItem(){}
template<class A> template<class T> T& Association<A>::get(){while(items.size()<=typeIndex<T>())items.push_back(0);Item*& item=items[typeIndex<T>()];if(!item)item=new TItem<T>();return static_cast<TItem<T>*>(item)->t;}
template boost::shared_ptr<Lua::ThreadRef::Node>& Association<Instance>::get<boost::shared_ptr<Lua::ThreadRef::Node> >();
}
