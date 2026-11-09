// from server: 100% by atomic.potato
extern "C" void target();

struct S
{
    void f();
};

void S::f()
{
    *(long*)this = 0x9d1274;
    *(long*)((char*)this + 4) = 0x9d126c;
    *(long*)((char*)this + 0x18) = 0x9d1260;
    *(long*)((char*)this + 0x1c) = 0x9d1258;
    *(long*)((char*)this + 0x94) = 0x9d1250;
    target();
}
