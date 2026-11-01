// from server: 67% by Intel




extern "C" void* __cdecl sub_521FE0();
extern "C" int __cdecl sub_7CCD90(void*, int);
extern "C" void __cdecl sub_B229DC(void*);
extern "C" void __cdecl sub_983144(int, void*);
extern "C" void __cdecl G1_func_00974680();

struct VInstance {
    void func_006A7AC0();
};

void VInstance::func_006A7AC0() {
    void* v1 = sub_521FE0();
    void* v2 = *(void**)v1;
    if (!sub_7CCD90(v2, 3)) {
        void* local_8[2];
        sub_B229DC(local_8);
        sub_983144(0xCE064C, local_8);
    }
    G1_func_00974680();
}
