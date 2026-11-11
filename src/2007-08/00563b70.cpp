// from server: 100% by EspClaude
// from server: 76% by Intel
// roc 2007-08 00563b70  unit: RBX::RunCommand  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00563b70
//
// 00563b70  56                   push esi
// 00563b71  57                   push edi
// 00563b72  8bf9                 mov edi, ecx
// 00563b74  8b770c               mov esi, dword ptr [edi + 0xc]
// 00563b77  e814a7ffff           call 0x55e290
// 00563b7c  6a01                 push 1
// 00563b7e  8d4f10               lea ecx, [edi + 0x10]
// 00563b81  e8bae6ffff           call 0x562240
// 00563b86  80b8ac01000000       cmp byte ptr [eax + 0x1ac], 0
// 00563b8d  5f                   pop edi
// 00563b8e  5e                   pop esi
// 00563b8f  750f                 jne 0x563ba0
// 00563b91  c744240401000000     mov dword ptr [esp + 4], 1
// 00563b99  8bc8                 mov ecx, eax
// 00563b9b  e9e09bfcff           jmp 0x52d780

struct Context;
#include <exception>
extern bool __cdecl testA(Context*, int);
extern bool __cdecl testB(Context*, int);
// 0055e290 takes its argument in esi: a static function of this file (custom calling convention).
static __declspec(noinline) void prepare(Context* c)
{
    // 0055e290: f(esi,1); test al; je; g(esi,1); test al; jne; else throw std::exception
    if (testA(c, 1) && !testB(c, 1))
        throw std::exception("");
}

struct RunService {
    char pad[0x1AC];
    bool running;
    void setRunState(int);
};
struct ServiceProvider {
    RunService* find(int);
};

struct RunCommand {
    char pad[0xC];
    Context* context;
    ServiceProvider services;
    void doIt(int);
};

void RunCommand::doIt(int)
{
    prepare(context);
    RunService* service = services.find(1);
    if (service->running)
        return;
    service->setRunState(1);
}
