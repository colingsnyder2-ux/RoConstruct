// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE2 /fp:fast
struct B1 { int a; };
struct B2 { int b; };
struct T : B1, B2 { void method(); };
typedef void (T::*PM)();
struct C {
    C(PM, const char*, const char*, const char*, void*);
    ~C();
    char storage[64];
};
C g(&T::method, "Resize", "x", "y", 0);
