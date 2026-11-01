// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct ExeGuid { unsigned long a; unsigned short b, c; unsigned char d[8]; };
extern const ExeGuid guid_8b6a38;
int __cdecl helper_4683a0(int, const ExeGuid*);
int __stdcall f_0040f2f0(int, int b)
{
    return helper_4683a0(b, &guid_8b6a38);
}
