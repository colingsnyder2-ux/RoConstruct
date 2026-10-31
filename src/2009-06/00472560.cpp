// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0046eb40  unit: RBX::LDraw2Lua::LDrawCommand  size: 421 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046eb40
//
// 0046eb40  6aff                 push -1
// 0046eb42  6809e77c00           push 0x7ce709
// 0046eb47  64a100000000         mov eax, dword ptr fs:[0]
// 0046eb4d  50                   push eax
// 0046eb4e  64892500000000       mov dword ptr fs:[0], esp
// 0046eb55  83ec1c               sub esp, 0x1c
// 0046eb58  53                   push ebx
// 0046eb59  56                   push esi
// 0046eb5a  8b742434             mov esi, dword ptr [esp + 0x34]
// 0046eb5e  57                   push edi
// 0046eb5f  68cccb8100           push 0x81cbcc
// 0046eb64  68acca8100           push 0x81caac
// 0046eb69  68c8cb8100           push 0x81cbc8
// 0046eb6e  56                   push esi
// 0046eb6f  8bf9                 mov edi, ecx
// 0046eb71  e8dab8fdff           call 0x44a450
// 0046eb76  83c408               add esp, 8
// 0046eb79  50                   push eax
// 0046eb7a  e8d1b8fdff           call 0x44a450
// 0046eb7f  83c408               add esp, 8
// 0046eb82  50                   push eax
// 0046eb83  e8c8b8fdff           call 0x44a450
// 0046eb88  83c408               add esp, 8
// 0046eb8b  68cccb8100           push 0x81cbcc
// 0046eb90  6890ca8100           push 0x81ca90
// 0046eb95  56                   push esi
// 0046eb96  e8b5b8fdff           call 0x44a450
// 0046eb9b  83c408               add esp, 8
// 0046eb9e  50                   push eax
// 0046eb9f  e8acb8fdff           call 0x44a450
// 0046eba4  83c408               add esp, 8
// 0046eba7  6a00                 push 0
// 0046eba9  83c770               add edi, 0x70
// 0046ebac  688cca8100           push 0x81ca8c
// 0046ebb1  8bcf                 mov ecx, edi
// 0046ebb3  ff1574248000         call dword ptr [0x802474]
// 0046ebb9  50                   push eax
// 0046ebba  6a00                 push 0
// 0046ebbc  8d442414             lea eax, [esp + 0x14]
// 0046ebc0  50                   push eax
// 0046ebc1  8bcf                 mov ecx, edi
// 0046ebc3  ff15e0238000         call dword ptr [0x8023e0]
// 0046ebc9  68cccb8100           push 0x81cbcc
// 0046ebce  6888ca8100           push 0x81ca88
// 0046ebd3  8d4c2414             lea ecx, [esp + 0x14]
// 0046ebd7  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0046ebdf  ff1564248000         call dword ptr [0x802464]
// 0046ebe5  50                   push eax
// 0046ebe6  6878ca8100           push 0x81ca78
// 0046ebeb  56                   push esi
// 0046ebec  e85fb8fdff           call 0x44a450
// 0046ebf1  83c408               add esp, 8
// 0046ebf4  50                   push eax
// 0046ebf5  e856b8fdff           call 0x44a450
// 0046ebfa  83c408               add esp, 8
// 0046ebfd  50                   push eax
// 0046ebfe  e84db8fdff           call 0x44a450
// 0046ec03  83c408               add esp, 8
// 0046ec06  50                   push eax
// 0046ec07  e844b8fdff           call 0x44a450
// 0046ec0c  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0046ec10  8b3b                 mov edi, dword ptr [ebx]
// 0046ec12  83c408               add esp, 8
// 0046ec15  68cccb8100           push 0x81cbcc
// 0046ec1a  57                   push edi
// 0046ec1b  6868ca8100           push 0x81ca68
// 0046ec20  56                   push esi
// 0046ec21  e82ab8fdff           call 0x44a450
// 0046ec26  83c408               add esp, 8
// 0046ec29  8bc8                 mov ecx, eax
// 0046ec2b  ff1570248000         call dword ptr [0x802470]
// 0046ec31  50                   push eax
// 0046ec32  e819b8fdff           call 0x44a450
// 0046ec37  83c408               add esp, 8
// 0046ec3a  85ff                 test edi, edi
// 0046ec3c  7426                 je 0x46ec64
// 0046ec3e  83ff02               cmp edi, 2
// 0046ec41  7421                 je 0x46ec64
// 0046ec43  8b4304               mov eax, dword ptr [ebx + 4]
// 0046ec46  68cccb8100           push 0x81cbcc
// 0046ec4b  50                   push eax
// 0046ec4c  6854ca8100           push 0x81ca54
// 0046ec51  56                   push esi
// 0046ec52  e8f9b7fdff           call 0x44a450
// 0046ec57  83c408               add esp, 8
// 0046ec5a  8bc8                 mov ecx, eax
// 0046ec5c  ff1570248000         call dword ptr [0x802470]
// 0046ec62  eb13                 jmp 0x46ec77
// 0046ec64  68cccb8100           push 0x81cbcc
// 0046ec69  6830ca8100           push 0x81ca30
// 0046ec6e  56                   push esi
// 0046ec6f  e8dcb7fdff           call 0x44a450
// 0046ec74  83c408               add esp, 8
// 0046ec77  50                   push eax
// 0046ec78  e8d3b7fdff           call 0x44a450
// 0046ec7d  83c408               add esp, 8
// 0046ec80  68cccb8100           push 0x81cbcc
// 0046ec85  685c2e8100           push 0x812e5c
// 0046ec8a  8d4b08               lea ecx, [ebx + 8]
// 0046ec8d  ff1564248000         call dword ptr [0x802464]
// 0046ec93  50                   push eax
// 0046ec94  6814ca8100           push 0x81ca14
// 0046ec99  56                   push esi
// 0046ec9a  e8b1b7fdff           call 0x44a450
// 0046ec9f  83c408               add esp, 8
// 0046eca2  50                   push eax
// 0046eca3  e8a8b7fdff           call 0x44a450
// 0046eca8  83c408               add esp, 8
// 0046ecab  50                   push eax
// 0046ecac  e89fb7fdff           call 0x44a450
// 0046ecb1  83c408               add esp, 8
// 0046ecb4  50                   push eax
// 0046ecb5  e896b7fdff           call 0x44a450
// 0046ecba  83c408               add esp, 8
// 0046ecbd  8d4c240c             lea ecx, [esp + 0xc]
// 0046ecc1  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 0046ecc9  ff1568248000         call dword ptr [0x802468]
// 0046eccf  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0046ecd3  5f                   pop edi
// 0046ecd4  5e                   pop esi
// 0046ecd5  b001                 mov al, 1
// 0046ecd7  5b                   pop ebx
// 0046ecd8  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ecdf  83c428               add esp, 0x28
// 0046ece2  c20800               ret 8

