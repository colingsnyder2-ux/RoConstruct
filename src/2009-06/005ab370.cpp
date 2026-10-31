// from server: 100% by EspClaude
// roc 2009-06 005ab370  unit: RBX::Mesh  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ab370
//
// 005ab370  55                   push ebp
// 005ab371  8bec                 mov ebp, esp
// 005ab373  83ec08               sub esp, 8
// 005ab376  894dfc               mov dword ptr [ebp - 4], ecx
// 005ab379  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ab37c  83c10c               add ecx, 0xc
// 005ab37f  e8ac090000           call 0x5abd30
// 005ab384  83e801               sub eax, 1
// 005ab387  50                   push eax
// 005ab388  6a00                 push 0
// 005ab38a  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ab38d  83c10c               add ecx, 0xc
// 005ab390  e89b090000           call 0x5abd30
// 005ab395  8945f8               mov dword ptr [ebp - 8], eax
// 005ab398  db45f8               fild dword ptr [ebp - 8]
// 005ab39b  dc4d08               fmul qword ptr [ebp + 8]
// 005ab39e  e81deb1600           call 0x719ec0
// 005ab3a3  50                   push eax
// 005ab3a4  e8b7ebeeff           call 0x499f60
// 005ab3a9  83c40c               add esp, 0xc
// 005ab3ac  8be5                 mov esp, ebp
// 005ab3ae  5d                   pop ebp
// 005ab3af  c20800               ret 8
// copied from an identical function in another client (function ?index@Mesh@ns_ROCX000001@@QAEHN@Z)

namespace ns_ROCX000001 {
#pragma optimize("", off)

extern int __cdecl clampValue(int value, int minimum, int maximum);

struct Values {
    int size();
};

struct Mesh {
    char padding[12];
    Values values;
    int index(double fraction);
};

int Mesh::index(double fraction)
{
    return clampValue((int)(values.size() * fraction), 0, values.size() - 1);
}
}
