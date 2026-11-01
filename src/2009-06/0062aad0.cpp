// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00600420  unit: RBX::VTool::?$BoundPropGetSet  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00600420
//
// 00600420  53                   push ebx
// 00600421  56                   push esi
// 00600422  8bf1                 mov esi, ecx
// 00600424  8b9ec8010000         mov ebx, dword ptr [esi + 0x1c8]
// 0060042a  57                   push edi
// 0060042b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0060042f  3bfb                 cmp edi, ebx
// 00600431  7e77                 jle 0x6004aa
// 00600433  68c4b79700           push 0x97b7c4
// 00600438  89bec8010000         mov dword ptr [esi + 0x1c8], edi
// 0060043e  e8bdd6e0ff           call 0x40db00
// 00600443  56                   push esi
// 00600444  e88794e8ff           call 0x4898d0
// 00600449  83c404               add esp, 4
// 0060044c  85c0                 test eax, eax
// 0060044e  745a                 je 0x6004aa
// 00600450  6a01                 push 1
// 00600452  56                   push esi
// 00600453  e8585ae9ff           call 0x495eb0
// 00600458  83c408               add esp, 8
// 0060045b  84c0                 test al, al
// 0060045d  744b                 je 0x6004aa
// 0060045f  83bec401000005       cmp dword ptr [esi + 0x1c4], 5
// 00600466  7c42                 jl 0x6004aa
// 00600468  8d47ff               lea eax, [edi - 1]
// 0060046b  3bc3                 cmp eax, ebx
// 0060046d  7e1d                 jle 0x60048c
// 0060046f  2501000080           and eax, 0x80000001
// 00600474  7905                 jns 0x60047b
// 00600476  48                   dec eax
// 00600477  83c8fe               or eax, 0xfffffffe
// 0060047a  40                   inc eax
// 0060047b  f7d8                 neg eax
// 0060047d  1bc0                 sbb eax, eax
// 0060047f  f7d8                 neg eax
// 00600481  83c005               add eax, 5
// 00600484  50                   push eax
// 00600485  8bce                 mov ecx, esi
// 00600487  e844f4ffff           call 0x5ff8d0
// 0060048c  81e701000080         and edi, 0x80000001
// 00600492  7905                 jns 0x600499
// 00600494  4f                   dec edi
// 00600495  83cffe               or edi, 0xfffffffe
// 00600498  47                   inc edi
// 00600499  f7df                 neg edi
// 0060049b  1bff                 sbb edi, edi
// 0060049d  f7df                 neg edi
// 0060049f  83c705               add edi, 5
// 006004a2  57                   push edi
// 006004a3  8bce                 mov ecx, esi
// 006004a5  e826f4ffff           call 0x5ff8d0
// 006004aa  5f                   pop edi
// 006004ab  5e                   pop esi
// 006004ac  5b                   pop ebx
// 006004ad  c20400               ret 4

extern char propertyDescriptor;
extern "C" int __cdecl sub_4898d0(int);
extern "C" int __cdecl sub_495eb0(int, int);

struct S
{
    char storage[0x1c4];
    int value;
    int count;

    void notify(const void *descriptor);
    void setValue(int newValue);
    void f(int newCount);
};

void S::f(int newCount)
{
    int oldCount = count;
    if (newCount > oldCount)
    {
        count = newCount;
        notify(&propertyDescriptor);
        if (sub_4898d0((int)this))
        {
            if ((unsigned char)sub_495eb0((int)this, 1))
            {
                if (value >= 5)
                {
                    if (newCount - 1 > oldCount)
                        setValue(5 + ((newCount - 1) % 2 != 0));
                    setValue(5 + (newCount % 2 != 0));
                }
            }
        }
    }
}
