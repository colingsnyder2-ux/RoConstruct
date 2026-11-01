// from server: 100% by colin
// from server: 99% by colin
// roc 2008-06 00428050  unit: MainLogManager  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00428050
//
// 00428050  6aff                 push -1
// 00428052  68fbf07b00           push 0x7bf0fb
// 00428057  64a100000000         mov eax, dword ptr fs:[0]
// 0042805d  50                   push eax
// 0042805e  64892500000000       mov dword ptr fs:[0], esp
// 00428065  83ec24               sub esp, 0x24
// 00428068  56                   push esi
// 00428069  57                   push edi
// 0042806a  8bf1                 mov esi, ecx
// 0042806c  8d442408             lea eax, [esp + 8]
// 00428070  50                   push eax
// 00428071  8d4e04               lea ecx, [esi + 4]
// 00428074  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042807c  e81ffbffff           call 0x427ba0
// 00428081  68d0038100           push 0x8103d0
// 00428086  8d4c2414             lea ecx, [esp + 0x14]
// 0042808a  c744243801000000     mov dword ptr [esp + 0x38], 1
// 00428092  ff1558248000         call dword ptr [0x802458]
// 00428098  83c630               add esi, 0x30
// 0042809b  56                   push esi
// 0042809c  8d4c2414             lea ecx, [esp + 0x14]
// 004280a0  c644243802           mov byte ptr [esp + 0x38], 2
// 004280a5  ff1550248000         call dword ptr [0x802450]
// 004280ab  8b0de8238000         mov ecx, dword ptr [0x8023e8]
// 004280b1  8b11                 mov edx, dword ptr [ecx]
// 004280b3  52                   push edx
// 004280b4  6a0c                 push 0xc
// 004280b6  8d4c2418             lea ecx, [esp + 0x18]
// 004280ba  ff15ec238000         call dword ptr [0x8023ec]
// 004280c0  6a03                 push 3
// 004280c2  6a04                 push 4
// 004280c4  8d4c2418             lea ecx, [esp + 0x18]
// 004280c8  ff15ec238000         call dword ptr [0x8023ec]
// 004280ce  8b442440             mov eax, dword ptr [esp + 0x40]
// 004280d2  50                   push eax
// 004280d3  8d4c2414             lea ecx, [esp + 0x14]
// 004280d7  ff1548248000         call dword ptr [0x802448]
// 004280dd  68c8038100           push 0x8103c8
// 004280e2  8d4c2414             lea ecx, [esp + 0x14]
// 004280e6  ff1548248000         call dword ptr [0x802448]
// 004280ec  8d4c2410             lea ecx, [esp + 0x10]
// 004280f0  ff1564248000         call dword ptr [0x802464]
// 004280f6  8bf0                 mov esi, eax
// 004280f8  56                   push esi
// 004280f9  ff15e42f8000         call dword ptr [0x802fe4]
// 004280ff  83c404               add esp, 4
// 00428102  8d4c2408             lea ecx, [esp + 8]
// 00428106  8bf8                 mov edi, eax
// 00428108  ff15e02f8000         call dword ptr [0x802fe0]
// 0042810e  8d4c0701             lea ecx, [edi + eax + 1]
// 00428112  51                   push ecx
// 00428113  8d4c240c             lea ecx, [esp + 0xc]
// 00428117  ff1584338000         call dword ptr [0x803384]
// 0042811d  56                   push esi
// 0042811e  50                   push eax
// 0042811f  ff15182b8000         call dword ptr [0x802b18]
// 00428125  6aff                 push -1
// 00428127  8d4c240c             lea ecx, [esp + 0xc]
// 0042812b  ff1580338000         call dword ptr [0x803380]
// 00428131  8d4c2408             lea ecx, [esp + 8]
// 00428135  ff15e03e8000         call dword ptr [0x803ee0]
// 0042813b  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 0042813f  50                   push eax
// 00428140  8bce                 mov ecx, esi
// 00428142  ff1558248000         call dword ptr [0x802458]
// 00428148  8d4c2410             lea ecx, [esp + 0x10]
// 0042814c  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00428154  c644243401           mov byte ptr [esp + 0x34], 1
// 00428159  ff1568248000         call dword ptr [0x802468]
// 0042815f  8d4c2408             lea ecx, [esp + 8]
// 00428163  ff15143f8000         call dword ptr [0x803f14]
// 00428169  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0042816d  5f                   pop edi
// 0042816e  8bc6                 mov eax, esi
// 00428170  5e                   pop esi
// 00428171  64890d00000000       mov dword ptr fs:[0], ecx
// 00428178  83c430               add esp, 0x30
// 0042817b  c20800               ret 8

