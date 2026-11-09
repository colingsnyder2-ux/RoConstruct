// from server: 100% by colin
// roc 2010-06 005a0e60  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005a0e60
//
// 005a0e60  c60520bdc00000       mov byte ptr [0xc0bd20], 0
// 005a0e67  c3                   ret

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct StandardOut {
    static bool allowPrintWarnings;
    void resetAllowPrintWarnings();
};

bool StandardOut::allowPrintWarnings = false;

void StandardOut::resetAllowPrintWarnings() {
    allowPrintWarnings = false;
}
