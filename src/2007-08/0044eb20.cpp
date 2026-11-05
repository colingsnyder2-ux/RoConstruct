// from server: 32% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vptr;
    long refcount;
    long refcount2;
};

struct CRobloxDoc {
    void* field0;
    Inner* field4;
    void setSomething(void* p);
};

extern "C" void __stdcall sub_40D550(void*);
extern "C" void __stdcall sub_468200(void*);
extern "C" void __stdcall sub_544FE0(void*, void*, int);
extern "C" void __stdcall sub_5595A0(void*);
extern "C" void __stdcall sub_6303DC(void*);
extern "C" void __stdcall sub_6303E8(void*, void*);
extern "C" void __stdcall sub_630A1E(void);

extern "C" void* __stdcall sub_77DD98();
extern "C" void __stdcall sub_77DDBC(void*);
extern "C" void __stdcall sub_77E698(void*, void*);
extern "C" void __stdcall sub_77E6AC(void*);

void CRobloxDoc::setSomething(void* p)
{
    void* old = this->field0;
    this->field0 = p;
    Inner* inner = this->field4;
    if (inner != 0) {
        _InterlockedExchangeAdd(&inner->refcount, 1);
    }
    this->field4 = inner;

    char buf1[0x20];
    sub_40D550(buf1);

    if (inner != 0) {
        if (_InterlockedExchangeAdd(&inner->refcount, -1) == 1) {
            void* vt = inner->vptr;
            void (*f1)(void*) = *(void (**)(void*))((char*)vt + 4);
            f1(inner);
            if (_InterlockedExchangeAdd(&inner->refcount2, -1) == 1) {
                void* vt2 = inner->vptr;
                void (*f2)(void*) = *(void (**)(void*))((char*)vt2 + 8);
                f2(inner);
            }
        }
    }

    char buf2[0x20];
    sub_6303E8(buf2, buf1);
    void* h = sub_77DD98();
    sub_77E698(buf2, h);

    char buf3[0x20];
    sub_544FE0(buf3, buf2, 1);

    sub_468200(*(void**)((char*)this + 0x78));

    sub_77E6AC(buf2);
    sub_77DDBC(buf1);
    sub_5595A0(buf3);
    sub_6303DC(buf2);
    sub_77DDBC(buf1);
}
