// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Name { int x; };
extern "C" void __cdecl sub_4015a0(void*, void (__cdecl*)());
extern "C" void __cdecl sub_51d190();
extern char dword_E1E170[];
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern "C" const Name* __cdecl sub_67f480();
extern "C" const Name* __cdecl sub_51bb80();
extern unsigned char byte_E580B3;
extern char (__cdecl *dword_E5809C)(const char*, const char*, int);
extern const Name* sClassName;

bool isClassNameNull()
{
    if (byte_E580B3 != 0) {
        const Name* a;
        if (sClassName == 0) {
            a = sub_67f480();
        } else {
            sub_4015a0(dword_E1E170, sub_51d190);
            a = sub_51bb80();
        }
        const Name* b = sub_67f480();
        if ((b == a) != (sClassName == 0)) {
            if (dword_E5809C == 0 || !dword_E5809C("className().empty() == (sClassName==NULL)", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h", 0x14b))
                sub_972290(byte_E580B3, "className().empty() == (sClassName==NULL) file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h line: 331");
        }
    }
    return sClassName == 0;
}