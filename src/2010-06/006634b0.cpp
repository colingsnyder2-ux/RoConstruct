// from server: 57% by atomic.potato
extern "C" void sub_004B12A0(void*);

struct S
{
    void f(void*);
    void* field38;
};

void S::f(void* p)
{
    if (p)
        sub_004B12A0((char*)field38 + ((char*)p - (char*)0x1c));
    else
        sub_004B12A0(field38);
}
