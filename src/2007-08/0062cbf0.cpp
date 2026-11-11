// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 78% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0066dc80  unit: RBX::GroupDragTool  size: 261 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066dc80
//
// 0066dc80  64a100000000         mov eax, dword ptr fs:[0]
// 0066dc86  6aff                 push -1
// 0066dc88  6868917d00           push 0x7d9168
// 0066dc8d  50                   push eax
// 0066dc8e  64892500000000       mov dword ptr fs:[0], esp
// 0066dc95  83ec08               sub esp, 8
// 0066dc98  56                   push esi
// 0066dc99  8bf1                 mov esi, ecx
// 0066dc9b  8b4624               mov eax, dword ptr [esi + 0x24]
// 0066dc9e  85c0                 test eax, eax
// 0066dca0  0f849d000000         je 0x66dd43
// 0066dca6  57                   push edi
// 0066dca7  50                   push eax
// 0066dca8  e8d3c2f2ff           call 0x599f80
// 0066dcad  50                   push eax
// 0066dcae  8d442410             lea eax, [esp + 0x10]
// 0066dcb2  50                   push eax
// 0066dcb3  e888adfaff           call 0x618a40
// 0066dcb8  83c40c               add esp, 0xc
// 0066dcbb  8b08                 mov ecx, dword ptr [eax]
// 0066dcbd  894e08               mov dword ptr [esi + 8], ecx
// 0066dcc0  8b7804               mov edi, dword ptr [eax + 4]
// 0066dcc3  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0066dccb  85ff                 test edi, edi
// 0066dccd  740c                 je 0x66dcdb
// 0066dccf  8d5708               lea edx, [edi + 8]
// 0066dcd2  b801000000           mov eax, 1
// 0066dcd7  f00fc102             lock xadd dword ptr [edx], eax
// 0066dcdb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0066dcde  85c9                 test ecx, ecx
// 0066dce0  7413                 je 0x66dcf5
// 0066dce2  8d5108               lea edx, [ecx + 8]
// 0066dce5  83c8ff               or eax, 0xffffffff
// 0066dce8  f00fc102             lock xadd dword ptr [edx], eax
// 0066dcec  7507                 jne 0x66dcf5
// 0066dcee  8b11                 mov edx, dword ptr [ecx]
// 0066dcf0  8b4208               mov eax, dword ptr [edx + 8]
// 0066dcf3  ffd0                 call eax
// 0066dcf5  897e0c               mov dword ptr [esi + 0xc], edi
// 0066dcf8  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0066dcfc  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0066dd04  5f                   pop edi
// 0066dd05  85f6                 test esi, esi
// 0066dd07  746c                 je 0x66dd75
// 0066dd09  8d4e04               lea ecx, [esi + 4]
// 0066dd0c  83caff               or edx, 0xffffffff
// 0066dd0f  f00fc111             lock xadd dword ptr [ecx], edx
// 0066dd13  7560                 jne 0x66dd75
// 0066dd15  8b06                 mov eax, dword ptr [esi]
// 0066dd17  8b5004               mov edx, dword ptr [eax + 4]
// 0066dd1a  8bce                 mov ecx, esi
// 0066dd1c  ffd2                 call edx
// 0066dd1e  8d4608               lea eax, [esi + 8]
// 0066dd21  83c9ff               or ecx, 0xffffffff
// 0066dd24  f00fc108             lock xadd dword ptr [eax], ecx
// 0066dd28  754b                 jne 0x66dd75
// 0066dd2a  8b16                 mov edx, dword ptr [esi]
// 0066dd2c  8b4208               mov eax, dword ptr [edx + 8]
// 0066dd2f  8bce                 mov ecx, esi
// 0066dd31  ffd0                 call eax
// 0066dd33  5e                   pop esi
// 0066dd34  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0066dd38  64890d00000000       mov dword ptr fs:[0], ecx
// 0066dd3f  83c414               add esp, 0x14
// 0066dd42  c3                   ret 
// 0066dd43  8d4608               lea eax, [esi + 8]
// 0066dd46  8d4c2404             lea ecx, [esp + 4]
// 0066dd4a  3bc8                 cmp ecx, eax
// 0066dd4c  7406                 je 0x66dd54
// 0066dd4e  c70000000000         mov dword ptr [eax], 0
// 0066dd54  8b4804               mov ecx, dword ptr [eax + 4]
// 0066dd57  c7400400000000       mov dword ptr [eax + 4], 0
// 0066dd5e  85c9                 test ecx, ecx
// 0066dd60  7413                 je 0x66dd75
// 0066dd62  8d5108               lea edx, [ecx + 8]
// 0066dd65  83c8ff               or eax, 0xffffffff
// 0066dd68  f00fc102             lock xadd dword ptr [edx], eax
// 0066dd6c  7507                 jne 0x66dd75
// 0066dd6e  8b11                 mov edx, dword ptr [ecx]
// 0066dd70  8b4208               mov eax, dword ptr [edx + 8]
// 0066dd73  ffd0                 call eax
// 0066dd75  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066dd79  5e                   pop esi
// 0066dd7a  64890d00000000       mov dword ptr fs:[0], ecx
// 0066dd81  83c414               add esp, 0x14
// 0066dd84  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

struct PartInstance;

struct GetSetImpl
{
    static PartInstance* get(PartInstance*);
};

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;

    void releaseWeak()
    {
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }

    void releaseStrong()
    {
        if (_InterlockedDecrement(&strong) == 0)
        {
            dispose();
            releaseWeak();
        }
    }
};

struct Shared
{
    PartInstance* pointer;
    Control* control;

    ~Shared()
    {
        if (control)
            control->releaseStrong();
    }
};

Shared __cdecl acquire(PartInstance*);

struct Weak
{
    PartInstance* pointer;
    Control* control;

    Weak() : pointer(0), control(0) {}

    ~Weak()
    {
        if (control)
            control->releaseWeak();
    }

    void assign(const Shared& value)
    {
        pointer = value.pointer;
        Control* replacement = value.control;
        if (replacement)
            _InterlockedIncrement(&replacement->weak);
        if (control)
            control->releaseWeak();
        control = replacement;
    }

    void swap(Weak& other)
    {
        {
            PartInstance* saved = pointer;
            pointer = other.pointer;
            other.pointer = saved;
        }
        Control* saved = control;
        control = other.control;
        other.control = saved;
    }
};

struct GroupDragTool
{
    char padding0[8];
    Weak selected;
    char padding1[20];
    PartInstance* part;

    void update();
};

void GroupDragTool::update()
{
    if (part)
        selected.assign(acquire(GetSetImpl::get(part)));
    else
    {
        *(PartInstance* volatile*)&selected.pointer = 0;
        Control* c = *(Control* volatile*)&selected.control;
        selected.control = 0;
        if (c)
            c->releaseWeak();
    }
}
