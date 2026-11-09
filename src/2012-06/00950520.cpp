// from server: 26% by Intel
struct AdvRotateTool {
    void __cdecl func(void* a, void* b, void* c);
};

extern "C" void __cdecl sub_9500e0(void*, void*);

void AdvRotateTool::func(void* a, void* b, void* c) {
    void* esi = a;
    void* ebx = b;
    void* edi = c;

    while (esi != ebx) {
        sub_9500e0(esi, edi);
        edi = (char*)edi + 0x28;
        esi = (char*)esi + 0x28;
    }
}
