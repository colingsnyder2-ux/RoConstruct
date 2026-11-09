// from server: 50% by atomic.potato
struct S {
    char pad0[0x1c];
    char c1c;
};

struct Str {
    char pad[0x1c];
};

extern "C" void __stdcall sub_9ea40c();
extern "C" void __stdcall sub_9ea400();
extern "C" void* __fastcall sub_4e8010(void* self, void* arg);

void __fastcall f(S* self, void* arg1, void* arg2, void* arg3, void* arg4)
{
    char buf[0x34];
    *(int*)(buf + 0x2c) = 1;
    sub_9ea40c();
    void* p = sub_4e8010(buf + 0x24, arg4);
    S* src = (S*)p;
    char* dst = (char*)arg2;
    *(int*)dst = *(int*)arg3;
    char* dst2 = dst + 4;
    sub_9ea40c();
    dst2[0x1c] = src->c1c;
    sub_9ea400();
    *(int*)(buf + 0x0c) = 1;
    *(char*)(buf + 0x2c) = 1;
    sub_9ea400();
    *(char*)(buf + 0x2c) = 0;
}
