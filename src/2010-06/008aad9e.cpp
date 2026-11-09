// from server: 41% by colin
extern "C" void __cdecl helper_008af41a(int);

extern "C" void __stdcall target_00bec150(int, int, int, int, int, float);

void __stdcall func_008aad9e(int a, int b, int c, int d, int e, float f)
{
    helper_008af41a(1);
    target_00bec150(a, b, c, d, e, f);
}
