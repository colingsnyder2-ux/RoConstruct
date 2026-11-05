// from server: 44% by Intel
struct std_exception { int _vftable; };
struct std_string { int _vftable; int _size; int _capacity; char* _ptr; };

extern "C" void __stdcall std_exception_ctor(std_exception* this_);
extern "C" void __stdcall std_string_ctor_cstr(std_string* this_, const char* str);
extern "C" void __stdcall std_string_ctor_copy(std_string* this_, const std_string& other);
extern "C" void __stdcall std_string_dtor(std_string* this_);
extern "C" void __stdcall unknown_call_1(void* this_, const std_string& str);
extern "C" void __stdcall unknown_call_2(void* this_);

int __cdecl sub_A99090(void* this_)
{
    std_string s1;
    std_string s2;
    std_exception e;

    std_string_ctor_cstr(&s1, (const char*)0xBD87E4);
    std_string_ctor_copy(&s2, s1);
    unknown_call_1(this_, s2);
    std_string_dtor(&s2);
    *(int*)0xB43C4C = 0;
    unknown_call_2(&e);
    return 0;
}
