// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int sub_6c11a0();
struct Base {
    char pad[0x18];
    int m1c;
    char pad2[0x10];
    Base(int a, int b, int c, int d);
    virtual ~Base();
};
struct Replicator : Base {
    int m30;
    int m34;
    Replicator(int a1, int a2, int a3, int a4, int a5, int a6);
    virtual ~Replicator();
};
Replicator::Replicator(int a1, int a2, int a3, int a4, int a5, int a6)
    : Base(a3, a4, a5, a6)
{
    m30 = a1;
    m34 = a2;
    m1c = sub_6c11a0();
}