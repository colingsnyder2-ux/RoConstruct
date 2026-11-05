// from server: 89% by atomic.potato
struct S
{
    int Get();
};

extern "C" int __stdcall Helper(S* p, int, int*);

int S::Get()
{
    int* p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x224);
    int* result = reinterpret_cast<int*>(Helper(this, 0, p));
    if (result != 0)
        return *reinterpret_cast<int*>(*reinterpret_cast<int**>(reinterpret_cast<char*>(result) + 0x198) + 0x108);
    return 0;
}
