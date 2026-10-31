// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0046ecf0  unit: RBX::LDraw2Lua::LDrawCommand  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046ecf0
//
// 0046ecf0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0046ecf3  8b4904               mov ecx, dword ptr [ecx + 4]
// 0046ecf6  56                   push esi
// 0046ecf7  6808cb8100           push 0x81cb08
// 0046ecfc  50                   push eax
// 0046ecfd  e87ee3ffff           call 0x46d080
// 0046ed02  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0046ed06  50                   push eax
// 0046ed07  68e4ca8100           push 0x81cae4
// 0046ed0c  56                   push esi
// 0046ed0d  e83eb7fdff           call 0x44a450
// 0046ed12  83c408               add esp, 8
// 0046ed15  8bc8                 mov ecx, eax
// 0046ed17  ff1570248000         call dword ptr [0x802470]
// 0046ed1d  50                   push eax
// 0046ed1e  e82db7fdff           call 0x44a450
// 0046ed23  68cccb8100           push 0x81cbcc
// 0046ed28  56                   push esi
// 0046ed29  e822b7fdff           call 0x44a450
// 0046ed2e  83c410               add esp, 0x10
// 0046ed31  b001                 mov al, 1
// 0046ed33  5e                   pop esi
// 0046ed34  c20400               ret 4

struct Context
{
    int f(int);
};

struct Stream;

extern "C" Stream * __cdecl append(Stream *, const char *);
extern Stream * (__thiscall *writeInteger)(Stream *, int);

struct Command
{
    int reserved0;
    Context *context;
    int reserved8;
    int value;

    bool f(Stream *);
};

bool Command::f(Stream *out)
{
    append(
        writeInteger(
            append(out, (const char *)0x81cae4),
            context->f(value)),
        (const char *)0x81cb08);
    append(out, (const char *)0x81cbcc);
    return true;
}
