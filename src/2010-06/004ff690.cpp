// from server: 39% by atomic.potato
extern "C" void* __stdcall make_desc_004d1260(const char*, int);
extern "C" void* __stdcall func_005a55f0();
extern "C" void* __stdcall func_007a79a0(unsigned int);

struct Sub_004fee50 {
    void call_004fee50(int, int);
};

struct Sub_0067a200 {
    void call_0067a200(void*);
};

struct VPeer_BoundFuncDesc {
    char pad_000[0x38];
    int field_038;
    int field_03c;
    int field_040;
    void* field_044;
    int field_048;
    void* field_04c;

    void ctor(int, int, int, int, int, int, int, int);
};

void VPeer_BoundFuncDesc::ctor(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    void* p = make_desc_004d1260((const char*)a1, a2);
    ((Sub_0067a200*)this)->call_0067a200(p);
    field_038 = a3;
    field_03c = a4;
    *(int*)this = 0xa1c72c;
    ++*(int*)0xc18584;
    field_040 = (int)func_005a55f0();
    void* q = func_007a79a0(8);
    if (q) {
        *(int*)q = 0xa046e8;
        *(int*)((char*)q + 4) = a5;
    } else {
        q = 0;
    }
    field_044 = q;
    ++*(int*)0xc18584;
    field_048 = (int)func_005a55f0();
    void* r = func_007a79a0(8);
    if (r) {
        *(int*)r = 0xa046e8;
        *(int*)((char*)r + 4) = a6;
    } else {
        r = 0;
    }
    field_04c = r;
    ((Sub_004fee50*)this)->call_004fee50(a7, a8);
}
