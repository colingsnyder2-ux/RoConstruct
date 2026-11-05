// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2008-06 00616b00  (agentH rewrite)

#include <string>
#include <vector>

struct B00 { virtual void f00(); char pad[0x0c]; };
struct B10 { virtual void f10(); };
struct B14 { virtual void f14(); char pad[0x08]; };
struct B20 { virtual void f20(); };
struct B24 { virtual void f24(); char pad[0x1c]; };
struct B44 { virtual void f44(); char pad[0x1c]; };
struct B64 { virtual void f64(); char pad[0x1c]; };
struct B84 { virtual void f84(); char pad[0x1c]; };
struct Ba4 { virtual void fa4(); char pad[0x1c]; };
struct Bc4 { virtual void fc4(); char pad[0x68]; };

struct Base : B00, B10, B14, B20, B24, B44, B64, B84, Ba4, Bc4 {
    Base();
    ~Base();
};

struct __declspec(novtable) Listener { virtual void f130(); };

struct Item;

struct RefCount;
struct Count {
    RefCount* pi;
    Count() : pi(0) {}
    ~Count();
};

struct Reference {
    void* px;
    Count pn;
    Reference() : px(0) {}
};

struct Selection : Base, Listener {
    Reference reference;
    std::vector<Item*> items;

    Selection();
    void setName(const std::string&);
};

Selection::Selection()
{
    std::string name("FilteredSelection");
    setName(name);
}
