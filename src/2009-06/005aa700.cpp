// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
class Item;
template<class T>
class Array {
public:
    ~Array();
    int size() const;
    T& operator[](int n);
    T* data;
    int num;
    int numAllocated;
};
class A { public: virtual ~A(); char data[8]; };
class B { public: virtual void f(); };
class Base : public A, public B {
public:
    virtual ~Base();
};
class Owner : public Base {
public:
    virtual ~Owner();
    virtual void f();
    static void release(Item* item);
    Array<Item*> items;
};
Owner::~Owner()
{
    for (int i = 0; i < items.size(); ++i)
        release(items[i]);
}
