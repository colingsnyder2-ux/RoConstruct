// from server: 58% by atomic.potato
struct GuiRoot {
    char pad0[0x50];
    void* field50;
    void method(int* arg);
};

extern "C" int __stdcall sub_4a50b0();
extern "C" void* __cdecl sub_7a8bea(void*, void*, void*, int, int);
extern "C" void __stdcall sub_9ea90c();

float g_c19210;
float g_c19214;

void GuiRoot::method(int* arg)
{
    float x0, y0, x1, y1;
    int* p = arg;
    void* obj = (void*)*p;
    void (__thiscall *fn)(void*, float*) = *(void (__thiscall**)(void*, float*))((char*)obj + 0x10);
    float tmp[4];
    fn(p, tmp);
    x0 = tmp[0];
    y0 = tmp[1];
    x1 = tmp[2];
    y1 = tmp[3];
    g_c19210 = x1 - x0;
    g_c19214 = y1 - y0;

    unsigned int count = (unsigned int)sub_4a50b0();
    unsigned int i = 0;
    while (i < count) {
        void* v = field50;
        int* begin = *(int**)((char*)v + 0xc);
        int* end = *(int**)((char*)v + 0x10);
        unsigned int n = (unsigned int)((char*)end - (char*)begin) >> 3;
        if (i >= n) {
            sub_9ea90c();
        }
        int a = begin[i * 2];
        void* r = sub_7a8bea((void*)a, (void*)0xb78e40, (void*)0xb7b8b0, 0, 0);
        if (r) {
            void (__thiscall *f2)(void*, int*) = *(void (__thiscall**)(void*, int*))((char*)*(void**)r + 0x74);
            f2(r, arg);
        }
        i++;
        count = (unsigned int)sub_4a50b0();
    }
}
