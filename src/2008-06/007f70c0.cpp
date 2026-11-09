// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void* makeType();
extern "C" void* makeClass();
struct Obj { void run(void*, void*, void*, void*, int); };
extern Obj obj;
extern "C" void tail(void*);
void func() {
    obj.run(makeClass(), makeType(), (void*)0x82f780, (void*)0x822490, 0);
    *(void**)&obj = (void*)0x840460;
    tail((void*)0x7ffbc0);
}