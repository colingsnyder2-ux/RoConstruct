// from server: 100% by colin
// roc 2007-08 0043f6e0  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043f6e0

extern "C" void __cdecl sub_62FC62(void*);

struct MVCXTPPropertyGridItem_XItem {
    void* Destroy(unsigned int flags);
    void sub_69A150();
};

void* MVCXTPPropertyGridItem_XItem::Destroy(unsigned int flags) {
    char* base;
    if (this != 0) {
        base = (char*)this + 0x100;
    } else {
        base = 0;
    }
    void* p = *(void**)(base + 8);
    if (p != 0) {
        sub_62FC62(p);
    }
    *(void**)(base + 8) = 0;
    *(void**)(base + 0xc) = 0;
    *(void**)(base + 0x10) = 0;
    this->sub_69A150();
    if (flags & 1) {
        sub_62FC62(this);
    }
    return this;
}
