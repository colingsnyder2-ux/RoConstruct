// from server: 100% by EspClaude
// from server: 100% by nuck16
// roc 2008-06 00656430  unit: RBX::ScoreHud  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00656430
//
// 00656430  56                   push esi
// 00656431  8bf1                 mov esi, ecx
// 00656433  e8a8aeffff           call 0x6512e0
// 00656438  83f803               cmp eax, 3
// 0065643b  7737                 ja 0x656474
// 0065643d  ff248578646500       jmp dword ptr [eax*4 + 0x656478]
// 00656444  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00656448  6a02                 push 2
// 0065644a  51                   push ecx
// 0065644b  8bce                 mov ecx, esi
// 0065644d  e8cef5ffff           call 0x655a20
// 00656452  5e                   pop esi
// 00656453  c20400               ret 4
// 00656456  8b542408             mov edx, dword ptr [esp + 8]
// 0065645a  6a03                 push 3
// 0065645c  52                   push edx
// 0065645d  8bce                 mov ecx, esi
// 0065645f  e8bcf5ffff           call 0x655a20
// 00656464  5e                   pop esi
// 00656465  c20400               ret 4
// 00656468  8b442408             mov eax, dword ptr [esp + 8]
// 0065646c  50                   push eax
// 0065646d  8bce                 mov ecx, esi
// 0065646f  e86cedffff           call 0x6551e0
// 00656474  5e                   pop esi
// 00656475  c20400               ret 4
// 00656478  6864650068           push 0x68006564
// 0065647d  646500446465         add byte ptr gs:[esp + 0x65], al
// 00656483  005664               add byte ptr [esi + 0x64], dl

// from server: 80% by coldek
// roc 2008-06 00656430  unit: RBX::ScoreHud  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00656430
//

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
