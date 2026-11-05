// from server: 50% by colin
struct FilteredSelection {
    char pad[0xc];
    void* rootSelection;
    void method(void* a, void* b);
};

struct Selection {
    char pad[0x2d4];
};

extern "C" void __stdcall sub_5E0D50(void*, void*, int, void*);
extern "C" void __stdcall sub_5E0660(void*);
extern "C" void __stdcall sub_5E0B70(void*, void*);
extern "C" void __stdcall sub_5E0FA0(void*);
extern "C" void __stdcall sub_5E0EF0(void*);
extern "C" void __stdcall sub_558B60(void*, void*);

void FilteredSelection::method(void* a, void* b) {
    int* p = (int*)a;
    if (p[1] != 0) {
        int count = (p[2] - p[1]) >> 2;
        if (count != 0) {
            char buf[0x30];
            void* r = rootSelection;
            sub_5E0D50(buf, a, 0, r);
            *(int*)(buf + 0x2c) = 0;
            sub_5E0660(buf);
            sub_5E0B70(buf, b);
            sub_5E0FA0(buf);
            Selection* sel = (Selection*)rootSelection;
            *(char*)(buf + 0x38) = 0;
            int val = *(int*)(buf + 0x38);
            sub_558B60((char*)sel + 0x2d4, &val);
            *(int*)(buf + 0x2c) = -1;
            sub_5E0EF0(buf);
        }
    }
}
