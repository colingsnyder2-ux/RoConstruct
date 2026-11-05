// from server: 85% by EspClaude
// roc-cl: 50727
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
    char padding[0x19c];
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
