// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00623d90  unit: lua_exception  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00623d90
//
// 00623d90  53                   push ebx
// 00623d91  56                   push esi
// 00623d92  8b742410             mov esi, dword ptr [esp + 0x10]
// 00623d96  8b4620               mov eax, dword ptr [esi + 0x20]
// 00623d99  57                   push edi
// 00623d9a  50                   push eax
// 00623d9b  56                   push esi
// 00623d9c  e85fb80300           call 0x65f600
// 00623da1  8b46f4               mov eax, dword ptr [esi - 0xc]
// 00623da4  ff08                 dec dword ptr [eax]
// 00623da6  8b7ef8               mov edi, dword ptr [esi - 8]
// 00623da9  8d5ef4               lea ebx, [esi - 0xc]
// 00623dac  83c408               add esp, 8
// 00623daf  85ff                 test edi, edi
// 00623db1  742a                 je 0x623ddd
// 00623db3  8d4f04               lea ecx, [edi + 4]
// 00623db6  83caff               or edx, 0xffffffff
// 00623db9  f00fc111             lock xadd dword ptr [ecx], edx
// 00623dbd  751e                 jne 0x623ddd
// 00623dbf  8b07                 mov eax, dword ptr [edi]
// 00623dc1  8b5004               mov edx, dword ptr [eax + 4]
// 00623dc4  8bcf                 mov ecx, edi
// 00623dc6  ffd2                 call edx
// 00623dc8  8d4708               lea eax, [edi + 8]
// 00623dcb  83c9ff               or ecx, 0xffffffff
// 00623dce  f00fc108             lock xadd dword ptr [eax], ecx
// 00623dd2  7509                 jne 0x623ddd
// 00623dd4  8b17                 mov edx, dword ptr [edi]
// 00623dd6  8b4208               mov eax, dword ptr [edx + 8]
// 00623dd9  8bcf                 mov ecx, edi
// 00623ddb  ffd0                 call eax
// 00623ddd  8b4630               mov eax, dword ptr [esi + 0x30]
// 00623de0  8b5628               mov edx, dword ptr [esi + 0x28]
// 00623de3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00623de7  8d0c40               lea ecx, [eax + eax*2]
// 00623dea  03c9                 add ecx, ecx
// 00623dec  03c9                 add ecx, ecx
// 00623dee  6a00                 push 0
// 00623df0  03c9                 add ecx, ecx
// 00623df2  51                   push ecx
// 00623df3  52                   push edx
// 00623df4  57                   push edi
// 00623df5  e8f6c80300           call 0x6606f0
// 00623dfa  8b462c               mov eax, dword ptr [esi + 0x2c]
// 00623dfd  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00623e00  6a00                 push 0
// 00623e02  c1e004               shl eax, 4
// 00623e05  50                   push eax
// 00623e06  51                   push ecx
// 00623e07  57                   push edi
// 00623e08  e8e3c80300           call 0x6606f0
// 00623e0d  6a00                 push 0
// 00623e0f  6884000000           push 0x84
// 00623e14  53                   push ebx
// 00623e15  57                   push edi
// 00623e16  e8d5c80300           call 0x6606f0
// 00623e1b  83c430               add esp, 0x30
// 00623e1e  5f                   pop edi
// 00623e1f  5e                   pop esi
// 00623e20  5b                   pop ebx
// 00623e21  c3                   ret 

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
