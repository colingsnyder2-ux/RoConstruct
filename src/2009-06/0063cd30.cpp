// from server: 100% by EspClaude
// from server: 82% by EspClaude
// roc 2009-06 0063cd30  unit: RBX::Accoutrement  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063cd30
//

// from server: 100% by Espeon
// roc 2008-06 005b10a0  unit: RBX::Accoutrement  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b10a0
//

// from server: 85% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S;

struct Controller {
    int check();
};

extern bool __cdecl validate(S*);
extern Controller* __cdecl resolve(void*);
extern void* __cdecl context(S*);

struct S {
    char padding[0x48];
    void* parent;

    void* find();
    void update(int, void*);
    inline int desired();
    void f();
};

inline int desiredParent(void* parent){Controller* controller=resolve(parent);if(!controller)return 2;return controller->check()?4:0;}
inline int S::desired(){if(!find())return 0;if(!validate(this))return 1;return desiredParent(parent);}
void S::f(){int result=desired();update(result,context(this));}
