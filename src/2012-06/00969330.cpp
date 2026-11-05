// from server: 69% by atomic.potato
// roc 2012-06 00969330  unit: RBX::AdvLuaDragTool  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00969330

extern "C" void* __stdcall sub_7bd700();
extern "C" void* __stdcall sub_7bd790();
extern "C" void __fastcall sub_896f50(void* self, void* arg);
extern "C" void __fastcall sub_8ef0e0(void* self, int a, void* b);
extern "C" void __fastcall sub_8ef290(void* self);
extern "C" void __stdcall sub_972290(int a, void* b);

extern unsigned char byte_e580b3;
extern void* dword_e5809c;

struct AdvLuaDragTool {
    char pad[0x7c];
    void* field_7c;
    int method(void* evt);
};

int AdvLuaDragTool::method(void* evt) {
    sub_896f50(this, evt);
    void* p = field_7c;
    if (*(int*)((char*)p + 0x80) == 2) {
        int t = *(int*)((char*)evt + 0x10);
        if (t == 0x65) {
            sub_8ef290(p);
        } else if (t == 0x72) {
            sub_8ef0e0(p, 2, sub_7bd700());
        } else if (t == 0x74) {
            sub_8ef0e0(p, 0, sub_7bd790());
        }
        return (int)this;
    }
    if (byte_e580b3 != 0) {
        void* fn = dword_e5809c;
        if (fn != 0) {
            if (((unsigned char (__stdcall*)(int, void*, void*))fn)(0x72, (void*)0xc08000, (void*)0xb460cc) != 0) {
                return 0;
            }
        }
        sub_972290(byte_e580b3, (void*)0xc080c0);
    }
    return 0;
}
