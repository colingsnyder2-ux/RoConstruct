// from server: 100% by Yeetserama
// roc 2010-06 005454e0  unit: RBX::RenderSceneBase  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005454e0
//
// 005454e0  6aff                 push -1
// 005454e2  68e8e19800           push 0x98e1e8
// 005454e7  64a100000000         mov eax, dword ptr fs:[0]
// 005454ed  50                   push eax
// 005454ee  64892500000000       mov dword ptr fs:[0], esp
// 005454f5  83ec10               sub esp, 0x10
// 005454f8  8d0424               lea eax, [esp]
// 005454fb  50                   push eax
// 005454fc  8d4c2408             lea ecx, [esp + 8]
// 00545500  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00545508  c744240410f3a100     mov dword ptr [esp + 4], 0xa1f310
// 00545510  ff1524a99e00         call dword ptr [0x9ea924]
// 00545516  6878b6b000           push 0xb0b678
// 0054551b  8d4c2408             lea ecx, [esp + 8]
// 0054551f  51                   push ecx
// 00545520  e88d342600           call 0x7a89b2
// copied from an identical function in another client (function ?fn_ROCX000017_005039e0@ns_ROCX000017@@YAXXZ)

namespace ns_ROCX000017 {
// from server: 100% by colin
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

void fn_ROCX000017_005039e0()
{
    Exception value;
    exceptionConstructor(&value, "shouldn't be here");
    throwException(&value, &exceptionThrowInfo);
}
}
