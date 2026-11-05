// from server: 23% by Intel
struct HumanoidController;

extern "C" void __cdecl sub_5C9FE8(int, const char*, int);
extern "C" void __stdcall sub_511180(void**);
extern "C" void __stdcall sub_793330(void*, void*);

struct HumanoidController {
    bool getNext(void** out);
    void process(void* arg);
};

bool HumanoidController::getNext(void** out) {
    return false;
}

void HumanoidController::process(void* arg) {
    void* local = 0;
    unsigned char flag = *reinterpret_cast<unsigned char*>(0xE580E1);
    if (flag != 0) {
        sub_5C9FE8(flag, reinterpret_cast<const char*>(0xB44EB8), 0);
    }
    while (true) {
        if (!getNext(&local)) {
            break;
        }
        sub_793330(arg, local);
    }
    sub_511180(&local);
}
