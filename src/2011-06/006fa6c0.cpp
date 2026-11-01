// from server: 100% by Yeetserama
// roc 2011-06 006fa6c0  unit: RBX::VelocityMotor  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006fa6c0
//
// 006fa6c0  8b442404             mov eax, dword ptr [esp + 4]
// 006fa6c4  83ec0c               sub esp, 0xc
// 006fa6c7  6a00                 push 0
// 006fa6c9  685490c700           push 0xc79054
// 006fa6ce  68f873c000           push 0xc073f8
// 006fa6d3  6a00                 push 0
// 006fa6d5  50                   push eax
// 006fa6d6  e80f0c1100           call 0x80b2ea
// 006fa6db  83c414               add esp, 0x14
// 006fa6de  85c0                 test eax, eax
// 006fa6e0  751e                 jne 0x6fa700
// 006fa6e2  680cc1a500           push 0xa5c10c
// 006fa6e7  8d4c2404             lea ecx, [esp + 4]
// 006fa6eb  ff15100aa400         call dword ptr [0xa40a10]
// 006fa6f1  68fc89b900           push 0xb989fc
// 006fa6f6  8d4c2404             lea ecx, [esp + 4]
// 006fa6fa  51                   push ecx
// 006fa6fb  e8ac091100           call 0x80b0ac
// 006fa700  83c40c               add esp, 0xc
// 006fa703  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000007_0060b970@ns_ROCX000007@@YAPAXPAX@Z)

namespace ns_ROCX000007 {
// from server: 100% by king_originala
extern char sourceType;
extern char targetType;
extern char badCastType;

extern "C" void* __cdecl runtimeCast(
    void*, long, void*, void*, int);

typedef void (__thiscall *BadCastConstructor)(void*, const char*);
extern BadCastConstructor constructBadCast;

extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

void* fn_ROCX000007_0060b970(void* object)
{
    void* result = runtimeCast(object, 0, &sourceType, &targetType, 0);
    if (!result)
    {
        char exception[12];
        constructBadCast(exception, "bad cast");
        throwException(exception, &badCastType);
    }
    return result;
}
}
