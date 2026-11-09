// from server: 27% by colin
struct Listener {
    char pad[0x34];
    int field34;
    char pad2[0x40];
    char field78;
    void sub_463a00();
    Listener(char);
};

extern "C" void __stdcall sub_41d870(int*);
extern "C" void __stdcall LeaveCriticalSection(void*);

Listener::Listener(char arg) {
    int local8;
    char localc;
    local8 = (int)&field34;
    localc = 0;
    sub_41d870(&local8);
    field78 = arg;
    sub_463a00();
    if (localc) {
        LeaveCriticalSection((void*)local8);
    }
}
