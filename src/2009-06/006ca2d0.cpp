// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0063de80  unit: RBX::LockTool  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063de80
//
// 0063de80  8b442404             mov eax, dword ptr [esp + 4]
// 0063de84  56                   push esi
// 0063de85  50                   push eax
// 0063de86  8bf1                 mov esi, ecx
// 0063de88  e8637bfdff           call 0x6159f0
// 0063de8d  33c0                 xor eax, eax
// 0063de8f  c706e4a28400         mov dword ptr [esi], 0x84a2e4
// 0063de95  c74604c8a28400       mov dword ptr [esi + 4], 0x84a2c8
// 0063de9c  89461c               mov dword ptr [esi + 0x1c], eax
// 0063de9f  894620               mov dword ptr [esi + 0x20], eax
// 0063dea2  8bc6                 mov eax, esi
// 0063dea4  5e                   pop esi
// 0063dea5  c20400               ret 4

extern "C" void* memset(void*, int, unsigned);
struct B0 { virtual void a(); };
struct B1 { virtual void b(); };
struct Mid : B0, B1 {
    char pad[0x14];
    Mid(int);
};
struct CloneTool : Mid {
    int p; int q;
    CloneTool(int a1);
    virtual void a();
    virtual void b();
};
 CloneTool::CloneTool(int a1) : Mid(a1) { memset(&p, 0, 8); }

