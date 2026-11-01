// from server: 100% by Yeetserama
// roc 2007-08 005c87c0  unit: lua_exception  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c87c0
//
// 005c87c0  53                   push ebx
// 005c87c1  56                   push esi
// 005c87c2  8b742410             mov esi, dword ptr [esp + 0x10]
// 005c87c6  8b4620               mov eax, dword ptr [esi + 0x20]
// 005c87c9  57                   push edi
// 005c87ca  50                   push eax
// 005c87cb  56                   push esi
// 005c87cc  e8efa80400           call 0x6130c0
// 005c87d1  8b46f4               mov eax, dword ptr [esi - 0xc]
// 005c87d4  8300ff               add dword ptr [eax], -1
// 005c87d7  8b7ef8               mov edi, dword ptr [esi - 8]
// 005c87da  8d5ef4               lea ebx, [esi - 0xc]
// 005c87dd  83c408               add esp, 8
// 005c87e0  85ff                 test edi, edi
// 005c87e2  742a                 je 0x5c880e
// 005c87e4  8d4f04               lea ecx, [edi + 4]
// 005c87e7  83caff               or edx, 0xffffffff
// 005c87ea  f00fc111             lock xadd dword ptr [ecx], edx
// 005c87ee  751e                 jne 0x5c880e
// 005c87f0  8b07                 mov eax, dword ptr [edi]
// 005c87f2  8b5004               mov edx, dword ptr [eax + 4]
// 005c87f5  8bcf                 mov ecx, edi
// 005c87f7  ffd2                 call edx
// 005c87f9  8d4708               lea eax, [edi + 8]
// 005c87fc  83c9ff               or ecx, 0xffffffff
// 005c87ff  f00fc108             lock xadd dword ptr [eax], ecx
// 005c8803  7509                 jne 0x5c880e
// 005c8805  8b17                 mov edx, dword ptr [edi]
// 005c8807  8b4208               mov eax, dword ptr [edx + 8]
// 005c880a  8bcf                 mov ecx, edi
// 005c880c  ffd0                 call eax
// 005c880e  8b4630               mov eax, dword ptr [esi + 0x30]
// 005c8811  8b5628               mov edx, dword ptr [esi + 0x28]
// 005c8814  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005c8818  8d0c40               lea ecx, [eax + eax*2]
// 005c881b  03c9                 add ecx, ecx
// 005c881d  03c9                 add ecx, ecx
// 005c881f  6a00                 push 0
// 005c8821  03c9                 add ecx, ecx
// 005c8823  51                   push ecx
// 005c8824  52                   push edx
// 005c8825  57                   push edi
// 005c8826  e8c5b10400           call 0x6139f0
// 005c882b  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005c882e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005c8831  6a00                 push 0
// 005c8833  c1e004               shl eax, 4
// 005c8836  50                   push eax
// 005c8837  51                   push ecx
// 005c8838  57                   push edi
// 005c8839  e8b2b10400           call 0x6139f0
// 005c883e  6a00                 push 0
// 005c8840  6884000000           push 0x84
// 005c8845  53                   push ebx
// 005c8846  57                   push edi
// 005c8847  e8a4b10400           call 0x6139f0
// 005c884c  83c430               add esp, 0x30
// 005c884f  5f                   pop edi
// 005c8850  5e                   pop esi
// 005c8851  5b                   pop ebx
// 005c8852  c3                   ret 
// copied from an identical function in another client (function ?releaseObject@ns_ROCX000002@@YAXPAXPAUObject@1@@Z)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Header
{
    int* count;
    Control* control;
    unsigned int unused;
};

struct Object
{
    unsigned char padding[32];
    void* first;
    unsigned int unused;
    void* second;
    unsigned int firstCount;
    unsigned int secondCount;
};

extern void __cdecl cleanup(Object*, void*);
extern void __cdecl resizeBlock(void*, void*, unsigned int, unsigned int);

void __cdecl releaseObject(void* state, Object* object)
{
    cleanup(object, object->first);

    Header* header = reinterpret_cast<Header*>(object) - 1;
    --*header->count;

    Control* control = header->control;
    if (control)
    {
        if (_InterlockedDecrement(&control->strong) == 0)
        {
            control->dispose();
            if (_InterlockedDecrement(&control->weak) == 0)
                control->destroy();
        }
    }

    resizeBlock(state, object->second, object->secondCount * 24, 0);
    resizeBlock(state, object->first, object->firstCount * 16, 0);
    resizeBlock(state, header, 0x84, 0);
}
}
