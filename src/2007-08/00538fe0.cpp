// from server: 100% by atomic.potato
struct S {
    void f(int, int, int);
};

extern "C" char __cdecl sub_4879D0(int*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

void S::f(int a, int b, int c)
{
    int local[3];
    local[0] = a;
    local[1] = b;
    local[2] = c;

    if (sub_4879D0(local) == 0) {
        *(int*)((char*)this + 8) = 0x5389C0;
        *(int*)this = 0x537E80;
        void* p = sub_62FEF6(0xC);
        if (p != 0) {
            *(int*)((char*)p + 0) = local[0];
            *(int*)((char*)p + 4) = local[1];
            *(int*)((char*)p + 8) = local[2];
        }
        *(void**)((char*)this + 4) = p;
    }
}
