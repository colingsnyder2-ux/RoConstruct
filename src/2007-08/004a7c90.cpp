// from server: 100% by EspClaude
// roc 2007-08 004a7c90  unit: RBX::Network::Replicator::ChangePropertyItem  size: 179 bytes
// RBX::Association<...>::find<T>(T*&) shape (util/Association.h): per-type static index taken from a
// shared counter, checked std::vector<Item*> lookup, TItem<T>::t at +4.
// roc-flags: /O2 /GS /EHsc /MD
#include <vector>
#include <stddef.h>
namespace RBX {
class Instance;
template<typename Associated>
class Association
{
public:
    class Item { public: virtual ~Item(); };
    template<typename T> class TItem : public Item { public: T t; };
private:
    std::vector<Item*> items;
    static size_t counter;
    template<typename T> static size_t index()
    {
        static size_t i = counter++;
        return i;
    }
public:
    template<typename T> bool find(T*& out)
    {
        out = 0;
        if (items.size() > index<T>())
        {
            Item* item = items[index<T>()];
            if (item)
                out = &static_cast<TItem<T>*>(item)->t;
        }
        return out != 0;
    }
};
struct ChangePropertyItem { int value; };
template bool Association<Instance>::find<ChangePropertyItem>(ChangePropertyItem*&);
}
