// from server: 39% by Intel
struct std_string {
    char _pad[28];
};

extern "C" void __stdcall std_string_ctor_copy(std_string*, const std_string*);
extern "C" void __stdcall sub_006c6a20(char*);

struct Settings {
    char pad[0xC8];
    std_string field_AC;

    void func_006c7010();
};

void Settings::func_006c7010()
{
    char local_7 = 0;
    if (*(char*)0x00DAC77C) {
        sub_006c6a20(&local_7);
    } else {
        local_7 = 0;
    }

    if (this->pad[0xC8] == 0 && local_7 == 0) {
        std_string_ctor_copy(&this->field_AC, (std_string*)(this + 0xAC));
    }
}
