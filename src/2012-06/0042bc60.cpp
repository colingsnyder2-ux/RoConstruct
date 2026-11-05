// from server: 85% by Intel
// Global variables
extern char byte_E182D4;  // 0xe182d4
extern int dword_E182CC;  // 0xe182cc
extern int dword_E182D0;  // 0xe182d0

// Function declarations
extern "C" void __cdecl sub_4015A0(const char*, const char*);  // 0x4015a0
extern "C" void __cdecl sub_9831F5(int);  // 0x9831f5

// String constants at specific addresses
extern const char str_42B2B0[];  // "8csm" at 0x42b2b0
extern const char str_E182E8[];  // "tUVW" at 0xe182e8
extern const int addr_B11900;    // 0xb11900

class CSelectionTreeCtrl {
public:
    int func_0042BC60();
};

int CSelectionTreeCtrl::func_0042BC60() {
    sub_4015A0(str_42B2B0, str_E182E8);
    
    if (byte_E182D4 & 1) {
        return 1;
    }
    
    byte_E182D4 |= 1;
    dword_E182CC = 0;
    dword_E182D0 = 0;
    sub_9831F5(addr_B11900);
    
    return 1;
}
