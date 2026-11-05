// from server: 100% by Espeon
// from server: 85% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
struct S;

struct Controller {
    int check();
};

extern bool __cdecl validate(S*);
extern Controller* __cdecl resolve(void*);
extern void* __cdecl context(S*);

struct S {
    char padding[0x104];
    void* parent;

    void* find();
    void update(int, void*);
    inline int desired();
    void f();
};

inline int desiredParent(void* parent){Controller* controller=resolve(parent);if(!controller)return 2;return controller->check()?4:0;}
inline int S::desired(){if(!find())return 0;if(!validate(this))return 1;return desiredParent(parent);}
void S::f(){int result=desired();update(result,context(this));}
