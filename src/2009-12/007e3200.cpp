// from server: 31% by atomic.potato
struct type_info {
    bool operator==(const type_info&) const;
};

struct Elem {
    int v;
    char pad[4];
    void dtor();
};

struct Holder {
    Elem* p;
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern "C" void __stdcall free_(void*);

void __cdecl sub_705fb0(Elem* dst, Elem* src);
void __cdecl sub_7046d0(Elem* p);
void __cdecl sub_7f385a(void* p);
void* __cdecl sub_7f3860(unsigned int n);

extern type_info ti_bind;
extern void* g_98b768;

struct S {
};

void __cdecl f(int op, void* a, void* b)
{
    if (op == 0) {
        Elem* src = *(Elem**)a;
        Elem* e = (Elem*)sub_7f3860(0x30);
        if (e) {
            e->v = src->v;
            sub_705fb0((Elem*)((char*)e + 8), (Elem*)((char*)src + 8));
            *(Elem**)b = e;
        } else {
            *(Elem**)b = 0;
        }
        return;
    }
    if (op == 1) {
        Elem* src = *(Elem**)a;
        *(Elem**)b = src;
        *(Elem**)a = 0;
        return;
    }
    if (op == 2) {
        Elem* e = *(Elem**)b;
        if (e) {
            sub_7046d0((Elem*)((char*)e + 8));
            sub_7f385a(e);
        }
        *(Elem**)b = 0;
        return;
    }
    if (op == 3) {
        Elem* e = *(Elem**)b;
        if (ti_bind.operator==(*(type_info*)&g_98b768)) {
            *(Elem**)b = *(Elem**)a;
        } else {
            *(Elem**)b = 0;
        }
        return;
    }
    *(void**)b = &ti_bind;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
