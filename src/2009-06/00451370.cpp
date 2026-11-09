// from server: 100% by EspClaude
// from server: 97% by EspClaude
// roc 2009-06 00451370  unit: RBX::VVisit::?$FactoryProduct::Creator  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00451370
//
// 00451370  64a100000000         mov eax, dword ptr fs:[0]
// 00451376  6aff                 push -1
// 00451378  68e8a68600           push 0x86a6e8
// 0045137d  50                   push eax
// 0045137e  64892500000000       mov dword ptr fs:[0], esp
// 00451385  83ec08               sub esp, 8
// 00451388  56                   push esi
// 00451389  8bf1                 mov esi, ecx
// 0045138b  e8a0feffff           call 0x451230
// 00451390  85c0                 test eax, eax
// 00451392  0f85ac000000         jne 0x451444
// 00451398  53                   push ebx
// 00451399  8d442408             lea eax, [esp + 8]
// 0045139d  57                   push edi
// 0045139e  50                   push eax
// 0045139f  e84c18fbff           call 0x402bf0
// 004513a4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004513a8  68a0ed4400           push 0x44eda0
// 004513ad  68a0b3a300           push 0xa3b3a0
// 004513b2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004513ba  e85103fbff           call 0x401710
// 004513bf  83c40c               add esp, 0xc
// 004513c2  e8e9c1ffff           call 0x44d5b0
// 004513c7  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 004513cd  2b8e98000000         sub ecx, dword ptr [esi + 0x98]
// 004513d3  8bf8                 mov edi, eax
// 004513d5  c1f903               sar ecx, 3
// 004513d8  3bf9                 cmp edi, ecx
// 004513da  7206                 jb 0x4513e2
// 004513dc  ff15ace98900         call dword ptr [0x89e9ac]
// 004513e2  8b9698000000         mov edx, dword ptr [esi + 0x98]
// 004513e8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004513ec  8d04fa               lea eax, [edx + edi*8]
// 004513ef  8d542410             lea edx, [esp + 0x10]
// 004513f3  8908                 mov dword ptr [eax], ecx
// 004513f5  52                   push edx
// 004513f6  8d4804               lea ecx, [eax + 4]
// 004513f9  e80211fbff           call 0x402500
// 004513fe  56                   push esi
// 004513ff  8bcb                 mov ecx, ebx
// 00451401  e84a0a1800           call 0x5d1e50
// 00451406  8b742410             mov esi, dword ptr [esp + 0x10]
// 0045140a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00451412  85f6                 test esi, esi
// 00451414  742a                 je 0x451440
// 00451416  8d4604               lea eax, [esi + 4]
// 00451419  83c9ff               or ecx, 0xffffffff
// 0045141c  f00fc108             lock xadd dword ptr [eax], ecx
// 00451420  751e                 jne 0x451440
// 00451422  8b16                 mov edx, dword ptr [esi]
// 00451424  8b4204               mov eax, dword ptr [edx + 4]
// 00451427  8bce                 mov ecx, esi
// 00451429  ffd0                 call eax
// 0045142b  8d4e08               lea ecx, [esi + 8]
// 0045142e  83caff               or edx, 0xffffffff
// 00451431  f00fc111             lock xadd dword ptr [ecx], edx
// 00451435  7509                 jne 0x451440
// 00451437  8b06                 mov eax, dword ptr [esi]
// 00451439  8b5008               mov edx, dword ptr [eax + 8]
// 0045143c  8bce                 mov ecx, esi
// 0045143e  ffd2                 call edx
// 00451440  5f                   pop edi
// 00451441  8bc3                 mov eax, ebx
// 00451443  5b                   pop ebx
// 00451444  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00451448  5e                   pop esi
// 00451449  64890d00000000       mov dword ptr fs:[0], ecx
// 00451450  83c414               add esp, 0x14
// 00451453  c3                   ret 

