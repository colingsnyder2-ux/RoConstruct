// from server: 48% by atomic.potato
// roc 2010-06 007626d0  unit: RBX::MovingAssemblyStage  size: 49 bytes
//
// 007626d0  83ec08               sub esp, 8
// 007626d3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007626d7  e8b440f1ff           call 0x676790
// 007626dc  8b4878               mov ecx, dword ptr [eax + 0x78]
// 007626df  890c24               mov dword ptr [esp], ecx
// 007626e2  8b507c               mov edx, dword ptr [eax + 0x7c]
// 007626e5  8d0424               lea eax, [esp]
// 007626e8  50                   push eax
// 007626e9  89542408             mov dword ptr [esp + 8], edx
// 007626ed  e8ce45edff           call 0x636cc0
// 007626f2  33c9                 xor ecx, ecx
// 007626f4  84c0                 test al, al
// 007626f6  0f94c1               sete cl
// 007626f9  8ac1                 mov al, cl
// 007626fb  83c40c               add esp, 0xc
// 007626fe  c20400               ret 4

struct RBX_Assembly {
    char pad[0x24];
    void* field_24;
    void* get();
};

void* RBX_Assembly::get() {
    char* p = (char*)field_24;
    char* q = *(char**)(p + 0x1c);
    if (q != 0) {
        return q - 8;
    }
    return 0;
}

extern "C" void* __stdcall get_676790();

extern "C" void* __stdcall call_636cc0(void* a, void* b);

int __stdcall RBX_MovingAssemblyStage_func007626d0(void* thisptr) {
    void* v1 = get_676790();
    void* v2 = *(void**)((char*)v1 + 0x78);
    void* v3 = *(void**)((char*)v1 + 0x7c);
    void* v4 = &v2;
    call_636cc0(v4, v3);
    int v5 = 0;
    if (*((unsigned char*)v4)) {
        v5 = 1;
    }
    return v5;
}
