// from server: 100% by EspClaude
// roc 2009-06 00448f30  unit: CRobloxCommandLineInfo  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00448f30
//
// 00448f30  83ec08               sub esp, 8
// 00448f33  8b542410             mov edx, dword ptr [esp + 0x10]
// 00448f37  56                   push esi
// 00448f38  8b742410             mov esi, dword ptr [esp + 0x10]
// 00448f3c  57                   push edi
// 00448f3d  51                   push ecx
// 00448f3e  b8b06c4400           mov eax, 0x446cb0
// 00448f43  50                   push eax
// 00448f44  8b442428             mov eax, dword ptr [esp + 0x28]
// 00448f48  50                   push eax
// 00448f49  52                   push edx
// 00448f4a  8954241c             mov dword ptr [esp + 0x1c], edx
// 00448f4e  e8fdf6ffff           call 0x448650
// 00448f53  83c410               add esp, 0x10
// 00448f56  8bf8                 mov edi, eax
// 00448f58  85f6                 test esi, esi
// 00448f5a  7406                 je 0x448f62
// 00448f5c  3b74241c             cmp esi, dword ptr [esp + 0x1c]
// 00448f60  7406                 je 0x448f68
// 00448f62  ff15ace98900         call dword ptr [0x89e9ac]
// 00448f68  33c0                 xor eax, eax
// 00448f6a  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 00448f6e  5f                   pop edi
// 00448f6f  0f94c0               sete al
// 00448f72  5e                   pop esi
// 00448f73  83c408               add esp, 8
// 00448f76  c21000               ret 0x10
// copied from an identical function in another client (function ?f@S@ns_ROCX00000c@@QAEHUIterator@2@0@Z)

namespace ns_ROCX00000c {
struct Iterator
{
    void* owner;
    void* position;
};

struct S
{
    bool predicate(void*, void*);
    int f(Iterator first, Iterator last);
};

struct Callback
{
    bool (S::*method)(void*, void*);
    S* object;
};

extern void* __cdecl search(void*, void*, Callback);
extern "C" void (__cdecl *_invalid_parameter_noinfo)();

int S::f(Iterator first, Iterator last)
{
    Callback callback = { &S::predicate, this };
    Iterator result = first;
    result.position = search(first.position, last.position, callback);

    if (!result.owner || result.owner != last.owner)
        _invalid_parameter_noinfo();

    return result.position == last.position;
}
}
