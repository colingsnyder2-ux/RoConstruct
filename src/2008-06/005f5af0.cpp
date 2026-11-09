// from server: 100% by colin




struct S {
    void f(int);
    void g();
};

void S::f(int a) {
    if (a == 1) {
        if (!(*(unsigned char*)((char*)this + 0xb0) & 2)) {
            *(int*)(*(int*)((char*)this + 0x10)) = 0;
            *(int*)(*(int*)((char*)this + 0x20)) = 0;
            *(int*)(*(int*)((char*)this + 0x30)) = 0;
            *(unsigned int*)((char*)this + 0xb0) |= 2;
        }
    } else if (a == 2) {
        if (!(*(unsigned char*)((char*)this + 0xb0) & 4)) {
            (*(void(**)(void))(*(int*)this + 0x30))();
            *(int*)(*(int*)((char*)this + 0x14)) = 0;
            *(int*)(*(int*)((char*)this + 0x24)) = 0;
            *(int*)(*(int*)((char*)this + 0x34)) = 0;
            *(unsigned int*)((char*)this + 0xb0) |= 4;
        }
    }
}
