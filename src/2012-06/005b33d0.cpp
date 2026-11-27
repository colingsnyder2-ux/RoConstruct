// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void __cdecl operator delete(void*);
struct Inner {
    int a;
    void* data;
    void clear();
};
struct Outer {
    int x;
    Inner inner;
};
void __stdcall f(Outer* o)
{
    Inner* q = &o->inner;
    q->clear();
    operator delete(q->data);
    q->data = 0;
}
