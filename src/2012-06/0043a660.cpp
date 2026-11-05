// from server: 33% by atomic.potato
struct CSelectionPropGrid {
    void f(void* a, char b);
};

extern "C" void __stdcall sub_5c9fe8(int, const char*, void*);
extern "C" void __stdcall sub_446340();
extern "C" void __stdcall sub_437500(void*, void*);
extern "C" int __stdcall IsWindow(void*);

extern char byte_dac768;
extern void* dword_e1879c;

void CSelectionPropGrid::f(void* a, char b)
{
    if (byte_dac768) {
        sub_5c9fe8((int)byte_dac768, (const char*)0xb50640, 0);
    }
    if (a == 0) return;
    int i = 0;
    while (true) {
        int* p = (int*)a;
        int count = (p[2] - p[1]) >> 2;
        if ((unsigned)i >= (unsigned)count) break;
        int* arr = (int*)p[1];
        int cnt2 = (p[2] - (int)arr) >> 2;
        if ((unsigned)cnt2 <= (unsigned)i) {
            sub_446340();
        }
        int item = arr[i];
        if (item) {
            if (byte_dac768) {
                sub_5c9fe8((int)byte_dac768, (const char*)0xb50614, (void*)item);
            }
            void** vt = *(void***)item;
            void (*fn)(void*, int) = (void (*)(void*, int))vt[0x164/4];
            fn((void*)item, b == 0 ? 1 : 0);
            if (!b) {
                void* w = *(void**)(item + 0x20);
                if (IsWindow(w)) {
                    void* g = dword_e1879c;
                    if (g) {
                        void* w2 = *(void**)((char*)g + 0x20);
                        if (IsWindow(w2)) {
                            sub_437500((void*)item, dword_e1879c);
                        }
                    }
                }
            }
        }
        i++;
    }
}
