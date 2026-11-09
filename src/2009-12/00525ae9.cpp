// from server: 49% by atomic.potato
struct S
{
    int f();
};

extern "C" void __cdecl sub_006c7390(int);

int S::f()
{
    int result = 0;
    if (reinterpret_cast<unsigned char *>(this)[0x14])
    {
        sub_006c7390(*reinterpret_cast<int *>(reinterpret_cast<char *>(this) - 0x24));
        result = 0x525b05;
    }
    return result;
}
