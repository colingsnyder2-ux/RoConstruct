// from server: 100% by EspClaude
// roc 2009-06 00421f80  unit: CSelectionTreeCtrl  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00421f80
//
// 00421f80  6aff                 push -1
// 00421f82  68a3e78400           push 0x84e7a3
// 00421f87  64a100000000         mov eax, dword ptr fs:[0]
// 00421f8d  50                   push eax
// 00421f8e  64892500000000       mov dword ptr fs:[0], esp
// 00421f95  83ec08               sub esp, 8
// 00421f98  56                   push esi
// 00421f99  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00421f9d  8d442408             lea eax, [esp + 8]
// 00421fa1  50                   push eax
// 00421fa2  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00421faa  c744240800000000     mov dword ptr [esp + 8], 0
// 00421fb2  e83910feff           call 0x402ff0
// 00421fb7  83c404               add esp, 4
// 00421fba  8bc8                 mov ecx, eax
// 00421fbc  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00421fc4  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00421fca  50                   push eax
// 00421fcb  8bce                 mov ecx, esi
// 00421fcd  ff15b4e48900         call dword ptr [0x89e4b4]
// 00421fd3  8d4c2408             lea ecx, [esp + 8]
// 00421fd7  c744240401000000     mov dword ptr [esp + 4], 1
// 00421fdf  c644241400           mov byte ptr [esp + 0x14], 0
// 00421fe4  ff1510fd8900         call dword ptr [0x89fd10]
// 00421fea  68580a8b00           push 0x8b0a58
// 00421fef  8bce                 mov ecx, esi
// 00421ff1  ff15a4e48900         call dword ptr [0x89e4a4]
// 00421ff7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00421ffb  8bc6                 mov eax, esi
// 00421ffd  5e                   pop esi
// 00421ffe  64890d00000000       mov dword ptr fs:[0], ecx
// 00422005  83c414               add esp, 0x14
// 00422008  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00009b_00427310@ns_ROCX00009b@@YA?AUString@1@XZ)

namespace ns_ROCX00009b {
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

static String __cdecl fn_ROCX00009b_00427310()
{
    String result(make_exception().text());
    result.append("/Game/KeepAlivePinger.ashx");
    return result;
}

String __cdecl keep_00427310() { return fn_ROCX00009b_00427310(); }
}
