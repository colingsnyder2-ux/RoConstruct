// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0063fdd0  unit: RBX::CloneTool  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063fdd0
//
// 0063fdd0  8b442404             mov eax, dword ptr [esp + 4]
// 0063fdd4  56                   push esi
// 0063fdd5  50                   push eax
// 0063fdd6  8bf1                 mov esi, ecx
// 0063fdd8  e8135cfdff           call 0x6159f0
// 0063fddd  33c0                 xor eax, eax
// 0063fddf  c706dca48400         mov dword ptr [esi], 0x84a4dc
// 0063fde5  c74604c0a48400       mov dword ptr [esi + 4], 0x84a4c0
// 0063fdec  89461c               mov dword ptr [esi + 0x1c], eax
// 0063fdef  894620               mov dword ptr [esi + 0x20], eax
// 0063fdf2  8bc6                 mov eax, esi
// 0063fdf4  5e                   pop esi
// 0063fdf5  c20400               ret 4

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

