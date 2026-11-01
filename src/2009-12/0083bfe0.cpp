// from server: 100% by colin
// roc 2009-12 0083bfe0  unit: CXTPAccessible  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bfe0
//
// 0083bfe0  83791002             cmp dword ptr [ecx + 0x10], 2
// 0083bfe4  7513                 jne 0x83bff9
// 0083bfe6  6a00                 push 0
// 0083bfe8  6a05                 push 5
// 0083bfea  e8e1f7ffff           call 0x83b7d0
// 0083bfef  84c0                 test al, al
// 0083bff1  7406                 je 0x83bff9
// 0083bff3  b801000000           mov eax, 1
// 0083bff8  c3                   ret 
// 0083bff9  33c0                 xor eax, eax
// 0083bffb  c3                   ret 
// copied from an identical function in another client (function ?method@CPropertyGridItemBrickColor@ns_ROCX000001@@QAEHXZ)

namespace ns_ROCX000001 {
struct CPropertyGridItemBrickColor {
    char gap[0x10];
    int m_state;
    bool check(int, int);
    int method();
};

int CPropertyGridItemBrickColor::method() {
    if (m_state == 2) {
        if (check(5, 0)) {
            return 1;
        }
    }
    return 0;
}
}
