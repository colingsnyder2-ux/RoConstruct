// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
struct S {
    int f(int a, int b, int c);
};

// StringConverter<CoordinateFrame>::convertToValue
extern "C" bool __cdecl fn_0060a2f0(int* p);

// INFERRED: the value stored at offset 0 is the address of an unknown global (likely a vtable)
extern "C" char g_00826eb8;

// INFERRED: unnamed target, so it is defined as the fixed-name extern "C" __fastcall function
extern "C" int __fastcall fn_004e9f40(S* self, int unusedEdx, int a, int b, int c)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    *(int*)self = 0;
    if (!fn_0060a2f0(local)) {
        int* p = (int*)((char*)self + 8);
        if (p) {
            p[0] = local[0];
            p[1] = local[1];
        }
        *(int*)self = (int)&g_00826eb8;
        return (int)self;
    }
    *(int*)self = 0;
    return (int)self;
}
