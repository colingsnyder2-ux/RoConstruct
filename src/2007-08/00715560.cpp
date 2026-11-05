// from server: 43% by colin
// roc 2007-08 00715560  unit: CXTCaptionButton  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00715560

struct CXTCaptionButton {
    int sub_715440(int, int);
    int sub_715560(unsigned short, int, int, int);
};

struct CXTString {
    void* vtable;
    void* data;
    CXTString();
    CXTString(const CXTString&);
    ~CXTString();
    int Compare(const CXTString&) const;
};

struct CXTStringHelper {
    void* vtable;
    void* data;
    CXTStringHelper();
    CXTStringHelper(const char*);
    ~CXTStringHelper();
};

extern "C" {
    void __stdcall sub_64AFA0(unsigned short, CXTString*);
    void __stdcall sub_648580(CXTString*);
    void __stdcall sub_6485E0(CXTString*, CXTString*);
    int __stdcall sub_648600(CXTString*);
    void __stdcall sub_649660(CXTString*, const CXTString*);
    void __stdcall sub_649680(CXTString*, const CXTString*);
    void __stdcall sub_6496A0(CXTString*);
    void __stdcall sub_630238(CXTStringHelper*, const CXTString*);
    void __stdcall sub_67F2C0(void*, const CXTStringHelper*);
    void __stdcall sub_6820A0(void*);
    void __stdcall sub_41F680(CXTStringHelper*);
}

int CXTCaptionButton::sub_715560(unsigned short a1, int a2, int a3, int a4)
{
    CXTString str1;
    CXTString str2;
    CXTStringHelper helper;
    int result;

    sub_648580(&str1);
    sub_64AFA0(a1, &str2);
    if (str2.data == 0) {
        sub_6496A0(&str1);
        return 0;
    }
    if (str1.data != 0) {
        sub_649680(&str1, &str2);
    } else {
        helper.vtable = (void*)0x788300;
        helper.data = 0;
        sub_630238(&helper, &str2);
        sub_67F2C0(&str1, &helper);
        sub_6820A0(&str1);
        sub_649660(&str1, &str2);
        helper.vtable = (void*)0x788300;
        sub_41F680(&helper);
    }
    if (sub_648600(&str1) != 0) {
        sub_6496A0(&str1);
        return 0;
    }
    {
        CXTString str3;
        CXTString str4;
        sub_648580(&str3);
        sub_6485E0(&str4, &str1);
        result = sub_715440(a4, a3);
        sub_6496A0(&str1);
    }
    return result;
}
