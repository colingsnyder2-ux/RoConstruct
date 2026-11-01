// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
template<class T> class ReferenceCountedPointer {
    T* m_pointer;
    void setPointer(T* x);
public:
    ReferenceCountedPointer(T* p) : m_pointer(0) { setPointer(p); }
    ~ReferenceCountedPointer();
};
}
namespace RBX {
typedef unsigned int size_t;
extern "C" void* __cdecl malloc(size_t);
extern "C" void __cdecl free(void*);
class Level00517340 { public: Level00517340(int a); char pad[0x8c]; static void* operator new(size_t s) { return malloc(s); } static void operator delete(void* p) { free(p); } };
G3D::ReferenceCountedPointer<Level00517340> create00517340(int a) { return new Level00517340(a); }
}
