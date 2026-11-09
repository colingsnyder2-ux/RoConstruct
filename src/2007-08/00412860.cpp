// from server: 100% by colin
// roc 2007-08 00412860  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00412860

extern "C" int __stdcall sub_406f90(int, int, int, int);

int g_8bae44;

int __stdcall sub_412860(int a1)
{
    return sub_406f90(g_8bae44, 0x74, a1, 0);
}
