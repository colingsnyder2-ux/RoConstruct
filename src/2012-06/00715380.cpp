// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String *);
struct String {
    char storage[28];
    ~String() { destroyString(this); }
};
extern unsigned char gFlag;
extern int gTag;
void helper(unsigned char, int*, String*);
struct Tool { void f(String s); };
void __stdcall Tool_f(Tool*, String);
void Tool::f(String s) {
    if (gFlag) helper(gFlag, &gTag, &s);
}