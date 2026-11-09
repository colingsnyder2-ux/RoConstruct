// from server: 100% by atomic.potato
extern "C" unsigned char* __cdecl func_007fb710(void*);

struct S
{
    void f();
};

void S::f()
{
    unsigned char buffer[8];
    unsigned char* result = func_007fb710(buffer);
    *(int*)((char*)this + 0x160) = *(int*)result;
    *(int*)((char*)this + 0x164) = *(int*)(result + 4);
}
