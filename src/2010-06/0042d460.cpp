// from server: 90% by atomic.potato
struct S
{
    int f();
};

extern "C" int __stdcall call_42d190(unsigned char);

int S::f()
{
    return call_42d190(((unsigned char*)this)[0xfc] == 0);
}
