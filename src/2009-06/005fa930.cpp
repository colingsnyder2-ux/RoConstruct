// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" {
    bool __cdecl sub_4C3F30(int, int);
    bool __cdecl sub_4C3F40(int, int);
    int __cdecl sub_4CAF90(int);
    bool __cdecl sub_4CADD0(int);
}
int __cdecl f(int a)
{
    bool v1 = sub_4C3F30(a, 1);
    bool v2 = sub_4C3F40(a, 1);
    bool v3 = (sub_4CAF90(a) != 0);
    bool v4 = sub_4CADD0(a);
    if (v2)
        return v4 ? 1 : 0;
    if (v1) {
        if (v3)
            return v4 ? 3 : 2;
        return 4;
    }
    return v3 ? 5 : 6;
}
