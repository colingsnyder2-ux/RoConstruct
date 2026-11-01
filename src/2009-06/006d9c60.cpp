// from server: 73% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0064b890  unit: RBX::SleepStage  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064b890
//
// 0064b890  56                   push esi
// 0064b891  57                   push edi
// 0064b892  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0064b896  837f0400             cmp dword ptr [edi + 4], 0
// 0064b89a  8bf1                 mov esi, ecx
// 0064b89c  743b                 je 0x64b8d9
// 0064b89e  8b4f04               mov ecx, dword ptr [edi + 4]
// 0064b8a1  8b01                 mov eax, dword ptr [ecx]
// 0064b8a3  8b5004               mov edx, dword ptr [eax + 4]
// 0064b8a6  53                   push ebx
// 0064b8a7  ffd2                 call edx
// 0064b8a9  8bd8                 mov ebx, eax
// 0064b8ab  8b06                 mov eax, dword ptr [esi]
// 0064b8ad  8b5004               mov edx, dword ptr [eax + 4]
// 0064b8b0  8bce                 mov ecx, esi
// 0064b8b2  ffd2                 call edx
// 0064b8b4  3bd8                 cmp ebx, eax
// 0064b8b6  5b                   pop ebx
// 0064b8b7  7c20                 jl 0x64b8d9
// 0064b8b9  807c241000           cmp byte ptr [esp + 0x10], 0
// 0064b8be  57                   push edi
// 0064b8bf  8bce                 mov ecx, esi
// 0064b8c1  7411                 je 0x64b8d4
// 0064b8c3  c686dc01000001       mov byte ptr [esi + 0x1dc], 1
// 0064b8ca  e801feffff           call 0x64b6d0
// 0064b8cf  5f                   pop edi
// 0064b8d0  5e                   pop esi
// 0064b8d1  c20800               ret 8
// 0064b8d4  e807fdffff           call 0x64b5e0
// 0064b8d9  5f                   pop edi
// 0064b8da  5e                   pop esi
// 0064b8db  c20800               ret 8

struct S;

struct Arg
{
    void* unused;
    S* stage;
};

struct S
{
    virtual void slot0();
    virtual int rank();

    char padding[0x1d8];
    bool pending;

    void func_0064b5e0(Arg*);
    void func_0064b6d0(Arg*);
    void func_0064b890(Arg*, bool);
};

void S::func_0064b890(Arg* arg, bool enable)
{
    if (arg->stage != 0)
    {
        int otherRank = arg->stage->rank();
        if (otherRank >= rank())
        {
            if (enable)
            {
                pending = true;
                func_0064b6d0(arg);
            }
            else
            {
                func_0064b5e0(arg);
            }
        }
    }
}
