// from server: 79% by atomic.potato
extern "C" void __cdecl imported_function(void *);

struct S
{
    unsigned char pad[4];
    unsigned int field4;
    void *fieldC;
    unsigned char field10;

    void f();
};

void S::f()
{
    if (field10 != 0 && field4 > 0x2000)
        imported_function(fieldC);
}
