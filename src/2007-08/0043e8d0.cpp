// from server: 54% by colin
struct Vector3ComponentItem {
    char pad[0x114];
    void* field114;
    void* field118;
    int field11c;
    void method(void* a, void* b);
};

extern "C" void __stdcall sub_439850(void*, int);
extern "C" void __stdcall sub_5595a0(void*);

void Vector3ComponentItem::method(void* a, void* b) {
    int local1;
    int local2;
    int local3;
    int local4;
    int local5;
    int local6;
    int local7;
    int local8;

    sub_439850(&local1, *(int*)((char*)field114 + 0x188));

    local7 = 0;

    void* p;
    if (a) {
        p = (char*)a + 4;
    } else {
        p = 0;
    }

    void* obj = *(void**)((char*)field118 + 0x18);
    void* vtbl = *(void**)obj;
    void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)vtbl + 4);
    fn(&local2, p);

    int idx = field11c * 4;
    float val = *(float*)((char*)b + idx);
    *(float*)((char*)&local2 + idx) = val;

    void* p2;
    if (a) {
        p2 = (char*)a + 4;
    } else {
        p2 = 0;
    }

    void* obj2 = *(void**)((char*)field118 + 0x18);
    void* vtbl2 = *(void**)obj2;
    void (*fn2)(void*, void*) = *(void (**)(void*, void*))((char*)vtbl2 + 8);
    fn2(p2, &local2);

    local7 = -1;
    sub_5595a0(&local1);
}
