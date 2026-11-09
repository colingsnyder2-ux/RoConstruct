// from server: 100% by atomic.potato
typedef unsigned int DWORD;

extern "C" int __cdecl sub_0050cd30(const char*, int);

DWORD g_00cb8584;
DWORD g_00cb8588;

void sub_0050cd90()
{
    ++g_00cb8588;
    if (g_00cb8588 == 1)
        g_00cb8584 = sub_0050cd30(".\\raknet\\Source\\StringCompressor.cpp", 30);
}
