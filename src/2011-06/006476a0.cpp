// from server: 61% by atomic.potato
struct S_006476a0 {
    void* f_8;
    int f_c;
    int f_10;
    void (*f_8_call)(void*);

    void f(void* p);
};

void S_006476a0::f(void* p)
{
    char* x;
    if (p)
        x = (char*)p - 0x1c;
    else
        x = 0;
    f_8_call((void*)((char*)x + f_c + *(int*)((char*)x + 0xb4) + f_10));
}
