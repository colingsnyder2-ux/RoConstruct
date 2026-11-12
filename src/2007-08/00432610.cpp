// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 00432610  unit: CDataModelPropGrid  size: 298 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00432610
//
// 00432610  6aff                 push -1
// 00432612  6872dd7300           push 0x73dd72
// 00432617  64a100000000         mov eax, dword ptr fs:[0]
// 0043261d  50                   push eax
// Destructor of a class with two bases: primary at +0 (dtor 0x430c40 called directly),
// secondary at +0xdc (vtable only, inline dtor). Members at 0xe8, 0xf0 (dllimport dtor via
// IAT 0x77ddbc), 0x120, 0x26c, 0x390/0x394/0x398 (owning pointers deleted through vtable slot 1),
// 0x39c, 0x3c8 -- offsets all from the target bytes; EH states 9..2 from the target stores.

class CPropBase
{
public:
    virtual ~CPropBase();
    char pad_[0xdc - 4];
};

class CPropMid : public CPropBase
{
public:
    virtual ~CPropMid() {}
};

class IPropListener
{
public:
    virtual ~IPropListener() {}
    virtual void OnChanged() = 0;
};

class CPropWnd
{
public:
    int Destroy();
};

class CRegistry
{
public:
    void Remove(IPropListener* l);
};
extern CRegistry g_registry;

class __declspec(dllimport) CImported
{
public:
    ~CImported() throw();
    char pad_[0x30];
};

class CMember120 { public: ~CMember120(); char pad_[0x14c]; };
class CMember26c { public: ~CMember26c(); char pad_[0x124]; };
class CMember39c { public: ~CMember39c(); char pad_[0x2c]; };
class CMember3c8 { public: ~CMember3c8(); };

class COwned
{
public:
    virtual void f0();
    virtual ~COwned();
};

template<class T> class owner_ptr
{
    T* p_;
public:
    ~owner_ptr() { delete p_; }
};

class CDataModelPropGrid : public CPropMid, public IPropListener
{
public:
    virtual ~CDataModelPropGrid();
    virtual void OnChanged();
    int pad_e0[2];
    CPropWnd* m_wnd;
    int pad_ec;
    CImported m_f0;
    CMember120 m_120;
    CMember26c m_26c;
    owner_ptr<COwned> m_390;
    owner_ptr<COwned> m_394;
    owner_ptr<COwned> m_398;
    CMember39c m_39c;
    CMember3c8 m_3c8;
};

CDataModelPropGrid::~CDataModelPropGrid()
{
    if (m_wnd)
    {
        m_wnd->Destroy();
        m_wnd = 0;
    }
    g_registry.Remove(this);
}
