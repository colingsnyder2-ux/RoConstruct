// from server: 57% by colin
// roc 2007-08 004f34e0  unit: boost::bad_lexical_cast  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f34e0

extern "C" {
    void __stdcall sub_77e6a4(void*);
    void __stdcall sub_77e698(void*, const char*);
    void __stdcall sub_77e69c(void*, void*);
    void __stdcall sub_77e6ac(void*);
    int __cdecl sub_50a7f0(void*, void*);
    void __cdecl sub_630a1e(void);
}

struct String {
    void* data[8];
    String();
    String(const String&);
    String(const char*);
    ~String();
};

struct CpuName {
    String name;
    String* get(String* result);
};

String* CpuName::get(String* result) {
    String key;
    String temp;
    int ok = sub_50a7f0(&key, &temp);
    if (ok) {
        sub_77e69c(result, &temp);
    } else {
        sub_77e698(result, "Could not determine CPU name");
    }
    return result;
}
