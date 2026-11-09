// from server: 63% by atomic.potato
typedef float Float;
typedef int (__cdecl *Callback)(int, Float);

extern "C" void __cdecl func_008fb2b4(int);
extern Callback G_00b6b340;

int __stdcall func_008f7b21(int a, Float b)
{
    func_008fb2b4(1);
    return G_00b6b340(a, b);
}
