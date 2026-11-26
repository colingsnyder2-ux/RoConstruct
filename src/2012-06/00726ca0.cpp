// from server: 85% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int sub_7092a0();
namespace RBX {
struct Base {
    char pad[0x18];
    int m1c;
    char pad2[0x10];
    Base(int a, int b, int c, int d);
    virtual ~Base();
};
struct Pair { int m30; int m34; Pair(int a, int b) : m30(a), m34(b) {} };struct Value { void* p; char pad[0x3c]; Value() : p(0) {} Value(const Value&); ~Value(); }; struct Item { const void* type; Value value; Item(const void* t) : type(t) {} };
struct RootInstance : Base, Pair {
    int m38;
    int m3c;
    RootInstance(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    virtual ~RootInstance();
    void init(int a, Item b);
};
RootInstance::RootInstance(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) : Base(a4, a6, a7, a8), Pair(a1, a2), m38(a3), m3c(0) { init(a5, Item((const void*)sub_7092a0())); } }