// from server: 97% by king_originala
// roc 2008-06 00428050  unit: MainLogManager  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00428050
//
// 00428050  6aff                 push -1
// 00428052  68fbf07b00           push 0x7bf0fb
// 00428057  64a100000000         mov eax, dword ptr fs:[0]
// 0042805d  50                   push eax
// 0042805e  64892500000000       mov dword ptr fs:[0], esp
// 00428065  83ec24               sub esp, 0x24
// 00428068  56                   push esi
// 00428069  57                   push edi
// 0042806a  8bf1                 mov esi, ecx
// 0042806c  8d442408             lea eax, [esp + 8]
// 00428070  50                   push eax
// 00428071  8d4e04               lea ecx, [esi + 4]
// 00428074  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042807c  e81ffbffff           call 0x427ba0
// 00428081  68d0038100           push 0x8103d0
// 00428086  8d4c2414             lea ecx, [esp + 0x14]
// 0042808a  c744243801000000     mov dword ptr [esp + 0x38], 1
// 00428092  ff1558248000         call dword ptr [0x802458]
// 00428098  83c630               add esi, 0x30
// 0042809b  56                   push esi
// 0042809c  8d4c2414             lea ecx, [esp + 0x14]
// 004280a0  c644243802           mov byte ptr [esp + 0x38], 2
// 004280a5  ff1550248000         call dword ptr [0x802450]
// 004280ab  8b0de8238000         mov ecx, dword ptr [0x8023e8]
// 004280b1  8b11                 mov edx, dword ptr [ecx]
// 004280b3  52                   push edx
// 004280b4  6a0c                 push 0xc
// 004280b6  8d4c2418             lea ecx, [esp + 0x18]
// 004280ba  ff15ec238000         call dword ptr [0x8023ec]
// 004280c0  6a03                 push 3
// 004280c2  6a04                 push 4
// 004280c4  8d4c2418             lea ecx, [esp + 0x18]
// 004280c8  ff15ec238000         call dword ptr [0x8023ec]
// 004280ce  8b442440             mov eax, dword ptr [esp + 0x40]
// 004280d2  50                   push eax
// 004280d3  8d4c2414             lea ecx, [esp + 0x14]
// 004280d7  ff1548248000         call dword ptr [0x802448]
// 004280dd  68c8038100           push 0x8103c8
// 004280e2  8d4c2414             lea ecx, [esp + 0x14]
// 004280e6  ff1548248000         call dword ptr [0x802448]
// 004280ec  8d4c2410             lea ecx, [esp + 0x10]
// 004280f0  ff1564248000         call dword ptr [0x802464]
// 004280f6  8bf0                 mov esi, eax
// 004280f8  56                   push esi
// 004280f9  ff15e42f8000         call dword ptr [0x802fe4]
// 004280ff  83c404               add esp, 4
// 00428102  8d4c2408             lea ecx, [esp + 8]
// 00428106  8bf8                 mov edi, eax
// 00428108  ff15e02f8000         call dword ptr [0x802fe0]
// 0042810e  8d4c0701             lea ecx, [edi + eax + 1]
// 00428112  51                   push ecx
// 00428113  8d4c240c             lea ecx, [esp + 0xc]
// 00428117  ff1584338000         call dword ptr [0x803384]
// 0042811d  56                   push esi
// 0042811e  50                   push eax
// 0042811f  ff15182b8000         call dword ptr [0x802b18]
// 00428125  6aff                 push -1
// 00428127  8d4c240c             lea ecx, [esp + 0xc]
// 0042812b  ff1580338000         call dword ptr [0x803380]
// 00428131  8d4c2408             lea ecx, [esp + 8]
// 00428135  ff15e03e8000         call dword ptr [0x803ee0]
// 0042813b  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 0042813f  50                   push eax
// 00428140  8bce                 mov ecx, esi
// 00428142  ff1558248000         call dword ptr [0x802458]
// 00428148  8d4c2410             lea ecx, [esp + 0x10]
// 0042814c  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00428154  c644243401           mov byte ptr [esp + 0x34], 1
// 00428159  ff1568248000         call dword ptr [0x802468]
// 0042815f  8d4c2408             lea ecx, [esp + 8]
// 00428163  ff15143f8000         call dword ptr [0x803f14]
// 00428169  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0042816d  5f                   pop edi
// 0042816e  8bc6                 mov eax, esi
// 00428170  5e                   pop esi
// 00428171  64890d00000000       mov dword ptr fs:[0], ecx
// 00428178  83c430               add esp, 0x30
// 0042817b  c20800               ret 8

struct String;
struct Path;

extern void (__thiscall *string_construct)(String *, const char *);
extern void (__thiscall *string_destroy)(String *);
extern String &(__thiscall *string_append_string)(String *, const String &);
extern String &(__thiscall *string_append_text)(String *, const char *);
extern String &(__thiscall *string_erase)(String *, unsigned int, unsigned int);
extern const char *(__thiscall *string_c_str)(const String *);
extern const unsigned int *string_npos;

extern unsigned int (__cdecl *text_length)(const char *);
extern int (__stdcall *path_append)(char *, const char *);
extern int (__thiscall *path_length)(const Path *);
extern char *(__thiscall *path_get_buffer)(Path *, int);
extern void (__thiscall *path_release_buffer)(Path *, int);
extern const char *(__thiscall *path_text)(const Path *);
extern void (__thiscall *path_destroy)(Path *);

struct Path
{
    unsigned char data[4];
    __declspec(dllimport) ~Path() throw();
};

struct String
{
    unsigned char data[28];
    String(const char *);
    ~String();
    Path getPath() const;
};

inline String::String(const char *text)
{
    string_construct(this, text);
}

inline String::~String()
{
    string_destroy(this);
}

struct MainLogManager
{
    unsigned int first;
    String directory;
    unsigned char padding[16];
    String identifier;

    String func_00428050(const char *);
};

String MainLogManager::func_00428050(const char *name)
{
    Path path = directory.getPath();
    String filename("log_");
    string_append_string(&filename, identifier);
    string_erase(&filename, 12, *string_npos);
    string_erase(&filename, 4, 3);
    string_append_text(&filename, name);
    string_append_text(&filename, ".txt");

    const char *text = string_c_str(&filename);
    char *buffer = path_get_buffer(&path, text_length(text) + path_length(&path) + 1);
    path_append(buffer, text);
    path_release_buffer(&path, -1);

    return String(path_text(&path));
}
