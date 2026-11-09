// from server: 48% by atomic.potato
extern "C" void __cdecl sub_009672e0(void *, void *, const char *, int, int);

struct CellContact
{
    void f();
};

void CellContact::f()
{
    char buffer[16];
    sub_009672e0(buffer, *(void **)((char *)this + 4), "UVWQRP", 5, 0);
}
