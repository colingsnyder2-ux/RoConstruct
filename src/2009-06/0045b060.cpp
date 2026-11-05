// from server: 100% by EspClaude
// from server: 86% by EspClaude
// roc 2009-06 0045b060  unit: CRobloxWnd  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045b060
//
// 0045b060  56                   push esi
// 0045b061  8bf1                 mov esi, ecx
// 0045b063  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0045b069  85c9                 test ecx, ecx
// 0045b06b  7407                 je 0x45b074
// 0045b06d  6a00                 push 0
// 0045b06f  e88cf80000           call 0x46a900
// 0045b074  8bce                 mov ecx, esi
// 0045b076  e88ddf2b00           call 0x719008
// 0045b07b  5e                   pop esi
// 0045b07c  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 0045bf30  unit: CRobloxWnd  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045bf30
//
// 0045bf30  56                   push esi
// 0045bf31  8bf1                 mov esi, ecx
// 0045bf33  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0045bf39  85c9                 test ecx, ecx
// 0045bf3b  7407                 je 0x45bf44
// 0045bf3d  6a00                 push 0
// 0045bf3f  e80cc10000           call 0x468050
// 0045bf44  8bce                 mov ecx, esi
// 0045bf46  e865ffffff           call 0x45beb0
// 0045bf4b  8bce                 mov ecx, esi
// 0045bf4d  e8164d2400           call 0x6a0c68
// 0045bf52  5e                   pop esi
// 0045bf53  c20400               ret 4

struct Object {
    void set(int);
};

struct CRobloxWnd {
    char padding[0xd8];
    Object* object;

    void start();
    void finish();
    void f(int);
};

void CRobloxWnd::f(int)
{
    if (object)
        object->set(0);
    finish();
}
