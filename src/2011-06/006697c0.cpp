// from server: 15% by atomic.potato
struct C1 { char pad[8]; };
struct C2 { char pad[8]; };
struct C3 { char pad[8]; };
struct C4 { char pad[8]; };
struct C5 { char pad[8]; };
struct C6 { char pad[8]; };

extern "C" void __stdcall sub_80b15d(void*);
extern "C" void __fastcall sub_40b300(void*, void*, void*);
extern "C" void __fastcall sub_410900(void*, void*);
extern "C" void __fastcall sub_40ac80(void*);
extern "C" void __fastcall sub_6b6f40(void*, void*);
extern "C" void __fastcall sub_40ddc0(void*);

struct Controller {
    void func();
};

void Controller::func() {
    if (*(unsigned char*)0xccdd18 & 1) {
        *(unsigned int*)0xccdd18 |= 1;
        sub_80b15d((void*)0xa3aed0);
        *(unsigned int*)0xccdd10 = 0;
        *(unsigned int*)0xccdd14 = 0;
    }
    char buf1[8];
    char buf2[8];
    char buf3[8];
    *(void**)buf3 = (void*)0xccdd10;
    sub_40b300(buf3, buf1, buf2);
    sub_410900((void*)0xccdd10, buf3);
    char buf4[8];
    sub_6b6f40(buf4, 0);
    int i = 10;
    void* p = *(void**)buf4;
    while (p) {
        *(void**)((char*)p + 0x10) = 0;
        if (--i == 0) break;
        p = (char*)p + 0xc;
        sub_6b6f40(buf4, p);
        p = *(void**)buf4;
    }
    sub_40ac80(buf4);
    sub_6b6f40(buf4, 0);
    if (p) {
        sub_40ddc0((char*)p + 5);
    }
    if (*(void**)0 == 0) {
        void* q = *(void**)0;
        if (q) {
            sub_40ddc0((char*)q + 5);
        }
    }
}
