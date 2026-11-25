// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS- /EHsc /Ob1
namespace ns_d {
struct Base { char pad[0x1d4]; ~Base(); };
struct Member { char d[16]; ~Member(); };
struct Derived : Base {
    Member m;
    ~Derived();
};
Derived::~Derived() {}
}