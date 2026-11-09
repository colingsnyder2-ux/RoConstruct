// from server: 42% by atomic.potato
struct X_006a7fa0 {
    char pad_0[0x10];
    void* f_10;
    void* f_14;
    void invoke(int a, unsigned char* b);
};

void X_006a7fa0::invoke(int a, unsigned char* b) {
    unsigned char v = *b;
    if (a != 0) {
        void* fn = f_10;
        void* ctx = f_14;
        int off = a - 0x1c;
        ((void (__thiscall*)(void*, int, unsigned char))fn)((char*)ctx + off, (int)v, v);
    } else {
        void* fn = f_10;
        void* ctx = f_14;
        ((void (__thiscall*)(void*, int, unsigned char))fn)(ctx, 0, v);
    }
}
