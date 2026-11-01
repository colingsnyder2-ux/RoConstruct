// from server: 100% by colin
// from server: 60% by colin
// roc 2008-06 00582740  unit: RBX::RunCommand  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582740
//
// 00582740  56                   push esi
// 00582741  57                   push edi
// 00582742  8bf9                 mov edi, ecx
// 00582744  8b770c               mov esi, dword ptr [edi + 0xc]
// 00582747  e804abffff           call 0x57d250
// 0058274c  6a01                 push 1
// 0058274e  8d4f10               lea ecx, [edi + 0x10]
// 00582751  e8aaf4ffff           call 0x581c00
// 00582756  5f                   pop edi
// 00582757  5e                   pop esi
// 00582758  c744240401000000     mov dword ptr [esp + 4], 1
// 00582760  8bc8                 mov ecx, eax
// 00582762  e93926fdff           jmp 0x554da0
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
struct RunCommand {
    char padding[0xc];
    Context* context;
    ServiceProvider services;
    void doIt(int);
};
void RunCommand::doIt(int)
{
    prepare(context);
    RunService* service = services.find(1);
    service->setRunState(1);
}
