// from server: 40% by atomic.potato
struct ToggleViewMode {
    char unknown_0x0[0xC];
    void* unknown_0xC;  // Member at offset 0xC that's used as 'this' for a call
};

extern "C" int __cdecl sub_7F90E0(int, const char*, const char*, int, int, int, int);
extern "C" void __fastcall sub_5FC610(void*);

bool g_ccc395;  // Global flag referenced at 0xCCC395
const char* g_a7231c = "Gui:ToggleViewMode";  // Global string at 0xA7231C
const char* g_a7244c = ".\\RobloxView.cpp";    // Global string at 0xA7244C

void __fastcall ToggleViewMode_method(ToggleViewMode* this_ptr) {
    if (g_ccc395) {
        sub_7F90E0(3, g_a7244c, g_a7231c, 0x1E8, 0, 0, 0);
    }
    sub_5FC610(this_ptr->unknown_0xC);
}
