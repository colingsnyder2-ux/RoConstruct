// from server: 44% by Intel
struct std_string {
    char _buf[28];
};

extern "C" void __stdcall std_string_ctor_copy(std_string* this_, const std_string* other);
extern "C" void __stdcall std_string_dtor(std_string* this_);
extern "C" void __stdcall func_00539770(int value);
extern "C" void __stdcall func_00b22644(int* out, const std_string* str);
extern "C" void __stdcall func_00b2263c(void* this_);

struct VPlayer_EventDesc {
    char pad[44];
    int field_2C;
    void func_0053a2d0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

void VPlayer_EventDesc::func_0053a2d0(int, int, int, int, int, int, int, int) {
    std_string local_str;
    int esp_val;
    int saved_ecx;

    std_string_ctor_copy(&local_str, (const std_string*)0xACA089);
    esp_val = 0;
    func_00b22644(&esp_val, &local_str);
    func_00539770(this->field_2C + esp_val);
    *(int*)((char*)&local_str + 16) = -1;
    func_00b2263c(&local_str);
}
