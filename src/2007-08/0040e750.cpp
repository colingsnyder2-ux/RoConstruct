// from server: 100% by EspClaude
// from server: 85% by EspClaude
// roc 2007-08 0040e750  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040e750
//
// 0040e750  6aff                 push -1
// 0040e752  68c8a77400           push 0x74a7c8
// 0040e757  64a100000000         mov eax, dword ptr fs:[0]
// 0040e75d  50                   push eax
// 0040e75e  83ec08               sub esp, 8
// 0040e761  53                   push ebx
// 0040e762  56                   push esi
// 0040e763  57                   push edi
// 0040e764  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040e769  33c4                 xor eax, esp
// 0040e76b  50                   push eax
// 0040e76c  8d442418             lea eax, [esp + 0x18]
// 0040e770  64a300000000         mov dword ptr fs:[0], eax
// 0040e776  8bf1                 mov esi, ecx
// 0040e778  e813feffff           call 0x40e590
// 0040e77d  85c0                 test eax, eax
// 0040e77f  0f85ae000000         jne 0x40e833
// 0040e785  8d442410             lea eax, [esp + 0x10]
// 0040e789  50                   push eax
// 0040e78a  e891f2ffff           call 0x40da20
// 0040e78f  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0040e793  688caf8b00           push 0x8baf8c
// 0040e798  6830d34000           push 0x40d330
// 0040e79d  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0040e7a5  e8766d3100           call 0x725520
// 0040e7aa  83c40c               add esp, 0xc
// 0040e7ad  e8cee6ffff           call 0x40ce80
// 0040e7b2  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 0040e7b8  85c9                 test ecx, ecx
// 0040e7ba  8bf8                 mov edi, eax
// 0040e7bc  740f                 je 0x40e7cd
// 0040e7be  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 0040e7c4  2bc1                 sub eax, ecx
// 0040e7c6  c1f803               sar eax, 3
// 0040e7c9  3bf8                 cmp edi, eax
// 0040e7cb  7206                 jb 0x40e7d3
// 0040e7cd  ff15d8e67700         call dword ptr [0x77e6d8]
// 0040e7d3  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 0040e7d9  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040e7dd  8d04f9               lea eax, [ecx + edi*8]
// 0040e7e0  8d4c2414             lea ecx, [esp + 0x14]
// 0040e7e4  51                   push ecx
// 0040e7e5  8d4804               lea ecx, [eax + 4]
// 0040e7e8  8910                 mov dword ptr [eax], edx
// 0040e7ea  e87142ffff           call 0x402a60
// 0040e7ef  56                   push esi
// 0040e7f0  8bcb                 mov ecx, ebx
// 0040e7f2  e8392e1300           call 0x541630
// 0040e7f7  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040e7fb  85f6                 test esi, esi
// 0040e7fd  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0040e805  742a                 je 0x40e831
// 0040e807  8d5604               lea edx, [esi + 4]
// 0040e80a  83c8ff               or eax, 0xffffffff
// 0040e80d  f00fc102             lock xadd dword ptr [edx], eax
// 0040e811  751e                 jne 0x40e831
// 0040e813  8b16                 mov edx, dword ptr [esi]
// 0040e815  8b4204               mov eax, dword ptr [edx + 4]
// 0040e818  8bce                 mov ecx, esi
// 0040e81a  ffd0                 call eax
// 0040e81c  8d4e08               lea ecx, [esi + 8]
// 0040e81f  83caff               or edx, 0xffffffff
// 0040e822  f00fc111             lock xadd dword ptr [ecx], edx
// 0040e826  7509                 jne 0x40e831
// 0040e828  8b06                 mov eax, dword ptr [esi]
// 0040e82a  8b5008               mov edx, dword ptr [eax + 8]
// 0040e82d  8bce                 mov ecx, esi
// 0040e82f  ffd2                 call edx
// 0040e831  8bc3                 mov eax, ebx
// 0040e833  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0040e837  64890d00000000       mov dword ptr fs:[0], ecx
// 0040e83e  59                   pop ecx
// 0040e83f  5f                   pop edi
// 0040e840  5e                   pop esi
// 0040e841  5b                   pop ebx
// 0040e842  83c414               add esp, 0x14
// 0040e845  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 00412710  unit: CChatPrompt  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00412710
//
// 00412710  64a100000000         mov eax, dword ptr fs:[0]
// 00412716  6aff                 push -1
// 00412718  6868917d00           push 0x7d9168
// 0041271d  50                   push eax
// 0041271e  64892500000000       mov dword ptr fs:[0], esp
// 00412725  83ec08               sub esp, 8
// 00412728  56                   push esi
// 00412729  8bf1                 mov esi, ecx
// 0041272b  e8a0feffff           call 0x4125d0
// 00412730  85c0                 test eax, eax
// 00412732  0f85ac000000         jne 0x4127e4
// 00412738  53                   push ebx
// 00412739  8d442408             lea eax, [esp + 8]
// 0041273d  57                   push edi
// 0041273e  50                   push eax
// 0041273f  e88cf8ffff           call 0x411fd0
// 00412744  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00412748  68e8cb9600           push 0x96cbe8
// 0041274d  6830194100           push 0x411930
// 00412752  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0041275a  e8d14b1400           call 0x557330
// 0041275f  83c40c               add esp, 0xc
// 00412762  e829edffff           call 0x411490
// 00412767  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0041276d  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 00412773  8bf8                 mov edi, eax
// 00412775  c1f903               sar ecx, 3
// 00412778  3bf9                 cmp edi, ecx
// 0041277a  7206                 jb 0x412782
// 0041277c  ff1590288000         call dword ptr [0x802890]
// 00412782  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 00412788  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041278c  8d04fa               lea eax, [edx + edi*8]
// 0041278f  8d542410             lea edx, [esp + 0x10]
// 00412793  8908                 mov dword ptr [eax], ecx
// 00412795  52                   push edx
// 00412796  8d4804               lea ecx, [eax + 4]
// 00412799  e812fefeff           call 0x4025b0
// 0041279e  56                   push esi
// 0041279f  8bcb                 mov ecx, ebx
// 004127a1  e84a811400           call 0x55a8f0
// 004127a6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004127aa  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004127b2  85f6                 test esi, esi
// 004127b4  742a                 je 0x4127e0
// 004127b6  8d4604               lea eax, [esi + 4]
// 004127b9  83c9ff               or ecx, 0xffffffff
// 004127bc  f00fc108             lock xadd dword ptr [eax], ecx
// 004127c0  751e                 jne 0x4127e0
// 004127c2  8b16                 mov edx, dword ptr [esi]
// 004127c4  8b4204               mov eax, dword ptr [edx + 4]
// 004127c7  8bce                 mov ecx, esi
// 004127c9  ffd0                 call eax
// 004127cb  8d4e08               lea ecx, [esi + 8]
// 004127ce  83caff               or edx, 0xffffffff
// 004127d1  f00fc111             lock xadd dword ptr [ecx], edx
// 004127d5  7509                 jne 0x4127e0
// 004127d7  8b06                 mov eax, dword ptr [esi]
// 004127d9  8b5008               mov edx, dword ptr [eax + 8]
// 004127dc  8bce                 mov ecx, esi
// 004127de  ffd2                 call edx
// 004127e0  5f                   pop edi
// 004127e1  8bc3                 mov eax, ebx
// 004127e3  5b                   pop ebx
// 004127e4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004127e8  5e                   pop esi
// 004127e9  64890d00000000       mov dword ptr fs:[0], ecx
// 004127f0  83c414               add esp, 0x14
// 004127f3  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct CChatPrompt;

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    void release();
};

struct Handle
{
    Control* p;
    Handle& operator=(const Handle&);
};

struct Object
{
    void attach(CChatPrompt*);
};

struct Shared
{
    Object* px;
    Handle pn;
    ~Shared();
};

extern Shared __cdecl create_shared();
extern unsigned __cdecl current_index();
extern void __cdecl register_callback(void (__cdecl*)(), void*);
extern void __cdecl callback();
extern char callback_data;
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct CChatPrompt
{
    char padding[0x134];
    Shared* first;
    Shared* last;

    Object* existing();
    Object* func_00412710();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline Shared::~Shared()
{
    if (pn.p)
        pn.p->release();
}

Object* CChatPrompt::func_00412710()
{
    Object* result = existing();
    if (!result)
    {
        Shared value = create_shared();
        result = value.px;
        register_callback(callback, &callback_data);

        unsigned index = current_index();
        unsigned size = first ? static_cast<unsigned>(last - first) : 0;
        if (index >= size)
            _invalid_parameter_noinfo();

        Shared& slot = first[index];
        slot.px = value.px;
        slot.pn = value.pn;
        result->attach(this);
    }
    return result;
}
