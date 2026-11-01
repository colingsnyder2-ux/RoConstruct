// from server: 100% by colin
struct ChatEnter {
    void sub_556900();
    void f(int, int);
};

void ChatEnter::f(int a, int b) {
    sub_556900();
    if (*(int*)((char*)this + 0xfc) == 3) {
        if (*(int*)b == 4) {
            *(int*)((char*)this + 0xfc) = 1;
            goto call_virtual;
        }
    } else {
        if (*(int*)b == 4) {
            *(int*)((char*)this + 0xfc) = 3;
        call_virtual:
            (*(void(__thiscall**)(ChatEnter*))(*(int*)this + 0x68))(this);
        }
    }
    *(int*)(a + 4) = 0;
    *(int*)a = 1;
}
