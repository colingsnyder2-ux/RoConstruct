// from server: 100% by EspClaude
// roc 2007-08 004f3770 455 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// Shape (from target): cdecl (float*, float*, bool*). Constants read from the
// exe: 0x79f738 = 50.0f, 0x79b500 = 20.0f, 0x797988 = 2.0f, 0x78fef0 = 100.0f;
// strings 0x797f4c "ATI", 0x79f730 "NVIDIA", 0x79f728 "MESA", 0x79f720 "Intel".
// msvcp80 basic_string copy/char* ctors and dtor through the IAT; 0x46d4d0
// returns the string copied into a local; 0x5085b0 is cdecl (s, temp) -> bool;
// 0x4f3110 returns float; 0x472f80 returns 64-bit (>> 20, unsigned);
// 0x4f35c0 returns int compared against 0x708.
#include <string>

const std::string& __cdecl getVendorString();
bool __cdecl stringContains(const std::string& s, const std::string& sub);
float __cdecl getFloatValue();
unsigned __int64 __cdecl getMemoryBytes();
int __cdecl getIntValue();

void __cdecl getDefaults(float* a, float* b, bool* c)
{
    *a = 50.0f;
    *b = 20.0f;
    *c = false;

    std::string vendor = getVendorString();
    bool found;
    {
        std::string name("ATI");
        found = stringContains(vendor, name);
    }
    if (!found) {
        std::string name("NVIDIA");
        found = stringContains(vendor, name);
    }
    if (!found) {
        std::string name("MESA");
        found = stringContains(vendor, name);
    }
    if (!found) {
        std::string name("Intel");
        found = stringContains(vendor, name);
    }

    float f = getFloatValue();
    int mb = (int)(getMemoryBytes() >> 20);
    if (getIntValue() >= 0x708 && f >= 2.0f && mb > 0x80) {
        *a = *b = 100.0f;
    }
}
