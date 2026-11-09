// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2008-06 00429b50  unit: ThreadLogManager  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00429b50
//
// 00429b50  8b442410             mov eax, dword ptr [esp + 0x10]
// 00429b54  83ec08               sub esp, 8
// 00429b57  85c0                 test eax, eax
// 00429b59  7404                 je 0x429b5f
// 00429b5b  8b00                 mov eax, dword ptr [eax]
// 00429b5d  eb02                 jmp 0x429b61
// 00429b5f  33c0                 xor eax, eax
// 00429b61  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00429b65  56                   push esi
// 00429b66  8b30                 mov esi, dword ptr [eax]
// 00429b68  8b442414             mov eax, dword ptr [esp + 0x14]
// 00429b6c  85c0                 test eax, eax
// 00429b6e  7404                 je 0x429b74
// 00429b70  8b08                 mov ecx, dword ptr [eax]
// 00429b72  eb02                 jmp 0x429b76
// 00429b74  33c9                 xor ecx, ecx
// 00429b76  8b442418             mov eax, dword ptr [esp + 0x18]
// 00429b7a  8b09                 mov ecx, dword ptr [ecx]
// 00429b7c  57                   push edi
// 00429b7d  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00429b81  57                   push edi
// 00429b82  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00429b86  57                   push edi
// 00429b87  52                   push edx
// 00429b88  56                   push esi
// 00429b89  50                   push eax
// 00429b8a  51                   push ecx
// 00429b8b  8d442420             lea eax, [esp + 0x20]
// 00429b8f  50                   push eax
// 00429b90  e8abf3ffff           call 0x428f40
// 00429b95  8b08                 mov ecx, dword ptr [eax]
// 00429b97  8b7004               mov esi, dword ptr [eax + 4]
// 00429b9a  83c41c               add esp, 0x1c
// 00429b9d  5f                   pop edi
// 00429b9e  394c2414             cmp dword ptr [esp + 0x14], ecx
// 00429ba2  7406                 je 0x429baa
// 00429ba4  ff1590288000         call dword ptr [0x802890]
// 00429baa  8b442410             mov eax, dword ptr [esp + 0x10]
// 00429bae  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00429bb2  897004               mov dword ptr [eax + 4], esi
// 00429bb5  8908                 mov dword ptr [eax], ecx
// 00429bb7  5e                   pop esi
// 00429bb8  83c408               add esp, 8
// 00429bbb  c3                   ret 
// copied from an identical function in another client (function ??$find_if@V?$_Iterator@$00@?$list@UEntry@@V?$allocator@UEntry@@@std@@@std@@UAfter@@@std@@YA?AV?$_Iterator@$00@?$list@UEntry@@V?$allocator@UEntry@@@std@@@0@V120@0UAfter@@@Z)

// from server: 100% by EspClaude
#include <list>
#include <algorithm>
struct Time {
    unsigned long low;
    unsigned long high;
    unsigned __int64 value() const { return low | ((unsigned __int64)high << 32); }
};
inline bool operator<(Time a, Time b) { return a.value() < b.value(); }
struct Entry {
    unsigned long tag;
    Time time;
    unsigned long padding[75];
    double alignment;
};
struct After {
    Time limit;
    bool operator()(Entry e) const { return limit < e.time; }
};
std::list<Entry>::iterator findBoundary(std::list<Entry>& l, Time limit)
{
    After a; a.limit = limit;
    return std::find_if(l.begin(), l.end(), a);
}