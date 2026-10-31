// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 005b6390  unit: RBX::PartTool  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b6390
//
// 005b6390  8b442404             mov eax, dword ptr [esp + 4]
// 005b6394  56                   push esi
// 005b6395  50                   push eax
// 005b6396  8bf1                 mov esi, ecx
// 005b6398  e853f60500           call 0x6159f0
// 005b639d  33c0                 xor eax, eax
// 005b639f  c7064c588300         mov dword ptr [esi], 0x83584c
// 005b63a5  c7460434588300       mov dword ptr [esi + 4], 0x835834
// 005b63ac  89461c               mov dword ptr [esi + 0x1c], eax
// 005b63af  894620               mov dword ptr [esi + 0x20], eax
// 005b63b2  8bc6                 mov eax, esi
// 005b63b4  5e                   pop esi
// 005b63b5  c20400               ret 4

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

