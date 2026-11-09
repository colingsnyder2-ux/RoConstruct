// from server: 64% by Intel




struct DxUserInputHardwareMouse;

extern "C" void __stdcall EnterCriticalSection(void* lpCriticalSection);
extern "C" void __stdcall LeaveCriticalSection(void* lpCriticalSection);

struct std_string {
    char _buf[28];
    std_string(const char* str);
    ~std_string();
};

void __stdcall std_string_ctor(std_string* this_, const char* str);
void __stdcall std_string_dtor(std_string* this_);

void __cdecl sub_4A8810(DxUserInputHardwareMouse* this_);
void __cdecl sub_B22648(void* this_, const std_string& str);
void __cdecl sub_B221B8(void* this_);
void __cdecl sub_B2263C(void* this_);
void __cdecl sub_B221B4(void* this_);

struct DxUserInputHardwareMouse {
    void setKeyboardDesired(char desired);
};

void DxUserInputHardwareMouse::setKeyboardDesired(char desired) {
    std_string str("setKeyboardDesired");
    EnterCriticalSection((void*)0xB62D3C);
    void* lock = (char*)this + 0x44;
    void* event = (char*)lock + 0x3C;
    sub_B221B8(event);
    char state = 1;
    sub_B2263C(&state);
    int ptr = *(int*)((char*)this + 0x1CC);
    *(char*)((char*)this + 0x1E2) = desired;
    if (ptr) {
        if (*(char*)((char*)this + 0x1E4) != desired) {
            if (desired) {
                sub_4A8810(this);
            } else {
                int vtable = *(int*)ptr;
                void (__thiscall* func)(int) = *(void (__thiscall**)(int))(vtable + 0x20);
                func(ptr);
                *(char*)((char*)this + 0x1E4) = 0;
            }
        }
    }
    sub_B221B4(event);
    LeaveCriticalSection((void*)0xB62D3C);
}
