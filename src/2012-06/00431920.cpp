// from server: 38% by atomic.potato
extern "C" {
    void __stdcall func_004015a0(int, int);
    void __cdecl func_00431800();
    void __cdecl func_00431280();
    void __cdecl func_00431200();
    void __cdecl func_00431910();
}

struct String {
    char pad[0x1c];
    String();
    String(const char*);
    ~String();
    String& operator+=(const String&);
    String& operator+=(const char*);
    const char* c_str() const;
};

extern "C" {
    void* __stdcall imp_b24780();
    void __stdcall imp_b22648(void*);
    void __stdcall imp_b226e0(void*);
    void __stdcall imp_b2263c(void*);
    void __stdcall imp_b2265c(void*);
    void __stdcall imp_b22640(void*);
    int __stdcall imp_b24654(void*);
    int __stdcall imp_b24658(void*);
    void __stdcall imp_b243ac(void*, int);
    void __stdcall imp_b23a30(void*, void*);
    void __stdcall imp_b243b0(void*);
    void __stdcall imp_b24798(void*);
    void __stdcall imp_b247d0(void*);
    void __stdcall PathAppendA(char*, const char*);
}

struct LogManager {
    void func_00431920(int);
};

void LogManager::func_00431920(int arg)
{
    String s1;
    String s2;
    String s3;
    char path[260];

    func_004015a0(0xe18784, 0x431910);
    func_00431800();
    imp_b24780();
    imp_b22648((void*)0xb4f3f0);
    func_00431280();
    imp_b226e0(&s1);
    imp_b2263c(&s2);
    imp_b2265c((void*)0xb4f3ec);
    func_00431200();
    imp_b226e0(&s1);
    imp_b2263c(&s2);
    imp_b2265c((void*)0xb4f3e0);
    imp_b22640(&s3);
    int n1 = imp_b24654(&s3);
    int n2 = imp_b24658(&s3);
    imp_b243ac(&s1, n1 + n2 + 1);
    imp_b23a30(&s1, &s3);
    imp_b243b0(&s1);
    imp_b24798(&s1);
    imp_b22648((void*)0xb4f3f0);
    imp_b2263c(&s2);
    imp_b247d0(&s1);
}
