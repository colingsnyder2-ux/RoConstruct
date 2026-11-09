// from server: 35% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub1 {
    void sub_664370();
    void sub_41af50();
};

struct Sub2 {
    void sub_6b62f0();
};

struct Sub3 {
    void sub_66aea0();
};

struct Sub4 {
    void sub_637b00();
};

struct Obj {
    char pad0[0xd0];
    char* ref;
    char pad1[0x0c];
    Sub2 sub_e0;
    char pad2[0x20];
    Sub2 sub_100;
    char pad3[0x24];
    Sub1 sub_124;
    void destroy();
};

void Obj::destroy()
{
    *(int*)((char*)this + 0) = 0x9d5eac;
    *(int*)((char*)this + 4) = 0x9d5ea0;
    *(int*)((char*)this + 0x18) = 0x9d5e94;
    *(int*)((char*)this + 0x1c) = 0x9d5e8c;

    sub_124.sub_664370();
    sub_124.sub_41af50();
    sub_100.sub_6b62f0();
    sub_e0.sub_6b62f0();

    char* p = ref;
    if (p != 0) {
        if (_InterlockedExchangeAdd((volatile long*)(p + 4), -1) == 1) {
            (*(void(**)(char*))p)(p);
            if (_InterlockedExchangeAdd((volatile long*)(p + 8), -1) == 1) {
                (*(void(**)(char*))(*(int*)p + 8))(p);
            }
        }
    }

    ((Sub3*)((char*)this + 0xa0))->sub_66aea0();

    *(int*)((char*)this + 0) = 0x9d5b6c;
    *(int*)((char*)this + 4) = 0x9d5b64;
    *(int*)((char*)this + 0x18) = 0x9d5b58;
    *(int*)((char*)this + 0x1c) = 0x9d5b50;

    ((Sub4*)this)->sub_637b00();
}
