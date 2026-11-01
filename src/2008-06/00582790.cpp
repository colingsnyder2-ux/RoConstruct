// from server: 100% by colin
// from server: 64% by colin
// roc 2008-06 00582790  unit: RBX::StopCommand  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582790
//
// 00582790  56                   push esi
// 00582791  57                   push edi
// 00582792  8bf9                 mov edi, ecx
// 00582794  8b770c               mov esi, dword ptr [edi + 0xc]
// 00582797  e8b4aaffff           call 0x57d250
// 0058279c  6a01                 push 1
// 0058279e  8d4f10               lea ecx, [edi + 0x10]
// 005827a1  e85af4ffff           call 0x581c00
// 005827a6  5f                   pop edi
// 005827a7  5e                   pop esi
// 005827a8  c744240402000000     mov dword ptr [esp + 4], 2
// 005827b0  8bc8                 mov ecx, eax
// 005827b2  e9e925fdff           jmp 0x554da0
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
struct StopCommand {
    char padding[0xc];
    Context* context;
    ServiceProvider services;
    void doIt(int);
};
void StopCommand::doIt(int)
{
    prepare(context);
    RunService* service = services.find(1);
    service->setRunState(2);
}
