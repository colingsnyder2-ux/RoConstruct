// from server: 94% by Intel
// from server: 85% by Intel
// roc 2007-08 0040c100  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 76 bytes
// 2007-08 hand variant, take 4: four explicit qualified base destructor calls in DECLARATION
// order so each becomes a direct inlined vptr store, plus the original null check.

struct A0 { virtual ~A0() {} };
struct A1 { virtual ~A1() {} };
struct A2 { virtual ~A2() {} char pad[8]; };
struct A3 { virtual ~A3() {} };

struct A2Base { void QueryInterface(int, int); };

struct VCBrowserViewExternal : A0, A1, A2, A3 {
    int refCount;

    long Release(int a1);
};

extern "C" void __cdecl sub_62FC62(void* ptr);

long VCBrowserViewExternal::Release(int a1) {
    VCBrowserViewExternal* self = (VCBrowserViewExternal*)a1;
    int result = --self->refCount;
    if (result == 0) {
        if (self != 0) {
            self->A0::~A0();
            self->A1::~A1();
            self->A2::~A2();
            self->A3::~A3();
            self->refCount = (int)0xC0000001;
            A2Base* inner = (A2Base*)((char*)self + 8);
            inner->QueryInterface(0, 0);
            sub_62FC62(self);
        }
    }
    return result;
}
