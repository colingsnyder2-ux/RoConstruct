// from server: 55% by colin
// roc 2007-08 006de2b0  unit: CXTPDockingPaneWindowSelect  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006de2b0

extern "C" int __stdcall UnhookWindowsHookEx(void*);

struct Inner {
    int get();
    void set(int);
};

struct S {
    char pad0[4];
    void* field4;
    char pad8[8];
    int field14;
    char pad18[0xb4];
    void* fieldCC;
    int method(void* a, int b);
};

int S::method(void* a, int b) {
    Inner* p;
    int r;
    if (a != 0) {
        void* q = this->fieldCC;
        if (q != 0) {
            q = *(void**)((char*)q + 0x20);
        }
        p = (Inner*)((char*)this + 8);
        p->set((int)q);
    }
    if (this->field4 != 0 && this->field14 == 0) {
        UnhookWindowsHookEx(this->field4);
        this->field4 = 0;
    }
    return r;
}
