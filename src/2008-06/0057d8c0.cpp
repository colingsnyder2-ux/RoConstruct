// from server: 100% by colin
// from server: 84% by king_originala
// roc 2008-06 0057d8c0  unit: RBX::SelectAllCommand  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057d8c0
//
// 0057d8c0  56                   push esi
// 0057d8c1  57                   push edi
// 0057d8c2  8bf9                 mov edi, ecx
// 0057d8c4  8b770c               mov esi, dword ptr [edi + 0xc]
// 0057d8c7  e884f9ffff           call 0x57d250
// 0057d8cc  8b470c               mov eax, dword ptr [edi + 0xc]
// 0057d8cf  8b8804020000         mov ecx, dword ptr [eax + 0x204]
// 0057d8d5  e836650200           call 0x5a3e10
// 0057d8da  5f                   pop edi
// 0057d8db  5e                   pop esi
// 0057d8dc  c20400               ret 4
struct Context;
struct Selection { Context* apply(); };
struct Context {
    char padding[0x204];
    Selection* selection;
};
extern bool __cdecl isLocked(Context*);
extern void __cdecl unlock(Context*);
// 0057d250 takes its argument in esi: a static function of this file (custom calling convention).
static __declspec(noinline) void prepare(Context* c)
{
    if (isLocked(c))
        unlock(c);
}
struct Command {
    char padding[0x0c];
    Context* context;
    Context* execute(int);
};
Context* Command::execute(int)
{
    prepare(context);
    return context->selection->apply();
}
