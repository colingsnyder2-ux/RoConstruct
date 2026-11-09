// from server: 70% by atomic.potato
extern "C" void __cdecl sub_498e80(float, int, int, int, int, int);

struct DxUserInputJob
{
    void __cdecl f(int, int, int, int);
};

void __cdecl DxUserInputJob::f(int a, int b, int c, int d)
{
    sub_498e80(0.0f, d, c, b, a, 6);
}
