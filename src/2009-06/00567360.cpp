// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 005039e0  unit: RBX::RenderBase::RenderSceneBase  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005039e0
//
// 005039e0  6aff                 push -1
// 005039e2  6818b57c00           push 0x7cb518
// 005039e7  64a100000000         mov eax, dword ptr fs:[0]
// 005039ed  50                   push eax
// 005039ee  64892500000000       mov dword ptr fs:[0], esp
// 005039f5  83ec10               sub esp, 0x10
// 005039f8  8d0424               lea eax, [esp]
// 005039fb  50                   push eax
// 005039fc  8d4c2408             lea ecx, [esp + 8]
// 00503a00  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00503a08  c74424043c748200     mov dword ptr [esp + 4], 0x82743c
// 00503a10  ff15a4288000         call dword ptr [0x8028a4]
// 00503a16  687c998d00           push 0x8d997c
// 00503a1b  8d4c2408             lea ecx, [esp + 8]
// 00503a1f  51                   push ecx
// 00503a20  e867db1900           call 0x6a158c

struct Exception;
typedef void (__thiscall *ExceptionConstructor)(Exception *, const char * const &);
extern ExceptionConstructor exceptionConstructor;
extern char exceptionThrowInfo;

extern "C" __declspec(noreturn) void __stdcall
throwException(void *, void *);

struct Exception {
    void *table;
    char *message;
    int ownsMessage;

    Exception();
    ~Exception();
};

__forceinline Exception::Exception()
{
}

void func_005039e0()
{
    Exception value;
    exceptionConstructor(&value, "shouldn't be here");
    throwException(&value, &exceptionThrowInfo);
}
