// from server: 100% by colin
struct BodyMover {
    void sub_005ef950(void*);
    void sub_005ef860();
};

extern "C" void __stdcall sub_00541960(void*);
extern "C" void* __cdecl sub_00630d36(void*, void*, void*, void*, void*);

void BodyMover::sub_005ef950(void* arg)
{
    sub_00541960(arg);
    if (*(void**)arg == this) {
        void* p = *(void**)((char*)arg + 8);
        void* r = sub_00630d36(p, 0, (void*)0x881f4c, (void*)0x884a28, 0);
        *(void**)((char*)this + 0xf8) = r;
    }
    sub_005ef860();
}
