// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063e370  unit: RBX::LockTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063e370
//
// 0063e370  56                   push esi
// 0063e371  8bf1                 mov esi, ecx
// 0063e373  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0063e376  85c0                 test eax, eax
// 0063e378  7430                 je 0x63e3aa
// 0063e37a  50                   push eax
// 0063e37b  e8c0bcf5ff           call 0x59a040
// 0063e380  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0063e383  84c0                 test al, al
// 0063e385  0f94c0               sete al
// 0063e388  0fb6c8               movzx ecx, al
// 0063e38b  51                   push ecx
// 0063e38c  52                   push edx
// 0063e38d  e88efaf5ff           call 0x59de20
// 0063e392  8b4618               mov eax, dword ptr [esi + 0x18]
// 0063e395  83c40c               add esp, 0xc
// 0063e398  6a08                 push 8
// 0063e39a  50                   push eax
// 0063e39b  e81024f4ff           call 0x5807b0
// 0063e3a0  83c404               add esp, 4
// 0063e3a3  8bc8                 mov ecx, eax
// 0063e3a5  e876f4f7ff           call 0x5bd820
// 0063e3aa  8bc6                 mov eax, esi
// 0063e3ac  5e                   pop esi
// 0063e3ad  c20400               ret 4

struct Instance;
struct ServiceProvider {
    void notify(int value);
};

extern bool __cdecl isLocked(Instance *object);
extern void __cdecl setLocked(Instance *object, bool locked);
extern ServiceProvider *__cdecl findServiceProvider(Instance *object);

struct LockTool {
    unsigned char padding[24];
    Instance *parent;
    Instance *object;

    LockTool *activate(int unused);
};

LockTool *LockTool::activate(int unused)
{
    if (object) {
        setLocked(object, !isLocked(object));
        findServiceProvider(parent)->notify(8);
    }
    return this;
}
