// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
using std::string;

struct Descriptor {
    bool isA(const Descriptor*) const;
};

struct Base0 {
    char pad0[0x1c];
};

struct Described {
    char pad1[0xc];
    Descriptor* desc;
};

struct S : Base0, Described {
    char pad2[0xc];
    S* parent;
    char pad3[8];
    string name;
    string getFullName() const;
};

struct DM : S {
    static const Descriptor* classDescriptor();
};

template<class T>
inline T* fastCast(Described* p) {
    if (p) {
        Descriptor* d = p->desc;
        if (d->isA(T::classDescriptor()))
            return static_cast<T*>(p);
    }
    return 0;
}

string S::getFullName() const {
    if (parent && !fastCast<DM>(parent))
        return parent->getFullName() + "." + name;
    return name;
}
