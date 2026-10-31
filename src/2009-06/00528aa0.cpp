// from server: 90% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004db690  unit: RBX::ViewNew::ViewG3D  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004db690
//
// 004db690  56                   push esi
// 004db691  8bf1                 mov esi, ecx
// 004db693  8b06                 mov eax, dword ptr [esi]
// 004db695  8b5024               mov edx, dword ptr [eax + 0x24]
// 004db698  57                   push edi
// 004db699  ffd2                 call edx
// 004db69b  dd0538698200         fld qword ptr [0x826938]
// 004db6a1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004db6a4  8b01                 mov eax, dword ptr [ecx]
// 004db6a6  8b5014               mov edx, dword ptr [eax + 0x14]
// 004db6a9  83ec08               sub esp, 8
// 004db6ac  dd1c24               fstp qword ptr [esp]
// 004db6af  ffd2                 call edx
// 004db6b1  8b4614               mov eax, dword ptr [esi + 0x14]
// 004db6b4  8b8004020000         mov eax, dword ptr [eax + 0x204]
// 004db6ba  8b9088020000         mov edx, dword ptr [eax + 0x288]
// 004db6c0  8b7608               mov esi, dword ptr [esi + 8]
// 004db6c3  8b3e                 mov edi, dword ptr [esi]
// 004db6c5  8d8888020000         lea ecx, [eax + 0x288]
// 004db6cb  8b4208               mov eax, dword ptr [edx + 8]
// 004db6ce  ffd0                 call eax
// 004db6d0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004db6d4  8b5714               mov edx, dword ptr [edi + 0x14]
// 004db6d7  50                   push eax
// 004db6d8  51                   push ecx
// 004db6d9  8bce                 mov ecx, esi
// 004db6db  ffd2                 call edx
// 004db6dd  5f                   pop edi
// 004db6de  5e                   pop esi
// 004db6df  c20400               ret 4

extern const double value;

struct Source {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void set(double);
};

struct Query {
    virtual void slot0();
    virtual void slot1();
    virtual int get();
};

struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void apply(int, int);
};

struct Context {
    char padding[0x288];
    Query query;
};

struct Holder {
    char padding[0x204];
    Context* context;
};

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void prepare();

    Source* source;
    Target* target;
    char padding[8];
    Holder* holder;

    void f(int);
};

void S::f(int arg) {
    prepare();
    source->set(value);
    Context* c = holder->context;
    Target* t = target;
    t->apply(arg, c->query.get());
}
