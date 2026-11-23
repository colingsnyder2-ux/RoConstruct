// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#undef _RELEASEASSERT
// Stats::Item::createChildItem: create an Item, name it, parent it to this.
// Mirrors the 2007 donor body; 2008 disassembly shows create<Item>, string(name) temp,
// Instance::setName via vtable slot 1 (+4), then setParent(this).
#include "stats/Stats.h"

RBX::Stats::Item* RBX::Stats::Item::createChildItem(const char* name)
{
    boost::shared_ptr<Item> item = RBX::Creatable<RBX::Instance>::create<Item>();
    item->setName(name);
    item->setParent(this);
    return item.get();
}