// from server: 100% by colin
// roc 2008-06 004530f0  unit: CRobloxDoc  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004530f0
//
// 004530f0  64a100000000         mov eax, dword ptr fs:[0]
// 004530f6  6aff                 push -1
// 004530f8  6868917d00           push 0x7d9168
// 004530fd  50                   push eax
// 004530fe  64892500000000       mov dword ptr fs:[0], esp
// 00453105  83ec08               sub esp, 8
// 00453108  56                   push esi
// 00453109  8bf1                 mov esi, ecx
// 0045310b  e870fbffff           call 0x452c80
// 00453110  85c0                 test eax, eax
// 00453112  0f85ac000000         jne 0x4531c4
// 00453118  53                   push ebx
// 00453119  8d442408             lea eax, [esp + 8]
// 0045311d  57                   push edi
// 0045311e  50                   push eax
// 0045311f  e87c2efbff           call 0x405fa0
// 00453124  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00453128  6870dd9600           push 0x96dd70
// 0045312d  6860084500           push 0x450860
// 00453132  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0045313a  e8f1411000           call 0x557330
// 0045313f  83c40c               add esp, 0xc
// 00453142  e879c2ffff           call 0x44f3c0
// 00453147  8b8ea0010000         mov ecx, dword ptr [esi + 0x1a0]
// 0045314d  2b8e9c010000         sub ecx, dword ptr [esi + 0x19c]
// 00453153  8bf8                 mov edi, eax
// 00453155  c1f903               sar ecx, 3
// 00453158  3bf9                 cmp edi, ecx
// 0045315a  7206                 jb 0x453162
// 0045315c  ff1590288000         call dword ptr [0x802890]
// 00453162  8b969c010000         mov edx, dword ptr [esi + 0x19c]
// 00453168  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045316c  8d04fa               lea eax, [edx + edi*8]
// 0045316f  8d542410             lea edx, [esp + 0x10]
// 00453173  8908                 mov dword ptr [eax], ecx
// 00453175  52                   push edx
// 00453176  8d4804               lea ecx, [eax + 4]
// 00453179  e832f4faff           call 0x4025b0
// 0045317e  56                   push esi
// 0045317f  8bcb                 mov ecx, ebx
// 00453181  e86a771000           call 0x55a8f0
// 00453186  8b742410             mov esi, dword ptr [esp + 0x10]
// 0045318a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00453192  85f6                 test esi, esi
// 00453194  742a                 je 0x4531c0
// 00453196  8d4604               lea eax, [esi + 4]
// 00453199  83c9ff               or ecx, 0xffffffff
// 0045319c  f00fc108             lock xadd dword ptr [eax], ecx
// 004531a0  751e                 jne 0x4531c0
// 004531a2  8b16                 mov edx, dword ptr [esi]
// 004531a4  8b4204               mov eax, dword ptr [edx + 4]
// 004531a7  8bce                 mov ecx, esi
// 004531a9  ffd0                 call eax
// 004531ab  8d4e08               lea ecx, [esi + 8]
// 004531ae  83caff               or edx, 0xffffffff
// 004531b1  f00fc111             lock xadd dword ptr [ecx], edx
// 004531b5  7509                 jne 0x4531c0
// 004531b7  8b06                 mov eax, dword ptr [esi]
// 004531b9  8b5008               mov edx, dword ptr [eax + 8]
// 004531bc  8bce                 mov ecx, esi
// 004531be  ffd2                 call edx
// 004531c0  5f                   pop edi
// 004531c1  8bc3                 mov eax, ebx
// 004531c3  5b                   pop ebx
// 004531c4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004531c8  5e                   pop esi
// 004531c9  64890d00000000       mov dword ptr fs:[0], ecx
// 004531d0  83c414               add esp, 0x14
// 004531d3  c3                   ret 

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
    char padding[0x98];
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
        if (index >= static_cast<unsigned>(last - first))
            _invalid_parameter_noinfo();

        Shared& slot = first[index];
        slot.px = value.px;
        slot.pn = value.pn;
        result->attach(this);
    }
    return result;
}
