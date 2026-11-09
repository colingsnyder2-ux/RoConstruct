// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// Constructor analog for 00545e30: clears the pointer, then binds it to the
// item's key (key 00540e80, assign 00598fa0).
class Item {
public:
    int key() const;
};

class Handle {
public:
    Handle(const Item& item);
    void assign(int key);
    void* pointer;
};

Handle::Handle(const Item& item)
{
    pointer = 0;
    assign(item.key());
}
