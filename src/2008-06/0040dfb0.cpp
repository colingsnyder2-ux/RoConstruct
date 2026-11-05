// from server: 100% by colin
// roc 2008-06 0040dfb0  unit: CBrowserView  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040dfb0

extern "C" int __stdcall sub_6a0a34(void*);

struct CBrowserView {
    void sub_40dfb0(void* p);
};

void CBrowserView::sub_40dfb0(void* p) {
    if (sub_6a0a34(p) == 0) {
        *(unsigned int*)((char*)p + 4) |= 0x1844016;
    }
}
