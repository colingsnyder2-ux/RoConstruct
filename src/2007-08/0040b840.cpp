// from server: 100% by colin
// roc 2007-08 0040b840  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040b840

extern "C" int __stdcall sub_4022a0(int, void*, int, int);

extern int g_785bd0;

int __stdcall sub_40b840(int a1, int a2, int a3)
{
    return sub_4022a0(a1, &g_785bd0, a2, a3);
}
