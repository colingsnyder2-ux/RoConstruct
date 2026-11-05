// from server: 100% by colin
struct RakPeer {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    char pad18[0x24];
    int field3C;
    char field38;
    RakPeer* init();
};

extern "C" void* __cdecl operator_new(unsigned int size);

RakPeer* RakPeer::init() {
    int* p;
    int i;

    p = (int*)operator_new(0x40);
    field8 = (int)p;
    *(char*)((char*)p + 0x38) = 0;
    p = (int*)field8;
    fieldC = (int)p;
    p = (int*)operator_new(0x40);
    *(int*)((char*)field8 + 0x3C) = (int)p;
    i = 6;
    do {
        p = (int*)field8;
        p = (int*)*(int*)((char*)p + 0x3C);
        field8 = (int)p;
        p = (int*)operator_new(0x40);
        *(int*)((char*)field8 + 0x3C) = (int)p;
        p = (int*)field8;
        *(char*)((char*)p + 0x38) = 0;
        i--;
    } while (i != 0);
    p = (int*)field8;
    p = (int*)*(int*)((char*)p + 0x3C);
    *(int*)((char*)p + 0x3C) = fieldC;
    field8 = fieldC;
    field0 = fieldC;
    field4 = fieldC;
    field14 = 0;
    field10 = 0;
    return this;
}
