// from server: 77% by colin
// roc 2007-08 00758eb0  unit: seg_00750000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00758eb0

extern "C" int __cdecl sub_630af7(void*, int, int, void*);

struct S {
    char pad[0xd4];
    void f();
};

void S::f() {
    sub_630af7((char*)this - 0xd4, 0x1c, 6, *(void**)0x77e6ac);
}
