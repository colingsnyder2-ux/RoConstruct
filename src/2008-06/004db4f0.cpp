// from server: 100% by Espeon
#include <intrin.h>

void __cdecl operator delete(void*);

extern "C" void __cdecl cleanup_004db130();
extern "C" void __cdecl cleanup_004db040();
extern "C" void __cdecl cleanup_004daf50();
extern "C" void __cdecl cleanup_004e5670();
extern "C" void __cdecl cleanup_004db310();
extern "C" void __cdecl cleanup_004db220();
extern "C" void __cdecl cleanup_004db400();

struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void release();
};

struct OwnedVirtual {
    virtual ~OwnedVirtual();
};

struct OwnedDirect {
    ~OwnedDirect();
};

struct ProductBase {
    virtual void slot0();
    ~ProductBase();
};

struct Product : ProductBase {
    virtual void slot0();
    ~Product() {}
};

struct Resource {
    void release();
};

struct ViewBase {
    virtual ~ViewBase();
};

struct View : ViewBase {
    Interface* interface_;
    OwnedVirtual* owned_;
    Product* product_;
    OwnedDirect* direct_;
    Resource* resource_;
    virtual ~View();
};

View::~View()
{
    interface_->release();

    delete owned_;
    owned_ = 0;
    _ReadWriteBarrier();

    delete direct_;
    direct_ = 0;
    _ReadWriteBarrier();

    delete product_;
    product_ = 0;
    _ReadWriteBarrier();

    if (resource_)
        resource_->release();

    cleanup_004db130();
    cleanup_004db040();
    cleanup_004daf50();
    cleanup_004e5670();
    cleanup_004db310();
    cleanup_004db220();
    cleanup_004db400();
}