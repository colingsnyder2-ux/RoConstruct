// from server: 100% by Yeetserama
// roc 2012-06 00899cc0  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00899cc0
//
// 00899cc0  8b442404             mov eax, dword ptr [esp + 4]
// 00899cc4  83ec0c               sub esp, 0xc
// 00899cc7  6a00                 push 0
// 00899cc9  68709ede00           push 0xde9e70
// 00899cce  68ac03d600           push 0xd603ac
// 00899cd3  6a00                 push 0
// 00899cd5  50                   push eax
// 00899cd6  e86d970e00           call 0x983448
// 00899cdb  83c414               add esp, 0x14
// 00899cde  85c0                 test eax, eax
// 00899ce0  751e                 jne 0x899d00
// 00899ce2  682841b400           push 0xb44128
// 00899ce7  8d4c2404             lea ecx, [esp + 4]
// 00899ceb  ff15202ab200         call dword ptr [0xb22a20]
// 00899cf1  68c0d5cd00           push 0xcdd5c0
// 00899cf6  8d4c2404             lea ecx, [esp + 4]
// 00899cfa  51                   push ecx
// 00899cfb  e844940e00           call 0x983144
// 00899d00  83c40c               add esp, 0xc
// 00899d03  c3                   ret 
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
