// from server: 38% by colin
struct MegaClusterInstance {
    char pad[0x1c];
    void* field_1c;
    void initialize();
};

extern "C" void* __cdecl sub_6c16e0();
extern "C" void* __cdecl sub_6c1280();
extern "C" void* __cdecl sub_67f2e0(void*, void*, void*);
extern "C" void __stdcall sub_709480(void*, void*);

void MegaClusterInstance::initialize() {
    void* p1;
    void* p2;
    void* p3;
    void* v;

    field_1c = sub_6c16e0();

    v = sub_6c1280();
    sub_67f2e0(&p1, v, &p1);
    sub_709480(&field_1c, p1);

    v = sub_6c1280();
    sub_67f2e0(&p2, v, &p2);
    sub_709480(&field_1c, p2);

    v = sub_6c1280();
    sub_67f2e0(&p3, v, &p3);
    sub_709480(&field_1c, p3);

    if (p1) {
        void (__stdcall *fn)(void*, void*) = *(void (__stdcall **)(void*, void*))((char*)p1 + 4);
        fn((char*)p1, &p1);
    }
    if (p2) {
        void (__stdcall *fn)(void*, void*) = *(void (__stdcall **)(void*, void*))((char*)p2 + 4);
        fn((char*)p2, &p2);
    }
    if (p3) {
        void (__stdcall *fn)(void*, void*) = *(void (__stdcall **)(void*, void*))((char*)p3 + 4);
        fn((char*)p3, &p3);
    }
}
