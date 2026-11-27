// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern unsigned char byte_E580B3;
extern char (__cdecl *dword_E5809C)(const char*, const char*, int);
struct Sub { void method(int); }; struct Inner { char pad[0x178]; Sub sub; }; 
struct S { char pad0[4]; Inner* field4; void method(int a); };
void S::method(int a) {
    if (byte_E580B3 != 0 && field4 == 0) {
        if (dword_E5809C == 0 || !dword_E5809C("workspace", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8datamodel\\GuiBuilder.cpp", 0x26))
            sub_972290(byte_E580B3, "workspace file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8datamodel\\GuiBuilder.cpp line: 38");
    }
    field4->sub.method(a);
}
