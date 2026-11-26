// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int sub_6c11a0();
namespace RBX {
struct Base {
    char pad[0x18];
    int m1c;
    char pad2[0x10];
    Base(int a, int b, int c, int d);
    virtual ~Base();
};
struct Pair { int m30; int m34; Pair(int a, int b) : m30(a), m34(b) {} };
struct ModelInstance : Base, Pair {
    int m38;
    ModelInstance(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    virtual ~ModelInstance();
};
ModelInstance::ModelInstance(int a1, int a2, int a3, int a4, int a5, int a6, int a7) : Base(a4, a5, a6, a7), Pair(a1, a2), m38(a3) { m1c = sub_6c11a0(); } }
