// from server: 100% by EspClaude
// roc 2009-06 006b15f0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class System { public: static void alignedFree(void* p); };
template<class T> class Array {
public:
    T* data; int num; int numAllocated;
    ~Array() { System::alignedFree(data); data = 0; num = 0; numAllocated = 0; }
};
}
namespace RBX {
class ContactBase { public: ~ContactBase(); char pad[0x34]; };
class Contact : public ContactBase {
public:
    G3D::Array<int> a;
    G3D::Array<int> b;
    ~Contact();
};
Contact::~Contact() {}
}
