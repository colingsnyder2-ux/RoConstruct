// from server: 43% by colin
struct VCApp {
    char pad[8];
    int field8;
    char pad2[0x10];
    int field1c;
    void sub_409290();
};

extern "C" void __stdcall sub_466b20(int);

void VCApp::sub_409290() {
    int* p = this ? (int*)((char*)this + 0x1c) : 0;
    int v = *(int*)((char*)p + 4);
    if (v != 0) {
        int* vt = *(int**)v;
        void (__stdcall *fn)(int) = *(void (__stdcall**)(int))(vt + 2);
        fn(v);
    }
    int* r = this ? (int*)((char*)this + 8) : 0;
    sub_466b20((int)r);
}
