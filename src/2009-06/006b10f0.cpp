// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class System { public: static void alignedFree(void* ptr); };
template<class T> class Array {
    T* data; int num; int numAllocated;
public:
    ~Array() {
        for (int i = 0; i < num; i++) (data + i)->~T();
        System::alignedFree(data);
        data = 0; num = 0; numAllocated = 0;
    }
};
}
template<class T> class scoped_ptr {
    T* px;
public:
    ~scoped_ptr() { delete px; }
};
class A { public: ~A(); int x; };
class B { public: virtual ~B(); };
class X {
public:
    A* a;
    int b;
    G3D::Array<int*> arr;
    scoped_ptr<B> c;
    ~X();
};
X::~X()
{
    delete a;
}
