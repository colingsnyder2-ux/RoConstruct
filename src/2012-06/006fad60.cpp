// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub1 {
    char pad[0x14];
    int get();
};

struct Sub2 {
    char pad[0x94];
    int a;
    int b;
};

struct Sub3 {
    char pad[0x20];
    int val;
};

struct Inner {
    char pad[0x98];
};

struct Obj {
    char pad[0x14];
    Sub1 s1;
    char pad2[0x8];
    Sub3 s3;
};

extern "C" int __stdcall f8090(Sub1*);
extern "C" int __stdcall f419490(int);
extern "C" Sub2* __stdcall f94d0(Sub3*);

struct AttachCameraCommand {
    char pad[0x14];
    Sub1 s1;
    char pad2[0x8];
    Sub3 s3;
    bool execute();
};

bool AttachCameraCommand::execute() {
    int r = f419490(f8090(&s1));
    if (r <= 0) {
        return false;
    }
    Sub3 local;
    local.val = s3.val;
    int zero1 = 0;
    int zero2 = 0;
    Sub2* p = f94d0(&local);
    int diff = p->b - p->a;
    diff &= 0xfffffffc;
    bool flag = (diff == 4);
    int* ref = (int*)zero2;
    if (ref) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)ref + 4), -1) == 1) {
            void** vt = (void**)ref;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(ref);
            if (_InterlockedExchangeAdd((volatile long*)((char*)ref + 8), -1) == 1) {
                void** vt2 = (void**)ref;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(ref);
            }
        }
    }
    return flag;
}
