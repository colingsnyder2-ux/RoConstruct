// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005b62a0  unit: RBX::VHat::?$FactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b62a0
//
// 005b62a0  51                   push ecx
// 005b62a1  8a44240c             mov al, byte ptr [esp + 0xc]
// 005b62a5  8a4c240d             mov cl, byte ptr [esp + 0xd]
// 005b62a9  8a54240e             mov dl, byte ptr [esp + 0xe]
// 005b62ad  56                   push esi
// 005b62ae  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005b62b2  88442404             mov byte ptr [esp + 4], al
// 005b62b6  884c2405             mov byte ptr [esp + 5], cl
// 005b62ba  88542406             mov byte ptr [esp + 6], dl
// 005b62be  c644240700           mov byte ptr [esp + 7], 0
// 005b62c3  8b442404             mov eax, dword ptr [esp + 4]
// 005b62c7  50                   push eax
// 005b62c8  56                   push esi
// 005b62c9  e8b2faffff           call 0x5b5d80
// 005b62ce  83c408               add esp, 8
// 005b62d1  8bc6                 mov eax, esi
// 005b62d3  5e                   pop esi
// 005b62d4  59                   pop ecx
// 005b62d5  c3                   ret 

struct RGB {
    unsigned char r, g, b;
};

struct RGBA {
    unsigned char r, g, b, a;
};

extern void __cdecl convert(void *destination, RGBA color);

void *__cdecl f(void *destination, RGB color)
{
    RGBA value;
    value.r = color.r;
    value.g = color.g;
    value.b = color.b;
    value.a = 0;
    convert(destination, value);
    return destination;
}
