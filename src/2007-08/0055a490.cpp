// from server: 100% by Intel_Inside
// roc-flags: /O2 /GS- /EHsc /MD
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
