// from server: 100% by atomic.potato
struct PartDropTool {
    void* vftable0;
    void* vftable1;
    char pad[0x3C];
    void* vftable2;
    void* destroy(char);
};

extern "C" void __cdecl sub_7d69e0();
extern "C" void __cdecl sub_7f385a(void*);

void* PartDropTool::destroy(char flag) {
    vftable0 = (void*)0x9eeaa4;
    vftable1 = (void*)0x9eea8c;
    vftable2 = (void*)0x9eea84;
    sub_7d69e0();
    if (flag & 1) {
        sub_7f385a(this);
    }
    return this;
}
