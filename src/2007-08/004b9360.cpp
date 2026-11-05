// from server: 100% by tester
struct RakPeer {
    unsigned char pad0[8];
    void* field8;
    void* fieldC;
    int field10;
    int field14;
    RakPeer* construct();
};

extern "C" void* __cdecl operator_new(unsigned int size);

RakPeer* RakPeer::construct()
{
    unsigned char* p;
    int i;

    p = (unsigned char*)operator_new(0x128);
    field8 = p;
    p[0x120] = 0;
    fieldC = field8;

    p = (unsigned char*)operator_new(0x128);
    *(void**)((unsigned char*)field8 + 0x124) = p;

    i = 6;
    while (i != 0) {
        unsigned char* q = (unsigned char*)field8;
        unsigned char* r = (unsigned char*)*(void**)(q + 0x124);
        field8 = r;
        p = (unsigned char*)operator_new(0x128);
        *(void**)((unsigned char*)field8 + 0x124) = p;
        ((unsigned char*)field8)[0x120] = 0;
        i--;
    }

    {
        unsigned char* a = (unsigned char*)field8;
        unsigned char* b = (unsigned char*)*(void**)(a + 0x124);
        unsigned char* c = (unsigned char*)fieldC;
        *(void**)(b + 0x124) = c;
    }

    field8 = fieldC;
    *(void**)this = fieldC;
    *(void**)((unsigned char*)this + 4) = fieldC;
    field14 = 0;
    field10 = 0;
    return this;
}
