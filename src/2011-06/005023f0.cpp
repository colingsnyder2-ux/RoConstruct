// from server: 100% by atomic.potato
typedef unsigned char Byte;

extern "C" void __cdecl Function500E70(int);
extern "C" void __cdecl Function80A058(int);

struct BoundFuncDesc
{
    int unused;
    int value;
    Byte unused2[1];
    Byte flags;
    void f();
};

void BoundFuncDesc::f()
{
    int value = this->value;
    if (value != 0)
    {
        if (this->flags != 0)
            Function500E70(value);
        Function80A058(this->value);
    }
}
