// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
//

void* __cdecl getBaseToken();
void* __cdecl getSharedToken0();
extern int sharedCounter;
inline void* getSharedToken() { ++sharedCounter; return getSharedToken0(); }
void* __cdecl operator new(unsigned int);

struct Holder {
    virtual ~Holder();
    void* value;

    Holder(void* p);
};

inline Holder::Holder(void* p) : value(p) {}

struct Shared {
    void* token;
    Holder* holder;

    Shared(void* p);
    ~Shared();
};

inline Shared::Shared(void* p)
    : token(getSharedToken()), holder(new Holder(p)) {}

struct Base {
    virtual ~Base();
    unsigned char storage[0x34];

    Base(void* token, void* a, void* b);
    void finish(void* a, void* b);
};

struct Product : Base {
    void* first;
    void* second;
    Shared left;
    Shared right;

    Product(void* a, void* b, void* c, void* d,
            void* e, void* f, void* g, void* h);
    virtual ~Product();
};

Product::Product(void* a, void* b, void* c, void* d,
                 void* e, void* f, void* g, void* h)
    : Base(getBaseToken(), c, h),
      first(a),
      second(b),
      left(e),
      right(g)
{
    finish(d, f);
}
