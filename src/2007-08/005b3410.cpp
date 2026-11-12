// from server: 100% by EspClaude
// from server: 58% by colin
// roc 2007-08 005b3410  unit: RBX::Assembly  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b3410
//
// 005b3410  53                   push ebx
// 005b3411  55                   push ebp
// 005b3412  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 005b3418  56                   push esi
// 005b3419  8b7134               mov esi, dword ptr [ecx + 0x34]
// 005b341c  3b7138               cmp esi, dword ptr [ecx + 0x38]
// 005b341f  57                   push edi
// 005b3420  8d7930               lea edi, [ecx + 0x30]
// 005b3423  7602                 jbe 0x5b3427
// 005b3425  ffd5                 call ebp
// 005b3427  8b5f08               mov ebx, dword ptr [edi + 8]
// 005b342a  395f04               cmp dword ptr [edi + 4], ebx
// 005b342d  7602                 jbe 0x5b3431
// 005b342f  ffd5                 call ebp
// 005b3431  85ff                 test edi, edi
// 005b3433  7404                 je 0x5b3439
// 005b3435  3bff                 cmp edi, edi
// 005b3437  7402                 je 0x5b343b
// 005b3439  ffd5                 call ebp
// 005b343b  3bf3                 cmp esi, ebx
// 005b343d  7427                 je 0x5b3466
// 005b343f  85ff                 test edi, edi
// 005b3441  7502                 jne 0x5b3445
// 005b3443  ffd5                 call ebp
// 005b3445  3b7708               cmp esi, dword ptr [edi + 8]
// 005b3448  7202                 jb 0x5b344c
// 005b344a  ffd5                 call ebp
// 005b344c  8b0e                 mov ecx, dword ptr [esi]
// 005b344e  8b01                 mov eax, dword ptr [ecx]
// 005b3450  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b3454  8b4034               mov eax, dword ptr [eax + 0x34]
// 005b3457  52                   push edx
// 005b3458  ffd0                 call eax
// 005b345a  3b7708               cmp esi, dword ptr [edi + 8]
// 005b345d  7202                 jb 0x5b3461
// 005b345f  ffd5                 call ebp
// 005b3461  83c604               add esi, 4
// 005b3464  ebc1                 jmp 0x5b3427
// 005b3466  5f                   pop edi
// 005b3467  5e                   pop esi
// 005b3468  5d                   pop ebp
// 005b3469  5b                   pop ebx

#include <vector>

struct Child {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34(int arg);
};

struct Assembly {
    int pad[12];
    std::vector<Child*> children;
    void forEachChild(int arg);
};

void Assembly::forEachChild(int arg)
{
    for (std::vector<Child*>::const_iterator it = children.begin(); it != children.end(); ++it)
        (*it)->v34(arg);
}
