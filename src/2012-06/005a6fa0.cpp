// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O1 /GS- /EHsc /MD 
struct T { bool h(void*); };
struct U { char pad[0xc]; T* q; };
void* g();
void* f(U* p)
{
    if (p) { T* q = p->q; if (q->h(g())) return (char*)p - 0x1c; }
    return 0;
}

