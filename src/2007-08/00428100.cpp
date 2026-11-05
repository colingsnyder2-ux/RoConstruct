// from server: 37% by colin
extern "C" {
    __declspec(dllimport) int __stdcall PathFileExistsA(const char*);
    __declspec(dllimport) int __stdcall PathAppendA(char*, const char*);
    __declspec(dllimport) int __stdcall PathRemoveFileSpecA(char*);
    __declspec(dllimport) int __stdcall PathStripPathA(char*);
    __declspec(dllimport) int __stdcall MoveFileA(const char*, const char*);
    __declspec(dllimport) int __cdecl _mkdir(const char*);
}

struct String {
    void* rep;
    String(const char*);
    ~String();
    const char* c_str() const;
};

struct COleException {
    void* vtable;
    char pad[0x40];
    COleException* COleException::func(const char* src, const char* dst);
};

COleException* COleException::func(const char* src, const char* dst) {
    char path1[0x104];
    char path2[0x104];
    String s1(src);
    String s2(dst);
    String s3(s1.c_str());
    String s4(s2.c_str());
    if (!PathFileExistsA(s3.c_str())) {
        _mkdir(s3.c_str());
    }
    String s5(s1.c_str());
    String s6(s2.c_str());
    PathAppendA(path1, s5.c_str());
    PathAppendA(path2, s6.c_str());
    PathRemoveFileSpecA(path1);
    PathStripPathA(path2);
    MoveFileA(path1, path2);
    return this;
}
