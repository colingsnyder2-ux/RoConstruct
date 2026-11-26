// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <new>
void* __cdecl rbx_allocate(unsigned int size);
template<class T> class Target {};
template<class T> void intrusive_ptr_add_ref(Target<T>* p);
template<class T> void intrusive_ptr_release(Target<T>* p);
template<class T> class intrusive_ptr {
public:
    T* px;
    intrusive_ptr(T* p) : px(p) { if (px != 0) intrusive_ptr_add_ref(px); }
    intrusive_ptr(const intrusive_ptr& r) : px(r.px) { if (px != 0) intrusive_ptr_add_ref(px); }
    ~intrusive_ptr() { if (px != 0) intrusive_ptr_release(px); }
};
class Owner;
#pragma pack(push, 1)
struct First { int a; char b; };
#pragma pack(pop)
class Item : public First, public Target<Item> {
public:
    int pad[0x6];
    Item(int a, Owner* owner) throw();
};
class Owner {
public:
    void add(Item* item);
    intrusive_ptr<Item> create(int a);
};
intrusive_ptr<Item> Owner::create(int a)
{
    Item* item = new (rbx_allocate(sizeof(Item))) Item(a, this);
    add(item);
    return intrusive_ptr<Item>(item);
}

