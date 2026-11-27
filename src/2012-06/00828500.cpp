// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern unsigned char byte_E580B3;
extern char (__cdecl *dword_E5809C)(const char*, const char*, int);
void* __cdecl sub_917690();
struct Contact {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    void sub_917700();
    void func();
};
void Contact::func()
{
    if (byte_E580B3 != 0 && !sub_917690()) {
        if (dword_E5809C == 0 || !dword_E5809C("getKernel()", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/Contact.h", 0x37))
            sub_972290(byte_E580B3, "getKernel() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\V8World/Contact.h line: 55");
    }
    vf6();
    sub_917700();
}