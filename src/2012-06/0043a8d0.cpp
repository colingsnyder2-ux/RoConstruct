// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Member
{
    void* vtbl;
    ~Member();
};
struct Base
{
    char pad[0x20c];
    ~Base();
};
struct Derived : Base
{
    Member member;
    ~Derived();
};
Derived::~Derived()
{
}