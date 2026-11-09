// from server: 44% by atomic.potato
typedef unsigned int U32;

extern "C" U32 __stdcall func_0053b360(U32);
extern "C" U32 __stdcall func_0053b3a0();
extern "C" void func_00921a20(void *, U32, U32);

struct AdornRbxGfx
{
    void f(U32, U32);
};

void AdornRbxGfx::f(U32 a, U32 b)
{
    func_00921a20(this, b, func_0053b3a0());
}
