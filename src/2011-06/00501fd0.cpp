// from server: 31% by atomic.potato
typedef unsigned char Byte;

extern "C" int __cdecl Function80B2EA(int, int, int, int, int);
extern "C" void __cdecl Function80B0AC(int, int);
extern "C" void __cdecl FunctionA40A10(int);

struct BoundFuncDesc
{
    Byte pad[0x28];
    int (__stdcall *callback)(int);
    int arg;
    void f(int a, int b);
};

void BoundFuncDesc::f(int a, int b)
{
    int result = Function80B2EA(a, 0, 0xC073F8, 0xC25CA4, 0);
    if (result == 0)
    {
        FunctionA40A10(0xA5C10C);
        Function80B0AC(0xB989FC, 0xA5C10C);
    }
    int offset = this->arg;
    int (__stdcall *cb)(int) = this->callback;
    cb(offset + result);
}
