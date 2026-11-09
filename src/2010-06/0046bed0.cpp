// from server: 44% by atomic.potato
// roc 2010-06 0046bed0  unit: CRobloxWnd  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046bed0

extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    char pad0[0xc];
    void** begin;
    void** end;
};

struct Outer {
    char pad0[0xc0];
    Inner inner;
};

struct CRobloxWnd {
    char pad0[0x4];
    void* field4;
    void* method1(void*);
    void* method2(void*, void*);
    void* method3(void*, void*);
};

void* __fastcall sub_64abc0(void*);
void* __fastcall sub_658380(void*, int, int);
void* __fastcall sub_46b1c0(void*, void*, void*);

void* CRobloxWnd::method1(void* a) {
    void* edi = sub_64abc0(a);
    Outer* esi = (Outer*)((char*)this + 0xc0);
    sub_658380(&esi->inner, 8, 0);
    int count = (int)((char*)esi->inner.end - (char*)esi->inner.begin) >> 2;
    if (count <= 0) {
        _invalid_parameter_noinfo();
    }
    void** ebx = esi->inner.begin;
    void* ebp = (char*)a + 8;
    *ebx = sub_46b1c0(edi, (void*)0xa0fe44, ebp);
    int count2 = (int)((char*)esi->inner.end - (char*)esi->inner.begin) >> 2;
    if (count2 <= 1) {
        _invalid_parameter_noinfo();
    }
    void** esi2 = esi->inner.begin;
    ebp = (char*)ebp + 8;
    esi2 = esi2 + 1;
    *esi2 = sub_46b1c0(edi, (void*)0xa0fe30, ebp);
    return edi;
}
