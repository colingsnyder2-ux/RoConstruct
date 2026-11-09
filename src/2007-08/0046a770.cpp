// from server: 22% by colin
struct LDraw2RobloxMapRoot {
    void assign_range(void* first, void* last, void* dest);
};

void LDraw2RobloxMapRoot::assign_range(void* first, void* last, void* dest) {
    char* f = (char*)first;
    char* l = (char*)last;
    char* d = (char*)dest;
    while (f != l) {
        if (d != 0) {
            ((void (__thiscall*)(void*, void*))0x46a600)(d, f);
        }
        d += 0x40;
        f += 0x40;
    }
}
