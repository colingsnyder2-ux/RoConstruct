// from server: 50% by atomic.potato
struct DxUserInput
{
    void f(void *a1, void *a2);
};

extern "C" void __cdecl sub_004a8290(void *a1);
extern "C" void __cdecl sub_004a8570(DxUserInput *pThis, void *a1, int a2);

void DxUserInput::f(void *a1, void *a2)
{
    sub_004a8290(a1);
    sub_004a8570(this, a2, 1);
}
