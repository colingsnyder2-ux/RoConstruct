// from server: 19% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    long ref1;
    long ref2;
};

struct Sub1 {
    void* vptr;
    void dtor();
};

struct Sub2 {
    void* vptr;
    void dtor();
};

struct CRobloxReportPaneView {
    char pad0[0x30c];
    RefCounted* field30c;
    RefCounted* field314;
    void dtor();
};

extern void* g_vtable_792210;
extern void* g_vtable_7921fc;

void sub_4555b0(void*, int);
void sub_454280(Sub1*);
void sub_4541f0(Sub2*);
void sub_6520d0(CRobloxReportPaneView*);

void CRobloxReportPaneView::dtor()
{
    *(void**)this = &g_vtable_792210;
    *(void**)((char*)this + 0x30c - 0x30c + 0x30c) = 0;
    *(void**)((char*)this + 0x30c) = 0;
    *(void**)((char*)this + 0x314) = 0;

    RefCounted* p314 = this->field314;
    if (p314) {
        if (_InterlockedExchangeAdd(&p314->ref1, -1) == 1) {
            void** vt = (void**)p314->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(p314);
            if (_InterlockedExchangeAdd(&p314->ref2, -1) == 1) {
                void** vt2 = (void**)p314->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(p314);
            }
        }
    }

    RefCounted* p30c = this->field30c;
    if (p30c) {
        if (_InterlockedExchangeAdd(&p30c->ref1, -1) == 1) {
            void** vt = (void**)p30c->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(p30c);
            if (_InterlockedExchangeAdd(&p30c->ref2, -1) == 1) {
                void** vt2 = (void**)p30c->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(p30c);
            }
        }
    }

    sub_454280((Sub1*)((char*)this + 0x30c - 0x30c + 0x30c));
    sub_4541f0((Sub2*)((char*)this + 0x30c - 0x30c + 0x30c));
    sub_6520d0(this);
}
