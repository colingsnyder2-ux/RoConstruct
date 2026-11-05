// from server: 36% by atomic.potato
extern "C" void* __cdecl sub_7F3860(unsigned int);

struct VHumanoidController {
    void* __cdecl sub_464F00(void* a);
};

struct AllocObj {
    void init();
};

void AllocObj::init() {}

void* VHumanoidController::sub_464F00(void* a)
{
    AllocObj* p = (AllocObj*)sub_7F3860(0xa8);
    if (p) {
        p->init();
    } else {
        p = 0;
    }
    ((void (__thiscall*)(void*, void*, void*))0x464E50)(this, p, a);
    return this;
}
