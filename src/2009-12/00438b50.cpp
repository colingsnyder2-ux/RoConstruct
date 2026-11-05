// from server: 71% by atomic.potato
struct VSoundId {
    char pad[0x12c];
    void* field_12c;
    void* method(void* a, void* b);
};

void* VSoundId::method(void* a, void* b) {
    void* p = 0;
    if (a) {
        p = (char*)a + 0x1c;
    } else {
        p = 0;
    }
    void* r = ((void* (__thiscall*)(void*, void*, void*))0x4422e0)(field_12c, b, p);
    return b;
}
