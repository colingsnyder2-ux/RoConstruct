// from server: 78% by colin
extern "C" void __stdcall sub_00630AF7(void*, int, int, void*);

struct seg_00750000 {
    char pad[0xfc];
    void method();
};

void seg_00750000::method() {
    sub_00630AF7((char*)this + 0xfc, 8, 2, (void*)0x492360);
}
