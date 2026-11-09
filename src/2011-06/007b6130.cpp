// from server: 29% by atomic.potato
struct RBX_MovingAssemblyStage {
    char pad[0x28];
    void* field_24;
    void* get();
    int func_007b6130();
};

void* RBX_MovingAssemblyStage::get() {
    char* p = (char*)field_24;
    char* q = *(char**)(p + 0x20);
    if (q != 0) {
        return q - 8;
    }
    return 0;
}

int RBX_MovingAssemblyStage::func_007b6130() {
    void* (*call_006a1db0)();
    call_006a1db0 = (void* (*)())0x6a1db0;
    void* result = call_006a1db0();
    void* ecx = *(void**)((char*)result + 0x74);
    void* edx = *(void**)((char*)result + 0x78);
    void* esi = this;
    esi = (char*)esi + 0x14;
    void* (*call_006d0860)(void*, void*);
    call_006d0860 = (void* (*)(void*, void*))0x6d0860;
    return (int)call_006d0860(ecx, edx);
}
