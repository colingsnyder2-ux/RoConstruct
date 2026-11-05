// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

extern void __cdecl freeArray(void*);
void __cdecl operator delete(void*) throw();

struct RawArray {
    void* p;
    void* end;
    void* cap;
    __forceinline ~RawArray() throw() {
        if (p)
            operator delete(p);
        p = 0;
        end = 0;
        cap = 0;
    }
};

struct DirectArray {
    void* p;
    void* end;
    void* cap;
    __forceinline ~DirectArray() throw() {
        operator delete(p);
    }
};

struct Array {
    void* p;
    void* end;
    void* cap;
    __forceinline ~Array() {
        freeArray(p);
        p = 0;
        end = 0;
        cap = 0;
    }
};

template<int N> struct __declspec(novtable) Notifier {
    virtual void notify() = 0;
    struct PlainArray { void* p; void* end; void* cap; } a, b;
    int pad;
    __forceinline ~Notifier() throw() {
        if (b.p)
            operator delete(b.p);
        void* first = a.p;
        b.p = 0;
        b.end = 0;
        b.cap = 0;
        operator delete(first);
    }
};

struct Stage {
    virtual ~Stage() {}
};

struct JointStage {
    ~JointStage();
};

template<class T> struct Scoped {
    T* p;
    __forceinline ~Scoped() { delete p; }
};

struct Tree {
    char data[0x2c];
    ~Tree();
};

struct World : Notifier<0>, Notifier<1>, Notifier<2>, Notifier<3> {
    int unknown80;
    JointStage* jointStage;
    Stage* contactManager;
    Array a8c;
    Array a98;
    int unknownA4[2];
    Array aac;
    Array ab8;
    Tree tree;
    Array af0;
    Scoped<Stage> stage0;
    Scoped<Stage> stage1;
    Scoped<Stage> stage2;
    Scoped<Stage> stage3;
    Scoped<Stage> stage4;
    Scoped<Stage> stage5;
    virtual ~World();
};

World::~World() {
    delete contactManager;
    delete jointStage;
}
