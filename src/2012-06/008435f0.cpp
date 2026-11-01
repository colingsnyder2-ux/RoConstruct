// from server: 28% by Intel
struct String {
    char _buf[16];
    int _len;
    int _cap;
    char* _ptr;
};

extern "C" void __cdecl string_ctor(String* this_, const char* str);
extern "C" void __cdecl string_dtor(String* this_);
extern "C" void __stdcall func_8320f0(void* a1, const char* a2, int a3);
extern "C" void __stdcall func_B2263C(void*);

int __cdecl func_8435F0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    String s;
    string_ctor(&s, (const char*)arg0);
    func_8320f0((void*)arg4, s._len < 16 ? s._buf : s._ptr, s._len);
    string_dtor(&s);
    func_B2263C(0);
    return 1;
}
