// from server: 100% by tester
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);

struct CXTPCustomizeSheet {
    char pad[0x20];
    void* field_20;
    char pad2[0x90];
    void* field_b4;
    int Check(int unused, void* p);
};

int CXTPCustomizeSheet::Check(int unused, void* p) {
    if (p != 0) {
        if (*(unsigned int*)((char*)p + 8) == 0x86) {
            void* v = field_b4;
            if (v != 0) {
                v = *(void**)((char*)v + 0x20);
            }
            if (*(void**)((char*)p + 0xc) == v) {
                if (*(void**)((char*)p + 4) != 0) {
                    PostMessageA(field_20, 0x8130, 0, 0);
                }
            }
        }
    }
    return 1;
}
