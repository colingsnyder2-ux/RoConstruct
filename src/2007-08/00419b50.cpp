// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 00419b50  unit: VDHTMLWindowService::?$FactoryProduct  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00419b50
// 00419b50  6aff                 push -1
// 00419b52  688e837400           push 0x74838e
// 00419b57  64a100000000         mov eax, dword ptr fs:[0]
// 00419b5d  50                   push eax
// 00419b5e  51                   push ecx
// 00419b5f  56                   push esi
// 00419b60  a188518b00           mov eax, dword ptr [0x8b5188]
// 00419b65  33c4                 xor eax, esp
// 00419b67  50                   push eax
// 00419b68  8d44240c             lea eax, [esp + 0xc]
// 00419b6c  64a300000000         mov dword ptr fs:[0], eax
// 00419b72  8bf1                 mov esi, ecx
// 00419b74  89742408             mov dword ptr [esp + 8], esi
// 00419b78  8b442438             mov eax, dword ptr [esp + 0x38]
// 00419b7c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00419b80  50                   push eax
// 00419b81  51                   push ecx
// 00419b82  e889ebffff           call 0x418710
// 00419b87  50                   push eax
// 00419b88  8bce                 mov ecx, esi
// 00419b8a  e821721500           call 0x570db0
// 00419b8f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00419b93  8b442420             mov eax, dword ptr [esp + 0x20]
// 00419b97  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00419b9f  c70634787800         mov dword ptr [esi], 0x787834
// 00419ba5  895628               mov dword ptr [esi + 0x28], edx
// 00419ba8  89462c               mov dword ptr [esi + 0x2c], eax
// 00419bab  e8203c1500           call 0x56d7d0
// 00419bb0  6a08                 push 8
// 00419bb2  894630               mov dword ptr [esi + 0x30], eax
// 00419bb5  e83c632100           call 0x62fef6
// 00419bba  83c404               add esp, 4
// 00419bbd  85c0                 test eax, eax
// 00419bbf  740f                 je 0x419bd0
// 00419bc1  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00419bc5  c70098717800         mov dword ptr [eax], 0x787198
// 00419bcb  894804               mov dword ptr [eax + 4], ecx
// 00419bce  eb02                 jmp 0x419bd2
// 00419bd0  33c0                 xor eax, eax
// 00419bd2  894634               mov dword ptr [esi + 0x34], eax
// 00419bd5  c644241401           mov byte ptr [esp + 0x14], 1
// 00419bda  e8f13b1500           call 0x56d7d0
// 00419bdf  6a08                 push 8
// 00419be1  894638               mov dword ptr [esi + 0x38], eax
// 00419be4  e80d632100           call 0x62fef6
// 00419be9  83c404               add esp, 4
// 00419bec  85c0                 test eax, eax
// 00419bee  740f                 je 0x419bff
// 00419bf0  8b542434             mov edx, dword ptr [esp + 0x34]
// 00419bf4  c70098717800         mov dword ptr [eax], 0x787198
// 00419bfa  895004               mov dword ptr [eax + 4], edx
// 00419bfd  eb02                 jmp 0x419c01
// 00419bff  33c0                 xor eax, eax
// 00419c01  89463c               mov dword ptr [esi + 0x3c], eax
// 00419c04  8b442430             mov eax, dword ptr [esp + 0x30]
// 00419c08  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00419c0c  50                   push eax
// 00419c0d  51                   push ecx
// 00419c0e  8bce                 mov ecx, esi
// 00419c10  c644241c02           mov byte ptr [esp + 0x1c], 2
// 00419c15  e8c69bffff           call 0x4137e0
// 00419c1a  8bc6                 mov eax, esi
// 00419c1c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00419c20  64890d00000000       mov dword ptr fs:[0], ecx
// 00419c27  59                   pop ecx
// 00419c28  5e                   pop esi
// 00419c29  83c410               add esp, 0x10
// 00419c2c  c22000               ret 0x20

int __stdcall makeBaseArg(int a, int b);
int getDescId();

struct Base {
    char pad[0x24];
    Base(int x);
    virtual ~Base();
    void finish(int a, int b);
};

struct Impl {
    int v;
    Impl(int x) : v(x) {}
    virtual ~Impl();
};

struct Member {
    int id;
    Impl* p;
    Member(int x) : id(getDescId()), p(new Impl(x)) {}
    ~Member();
};

struct FactoryProduct : Base {
    int a28;
    int a2c;
    Member m30;
    Member m38;
    FactoryProduct(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

FactoryProduct::FactoryProduct(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
    : Base(makeBaseArg(a2, a7)), a28(a0), a2c(a1), m30(a4), m38(a6)
{
    finish(a3, a5);
}
