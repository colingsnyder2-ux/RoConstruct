// from server: 100% by colin
// from server: 87% by king_originala
// roc 2008-06 0057d8e0  unit: RBX::AllCanSelectCommand  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057d8e0
//
// 0057d8e0  56                   push esi
// 0057d8e1  57                   push edi
// 0057d8e2  8bf9                 mov edi, ecx
// 0057d8e4  8b770c               mov esi, dword ptr [edi + 0xc]
// 0057d8e7  e864f9ffff           call 0x57d250
// 0057d8ec  8b470c               mov eax, dword ptr [edi + 0xc]
// 0057d8ef  8bb004020000         mov esi, dword ptr [eax + 0x204]
// 0057d8f5  6a00                 push 0
// 0057d8f7  56                   push esi
// 0057d8f8  e823050200           call 0x59de20
// 0057d8fd  8b4704               mov eax, dword ptr [edi + 4]
// 0057d900  83c004               add eax, 4
// 0057d903  83c408               add esp, 8
// 0057d906  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0057d90a  7205                 jb 0x57d911
// 0057d90c  8b4004               mov eax, dword ptr [eax + 4]
// 0057d90f  eb03                 jmp 0x57d914
// 0057d911  83c004               add eax, 4
// 0057d914  56                   push esi
// 0057d915  50                   push eax
// 0057d916  e8a5ec0000           call 0x58c5c0
// 0057d91b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0057d91f  8b11                 mov edx, dword ptr [ecx]
// 0057d921  83c408               add esp, 8
// 0057d924  5f                   pop edi
// 0057d925  5e                   pop esi
// 0057d926  c744240401000000     mov dword ptr [esp + 4], 1
// 0057d92e  8b02                 mov eax, dword ptr [edx]
// 0057d930  ffe0                 jmp eax
#include <string>
struct Context;
extern bool __cdecl isLocked(Context*);
extern void __cdecl unlock(Context*);
// 0057d250 takes its argument in esi: a static function of this file (custom calling convention).
static __declspec(noinline) void prepare(Context* c)
{
    if (isLocked(c))
        unlock(c);
}
struct Selection;
struct Context {
    char padding[0x204];
    Selection* selection;
};
struct Description {
    int unused;
    std::string name;
};
struct Listener { virtual void done(int); };
extern void __cdecl setAllCanSelect(Selection*, bool);
extern void __cdecl record(const char*, Selection*);
struct AllCanSelectCommand {
    int unused;
    Description* description;
    char padding[4];
    Context* context;
    void doIt(Listener* listener);
};
void AllCanSelectCommand::doIt(Listener* listener)
{
    prepare(context);
    Selection* selection = context->selection;
    setAllCanSelect(selection, false);
    record(description->name.c_str(), selection);
    listener->done(1);
}
