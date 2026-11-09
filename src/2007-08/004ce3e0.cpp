// from server: 100% by colin
struct View {
    void f(int, int, int);
};

extern "C" char __cdecl sub_4879D0(void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

void View::f(int a1, int a2, int a3)
{
    int local[3];
    local[0] = a1;
    local[1] = a2;
    local[2] = a3;

    if (!sub_4879D0(local)) {
        *(int*)((char*)this + 8) = 0x4D2D30;
        *(int*)this = 0x4CDAE0;
        void* p = sub_62FEF6(0xC);
        if (p) {
            *(int*)((char*)p + 0) = local[0];
            *(int*)((char*)p + 4) = local[1];
            *(int*)((char*)p + 8) = local[2];
        }
        *(void**)((char*)this + 4) = p;
    }
}
