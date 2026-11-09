// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
}
struct Resource { void release(); };
struct Object { virtual void unused(); virtual ~Object(); };
struct OwnedObject { Object* p; ~OwnedObject() { if (p) delete p; } };
struct Auxiliary { ~Auxiliary(); };
struct OwnedAuxiliary { Auxiliary* p; ~OwnedAuxiliary() { if (p) delete p; } };
struct Member10c { char data[0x30]; __declspec(dllimport) ~Member10c() throw(); };
struct Member13c { char data[0x14c]; ~Member13c(); };
struct Member288 { char data[0x124]; ~Member288(); };
struct Member3b8 { char data[0x2c]; ~Member3b8(); };
struct Base3e4 { char data[8]; ~Base3e4(); };
struct Member3e4 : Base3e4 { void clear(); ~Member3e4() { clear(); } };
struct Member3ec { ~Member3ec(); };
struct Base2 { virtual void baseMethod(); char data[0xec]; ~Base2(); };
struct Base : Base2 { virtual void baseMethod(); ~Base() {} };
struct Doc;
struct CDataModelPropGrid : Base {
    boost::shared_ptr<Doc> doc;
    OwnedAuxiliary auxiliary;
    char paddingFc[8];
    Resource* resource;
    char padding108[4];
    Member10c member10c;
    Member13c member13c;
    Member288 member288;
    OwnedObject member3ac;
    OwnedObject member3b0;
    OwnedObject member3b4;
    Member3b8 member3b8;
    Member3e4 member3e4;
    Member3ec member3ec;
    virtual void baseMethod();
    ~CDataModelPropGrid();
};
CDataModelPropGrid::~CDataModelPropGrid()
{
    if (resource) {
        resource->release();
        resource = 0;
    }
}
