// from server: 24% by colin
struct DxUserInput {
    char pad[0x34];
    int field34;
    char pad2[0x17c - 0x38];
    int field17c;
    bool check(int);
};

extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void __cdecl sub_41D870(void*);
extern "C" int __cdecl sub_465860(int);

bool DxUserInput::check(int arg) {
    void* local8;
    char localC;
    local8 = &this->field34;
    localC = 0;
    sub_41D870(&local8);
    int v = this->field17c;
    if (v != 0 && arg == v) {
        if (localC != 0) {
            LeaveCriticalSection(local8);
        }
        return true;
    }
    int r = sub_465860(arg);
    if ((*(unsigned char*)((char*)this + r + 0x7b) & 0x80) != 0) {
        if (localC != 0) {
            LeaveCriticalSection(local8);
        }
        return true;
    }
    if (localC != 0) {
        LeaveCriticalSection(local8);
    }
    return false;
}
