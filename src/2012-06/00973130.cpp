// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#pragma pack(push, 1)
struct A { char a[5]; };
struct B { int x; };
struct T : A, B { };
#pragma pack(pop)
void intrusive_ptr_release(B*);
void intrusive_ptr_add_ref(B*);
struct P { T* p; P& operator=(const P& o); P& operator=(T* o); };
P& P::operator=(const P& o)
{
    T* v = o.p;
    if (p) intrusive_ptr_release(p);
    p = v;
    if (v) intrusive_ptr_add_ref(v);
    return *this;
}
