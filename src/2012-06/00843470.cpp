// from server: 39% by Intel
struct String {
    char _buf[16];
    int _size;
    int _capacity;
    char* _ptr;
};

extern "C" void __cdecl string_ctor(String* this_, const char* str);
extern "C" void __cdecl string_dtor(String* this_);
extern "C" void __stdcall func_8320f0(int a1, const char* a2, int a3);
extern "C" void __stdcall func_B2263C();

int __cdecl sub_843470(int arg1, int arg2, int arg3, int arg4) {
    String local_str;
    string_ctor(&local_str, reinterpret_cast<const char*>(arg1));
    
    const char* str_data = (local_str._size >= 16) ? local_str._ptr : local_str._buf;
    func_8320f0(arg2, str_data, arg4);
    
    string_dtor(&local_str);
    func_B2263C();
    return 1;
}
