// from server: 43% by colin
struct WeldSelectionVerb {
    char pad0[0x14];
    int field14;
    char pad18[0x8];
    void* field20;
    void doIt(int);
};

extern "C" void __stdcall sub_55E290();
extern "C" void __stdcall sub_410D40();
extern "C" void __stdcall sub_562300();
extern "C" void __stdcall sub_55F400();
extern "C" void __stdcall sub_55A920();
extern "C" void __stdcall sub_58C810();
extern "C" void __stdcall sub_4108B0();
extern "C" void __stdcall sub_77E6D8();

void WeldSelectionVerb::doIt(int arg)
{
    void* p = field20;
    sub_55E290();
    if (field20 != 0) {
        sub_410D40();
    }

    char flag = *(char*)((char*)&arg + 4);
    int* p14 = &field14;
    sub_562300();
    int* a = *(int**)((char*)p14 + 0x104);
    int b = *(int*)((char*)a + 8);
    if (*(int*)((char*)a + 4) > b) {
        sub_77E6D8();
    }

    sub_562300();
    int* c = *(int**)((char*)p14 + 0x104);
    int d = *(int*)((char*)c + 4);
    if (d > *(int*)((char*)c + 8)) {
        sub_77E6D8();
        d = *(int*)((char*)c + 4);
    }

    sub_55F400();
    void* q = field20;
    if (q != 0) {
        sub_55A920();
    } else {
        q = 0;
    }
    sub_58C810();
    sub_4108B0();
    void** vt = *(void***)q;
    void (*fn)(void*) = (void (*)(void*))vt[1];
    *(int*)((char*)q + 4) = -1;
    fn(q);
}
