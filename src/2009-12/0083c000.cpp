// from server: 92% by sophus
// roc 2009-12 0083bfc0  unit: CXTPAccessible  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083bfc0
//
// 0083bfc0  83791002             cmp dword ptr [ecx + 0x10], 2
// 0083bfc4  7513                 jne 0x83bfd9
// 0083bfc6  6a00                 push 0
// 0083bfc8  6a04                 push 4
// 0083bfca  e801f8ffff           call 0x83b7d0
// 0083bfcf  84c0                 test al, al
// 0083bfd1  7406                 je 0x83bfd9
// 0083bfd3  b801000000           mov eax, 1
// 0083bfd8  c3                   ret 
// 0083bfd9  33c0                 xor eax, eax
// 0083bfdb  c3                   ret 
// copied from an identical function in another client (function ?isHighlighted@CPropertyGridItemBrickColor@ns_ROCX000000@@QAE_NXZ)

namespace ns_ROCX000000 {
struct CPropertyGridItemBrickColor {
    char gap[0x10];
    int m_state;
    bool checkFlag(int, int);
    bool isHighlighted();
};

bool CPropertyGridItemBrickColor::isHighlighted() {
    return m_state == 2 && checkFlag(4, 0);
}
}
