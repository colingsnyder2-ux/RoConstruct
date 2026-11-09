// from server: 100% by user
// roc 2008-06 00574330  unit: RBX::UnifiedWidget  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00574330
//
// 00574330  83ec0c               sub esp, 0xc
// 00574333  53                   push ebx
// 00574334  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00574338  55                   push ebp
// 00574339  56                   push esi
// 0057433a  8bf1                 mov esi, ecx
// 0057433c  8b06                 mov eax, dword ptr [esi]
// 0057433e  8b5048               mov edx, dword ptr [eax + 0x48]
// 00574341  57                   push edi
// 00574342  53                   push ebx
// 00574343  ffd2                 call edx
// 00574345  8b06                 mov eax, dword ptr [esi]
// 00574347  8b505c               mov edx, dword ptr [eax + 0x5c]
// 0057434a  8d4c2414             lea ecx, [esp + 0x14]
// 0057434e  51                   push ecx
// 0057434f  8bce                 mov ecx, esi
// 00574351  ffd2                 call edx
// 00574353  d9442414             fld dword ptr [esp + 0x14]
// 00574357  d8056c6e8200         fadd dword ptr [0x826e6c]
// 0057435d  d803                 fadd dword ptr [ebx]
// 0057435f  d91b                 fstp dword ptr [ebx]
// 00574361  d9442418             fld dword ptr [esp + 0x18]
// 00574365  e886d41200           call 0x6a17f0
// 0057436a  d9057c4d9700         fld dword ptr [0x974d7c]
// 00574370  8bf8                 mov edi, eax
// 00574372  83c704               add edi, 4
// 00574375  e876d41200           call 0x6a17f0
// 0057437a  d94304               fld dword ptr [ebx + 4]
// 0057437d  83e878               sub eax, 0x78
// 00574380  99                   cdq 
// 00574381  f7ff                 idiv edi
// 00574383  8be8                 mov ebp, eax
// 00574385  e866d41200           call 0x6a17f0
// 0057438a  83e814               sub eax, 0x14
// 0057438d  99                   cdq 
// 0057438e  f7ff                 idiv edi
// 00574390  8bb608010000         mov esi, dword ptr [esi + 0x108]
// 00574396  8bc8                 mov ecx, eax
// 00574398  894c2420             mov dword ptr [esp + 0x20], ecx
// 0057439c  85f6                 test esi, esi
// 0057439e  740b                 je 0x5743ab
// 005743a0  8b4610               mov eax, dword ptr [esi + 0x10]
// 005743a3  2b460c               sub eax, dword ptr [esi + 0xc]
// 005743a6  c1f803               sar eax, 3
// 005743a9  eb02                 jmp 0x5743ad
// 005743ab  33c0                 xor eax, eax
// 005743ad  99                   cdq 
// 005743ae  2bc2                 sub eax, edx
// 005743b0  d1f8                 sar eax, 1
// 005743b2  2be8                 sub ebp, eax
// 005743b4  3bc1                 cmp eax, ecx
// 005743b6  89442410             mov dword ptr [esp + 0x10], eax
// 005743ba  896c2414             mov dword ptr [esp + 0x14], ebp
// 005743be  8d4c2420             lea ecx, [esp + 0x20]
// 005743c2  7c04                 jl 0x5743c8
// 005743c4  8d4c2410             lea ecx, [esp + 0x10]
// 005743c8  8b09                 mov ecx, dword ptr [ecx]
// 005743ca  894c2420             mov dword ptr [esp + 0x20], ecx
// 005743ce  3bcd                 cmp ecx, ebp
// 005743d0  8d4c2420             lea ecx, [esp + 0x20]
// 005743d4  7c04                 jl 0x5743da
// 005743d6  8d4c2414             lea ecx, [esp + 0x14]
// 005743da  8b09                 mov ecx, dword ptr [ecx]
// 005743dc  2bc8                 sub ecx, eax
// 005743de  0fafcf               imul ecx, edi
// 005743e1  83c114               add ecx, 0x14
// 005743e4  5f                   pop edi
// 005743e5  894c241c             mov dword ptr [esp + 0x1c], ecx
// 005743e9  5e                   pop esi
// 005743ea  db442418             fild dword ptr [esp + 0x18]
// 005743ee  5d                   pop ebp
// 005743ef  8bc3                 mov eax, ebx
// 005743f1  d95b04               fstp dword ptr [ebx + 4]
// 005743f4  5b                   pop ebx
// 005743f5  83c40c               add esp, 0xc
// 005743f8  c20400               ret 4

#pragma fenv_access(on)
const float horizontalOffset = 4.0f;
extern float availableHeight;

struct Vec2 {
    float x;
    float y;
};

struct Entry {
    char data[8];
};

struct Entries {
    char padding[12];
    Entry* begin;
    Entry* end;
};

template<class T>
inline const T& maximum(const T& a, const T& b)
{
    return a < b ? b : a;
}

template<class T>
inline const T& minimum(const T& a, const T& b)
{
    return a < b ? a : b;
}

struct S {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual Vec2 position() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual Vec2 size() = 0;

    char padding[260];
    Entries* entries;

    Vec2 f();
};

Vec2 S::f()
{
    Vec2 result = position();
    Vec2 dimensions = size();

    result.x += dimensions.x + horizontalOffset;

    int spacing = (int)dimensions.y + 4;
    int limit = ((int)availableHeight - 120) / spacing;
    int row = ((int)result.y - 20) / spacing;
    Entries* list = entries;
    int half = (list ? (int)(list->end - list->begin) : 0) / 2;

    limit -= half;
    row = maximum(half, row);
    row = minimum(row, limit);
    result.y = (float)((row - half) * spacing + 20);

    return result;
}
