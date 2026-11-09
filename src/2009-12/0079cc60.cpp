// from server: 100% by atomic.potato
extern "C" int __cdecl sub_78a8b0(int, int);
extern "C" void __declspec(dllimport) __cdecl srand(unsigned int);

int f(int value)
{
    srand(sub_78a8b0(value, 1));
    return 0;
}
