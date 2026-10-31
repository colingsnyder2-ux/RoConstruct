// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 007b75a0  unit: RBX::Render::Material  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007b75a0
//
// 007b75a0  51                   push ecx
// 007b75a1  57                   push edi
// 007b75a2  8bf9                 mov edi, ecx
// 007b75a4  8b07                 mov eax, dword ptr [edi]
// 007b75a6  8b5010               mov edx, dword ptr [eax + 0x10]
// 007b75a9  ffd2                 call edx
// 007b75ab  85c0                 test eax, eax
// 007b75ad  7505                 jne 0x7b75b4
// 007b75af  5f                   pop edi
// 007b75b0  59                   pop ecx
// 007b75b1  c20400               ret 4
// 007b75b4  8b4710               mov eax, dword ptr [edi + 0x10]
// 007b75b7  89442404             mov dword ptr [esp + 4], eax
// 007b75bb  db442404             fild dword ptr [esp + 4]
// 007b75bf  56                   push esi
// 007b75c0  8d70ff               lea esi, [eax - 1]
// 007b75c3  d84c2410             fmul dword ptr [esp + 0x10]
// 007b75c7  e824a2eeff           call 0x6a17f0
// 007b75cc  85c0                 test eax, eax
// 007b75ce  7f04                 jg 0x7b75d4
// 007b75d0  33c0                 xor eax, eax
// 007b75d2  eb06                 jmp 0x7b75da
// 007b75d4  3bc6                 cmp eax, esi
// 007b75d6  7c02                 jl 0x7b75da
// 007b75d8  8bc6                 mov eax, esi
// 007b75da  6bc02c               imul eax, eax, 0x2c
// 007b75dd  03470c               add eax, dword ptr [edi + 0xc]
// 007b75e0  8bf0                 mov esi, eax
// 007b75e2  8b06                 mov eax, dword ptr [esi]
// 007b75e4  8b10                 mov edx, dword ptr [eax]
// 007b75e6  8bce                 mov ecx, esi
// 007b75e8  ffd2                 call edx
// 007b75ea  0fb6c0               movzx eax, al
// 007b75ed  f7d8                 neg eax
// 007b75ef  1bc0                 sbb eax, eax
// 007b75f1  f7d0                 not eax
// 007b75f3  23c6                 and eax, esi
// 007b75f5  5e                   pop esi
// 007b75f6  5f                   pop edi
// 007b75f7  59                   pop ecx
// 007b75f8  c20400               ret 4

struct Frame
{
    virtual bool unavailable() = 0;
    char data[40];
};

struct Material
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual int ready() = 0;

    int padding[2];
    Frame* frames;
    int count;

    Frame* select(float position);
};

Frame* Material::select(float position)
{
    if (!ready())
        return 0;

    int last = count - 1;
    int index = (int)(count * position);
    if (index <= 0)
        index = 0;
    else if (index >= last)
        index = last;

    Frame* frame = frames + index;
    return frame->unavailable() ? 0 : frame;
}
