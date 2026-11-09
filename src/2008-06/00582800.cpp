// from server: 100% by colin
// from server: 64% by colin
// roc 2008-06 00582800  unit: RBX::ResetCommand  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582800
//
// 00582800  56                   push esi
// 00582801  57                   push edi
// 00582802  8bf9                 mov edi, ecx
// 00582804  8b770c               mov esi, dword ptr [edi + 0xc]
// 00582807  e844aaffff           call 0x57d250
// 0058280c  6a01                 push 1
// 0058280e  8d4f10               lea ecx, [edi + 0x10]
// 00582811  e8eaf3ffff           call 0x581c00
// 00582816  5f                   pop edi
// 00582817  5e                   pop esi
// 00582818  c744240400000000     mov dword ptr [esp + 4], 0
// 00582820  8bc8                 mov ecx, eax
// 00582822  e97925fdff           jmp 0x554da0
struct Context;
extern bool __cdecl isLocked(Context*);
extern void __cdecl unlock(Context*);
// 0057d250 takes its argument in esi: a static function of this file (custom calling convention).
static __declspec(noinline) void prepare(Context* c)
{
    if (isLocked(c))
        unlock(c);
}
struct RunService { void setRunState(int); };
struct ServiceProvider { RunService* find(int); };
struct ResetCommand {
    char padding[0xc];
    Context* context;
    ServiceProvider services;
    void doIt(int);
};
void ResetCommand::doIt(int)
{
    prepare(context);
    RunService* service = services.find(1);
    service->setRunState(0);
}
