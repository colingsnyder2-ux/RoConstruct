// from server: 100% by colin
// from server: 79% by colin
// roc 2008-06 00580b20  unit: RBX::ClearStarterpack  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00580b20
//
// 00580b20  56                   push esi
// 00580b21  57                   push edi
// 00580b22  8bf9                 mov edi, ecx
// 00580b24  8b770c               mov esi, dword ptr [edi + 0xc]
// 00580b27  e824c7ffff           call 0x57d250
// 00580b2c  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00580b2f  5f                   pop edi
// 00580b30  5e                   pop esi
// 00580b31  85c9                 test ecx, ecx
// 00580b33  7410                 je 0x580b45
// 00580b35  e83602f1ff           call 0x490d70
// 00580b3a  85c0                 test eax, eax
// 00580b3c  7407                 je 0x580b45
// 00580b3e  8bc8                 mov ecx, eax
// 00580b40  e88ba4fdff           call 0x55afd0
// 00580b45  c20400               ret 4
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
struct Context { Container* findStarterPack(); };
struct ClearStarterpack {
    char padding[0xc];
    Context* context;
    void doIt(int);
};
void ClearStarterpack::doIt(int)
{
    prepare(context);
    if (context) {
        if (Container* pack = context->findStarterPack())
            pack->clear();
    }
}
