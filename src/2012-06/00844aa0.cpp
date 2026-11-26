// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct L;
typedef int (__cdecl *CFunc)(L*);
extern int g_value;
extern const char g_name1[];
extern const char g_name2[];
extern const char g_name3[];
extern const char g_name4[];
extern const char g_name5[];
extern int __cdecl rawSet(L*, int);
extern void __cdecl checkStack(L*, int);
extern void __cdecl pushString(L*, const char*);
extern void __cdecl pushCClosure(L*, CFunc, int);
extern void __cdecl setField(L*, int);
extern void __cdecl pushBool(L*, int, int);
extern void __cdecl setTop(L*, int);
extern int __cdecl fn3(L*);
extern int __cdecl fn4(L*);
extern int __cdecl fn5(L*);
void __cdecl f(L* s, CFunc a, CFunc b)
{
    rawSet(s, g_value);
    checkStack(s, -1);
    pushString(s, g_name1);
    pushCClosure(s, a, 0);
    setField(s, -3);
    pushString(s, g_name2);
    pushCClosure(s, b, 0);
    setField(s, -3);
    pushString(s, g_name3);
    pushCClosure(s, fn3, 0);
    setField(s, -3);
    pushString(s, g_name4);
    pushCClosure(s, fn4, 0);
    setField(s, -3);
    pushString(s, g_name5);
    pushCClosure(s, fn5, 0);
    setField(s, -3);
    pushBool(s, -1, 1);
    setTop(s, -2);
}
