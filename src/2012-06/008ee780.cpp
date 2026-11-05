// from server: 58% by tester
struct S {
    char pad0[0x80];
    int state;
    char pad1[0x88 - 0x84];
    int field88;
    int field8c;
    char pad2[0x9c - 0x90];
    void* field9c;
    char pad3[0xa4 - 0xa0];
    int fielda4;
    void method();
};

extern "C" void* __stdcall sub_443530();
extern "C" void __stdcall sub_82f4f0(void*);
extern "C" void __stdcall sub_82edd0(void*);
extern "C" void __stdcall sub_955520(void*);
extern "C" void __stdcall sub_982114(void*);
extern "C" void __stdcall sub_972290(int, const char*);
extern "C" void __stdcall sub_40c0a0(void*, void*);
extern "C" void __stdcall sub_983144(void*, void*);
extern "C" void* __stdcall sub_b22648(const char*);

extern unsigned char byte_e580b3;
extern void* ptr_e5809c;

void S::method() {
    void* p = sub_443530();
    *(unsigned char*)((char*)p + 0x95) = 1;

    if (state != 2) {
        sub_82f4f0(&fielda4);
        sub_82edd0(&fielda4);
        if (field9c) {
            sub_955520(field9c);
            sub_982114(field9c);
        }
        field9c = 0;
        state = 3;
    } else if (state == 1) {
        state = 4;
    } else {
        char buf[0x20];
        sub_b22648("jointsIMade.size() == 0");
        sub_40c0a0(buf, 0);
        sub_983144(buf, "jointsIMade.size() == 0 file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\tool\\LuaDragger.cpp line: 151");
        return;
    }

    if (byte_e580b3) {
        if ((field8c - field88) & 0xfffffff8) {
            if (ptr_e5809c) {
                if (!((unsigned char (__stdcall*)(int, const char*, const char*))ptr_e5809c)(0x97, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\tool\\LuaDragger.cpp", "jointsIMade.size() == 0")) {
                    sub_972290(byte_e580b3, "Call to LuaDragger::mouseUp without mouseDown");
                }
            } else {
                sub_972290(byte_e580b3, "Call to LuaDragger::mouseUp without mouseDown");
            }
        }
    }
}
