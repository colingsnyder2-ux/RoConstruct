// from server: 100% by colin
// roc 2007-08 005a31c0  unit: RBX::Teams  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a31c0
//
// 005a31c0  8b442404             mov eax, dword ptr [esp + 4]
// 005a31c4  80b82401000000       cmp byte ptr [eax + 0x124], 0
// 005a31cb  7405                 je 0x5a31d2
// 005a31cd  33c0                 xor eax, eax
// 005a31cf  c20400               ret 4
// 005a31d2  8b8020010000         mov eax, dword ptr [eax + 0x120]
// 005a31d8  89442404             mov dword ptr [esp + 4], eax
// 005a31dc  e94fffffff           jmp 0x5a3130

struct Teams {
    char pad[0x120];
    int field120;
    char field124;
};

int __stdcall getTeamFromPlayer(Teams* p);

int __stdcall tail(int);

int __stdcall getTeamFromPlayer(Teams* p)
{
    if (p->field124 != 0)
        return 0;
    return tail(p->field120);
}
