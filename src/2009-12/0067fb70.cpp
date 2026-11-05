// from server: 72% by atomic.potato
struct ModelInstance {
    char pad[0xc9];
    bool flag;
    void sub_636ac0(int);
    void func(int);
};

struct Helper {
    void sub_4f5230(int);
};

extern "C" void* __cdecl sub_4fca00(int, int);

void ModelInstance::func(int a) {
    if (flag) {
        void* p = sub_4fca00(3, 0x9d0134);
        ((Helper*)p)->sub_4f5230(0);
    }
    sub_636ac0(a);
}
