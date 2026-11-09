// from server: 100% by Intel
extern "C" int __cdecl SetGridToOne();

int __cdecl SetGridToOne()
{
    int* ptr = (int*)0x00E52558;
    return (*ptr == 0) ? 1 : 0;
}
