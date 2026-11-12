// from server: 96% by EspClaude
// from server: 44% by colin
// roc 2007-08 0064ee10  unit: CXTPToolBar  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0064ee10
//
// 0064ee10  6aff                 push -1
// 0064ee12  68b8f27500           push 0x75f2b8
// 0064ee17  64a100000000         mov eax, dword ptr fs:[0]
// 0064ee1d  50                   push eax
// 0064ee1e  51                   push ecx
// 0064ee1f  56                   push esi
// 0064ee20  a188518b00           mov eax, dword ptr [0x8b5188]
// 0064ee25  33c4                 xor eax, esp
// 0064ee27  50                   push eax
// 0064ee28  8d44240c             lea eax, [esp + 0xc]
// 0064ee2c  64a300000000         mov dword ptr fs:[0], eax
// 0064ee32  8bf1                 mov esi, ecx
// 0064ee34  89742408             mov dword ptr [esp + 8], esi
// 0064ee38  c70684737c00         mov dword ptr [esi], 0x7c7384
// 0064ee3e  c7465474737c00       mov dword ptr [esi + 0x54], 0x7c7374
// 0064ee45  c7465c14737c00       mov dword ptr [esi + 0x5c], 0x7c7314
// 0064ee4c  8b8e84010000         mov ecx, dword ptr [esi + 0x184]
// 0064ee52  85c9                 test ecx, ecx
// 0064ee54  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0064ee5c  7412                 je 0x64ee70
// 0064ee5e  8b01                 mov eax, dword ptr [ecx]
// 0064ee60  8b10                 mov edx, dword ptr [eax]
// 0064ee62  6a01                 push 1
// 0064ee64  ffd2                 call edx
// 0064ee66  c7868401000000000000 mov dword ptr [esi + 0x184], 0
// 0064ee70  8bce                 mov ecx, esi
// 0064ee72  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0064ee7a  e8b184ffff           call 0x647330
// 0064ee7f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0064ee83  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ee8a  59                   pop ecx
// 0064ee8b  5e                   pop esi
// 0064ee8c  83c410               add esp, 0x10
// 0064ee8f  c3                   ret 
// 0064ee90  83c118               add ecx, 0x18
// 0064ee93  ff25bcdd7700         jmp dword ptr [0x77ddbc]


// Destructor shape: vtables stored at +0, +0x54, +0x5c (three bases), body deletes the
// object at +0x184 through its virtual destructor (push 1; call [vtbl+0]) and nulls it,
// then the primary base destructor (0x647330) runs on this.
class CXTPPrimaryBase {
public:
    virtual ~CXTPPrimaryBase();
    char _b[0x54 - 4];
};
class CXTPSecondBase {
public:
    virtual void f1();
    char _b[0x5c - 0x54 - 4];
};
class CXTPThirdBase {
public:
    virtual void f2();
};
class CXTPOwned {
public:
    virtual ~CXTPOwned();
};

class CXTPToolBar : public CXTPPrimaryBase, public CXTPSecondBase, public CXTPThirdBase {
public:
    virtual ~CXTPToolBar();
    char _p[0x184 - 0x60];
    CXTPOwned* m_pOwned;
};

CXTPToolBar::~CXTPToolBar()
{
    if (m_pOwned) {
        delete m_pOwned;
        m_pOwned = 0;
    }
}
