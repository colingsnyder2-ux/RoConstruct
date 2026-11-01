// from server: 30% by atomic.potato
extern "C" int __cdecl sub_7f41f0();
extern "C" int __cdecl sub_84b2d0();
extern "C" int __cdecl sub_8c04b0();
extern "C" int __cdecl sub_82f9d0();
extern "C" int __cdecl sub_82f100(int, int);
extern "C" int __cdecl sub_7f45fe(void*, void*, int);
extern "C" int __cdecl sub_7f41ea(void*);
extern "C" int __cdecl sub_7f539a();

struct CXTPShadowsManager_CShadowWnd {
    void func();
};

void CXTPShadowsManager_CShadowWnd::func()
{
    char buf1[0x18];
    char buf2[0x18];
    char buf3[0x18];
    int saved;
    int cookie;
    int val;

    sub_7f41f0();
    sub_84b2d0();
    val = sub_8c04b0();
    if (*(int*)(val + 0x20) == 0) {
        val = sub_82f9d0();
        sub_82f100(val, 0x10);
    }
    sub_7f45fe(buf3, buf2, val);
    sub_7f41ea(buf1);
    sub_7f539a();
}
