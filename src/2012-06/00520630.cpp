// from server: 79% by atomic.potato
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00bc069c;
Value& sub_0067f2e0(void*);
Value& func_0051bb80();

extern "C" void __stdcall sub_004015a0(const char*, const char*);
extern "C" void __stdcall sub_00972290(unsigned char, const char*);
extern "C" void* __stdcall sub_0067f480();

extern unsigned char g_00e580b3;
extern void* g_00e5809c;

int func_00520630() {
    if (g_00e580b3) {
        void* a;
        if (g_00bc069c.pad[0] == 0) {
            a = sub_0067f480();
        } else {
            sub_004015a0((const char*)0xe1e170, (const char*)0x51d190);
            a = (void*)&func_0051bb80();
        }
        void* b = sub_0067f480();
        int c = (b == a);
        int d = (g_00bc069c.pad[0] == 0);
        if (c != d) {
            if (g_00e5809c) {
                if (((unsigned char (__stdcall*)(const char*, const char*, int))g_00e5809c)(
                        (const char*)0xb42fa8, (const char*)0xb46518, 0x14b)) {
                    return 0;
                }
            }
            sub_00972290(g_00e580b3, (const char*)0xb46490);
        }
    }
    return g_00bc069c.pad[0] == 0;
}
