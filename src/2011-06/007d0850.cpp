// from server: 62% by atomic.potato
struct ChatOutput {
    char pad0[0xa4];
    void* field_a4;
    void f(int);
};

extern "C" void __stdcall sub_7d0140(int, int);
extern "C" void __stdcall sub_7cf0e0(int, int);

void ChatOutput::f(int arg) {
    char flag;
    void* p = field_a4;
    if (p != 0) {
        int v = *(int*)((char*)p + 0x1ec);
        if (v == 1 || v == 2)
            flag = 1;
        else
            flag = 0;
    } else {
        flag = 0;
    }
    sub_7d0140(arg, (int)flag);

    p = field_a4;
    char b;
    if (p != 0) {
        int v = *(int*)((char*)p + 0x1ec);
        if (v != 0 && v != 2)
            b = 0;
        else
            b = 1;
    } else {
        b = 1;
    }
    sub_7cf0e0(arg, (int)(b == 0));
}
