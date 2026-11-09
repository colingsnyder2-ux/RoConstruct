// roc 2012-06 006275b0  unit: seg_00620000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006275b0
//
// 006275b0  57                   push edi
// 006275b1  8bf9                 mov edi, ecx
// 006275b3  8b4704               mov eax, dword ptr [edi + 4]
// 006275b6  85c0                 test eax, eax
// 006275b8  7446                 je 0x627600
// 006275ba  56                   push esi
// 006275bb  8b35a829b200         mov esi, dword ptr [0xb229a8]
// 006275c1  687833b800           push 0xb83378
// 006275c6  50                   push eax
// 006275c7  ffd6                 call esi
// 006275c9  8b442414             mov eax, dword ptr [esp + 0x14]
// 006275cd  83c408               add esp, 8
// 006275d0  83781810             cmp dword ptr [eax + 0x18], 0x10
// 006275d4  7217                 jb 0x6275ed
// 006275d6  8b4004               mov eax, dword ptr [eax + 4]
// 006275d9  50                   push eax
// 006275da  8b4704               mov eax, dword ptr [edi + 4]
// 006275dd  686033b800           push 0xb83360
// 006275e2  50                   push eax
// 006275e3  ffd6                 call esi
// 006275e5  83c40c               add esp, 0xc
// 006275e8  5e                   pop esi
// 006275e9  5f                   pop edi
// 006275ea  c20400               ret 4
// 006275ed  83c004               add eax, 4
// 006275f0  50                   push eax
// 006275f1  8b4704               mov eax, dword ptr [edi + 4]
// 006275f4  686033b800           push 0xb83360
// 006275f9  50                   push eax
// 006275fa  ffd6                 call esi
// 006275fc  83c40c               add esp, 0xc
// 006275ff  5e                   pop esi
// 00627600  5f                   pop edi
// 00627601  c20400               ret 4
// copied from an identical function in another client (function ?write@Shader@@QAEXABUString@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" int (__cdecl *fprintf)(void *, const char *, ...);

struct String {
    unsigned allocator;
    union {
        char buffer[16];
        char *pointer;
    };
    unsigned length;
    unsigned capacity;
};

struct Shader {
    unsigned reserved;
    void *file;
    void write(const String &text);
};

void Shader::write(const String &text)
{
    if (file) {
        int (__cdecl *print)(void *, const char *, ...) = fprintf;
        print(file, "_____________________________________________________\n");
        print(file, "\n    ###    %s    ###\n\n",
              text.capacity >= 16 ? text.pointer : text.buffer);
    }
}