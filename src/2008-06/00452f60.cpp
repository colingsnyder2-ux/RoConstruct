// from server: 100% by coldek
// from server: 100% by colin
// roc 2008-06 00452f60  unit: CRobloxDoc  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00452f60
//
// 00452f60  55                   push ebp
// 00452f61  8bec                 mov ebp, esp
// 00452f63  6aff                 push -1
// 00452f65  68901e7c00           push 0x7c1e90
// 00452f6a  64a100000000         mov eax, dword ptr fs:[0]
// 00452f70  50                   push eax
// 00452f71  64892500000000       mov dword ptr fs:[0], esp
// 00452f78  83ec08               sub esp, 8
// 00452f7b  53                   push ebx
// 00452f7c  56                   push esi
// 00452f7d  57                   push edi
// 00452f7e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00452f81  8bf1                 mov esi, ecx
// 00452f83  e83ada2400           call 0x6a09c2
// 00452f88  85c0                 test eax, eax
// 00452f8a  7456                 je 0x452fe2
// 00452f8c  8bce                 mov ecx, esi
// 00452f8e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00452f95  e8c6ebffff           call 0x451b60
// 00452f9a  8b06                 mov eax, dword ptr [esi]
// 00452f9c  8b5064               mov edx, dword ptr [eax + 0x64]
// 00452f9f  6a00                 push 0
// 00452fa1  8bce                 mov ecx, esi
// 00452fa3  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 00452faa  ffd2                 call edx
// 00452fac  b801000000           mov eax, 1
// 00452fb1  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00452fb4  64890d00000000       mov dword ptr fs:[0], ecx
// 00452fbb  5f                   pop edi
// 00452fbc  5e                   pop esi
// 00452fbd  5b                   pop ebx
// 00452fbe  8be5                 mov esp, ebp
// 00452fc0  5d                   pop ebp
// 00452fc1  c3                   ret 

struct S
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void finish(int);

    int check();
    void perform();
    int func_00452f60();
};

void handleCreateError(S*);
void __stdcall trace3(const char*, int, int);

int S::func_00452f60()
{
    if (!check())
        return 0;

    try
    {
        perform();
    }
    catch (S* exception)
    {
        handleCreateError(exception);
        trace3("An error occured while creating the document", 0x30, 0);
        return 0;
    }

    finish(0);
    return 1;
}