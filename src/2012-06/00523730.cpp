// from server: 100% by Xemicl
// roc 2012-06 00523730  unit: RBX::Network::Player::W4ChatMode::?$EnumDesc  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00523730
//
// 00523730  6aff                 push -1
// 00523732  68c8b3aa00           push 0xaab3c8
// 00523737  64a100000000         mov eax, dword ptr fs:[0]
// 0052373d  50                   push eax
// 0052373e  64892500000000       mov dword ptr fs:[0], esp
// 00523745  51                   push ecx
// 00523746  53                   push ebx
// 00523747  56                   push esi
// 00523748  8bf1                 mov esi, ecx
// 0052374a  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0052374e  33c0                 xor eax, eax
// 00523750  89442414             mov dword ptr [esp + 0x14], eax
// 00523754  88442408             mov byte ptr [esp + 8], al
// 00523758  8b442408             mov eax, dword ptr [esp + 8]
// 0052375c  50                   push eax
// 0052375d  51                   push ecx
// 0052375e  83ec30               sub esp, 0x30
// 00523761  8d542454             lea edx, [esp + 0x54]
// 00523765  8bcc                 mov ecx, esp
// 00523767  89a42484000000       mov dword ptr [esp + 0x84], esp
// 0052376e  52                   push edx
// 0052376f  e83ce1ffff           call 0x5218b0
// 00523774  8bce                 mov ecx, esi
// 00523776  e8a5f4ffff           call 0x522c20
// 0052377b  8d4c2420             lea ecx, [esp + 0x20]
// 0052377f  8ad8                 mov bl, al
// 00523781  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00523789  e8c2a3ffff           call 0x51db50
// 0052378e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00523792  5e                   pop esi
// 00523793  8ac3                 mov al, bl
// 00523795  64890d00000000       mov dword ptr fs:[0], ecx
// 0052379c  5b                   pop ebx
// 0052379d  83c410               add esp, 0x10
// 005237a0  c23400               ret 0x34
// copied from an identical function in another client (function ?process@Dispatcher@@QAE_NURequest@@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct WeakRef { void* px; void* pn; };
struct RequestTarget {
    std::string name;
    WeakRef a;
    WeakRef b;
    ~RequestTarget();
};
struct Request {
    int kind;
    RequestTarget target;
    Request(const Request&);
};
struct Flag { bool value; Flag(bool v) : value(v) {} };
class Dispatcher {
public:
    bool process(Request r, int x, Flag f);
    bool process(Request r, int x);
};
bool Dispatcher::process(Request r, int x)
{
    return process(r, x, Flag(false));
}