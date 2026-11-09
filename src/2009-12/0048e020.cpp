// from server: 54% by atomic.potato
struct VertexStreamer {
    char pad0[0x18];
    void* field18;
    char pad1[0x10];
    void* field2c;
    char pad2[0x04];
    char field34[0x04];
    void func(void* arg);
};

extern "C" void __stdcall invalid_parameter_noinfo();

void VertexStreamer::func(void* arg) {
    void* esi = field18;
    void* edi = field2c;
    if (!esi) {
        invalid_parameter_noinfo();
    }
    edi = *(void**)((char*)edi + 4);
    void* eax;
    if (esi) {
        eax = *(void**)esi;
    } else {
        eax = 0;
    }
    if (edi == *(void**)((char*)eax + 0x14)) {
        invalid_parameter_noinfo();
    }
    while (esi) {
        esi = *(void**)esi;
        if (edi == *(void**)((char*)esi + 0x14)) {
            invalid_parameter_noinfo();
        }
    }
    invalid_parameter_noinfo();
    if (edi == *(void**)((char*)esi + 0x14)) {
        invalid_parameter_noinfo();
    }
    *(int*)((char*)edi + 0x1c) += 1;
    ((void (__thiscall*)(void*, void*))0x48dee0)(field34, arg);
}
