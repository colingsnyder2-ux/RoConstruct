// from server: 100% by Yeetserama
// roc 2007-08 0042ad80  unit: VCLuaFunction::?$CComObject  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042ad80
//
// 0042ad80  6aff                 push -1
// 0042ad82  688b9e7400           push 0x749e8b
// 0042ad87  64a100000000         mov eax, dword ptr fs:[0]
// 0042ad8d  50                   push eax
// 0042ad8e  51                   push ecx
// 0042ad8f  53                   push ebx
// 0042ad90  55                   push ebp
// 0042ad91  56                   push esi
// 0042ad92  57                   push edi
// 0042ad93  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042ad98  33c4                 xor eax, esp
// 0042ad9a  50                   push eax
// 0042ad9b  8d442418             lea eax, [esp + 0x18]
// 0042ad9f  64a300000000         mov dword ptr fs:[0], eax
// 0042ada5  8be9                 mov ebp, ecx
// 0042ada7  896c2414             mov dword ptr [esp + 0x14], ebp
// 0042adab  8b742428             mov esi, dword ptr [esp + 0x28]
// 0042adaf  8d5d04               lea ebx, [ebp + 4]
// 0042adb2  56                   push esi
// 0042adb3  8bcb                 mov ecx, ebx
// 0042adb5  897500               mov dword ptr [ebp], esi
// 0042adb8  e8c3f8ffff           call 0x42a680
// 0042adbd  85f6                 test esi, esi
// 0042adbf  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0042adc7  7438                 je 0x42ae01
// 0042adc9  8d7e04               lea edi, [esi + 4]
// 0042adcc  85ff                 test edi, edi
// 0042adce  7431                 je 0x42ae01
// 0042add0  8937                 mov dword ptr [edi], esi
// 0042add2  8b33                 mov esi, dword ptr [ebx]
// 0042add4  85f6                 test esi, esi
// 0042add6  740c                 je 0x42ade4
// 0042add8  8d4608               lea eax, [esi + 8]
// 0042addb  b901000000           mov ecx, 1
// 0042ade0  f00fc108             lock xadd dword ptr [eax], ecx
// 0042ade4  8b4f04               mov ecx, dword ptr [edi + 4]
// 0042ade7  85c9                 test ecx, ecx
// 0042ade9  7413                 je 0x42adfe
// 0042adeb  8d5108               lea edx, [ecx + 8]
// 0042adee  83c8ff               or eax, 0xffffffff
// 0042adf1  f00fc102             lock xadd dword ptr [edx], eax
// 0042adf5  7507                 jne 0x42adfe
// 0042adf7  8b11                 mov edx, dword ptr [ecx]
// 0042adf9  8b4208               mov eax, dword ptr [edx + 8]
// 0042adfc  ffd0                 call eax
// 0042adfe  897704               mov dword ptr [edi + 4], esi
// 0042ae01  8bc5                 mov eax, ebp
// 0042ae03  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042ae07  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ae0e  59                   pop ecx
// 0042ae0f  5f                   pop edi
// 0042ae10  5e                   pop esi
// 0042ae11  5d                   pop ebp
// 0042ae12  5b                   pop ebx
// 0042ae13  83c410               add esp, 0x10
// 0042ae16  c20400               ret 4
// copied from an identical function in another client (function ??0S@ns_ROCX00000b@@QAE@PAUObject@1@@Z)

namespace ns_ROCX00000b {
// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct Object;

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    long strong;
    long weak;
    Object* object;
};

struct Weak {
    Object* object;
    Control* control;
};

struct Object {
    virtual ~Object();
    Weak weak;
};

struct Count {
    Control* control;
    Count(Object*);
    ~Count();
};

struct S {
    Object* object;
    Count count;
    S(Object*);
};

S::S(Object* p) : object(p), count(p)
{
    if (p) {
        Weak* w = &p->weak;
        if (w) {
            w->object = p;
            Control* c = count.control;
            if (c)
                _InterlockedIncrement(&c->weak);

            Control* old = w->control;
            if (old && _InterlockedDecrement(&old->weak) == 0)
                old->destroy();

            w->control = c;
        }
    }
}
}
