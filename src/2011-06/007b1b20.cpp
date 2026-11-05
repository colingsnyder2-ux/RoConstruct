// from server: 50% by atomic.potato
struct RBX_Assembly {
    char pad[0x28];
    void* field_24;
    void* get();
};

struct P_func_006a4b30 { void g(); };
struct S_func_006a4b30 {
    char pad[264];
    P_func_006a4b30* m_p;
    void f();
};

struct CleanStage {
    bool check(void* a);
};

bool CleanStage::check(void* a) {
    char* base = (char*)a + 0xc;
    int i;
    for (i = 0; i < 2; i++) {
        RBX_Assembly* asm_ = (RBX_Assembly*)(*(void**)(base + i * 4));
        void* r = asm_->get();
        char* edi = (char*)r;
        S_func_006a4b30* s = (S_func_006a4b30*)((RBX_Assembly*)edi)->get();
        char* esi = (char*)s + 0x30;
        int j;
        for (j = 0; j < 3; j++) {
            float v = *(float*)(esi + j * 4);
            if (v < 0) v = -v;
            if (v > 1.0f) return true;
        }
        if (edi[0x7c] != 0) {
            int ecx = *(int*)(edi + 0x8c) + *(int*)(edi + 0x80);
            void (*fn)() = *(void(**)())(edi + 0x88);
            fn();
            *(float*)(edi + 0x78) = 0.0f;
            edi[0x7c] = 0;
        }
        float scale = *(float*)(edi + 0x78);
        float x = *(float*)(esi + 0xc) * scale;
        float y = *(float*)(esi + 0x10) * scale;
        float z = *(float*)(esi + 0x14) * scale;
        float arr[3];
        arr[0] = x; arr[1] = y; arr[2] = z;
        for (j = 0; j < 3; j++) {
            float v = arr[j];
            if (v < 0) v = -v;
            if (v > 1.0f) return true;
        }
    }
    return false;
}
