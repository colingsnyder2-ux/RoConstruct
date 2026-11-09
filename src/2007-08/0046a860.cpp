// from server: 26% by colin
struct LDraw2RobloxMapRoot {
    void __cdecl constructRange(void* first, unsigned int count, void* arg);
};

void LDraw2RobloxMapRoot::constructRange(void* first, unsigned int count, void* arg)
{
    char* p = (char*)first;
    unsigned int i = count;
    while (i > 0) {
        if (p != 0) {
            ((LDraw2RobloxMapRoot*)p)->constructRange(arg, 0, 0);
        }
        i--;
        p += 0x40;
    }
}
