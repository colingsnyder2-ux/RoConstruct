// from server: 47% by atomic.potato
struct Inner {
    char pad[0x1c];
    int field1c;
};

struct Outer {
    char pad[0x1c];
    int field1c;
};

struct S {
    char pad[0xc];
    int off_c;
    int off_8;
    Outer* f(int* a, int* b);
};

extern "C" void __stdcall string_copy_ctor(void* dst, const void* src);

Outer* S::f(int* a, int* b) {
    Inner* p = (Inner*)a;
    if (p != 0) {
        p = (Inner*)((char*)p - 0x1c);
    }
    int (*fn)(int) = (int (*)(int))*(void**)((char*)this + 8);
    int arg = *(int*)((char*)this + 0xc) + (int)p;
    int result = fn(arg);
    Outer* out = (Outer*)b;
    string_copy_ctor(out, (void*)result);
    out->field1c = *(int*)(result + 0x1c);
    return out;
}
