// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 00409290  unit: VCApp::?$CComObject  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00409290
//
// 00409290  6aff                 push -1
// 00409292  6857987300           push 0x739857
// 00409297  64a100000000         mov eax, dword ptr fs:[0]
// 0040929d  50                   push eax
// 0040929e  83ec08               sub esp, 8
// 004092a1  56                   push esi
// 004092a2  a188518b00           mov eax, dword ptr [0x8b5188]
// 004092a7  33c4                 xor eax, esp
// 004092a9  50                   push eax
// 004092aa  8d442410             lea eax, [esp + 0x10]
// 004092ae  64a300000000         mov dword ptr fs:[0], eax
// 004092b4  8bf1                 mov esi, ecx
// 004092b6  8974240c             mov dword ptr [esp + 0xc], esi
// 004092ba  85f6                 test esi, esi
// 004092bc  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004092c4  7405                 je 0x4092cb
// 004092c6  8d461c               lea eax, [esi + 0x1c]
// 004092c9  eb02                 jmp 0x4092cd
// 004092cb  33c0                 xor eax, eax
// 004092cd  8b4004               mov eax, dword ptr [eax + 4]
// 004092d0  85c0                 test eax, eax
// 004092d2  7408                 je 0x4092dc
// 004092d4  8b08                 mov ecx, dword ptr [eax]
// 004092d6  8b5108               mov edx, dword ptr [ecx + 8]
// 004092d9  50                   push eax
// 004092da  ffd2                 call edx
// 004092dc  85f6                 test esi, esi
// 004092de  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004092e6  7405                 je 0x4092ed
// 004092e8  8d4e08               lea ecx, [esi + 8]
// 004092eb  eb02                 jmp 0x4092ef
// 004092ed  33c9                 xor ecx, ecx
// 004092ef  e82cd80500           call 0x466b20
// 004092f4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004092f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004092ff  59                   pop ecx
// 00409300  5e                   pop esi
// 00409301  83c414               add esp, 0x14
// 00409304  c3                   ret 

struct IUnk {
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct Base0 { int a[2]; };

struct Base8 {
    int b[5];
    ~Base8();   // 0x466b20
};

struct Base1c {
    int c;
    IUnk* p;
    ~Base1c() { IUnk* t = p; if (t) t->Release(); }
};

struct VCApp : Base0, Base8, Base1c {
    ~VCApp();
};

VCApp::~VCApp() {}
