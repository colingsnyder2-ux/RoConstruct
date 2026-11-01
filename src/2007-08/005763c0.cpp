// from server: 100% by colin
struct S {
    void f();
};

extern "C" void __cdecl sub_62fc62(void*);

void S::f()
{
    *(int*)this = 0x7aaab4;
    int* p = (int*)((char*)this + 8);
    if (*p) {
        sub_62fc62((void*)*p);
    }
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0xc) = 0;
    *(int*)((char*)this + 0x10) = 0;
}
