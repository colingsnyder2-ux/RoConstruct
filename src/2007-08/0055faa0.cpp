// from server: 38% by colin
struct FilteredSelection {
    int field0;
    char field4;
    int field8;
    int fieldC;
    FilteredSelection(int a, char b);
};

extern "C" void* __cdecl operator_new(unsigned int size);

struct VTableInit {
    void* vtbl;
    void* vtbl2;
    void* vtbl3;
};

extern int g_8c225c;

FilteredSelection::FilteredSelection(int a, char b) {
    field0 = a;
    field4 = b;
    void* p = operator_new(0x2c);
    if (p == 0) {
        *(int*)((char*)p + 4) = 0x786db0;
        *(int*)((char*)p + 0x28) = 0x786d0c;
        int edx = *(int*)((char*)p + 4);
        *(int*)p = 0x786d9c;
        int ecx = *(int*)(edx + 4);
        *(int*)((char*)p + ecx + 4) = 0x786d94;
        int g = g_8c225c;
        *(int*)((char*)p + 8) = 0;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 0x14) = g;
        *(int*)((char*)p + 0x18) = 0;
        *(int*)((char*)p + 0x20) = 0;
        *(int*)((char*)p + 0x24) = 0;
        int edx2 = *(int*)((char*)p + 4);
        *(int*)p = 0x786dac;
        int ecx2 = *(int*)(edx2 + 4);
        *(int*)((char*)p + ecx2 + 4) = 0x786da4;
    } else {
        p = 0;
    }
    field8 = (int)p;

    void* q = operator_new(0x2c);
    if (q != 0) {
        *(int*)((char*)q + 4) = 0x786db0;
        *(int*)((char*)q + 0x28) = 0x786d0c;
        int edx = *(int*)((char*)q + 4);
        *(int*)q = 0x786d9c;
        int ecx = *(int*)(edx + 4);
        *(int*)((char*)q + ecx + 4) = 0x786d94;
        int g = g_8c225c;
        *(int*)((char*)q + 8) = 0;
        *(int*)((char*)q + 0xc) = 0;
        *(int*)((char*)q + 0x10) = 0;
        *(int*)((char*)q + 0x18) = 0;
        *(int*)((char*)q + 0x14) = g;
        *(int*)((char*)q + 0x20) = 0;
        *(int*)((char*)q + 0x24) = 0;
        int edx2 = *(int*)((char*)q + 4);
        *(int*)q = 0x786dc4;
        int ecx2 = *(int*)(edx2 + 4);
        *(int*)((char*)q + ecx2 + 4) = 0x786dbc;
        fieldC = (int)q;
    } else {
        fieldC = 0;
    }
}
