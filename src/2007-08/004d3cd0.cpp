// from server: 100% by colin
struct Chunk {
    void f(int, int);
};

extern "C" bool __cdecl sub_4879D0(int*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

void Chunk::f(int a, int b) {
    int local[2];
    local[0] = a;
    local[1] = b;
    if (!sub_4879D0(local)) {
        *(int*)((char*)this + 8) = 0x5466b0;
        *(int*)this = 0x4d2410;
        void* p = sub_62FEF6(8);
        if (p) {
            *(int*)p = local[0];
            *(int*)((char*)p + 4) = local[1];
        }
        *(int*)((char*)this + 4) = (int)p;
    }
}
