// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace rbx { namespace signals {
class connection {
public:
	~connection();
	void disconnect() const;
	void* a; void* b;
};
class scoped_connection : public connection {
public:
	~scoped_connection() { disconnect(); }
};
} }
namespace RBX {
struct B0 { virtual void f0(); char p[0x10]; };
struct B14 { virtual void f1(); };
struct B18 { virtual void f2(); void* descriptor; };
struct B20 { virtual void f3(); char p[0x68]; };
class IHasLocation { public: virtual void getLocation(); };
class IHasPrimaryPart { public: virtual void getPrimaryPart(); };
class PVInstance : public B0, public B14, public B18, public B20, public IHasPrimaryPart, public virtual IHasLocation { public: char pv[8]; virtual ~PVInstance(); };
class IMoving { public: virtual void moving(); char p[8]; };
class IRenderable { public: virtual void render(); char p[0xc]; };
class CameraSubject { public: virtual void cameraSubject(); char p[0x10]; };
class PartInstance : public PVInstance, public IMoving, public IRenderable, public CameraSubject {
public:
    char pad[0x240 - 0xcc];
    virtual ~PartInstance();
};
class BasicPartInstance : public PartInstance {
public:
    virtual ~BasicPartInstance();
};
template<class Base>
class SeatImpl : public Base {
    rbx::signals::scoped_connection c1;
    rbx::signals::scoped_connection c2;
public:
    virtual ~SeatImpl();
    virtual void getLocation();
};
template<class Base> SeatImpl<Base>::~SeatImpl() {}
template SeatImpl<BasicPartInstance>::~SeatImpl();
}
