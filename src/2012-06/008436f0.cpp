// from server: 25% by Intel
struct std_string {
    char _buf[16];
    int _len;
    int _cap;
    char _small[16];
};

extern "C" void __stdcall __CxxFrameHandler3();
extern "C" void __cdecl sub_745620(void* dst, const void* src);
extern "C" void __cdecl sub_8320f0(const char* str, int len, int arg);

struct VWaitScriptSlot {
    int func();
};

int VWaitScriptSlot::func() {
    int v20;
    std_string s;
    int v24 = 0;

    sub_745620(&s, (void*)(v20 + 4));

    const char* str = (s._len >= 16) ? *(const char**)&s._buf[0] : &s._small[0];
    int len = s._len;

    sub_8320f0(str, len, v20);

    v24 = -1;
    s.~std_string();

    return 1;
}
