// from server: 85% by tester
struct AsyncResult {
    void* vtable;
    int field4;
    void returnResult(int);
};

extern "C" void* __stdcall sub_6c1590();
extern "C" char __cdecl sub_4492f0(void*);
extern "C" void __cdecl sub_972290(unsigned char, const char*);

extern unsigned char byte_E580B3;
extern void* dword_E5809C;
extern const char str_B43F40[];
extern const char str_B753E0[];
extern const char str_B753F8[];

void AsyncResult::returnResult(int arg)
{
    if (byte_E580B3 != 0) {
        sub_6c1590();
        void* vt = *(void**)this;
        void* obj = *(void**)((char*)vt + 0x20);
        if (sub_4492f0(obj)) {
            goto done;
        }
        if (dword_E5809C != 0) {
            typedef char (__stdcall *Fn)(const char*, const char*, unsigned);
            Fn fn = (Fn)dword_E5809C;
            if (fn(str_B753E0, str_B43F40, 0x133)) {
                goto done;
            }
        }
        sub_972290(byte_E580B3, str_B753F8);
    }
done:
    {
        void* vt = *(void**)this;
        void* obj = *(void**)((char*)vt + 0x28);
        void** vtbl = *(void***)obj;
        typedef void (__stdcall *Fn2)(void*, int, int);
        Fn2 fn = (Fn2)vtbl[3];
        fn(obj, field4, arg);
    }
}
