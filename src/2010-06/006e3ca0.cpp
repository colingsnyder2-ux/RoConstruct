// from server: 52% by atomic.potato
// roc 2010-06 006e3ca0  unit: RBX::VLuaDragger::?$FactoryProduct  size: 206 bytes

struct S {
    char pad0[0x94];
    int state;
    char pad1[0x20];
    void* ptr_b8;
    char pad2[4];
    char buf_c0[0x10];
    void mouseUp();
};

extern "C" void __stdcall sub_71ad40(void*);
extern "C" void __stdcall sub_71a880(void*);
extern "C" void __stdcall sub_7657d0(void*);
extern "C" void __stdcall sub_7a799a(void*);
extern "C" void __stdcall sub_7a89b2(void*, void*);
extern "C" void __stdcall sub_4093b0(void*, void*);
extern "C" void __stdcall sub_9ea410(void*, const char*);

void S::mouseUp() {
    if (state == 2) {
        sub_71ad40(buf_c0);
        sub_71a880(buf_c0);
        void* p = ptr_b8;
        if (p) {
            sub_7657d0(p);
            sub_7a799a(p);
        }
        ptr_b8 = 0;
        state = 3;
        return;
    }
    if (state == 1) {
        state = 4;
        return;
    }
    char local[0x20];
    sub_9ea410(local, "Call to LuaDragger::mouseUp without mouseDown");
    void* v = local;
    sub_4093b0(local + 0x1c, &v);
    sub_7a89b2(local + 0x1c, (void*)0xb03074);
}
