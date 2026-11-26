// from server: 100% by Xemicl
// roc 2012-06 00479dd0  unit: CRobloxDHtmlDialog  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00479dd0
//
// 00479dd0  64a100000000         mov eax, dword ptr fs:[0]
// 00479dd6  6aff                 push -1
// 00479dd8  68990eaa00           push 0xaa0e99
// 00479ddd  50                   push eax
// 00479dde  64892500000000       mov dword ptr fs:[0], esp
// 00479de5  8b442414             mov eax, dword ptr [esp + 0x14]
// 00479de9  56                   push esi
// 00479dea  8bf1                 mov esi, ecx
// 00479dec  8d4c2418             lea ecx, [esp + 0x18]
// 00479df0  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 00479df6  ff158447b200         call dword ptr [0xb24784]
// 00479dfc  6a01                 push 1
// 00479dfe  8d4c241c             lea ecx, [esp + 0x1c]
// 00479e02  51                   push ecx
// 00479e03  68ed130180           push 0x800113ed
// 00479e08  6890b7b500           push 0xb5b790
// 00479e0d  8bce                 mov ecx, esi
// 00479e0f  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00479e17  e8cc905000           call 0x982ee8
// 00479e1c  68e83bb400           push 0xb43be8
// 00479e21  8d4c241c             lea ecx, [esp + 0x1c]
// 00479e25  ff159c47b200         call dword ptr [0xb2479c]
// 00479e2b  85c0                 test eax, eax
// 00479e2d  7423                 je 0x479e52
// 00479e2f  8d4c2418             lea ecx, [esp + 0x18]
// 00479e33  ff159847b200         call dword ptr [0xb24798]
// 00479e39  50                   push eax
// 00479e3a  ff15d42ab200         call dword ptr [0xb22ad4]
// 00479e40  83c404               add esp, 4
// 00479e43  83f801               cmp eax, 1
// 00479e46  750a                 jne 0x479e52
// 00479e48  8b16                 mov edx, dword ptr [esi]
// 00479e4a  8b8260010000         mov eax, dword ptr [edx + 0x160]
// 00479e50  eb08                 jmp 0x479e5a
// 00479e52  8b16                 mov edx, dword ptr [esi]
// 00479e54  8b8264010000         mov eax, dword ptr [edx + 0x164]
// 00479e5a  8bce                 mov ecx, esi
// 00479e5c  ffd0                 call eax
// 00479e5e  8d4c2418             lea ecx, [esp + 0x18]
// 00479e62  ff15d047b200         call dword ptr [0xb247d0]
// 00479e68  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00479e6c  64890d00000000       mov dword ptr fs:[0], ecx
// 00479e73  5e                   pop esi
// 00479e74  83c40c               add esp, 0xc
// 00479e77  c20800               ret 8
// copied from an identical function in another client (function ?handle@Dialog@ns_ROCX000008@@QAEXPAXPAJ@Z)

namespace ns_ROCX000008 {
struct String;

typedef void (__thiscall *StringInit)(String*);
typedef void (__thiscall *StringDestroy)(String*);
typedef int (__thiscall *StringCompare)(const String*, const char*);
typedef const char* (__thiscall *StringData)(const String*);
typedef int (__cdecl *Atoi)(const char*);

extern StringInit stringInit;
extern StringDestroy stringDestroy;
extern StringCompare stringCompare;
extern StringData stringData;
extern Atoi atoi;
extern char propertyName[];
extern char emptyText[];

struct String
{
    void* data;
    String();
    __declspec(dllimport) void __thiscall destroyImport() throw();
    __declspec(nothrow) ~String();
    int compare(const char*) const;
    const char* text() const;
};

__forceinline String::String()
{
    stringInit(this);
}

__declspec(nothrow) __forceinline String::~String()
{
    this->destroyImport();
}

__forceinline int String::compare(const char* value) const
{
    return stringCompare(this, value);
}

__forceinline const char* String::text() const
{
    return stringData(this);
}

struct Dialog;
typedef void (__thiscall *DialogAction)(Dialog*);

struct DialogTable
{
    DialogAction preceding[88];
    DialogAction accept;
    DialogAction cancel;
};

struct Dialog
{
    DialogTable* table;
    void getProperty(const char*, unsigned long, String*, int);
    void handle(void*, long*);
};

void Dialog::handle(void*, long* result)
{
    *result = -1;
    String value;
    getProperty(propertyName, 0x800113EDUL, &value, 1);

    if (value.compare(emptyText) && atoi(value.text()) == 1)
        table->accept(this);
    else
        table->cancel(this);
}
}