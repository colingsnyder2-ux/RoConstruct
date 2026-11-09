// from server: 37% by colin
// roc 2007-08 00462210  unit: CSelectionCaption  size: 187 bytes
// library xtp-11.2.2-vc8/Source\Controls\XTThemeManager.cpp

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) int __cdecl memmove_s(void*, unsigned int, const void*, unsigned int);
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

extern "C" void __stdcall sub_41D870(void*);

struct CSelectionCaption {
    void sub_462210();
};

void CSelectionCaption::sub_462210() {
    char local[8];
    int* p = (int*)((char*)this + 0x18);
    int* q = (int*)((char*)p + 0x2c);
    *(int*)&local[0] = (int)q;
    local[4] = 0;
    sub_41D870(local);

    int* begin = *(int**)((char*)this + 8);
    int* end = *(int**)((char*)this + 0xc);
    int* cap = *(int**)((char*)this + 0x10);

    if (begin > cap) {
        _invalid_parameter_noinfo();
    }
    if (end > cap) {
        _invalid_parameter_noinfo();
    }
    if (begin == end) {
        while (begin != end) {
            int* v = *(int**)begin;
            *(int*)((char*)v + 0xc) = 0;
            begin++;
        }
    }

    int* newEnd = *(int**)((char*)this + 0xc);
    int* newCap = *(int**)((char*)this + 0x10);
    if (newEnd > newCap) {
        _invalid_parameter_noinfo();
    }
    int* first = *(int**)((char*)this + 0x8);
    if (first > newCap) {
        _invalid_parameter_noinfo();
    }
    if (first != newEnd) {
        int count = (int)((char*)newCap - (char*)newEnd) >> 2;
        int bytes = count * 4;
        int* dest = (int*)((char*)first + bytes);
        if (count > 0) {
            memmove_s(newEnd, bytes, first, bytes);
        }
        *(int**)((char*)this + 0x10) = dest;
    }

    if (local[4] != 0) {
        LeaveCriticalSection(*(void**)local);
    }
}
