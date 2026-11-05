// from server: 69% by atomic.potato
struct S {
    char pad[8];
    int field8;
    int f(int a, int b);
};

extern "C" void __stdcall sub_98b6f0(void*, const void*);

int S::f(int a, int b)
{
    int tmp = 0;
    int* p = (int*)a;
    if (p != 0)
        p = (int*)((char*)p - 0x1c);
    else
        p = 0;
    int* q = (int*)((char*)this->field8 + (int)p);
    sub_98b6f0((void*)b, (const void*)q);
    *(int*)((char*)b + 0x1c) = *(int*)((char*)q + 0x1c);
    return b;
}
