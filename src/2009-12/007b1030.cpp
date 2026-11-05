// from server: 74% by atomic.potato
struct Body {
    char pad0[4];
    void* field4;
    char pad8[0x28];
    void* field30;
    void* field34;
    void method();
};

void sub_7b0ff0();

void Body::method() {
    if (field30 != 0 && *(char*)((char*)field30 + 4) != 0)
        return;
    if (field4 != 0) {
        sub_7b0ff0();
    } else if (field34 != 0) {
        *(char*)((char*)field34 + 8) = 1;
    }
    if (field30 != 0)
        *(char*)((char*)field30 + 4) = 1;
}
