// from server: 30% by atomic.potato
struct T_008f86d0 {
    void f_008f86d0(int, int, int, int, int);
};

extern "C" void __stdcall g_00524ff0(void*, int);
extern "C" void __stdcall g_004658b0(void*, void*);
extern "C" int __stdcall g_006c13d0();
extern "C" void __stdcall g_00982114(void*);

void T_008f86d0::f_008f86d0(int a, int b, int c, int d, int e)
{
    char buf[16];
    void* p;
    int i;

    g_00524ff0(buf, 4);
    p = *(void**)buf;
    *(int*)((char*)p + 0) = g_006c13d0();
    g_004658b0((char*)p + 4, (char*)buf + 0x2c);
    p = *(void**)buf;
    *(int*)((char*)p + 0x44) = g_006c13d0();
    g_004658b0((char*)p + 0x48, (char*)buf + 0x30);
    p = *(void**)buf;
    *(int*)((char*)p + 0x88) = g_006c13d0();
    g_004658b0((char*)p + 0x8c, (char*)buf + 0x34);
    p = *(void**)buf;
    *(int*)((char*)p + 0xcc) = g_006c13d0();
    g_004658b0((char*)p + 0xd0, (char*)buf + 0x38);

    {
        void* q = *(void**)buf;
        void* r = *(void**)q;
        void (*fn)(void*, void*) = *(void(**)(void*, void*))((char*)r + 4);
        fn((void*)a, buf + 8);
    }

    {
        void* start = *(void**)buf;
        if (start != 0) {
            void* end = *(void**)(buf + 4);
            void* it = start;
            if (start != end) {
                char* s = (char*)start + 4;
                do {
                    void* v = *(void**)s;
                    if (v != 0) {
                        void (*fn)(void*) = *(void(**)(void*))((char*)v + 4);
                        fn(s + 4);
                    }
                    s += 0x44;
                    it = s - 4;
                } while (it != end);
                start = *(void**)buf;
            }
            g_00982114(start);
        }
    }
}
