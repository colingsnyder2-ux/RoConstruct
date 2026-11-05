// from server: 100% by EspClaude
// roc 2009-06 0044d220  unit: CRobloxDHtmlDialog  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044d220
//
// 0044d220  64a100000000         mov eax, dword ptr fs:[0]
// 0044d226  6aff                 push -1
// 0044d228  68192e8500           push 0x852e19
// 0044d22d  50                   push eax
// 0044d22e  64892500000000       mov dword ptr fs:[0], esp
// 0044d235  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044d239  56                   push esi
// 0044d23a  8bf1                 mov esi, ecx
// 0044d23c  8d4c2418             lea ecx, [esp + 0x18]
// 0044d240  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 0044d246  ff15bcfc8900         call dword ptr [0x89fcbc]
// 0044d24c  6a01                 push 1
// 0044d24e  8d4c241c             lea ecx, [esp + 0x1c]
// 0044d252  51                   push ecx
// 0044d253  68ed130180           push 0x800113ed
// 0044d258  68307c8b00           push 0x8b7c30
// 0044d25d  8bce                 mov ecx, esi
// 0044d25f  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0044d267  e894c52c00           call 0x719800
// 0044d26c  6816d28a00           push 0x8ad216
// 0044d271  8d4c241c             lea ecx, [esp + 0x1c]
// 0044d275  ff15d4fc8900         call dword ptr [0x89fcd4]
// 0044d27b  85c0                 test eax, eax
// 0044d27d  7423                 je 0x44d2a2
// 0044d27f  8d4c2418             lea ecx, [esp + 0x18]
// 0044d283  ff15d0fc8900         call dword ptr [0x89fcd0]
// 0044d289  50                   push eax
// 0044d28a  ff1574e98900         call dword ptr [0x89e974]
// 0044d290  83c404               add esp, 4
// 0044d293  83f801               cmp eax, 1
// 0044d296  750a                 jne 0x44d2a2
// 0044d298  8b16                 mov edx, dword ptr [esi]
// 0044d29a  8b8260010000         mov eax, dword ptr [edx + 0x160]
// 0044d2a0  eb08                 jmp 0x44d2aa
// 0044d2a2  8b16                 mov edx, dword ptr [esi]
// 0044d2a4  8b8264010000         mov eax, dword ptr [edx + 0x164]
// 0044d2aa  8bce                 mov ecx, esi
// 0044d2ac  ffd0                 call eax
// 0044d2ae  8d4c2418             lea ecx, [esp + 0x18]
// 0044d2b2  ff1510fd8900         call dword ptr [0x89fd10]
// 0044d2b8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044d2bc  64890d00000000       mov dword ptr fs:[0], ecx
// 0044d2c3  5e                   pop esi
// 0044d2c4  83c40c               add esp, 0xc
// 0044d2c7  c20800               ret 8
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
