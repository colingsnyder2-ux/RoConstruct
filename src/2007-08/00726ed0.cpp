// from server: 46% by colin
// roc 2007-08 00726ed0  unit: boost::thread_resource_error  size: 222 bytes

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long, void*);
extern "C" void __cdecl _invalid_parameter_noinfo();

void __cdecl sub_725520(void*, void*);
void __cdecl sub_725750(void*);
void __cdecl sub_725770(void*);
void __cdecl sub_408bc0(void*);
void __cdecl sub_77e6d8();
void __cdecl sub_726e20(void*, void*, void*);
void __cdecl sub_726e80(void*);
void __cdecl sub_62fc62(void*);

struct S {
    void f();
};

void S::f() {
    char buf[16];
    void* tls;
    void* p;

    sub_725520((void*)0x8c98fc, (void*)0x726c80);
    tls = *(void**)0x8c98f8;
    *(void**)(buf + 8) = tls;
    sub_725750(tls);
    if (*(int*)0x8bab84 == -1) {
        sub_725770(tls);
        return;
    }
    p = TlsGetValue(*(unsigned long*)0x8bab84);
    if (p == 0) {
        sub_725770(tls);
        return;
    }
    if (TlsSetValue(*(unsigned long*)0x8bab84, 0) == 0) {
        sub_725770(tls);
        return;
    }
    *(int*)0x8c9900 -= 1;
    sub_408bc0(buf + 12);
    while (*(int*)((char*)p + 8) != 0) {
        void* v = *(void**)((char*)p + 4);
        void* w = *(void**)v;
        if (w == v) {
            sub_77e6d8();
        }
        w = *(void**)((char*)w + 8);
        if (w != 0) {
            ((void (*)())w)();
        }
        void* x = *(void**)((char*)p + 4);
        void* y = *(void**)x;
        sub_726e20(p, y, buf + 12);
    }
    sub_726e80(p);
    sub_62fc62(p);
    if (*(char*)(buf + 12) != 0) {
        sub_725770(*(void**)(buf + 8));
        return;
    }
}
