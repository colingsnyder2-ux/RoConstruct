// from server: 36% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall _mbscmp(const unsigned char*, const unsigned char*);
extern "C" int __cdecl _mbsnbcpy_s(char*, unsigned int, const char*, unsigned int);

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Str {
    char* data;
};

extern void func_00412d60(Str*);
extern void func_004135a0(Str*, int, int);
extern void func_00545160(void*);
extern void func_00547600(Str*, char*);
extern void func_0054c560(Str*);
extern Str* func_0054b860(Str*, Str*, int);
extern void func_00630b60();

extern unsigned int g_786f98;
extern void* g_77e6cc;
extern void* g_77e988;

struct S {
    char f();
};

char S::f()
{
    Str a;
    Str b;
    Str c;
    char buf[0x1254];
    char* p;
    int n;
    int flag;
    unsigned int v;

    func_00630b60();
    func_00412d60(&a);

    v = g_786f98;
    *(int*)(buf + 0x1248) = 2;
    *(int*)(buf + 0x124c) = 4;
    *(unsigned short*)(buf + 0x1246) = 0x50;

    _mbsnbcpy_s(buf, 0x21, (const char*)v, 4);
    func_00545160((void*)g_77e6cc);
    func_004135a0(&a, 0, 0);

    n = *(int*)(buf + 0x1238);
    if (n != 0) {
        if (n > 1 && n <= 3) {
            goto body;
        }
        return 0;
    }

body:
    func_00547600(&b, buf + 0x3d);
    func_0054c560(&c);

    {
        Str* r = func_0054b860(&c, &b, 0xa);
        flag = (_mbscmp((const unsigned char*)*(void**)r, (const unsigned char*)"roblox.com") != 0);
        {
            RefCounted* rc = (RefCounted*)((char*)*(void**)r - 0x10);
            long old = _InterlockedExchangeAdd(&rc->refcount, -1);
            if (old - 1 <= 0) {
                void** vt = (void**)rc->vptr;
                ((void (__thiscall*)(RefCounted*))vt[1])(rc);
            }
        }
    }

    if (!flag) {
        Str* r = func_0054b860(&c, &b, 0xc);
        flag = (_mbscmp((const unsigned char*)*(void**)r, (const unsigned char*)"robloxopolis.com") != 0);
        {
            RefCounted* rc = (RefCounted*)((char*)*(void**)r - 0x10);
            long old = _InterlockedExchangeAdd(&rc->refcount, -1);
            if (old - 1 <= 0) {
                void** vt = (void**)rc->vptr;
                ((void (__thiscall*)(RefCounted*))vt[1])(rc);
            }
        }
        if (!flag) {
            Str* r = func_0054b860(&c, &b, 0x10);
            flag = (_mbscmp((const unsigned char*)*(void**)r, (const unsigned char*)"gopher") == 0);
            {
                RefCounted* rc = (RefCounted*)((char*)*(void**)r - 0x10);
                long old = _InterlockedExchangeAdd(&rc->refcount, -1);
                if (old - 1 <= 0) {
                    void** vt = (void**)rc->vptr;
                    ((void (__thiscall*)(RefCounted*))vt[1])(rc);
                }
            }
            {
                RefCounted* rc = (RefCounted*)((char*)*(void**)&c - 0x10);
                long old = _InterlockedExchangeAdd(&rc->refcount, -1);
                if (flag) {
                    if (old - 1 <= 0) {
                        void** vt = (void**)rc->vptr;
                        ((void (__thiscall*)(RefCounted*))vt[1])(rc);
                    }
                    return 1;
                }
                if (old - 1 <= 0) {
                    void** vt = (void**)rc->vptr;
                    ((void (__thiscall*)(RefCounted*))vt[1])(rc);
                }
            }
            return 0;
        }
    }

    {
        RefCounted* rc = (RefCounted*)((char*)*(void**)&c - 0x10);
        long old = _InterlockedExchangeAdd(&rc->refcount, -1);
        if (old - 1 <= 0) {
            void** vt = (void**)rc->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(rc);
        }
    }
    return 1;
}
