// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00565430[];   // INFERRED: unnamed global at 0x00565430 in the original
extern "C" char g_009744b0[];   // INFERRED: unnamed global at 0x009744b0 in the original
#include <new>
typedef unsigned int size_t_local;

// INFERRED: callee names/signatures follow the fn_<addr> convention
extern "C" void __cdecl fn_00557330(void (__cdecl *)(), void *); // boost::call_once
extern "C" void *__cdecl fn_005653d0();                          // enum/type accessor
extern "C" void *__cdecl fn_00564ee0();                          // classDescriptor
void __cdecl operator delete(void *);

namespace {

struct Temporary {
    void *p;
    void *release() const;
    ~Temporary();
};

inline void *Temporary::release() const {
    void *result = p;
    const_cast<Temporary *>(this)->p = 0;
    return result;
}

inline Temporary::~Temporary() {
    if (p)
        operator delete(p);
}

struct Owner {
    void *p;
    Owner(const Temporary &);
    ~Owner();
};

inline Owner::Owner(const Temporary &other) : p(other.release()) {
}

inline Owner::~Owner() {
    if (p)
        operator delete(p);
}

} // namespace

// INFERRED: getset helper returns an owning temporary
extern "C" Temporary __cdecl fn_00563dd0(int, int, int, int);

// INFERRED: Root is the PropertyDescriptor base; its constructor (0x0056c650) is external
struct Local_005656b0_Root {
    unsigned char storage[20];
    Local_005656b0_Root(void *, void *, int, int, int);
    virtual ~Local_005656b0_Root();
};

namespace {

struct Local_005656b0_Base : Local_005656b0_Root {
    void *descriptor;
    Local_005656b0_Base(int, int, int,
         void * = fn_005653d0(),
         void * = (fn_00557330((void (__cdecl *)())((int)&g_00565430),
                               (void *)((int)&g_009744b0)),
                   fn_00564ee0()));
};

__forceinline Local_005656b0_Base::Local_005656b0_Base(int a, int b, int g, void *en, void *desc)
    : Local_005656b0_Root(en, desc, a, b, g), descriptor(desc) {
}

struct Local_005656b0_S : Local_005656b0_Base {
    Owner object;
    void *factory;
    Local_005656b0_S(int, int, int, int, int, int, int);
    virtual ~Local_005656b0_S();
    static void *operator new(size_t_local, void *p) { return p; }
};

inline Local_005656b0_S::~Local_005656b0_S() {
}

__forceinline Local_005656b0_S::Local_005656b0_S(int a, int b, int c, int d, int e, int f, int g)
    : Local_005656b0_Base(a, b, g), object(fn_00563dd0(c, d, e, f)) {
    fn_00557330((void (__cdecl *)())((int)&g_00565430), (void *)((int)&g_009744b0));
    factory = fn_00564ee0();
}

} // namespace

extern "C" Local_005656b0_S * __fastcall fn_005656b0(Local_005656b0_S *self, int unusedEdx,
    int a, int b, int c, int d, int e, int f, int g)
{
    return new (self) Local_005656b0_S(a, b, c, d, e, f, g);
}
