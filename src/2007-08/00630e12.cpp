// from server: 19% by colin
extern "C" {
    int __stdcall GetStartupInfoA(void*);
    long __stdcall InterlockedCompareExchange(long volatile*, long, long);
    long __stdcall InterlockedExchange(long volatile*, long);
    void __stdcall Sleep(unsigned long);
    void __cdecl __getmainargs(int*, char***, char***, int, void*);
    char** __cdecl _acmdln(void);
    int __cdecl _ismbblead(unsigned int);
    void __cdecl exit(int);
}

extern "C" void __cdecl sub_63174a(int);
extern "C" int __cdecl sub_631884(const char*, const char*);
extern "C" int __cdecl sub_63187e(const char*, const char*);
extern "C" int __cdecl sub_631812(void*);
extern "C" void __cdecl sub_631620(void);
extern "C" void __cdecl sub_630d23(void);
extern "C" int __cdecl sub_738d66(const char*, int, int, int, int);

extern char byte_8C8354;
extern char byte_8C8344;
extern char byte_8C8348;
extern char byte_8C8340;
extern int dword_8C8350;
extern int dword_8C8358;
extern int dword_8C835C;
extern int dword_8C9BF0;
extern int dword_8C9BFC;
extern char byte_8C9BF4;
extern int dword_8C8694;
extern int dword_8C8698;

struct S {
    void f();
};

void S::f() {
    sub_630d23();
    int eax = dword_8C8698;
    *(int*)&byte_8C8354 = eax;
    InterlockedExchange((long volatile*)&byte_8C8354, (long)&byte_8C8354);
    GetStartupInfoA(&byte_8C8340);
    dword_8C8350 = 0;
    if (dword_8C8350 >= 0) {
        sub_63174a(8);
    }
}
