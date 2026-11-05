// from server: 100% by EspClaude
// from server: 80% by colin
// roc 2008-06 005db600  unit: RBX::Humanoid  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005db600
//
// 005db600  53                   push ebx
// 005db601  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005db605  56                   push esi
// 005db606  8bf1                 mov esi, ecx
// 005db608  85db                 test ebx, ebx
// 005db60a  7444                 je 0x5db650
// 005db60c  8b8e20020000         mov ecx, dword ptr [esi + 0x220]
// 005db612  85c9                 test ecx, ecx
// 005db614  7409                 je 0x5db61f
// 005db616  8b01                 mov eax, dword ptr [ecx]
// 005db618  8b5018               mov edx, dword ptr [eax + 0x18]
// 005db61b  6a01                 push 1
// 005db61d  ffd2                 call edx
// 005db61f  57                   push edi
// 005db620  c7862002000000000000 mov dword ptr [esi + 0x220], 0
// 005db62a  85f6                 test esi, esi
// 005db62c  7408                 je 0x5db636
// 005db62e  8dbea4010000         lea edi, [esi + 0x1a4]
// 005db634  eb02                 jmp 0x5db638
// 005db636  33ff                 xor edi, edi
// 005db638  8bcb                 mov ecx, ebx
// 005db63a  e8b17ae7ff           call 0x4530f0
// 005db63f  85c0                 test eax, eax
// 005db641  740c                 je 0x5db64f
// 005db643  57                   push edi
// 005db644  8d8850010000         lea ecx, [eax + 0x150]
// 005db64a  e831a40000           call 0x5e5a80
// 005db64f  5f                   pop edi
// 005db650  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005db654  85c9                 test ecx, ecx
// 005db656  7423                 je 0x5db67b
// 005db658  85f6                 test esi, esi
// 005db65a  7408                 je 0x5db664
// 005db65c  81c6a4010000         add esi, 0x1a4
// 005db662  eb02                 jmp 0x5db666
// 005db664  33f6                 xor esi, esi
// 005db666  e8857ae7ff           call 0x4530f0
// 005db66b  85c0                 test eax, eax
// 005db66d  740c                 je 0x5db67b
// 005db66f  56                   push esi
// 005db670  8d8850010000         lea ecx, [eax + 0x150]
// 005db676  e82562e4ff           call 0x4218a0
// 005db67b  5e                   pop esi
// 005db67c  5b                   pop ebx
// 005db67d  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct VInstance
{
    void* getSomething();
};

struct Listener
{
    void remove(void*);
};

struct JointsService
{
    void remove(void*);
};

struct Holder
{
    void* p;
    void reset()
    {
        if (p)
        {
            void** vt = *(void***)p;
            typedef void (__thiscall *Fn)(void*, int);
            ((Fn)vt[6])(p, 1);
        }
        p = 0;
    }
};

struct PadBase { char pad[0x1a4]; };
struct ConnBase { void* field_0x1a4; };
struct Humanoid : PadBase, ConnBase
{
    char pad2[0x220 - 0x1a8];
    Holder field_0x220;
    void setSomething(void* a, void* b);
};

void Humanoid::setSomething(void* a, void* b)
{
    if (a)
    {
        field_0x220.reset();
        void* self = static_cast<ConnBase*>(this);
        VInstance* v = (VInstance*)a;
        void* r = v->getSomething();
        if (r)
        {
            ((JointsService*)((char*)r + 0x150))->remove(self);
        }
    }
    if (b)
    {
        void* self = static_cast<ConnBase*>(this);
        VInstance* v = (VInstance*)b;
        void* r = v->getSomething();
        if (r)
        {
            ((Listener*)((char*)r + 0x150))->remove(self);
        }
    }
}
