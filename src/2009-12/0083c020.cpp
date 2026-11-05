// from server: 100% by colin
// roc 2009-12 0083c020  unit: CXTPAccessible  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c020
//
// 0083c020  83791002             cmp dword ptr [ecx + 0x10], 2
// 0083c024  7213                 jb 0x83c039
// 0083c026  6a01                 push 1
// 0083c028  6a05                 push 5
// 0083c02a  e871f7ffff           call 0x83b7a0
// 0083c02f  84c0                 test al, al
// 0083c031  7406                 je 0x83c039
// 0083c033  b801000000           mov eax, 1
// 0083c038  c3                   ret 
// 0083c039  33c0                 xor eax, eax
// 0083c03b  c3                   ret 
// copied from an identical function in another client (function ?method@CPropertyGridItemBrickColor@ns_ROCX000003@@QAEHXZ)

namespace ns_ROCX000003 {
struct CPropertyGridItemBrickColor {
    char pad[0x10];
    unsigned int count;
    bool sub_6711C0(int, int);
    int method();
};

int CPropertyGridItemBrickColor::method() {
    if (count >= 2) {
        if (sub_6711C0(5, 1))
            return 1;
    }
    return 0;
}
}
