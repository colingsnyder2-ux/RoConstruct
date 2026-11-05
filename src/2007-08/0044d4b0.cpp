// from server: 29% by colin
extern "C" {
    void __stdcall G1_00401000(unsigned int);
    void* __stdcall G1_00401180(void*, int);
    void __stdcall G1_006303dc();
    void* __stdcall G1_006303e8(void*);
    int __stdcall G1_006303ee(void*);
    void __stdcall G1_006303f4(void*, int, int, const char*, int, void*);
    void __stdcall G1_00630a1e();
    void __stdcall G1_0077d59c();
    void* __stdcall G1_0077dd98(void*);
    void __stdcall G1_0077ddac();
    void __stdcall G1_0077ddbc();
    void __stdcall G1_0077e9b0(void*);
    void __stdcall G1_0077e9b0_free(void*);
}

struct ExitCommand {
    char pad[0x78];
    void* field_78;
    void execute();
};

void ExitCommand::execute()
{
    char buf[0x1d8];
    void* p;
    int r;
    void* s;

    G1_0077ddac();
    G1_0077d59c();
    G1_0077dd98(buf);
    G1_006303f4(buf, 0, 6, (const char*)0x791564, 0, 0);
    r = G1_006303ee(buf);
    if (r == 1) {
        p = G1_006303e8(buf);
        s = G1_0077dd98(p);
        if (s != 0) {
            s = G1_00401180(s, -1);
            if (s == 0) {
                G1_00401000(0x8007000e);
            }
        } else {
            s = 0;
        }
        G1_0077ddbc();
        void* v = field_78;
        void** vt = *(void***)v;
        void (*fn)(void*, void*) = (void (*)(void*, void*))vt[8];
        fn(v, s);
        G1_0077e9b0_free(s);
    }
    G1_006303dc();
    G1_0077ddbc();
    G1_00630a1e();
}
