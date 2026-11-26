// from server: 100% by Xemicl
// roc 2012-06 00430b00  unit: CSelectionTreeCtrl  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00430b00
//
// 00430b00  6aff                 push -1
// 00430b02  6893c8a900           push 0xa9c893
// 00430b07  64a100000000         mov eax, dword ptr fs:[0]
// 00430b0d  50                   push eax
// 00430b0e  64892500000000       mov dword ptr fs:[0], esp
// 00430b15  83ec08               sub esp, 8
// 00430b18  56                   push esi
// 00430b19  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00430b1d  8d442408             lea eax, [esp + 8]
// 00430b21  50                   push eax
// 00430b22  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00430b2a  c744240800000000     mov dword ptr [esp + 8], 0
// 00430b32  e89947feff           call 0x4152d0
// 00430b37  83c404               add esp, 4
// 00430b3a  8bc8                 mov ecx, eax
// 00430b3c  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00430b44  ff159847b200         call dword ptr [0xb24798]
// 00430b4a  50                   push eax
// 00430b4b  8bce                 mov ecx, esi
// 00430b4d  ff154826b200         call dword ptr [0xb22648]
// 00430b53  8d4c2408             lea ecx, [esp + 8]
// 00430b57  c744240401000000     mov dword ptr [esp + 4], 1
// 00430b5f  c644241400           mov byte ptr [esp + 0x14], 0
// 00430b64  ff15d047b200         call dword ptr [0xb247d0]
// 00430b6a  6808f3b400           push 0xb4f308
// 00430b6f  8bce                 mov ecx, esi
// 00430b71  ff155c26b200         call dword ptr [0xb2265c]
// 00430b77  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00430b7b  8bc6                 mov eax, esi
// 00430b7d  5e                   pop esi
// 00430b7e  64890d00000000       mov dword ptr fs:[0], ecx
// 00430b85  83c414               add esp, 0x14
// 00430b88  c3                   ret 
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