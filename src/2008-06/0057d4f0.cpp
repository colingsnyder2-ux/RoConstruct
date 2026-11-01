// from server: 100% by colin
// from server: 80% by king_originala
// roc 2008-06 0057d4f0  unit: RBX::ClearBackpack  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057d4f0
//
// 0057d4f0  56                   push esi
// 0057d4f1  57                   push edi
// 0057d4f2  8bf9                 mov edi, ecx
// 0057d4f4  8b770c               mov esi, dword ptr [edi + 0xc]
// 0057d4f7  e854fdffff           call 0x57d250
// 0057d4fc  8b470c               mov eax, dword ptr [edi + 0xc]
// 0057d4ff  50                   push eax
// 0057d500  e87bd7f1ff           call 0x49ac80
// 0057d505  83c404               add esp, 4
// 0057d508  5f                   pop edi
// 0057d509  5e                   pop esi
// 0057d50a  85c0                 test eax, eax
// 0057d50c  740e                 je 0x57d51c
// 0057d50e  8bc8                 mov ecx, eax
// 0057d510  e85beff0ff           call 0x48c470
// 0057d515  8bc8                 mov ecx, eax
// 0057d517  e8b4dafdff           call 0x55afd0
// 0057d51c  c20400               ret 4
struct Context;
extern bool __cdecl isLocked(Context*);
extern void __cdecl unlock(Context*);
// 0057d250 takes its argument in esi: a static function of this file (custom calling convention).
static __declspec(noinline) void prepare(Context* c)
{
    if (isLocked(c))
        unlock(c);
}

struct Container { void clear(); };
struct Player { Container* backpack(); };
extern Player* __cdecl localPlayer(Context*);
struct ClearBackpack {
    char padding[0xc];
    Context* context;
    void doIt(int);
};
void ClearBackpack::doIt(int)
{
    prepare(context);
    if (Player* player = localPlayer(context))
        player->backpack()->clear();
}
