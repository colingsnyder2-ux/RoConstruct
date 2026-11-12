// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2007-08 005e6c40  unit: RBX::VFlag::?$FactoryProduct  size: 426 bytes
// Per-index cached shared_ptr in a std::vector at this+0x130 (8-byte elements: sar 3);
// call_once(fn 0x5e6370, flag 0x8c6f24) + index getter 0x5e62a0; resize 0x40e470 (by-value elem);
// static bool from call_once(0x58dd90, 0x8c37c4)+0x58d830 == 0x52cb30; factory 0x554de0 returns
// shared_ptr by hidden pointer; shared_count::operator= 0x402a60; ~shared_ptr 0x492360.
#include <vector>

namespace boost {
typedef long once_flag;
void call_once(void (*func)(), once_flag& flag);
namespace detail {
class shared_count {
public:
    void* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r);
    ~shared_count();
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    ~shared_ptr();
    shared_ptr& operator=(const shared_ptr& r) { px = r.px; pn = r.pn; return *this; }
    T* get() const { return px; }
};
}

class Name;
class Item;

void initIndexFlag();
extern boost::once_flag indexFlag;
int itemIndex();

void initNameFlag();
extern boost::once_flag nameFlag;
const Name* nameA();
const Name* nameB();

class Owner {
public:
    char pad0[0x130];
    std::vector<boost::shared_ptr<Item> > items;

    boost::shared_ptr<Item> create(const Name* name);
    Item* getItem();
};

Item* Owner::getItem()
{
    boost::call_once(&initIndexFlag, indexFlag);
    int index = itemIndex();
    if ((size_t)(index + 1) > items.size())
        items.resize(index + 1, boost::shared_ptr<Item>());
    else if (Item* existing = items[index].get())
        return existing;

    static bool same = (boost::call_once(&initNameFlag, nameFlag), nameA() == nameB());
    if (same)
        return 0;
    boost::call_once(&initNameFlag, nameFlag);
    boost::shared_ptr<Item> item = create(nameA());
    if (!item.get())
        return 0;
    Item* result = item.get();
    items[index] = item;
    return result;
}