struct String;

extern void (__thiscall *destroyString)(String *);
extern const char *(__thiscall *stringCStr)(const String *);
extern unsigned int (__thiscall *stringFindFirstOf)(
    const String *, const char *, unsigned int);
extern String *(__thiscall *stringSubstr)(
    const String *, String *, unsigned int, unsigned int);

struct String {
    char storage[28];
    String(const String *source, unsigned int start, unsigned int count);
    ~String();
};

inline String::String(
    const String *source, unsigned int start, unsigned int count)
{
    stringSubstr(source, this, start, count);
}

inline String::~String()
{
    destroyString(this);
}

struct Stream {};

extern Stream &__cdecl writeText(Stream &, const char *);
extern Stream &(__thiscall *writeInteger)(Stream *, int);

struct Part {
    int shape;
    int formFactor;
    String size;
};

struct S {
    char padding[112];
    String description;

    bool write(Stream &stream, const Part *part);
};

bool S::write(Stream &stream, const Part *part)
{
    writeText(
        writeText(
            writeText(stream, (const char *)0x0081cbc8),
            (const char *)0x0081caac),
        (const char *)0x0081cbcc);

    writeText(
        writeText(stream, (const char *)0x0081ca90),
        (const char *)0x0081cbcc);

    String name(
        &description, 0,
        stringFindFirstOf(&description, (const char *)0x0081ca8c, 0));

    writeText(
        writeText(
            writeText(
                writeText(stream, (const char *)0x0081ca78),
                stringCStr(&name)),
            (const char *)0x0081ca88),
        (const char *)0x0081cbcc);

    int shape = part->shape;
    writeText(
        writeInteger(
            &writeText(stream, (const char *)0x0081ca68), shape),
        (const char *)0x0081cbcc);

    if (shape != 0 && shape != 2) {
        int formFactor = part->formFactor;
        writeText(
            writeInteger(
                &writeText(stream, (const char *)0x0081ca54),
                formFactor),
            (const char *)0x0081cbcc);
    } else {
        writeText(
            writeText(stream, (const char *)0x0081ca30),
            (const char *)0x0081cbcc);
    }

    writeText(
        writeText(
            writeText(
                writeText(stream, (const char *)0x0081ca14),
                stringCStr(&part->size)),
            (const char *)0x00812e5c),
        (const char *)0x0081cbcc);

    return true;
}
