// from server: 100% by coldek
// roc 2008-06 00427310  unit: CSelectionTreeCtrl  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00427310
//
// 00427310  6aff                 push -1
// 00427312  6833ef7b00           push 0x7bef33
// 00427317  64a100000000         mov eax, dword ptr fs:[0]
// 0042731d  50                   push eax
// 0042731e  64892500000000       mov dword ptr fs:[0], esp
// 00427325  83ec08               sub esp, 8
// 00427328  56                   push esi
// 00427329  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0042732d  8d442408             lea eax, [esp + 8]
// 00427331  50                   push eax
// 00427332  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0042733a  c744240800000000     mov dword ptr [esp + 8], 0
// 00427342  e889edfdff           call 0x4060d0
// 00427347  83c404               add esp, 4
// 0042734a  8bc8                 mov ecx, eax
// 0042734c  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00427354  ff15e03e8000         call dword ptr [0x803ee0]
// 0042735a  50                   push eax
// 0042735b  8bce                 mov ecx, esi
// 0042735d  ff1558248000         call dword ptr [0x802458]
// 00427363  8d4c2408             lea ecx, [esp + 8]
// 00427367  c744240401000000     mov dword ptr [esp + 4], 1
// 0042736f  c644241400           mov byte ptr [esp + 0x14], 0
// 00427374  ff15143f8000         call dword ptr [0x803f14]
// 0042737a  68b0028100           push 0x8102b0
// 0042737f  8bce                 mov ecx, esi
// 00427381  ff1548248000         call dword ptr [0x802448]
// 00427387  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042738b  8bc6                 mov eax, esi
// 0042738d  5e                   pop esi
// 0042738e  64890d00000000       mov dword ptr fs:[0], ecx
// 00427395  83c414               add esp, 0x14
// 00427398  c3                   ret 

struct Temporary
{
    void *data;
    const char *text() const;
    ~Temporary();
};

typedef const char *(__thiscall *GetText)(const Temporary *);
typedef void (__thiscall *DestroyTemporary)(Temporary *);

extern GetText getText;
extern DestroyTemporary destroyTemporary;
extern Temporary __cdecl make_exception();

inline const char *Temporary::text() const
{
    return getText(this);
}

inline Temporary::~Temporary()
{
    destroyTemporary(this);
}

struct String
{
    unsigned char storage[28];
    String(const char *);
    ~String();
    String &append(const char *);
};

typedef void (__thiscall *ConstructString)(String *, const char *);
typedef String &(__thiscall *AppendString)(String *, const char *);

extern ConstructString constructString;
extern AppendString appendString;

inline String::String(const char *text)
{
    constructString(this, text);
}

inline String &String::append(const char *text)
{
    return appendString(this, text);
}

static String __cdecl func_00427310()
{
    String result(make_exception().text());
    result.append("/Game/KeepAlivePinger.ashx");
    return result;
}

String __cdecl keep_00427310() { return func_00427310(); }
