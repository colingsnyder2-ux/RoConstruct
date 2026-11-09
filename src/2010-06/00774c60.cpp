// from server: 100% by Yeetserama
// roc 2010-06 00774c60  unit: RBX::ScoreHud  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00774c60
//
// 00774c60  56                   push esi
// 00774c61  8bf1                 mov esi, ecx
// 00774c63  e8d8aaffff           call 0x76f740
// 00774c68  83f803               cmp eax, 3
// 00774c6b  7737                 ja 0x774ca4
// 00774c6d  ff2485a84c7700       jmp dword ptr [eax*4 + 0x774ca8]
// 00774c74  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00774c78  6a02                 push 2
// 00774c7a  51                   push ecx
// 00774c7b  8bce                 mov ecx, esi
// 00774c7d  e85ef4ffff           call 0x7740e0
// 00774c82  5e                   pop esi
// 00774c83  c20400               ret 4
// 00774c86  8b542408             mov edx, dword ptr [esp + 8]
// 00774c8a  6a03                 push 3
// 00774c8c  52                   push edx
// 00774c8d  8bce                 mov ecx, esi
// 00774c8f  e84cf4ffff           call 0x7740e0
// 00774c94  5e                   pop esi
// 00774c95  c20400               ret 4
// 00774c98  8b442408             mov eax, dword ptr [esp + 8]
// 00774c9c  50                   push eax
// 00774c9d  8bce                 mov ecx, esi
// 00774c9f  e82cebffff           call 0x7737d0
// 00774ca4  5e                   pop esi
// 00774ca5  c20400               ret 4
// 00774ca8  98                   cwde 
// 00774ca9  4c                   dec esp
// 00774caa  7700                 ja 0x774cac
// 00774cac  98                   cwde 
// 00774cad  4c                   dec esp
// 00774cae  7700                 ja 0x774cb0
// 00774cb0  744c                 je 0x774cfe
// 00774cb2  7700                 ja 0x774cb4
// 00774cb4  864c7700             xchg byte ptr [edi + esi*2], cl
// copied from an identical function in another client (function ?dispatch@ScoreHud@ns_ROCX000010@@QAEXH@Z)

namespace ns_ROCX000010 {
// from server: 78% by colin
// roc 2008-06 00656430  unit: RBX::ScoreHud  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00656430
//

struct ScoreHud {
    int getState();
    void setA(int, int);
    void setB(int);
    void dispatch(int);
};

void ScoreHud::dispatch(int arg)
{
    switch (getState())
    {
    case 1:
        setB(arg);
        break;
    case 2:
        setA(arg, 2);
        break;
    case 3:
        setA(arg, 3);
        break;
    case 0:
        setB(arg);
        break;
    }
}
}
