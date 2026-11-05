// from server: 100% by colin
struct World {
    char pad[0x4c];
    int field_0x4c;
    void func(int arg);
};

extern "C" void __stdcall helper(int* out);

void World::func(int arg) {
    helper(&arg);
    int* p = (int*)arg;
    p[0x13] = 0;
}
