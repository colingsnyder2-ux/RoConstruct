// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00685170  unit: Ogre::RbxSubEntity  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00685170
//
// 00685170  83ec10               sub esp, 0x10
// 00685173  8d0424               lea eax, [esp]
// 00685176  50                   push eax
// 00685177  8d4c2408             lea ecx, [esp + 8]
// 0068517b  c744240418e88400     mov dword ptr [esp + 4], 0x84e818
// 00685183  ff15a4288000         call dword ptr [0x8028a4]
// 00685189  687c998d00           push 0x8d997c
// 0068518e  8d4c2408             lea ecx, [esp + 8]
// 00685192  51                   push ecx
// 00685193  e8f4c30100           call 0x6a158c

struct ExceptionStorage {
    unsigned long data[3];
};

extern "C" void (__thiscall *exceptionConstructor)(
    ExceptionStorage*, const char* const&);

extern unsigned char exceptionThrowInfo;
extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

void getEdgeList()
{
    const char* message =
        "RBX RbxSubEntity::getEdgeList(): should not be called";
    ExceptionStorage exception;
    exceptionConstructor(&exception, message);
    throwException(&exception, &exceptionThrowInfo);
}
