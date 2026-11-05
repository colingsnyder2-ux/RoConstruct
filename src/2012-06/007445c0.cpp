// from server: 59% by atomic.potato
struct S {
    char pad[0x28];
    int field28;
    char pad2[0x14];
    int field14;
    int field18;
    int field0;
    void destroy();
};

extern "C" void __stdcall sub_b22a24();

void S::destroy()
{
    field28 = 0xb43c34;
    field0 = 0xbaa954;
    field14 = 0xbaa94c;
    field14 = 0xb43e60;
    int* p = (int*)field18;
    if (p) {
        int* vt = (int*)*p;
        void (__stdcall *fn)(int*) = (void (__stdcall *)(int*))vt[4];
        fn(p);
    }
    field0 = 0xbaa87c;
    sub_b22a24();
}
