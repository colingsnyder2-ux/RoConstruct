// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 006851a0  unit: Ogre::RbxSubEntity  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006851a0
//
// 006851a0  83ec10               sub esp, 0x10
// 006851a3  8d0424               lea eax, [esp]
// 006851a6  50                   push eax
// 006851a7  8d4c2408             lea ecx, [esp + 8]
// 006851ab  c744240450e88400     mov dword ptr [esp + 4], 0x84e850
// 006851b3  ff15a4288000         call dword ptr [0x8028a4]
// 006851b9  687c998d00           push 0x8d997c
// 006851be  8d4c2408             lea ecx, [esp + 8]
// 006851c2  51                   push ecx
// 006851c3  e8c4c30100           call 0x6a158c

struct ExceptionStorage {
    unsigned long data[3];
};

extern "C" void (__thiscall *exceptionConstructor)(
    ExceptionStorage*, const char* const&);

extern unsigned char exceptionThrowInfo;
extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

void hasEdgeList()
{
    const char* message =
        "RBX RbxSubEntity::hasEdgeList(): should not be called";
    ExceptionStorage exception;
    exceptionConstructor(&exception, message);
    throwException(&exception, &exceptionThrowInfo);
}
