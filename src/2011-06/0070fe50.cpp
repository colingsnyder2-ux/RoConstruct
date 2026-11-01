// from server: 100% by Yeetserama
// roc 2011-06 0070fe50  unit: RBX::VBasicPartInstance::?$SeatImpl  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0070fe50
//
// 0070fe50  8b442404             mov eax, dword ptr [esp + 4]
// 0070fe54  83ec0c               sub esp, 0xc
// 0070fe57  6a00                 push 0
// 0070fe59  688410c800           push 0xc81084
// 0070fe5e  68f873c000           push 0xc073f8
// 0070fe63  6a00                 push 0
// 0070fe65  50                   push eax
// 0070fe66  e87fb40f00           call 0x80b2ea
// 0070fe6b  83c414               add esp, 0x14
// 0070fe6e  85c0                 test eax, eax
// 0070fe70  751e                 jne 0x70fe90
// 0070fe72  680cc1a500           push 0xa5c10c
// 0070fe77  8d4c2404             lea ecx, [esp + 4]
// 0070fe7b  ff15100aa400         call dword ptr [0xa40a10]
// 0070fe81  68fc89b900           push 0xb989fc
// 0070fe86  8d4c2404             lea ecx, [esp + 4]
// 0070fe8a  51                   push ecx
// 0070fe8b  e81cb20f00           call 0x80b0ac
// 0070fe90  83c40c               add esp, 0xc
// 0070fe93  c3                   ret 
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
