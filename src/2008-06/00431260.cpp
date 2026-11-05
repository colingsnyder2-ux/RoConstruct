// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    typedef T* shared_ptr::*unspecified_bool_type;
    T* px;
    shared_count pn;
    template<class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
    T* operator->() const { return px; }
    T* get() const { return px; }
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

class String {
public:
    __declspec(dllimport) String(const char* s);
    __declspec(dllimport) String(const String& s);
    __declspec(dllimport) ~String();
    char storage[0x1c];
};

struct NMHDR { void* hwndFrom; unsigned int idFrom; unsigned int code; };
typedef long LRESULT;

namespace G3D {
class Color3uint8 {
public:
    unsigned char r, g, b;
};
}

class ColorPicker {
public:
    unsigned long GetColor() const;
};

struct NMCOLORPICKER {
    NMHDR hdr;
    ColorPicker* picker;
};

namespace RBX {
class BrickColor {
public:
    int number;
    BrickColor() {}
    bool operator!=(const BrickColor& other) const { return number != other.number; }
    static BrickColor closest(G3D::Color3uint8 color);
};

class ColorSetting {
public:
    char pad[0x20];
    BrickColor color;
    void raiseChanged(BrickColor value);
    void setColor(BrickColor value)
    {
        if (color != value)
        {
            color = value;
            raiseChanged(value);
        }
    }
};
extern ColorSetting fillColor;

class IDataState {
public:
    virtual void a();
};

class Verb {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void doIt(IDataState* dataState);
};

class VerbContainer {
public:
    virtual ~VerbContainer();
    char vpad[0x24];
    Verb* getVerb(String name);
};

class DataModelBase {
public:
    virtual ~DataModelBase();
    char pad[0x1c4];
};

class DataModel : public DataModelBase, public VerbContainer, public IDataState {
public:
    class scoped_lock {
    public:
        scoped_lock(shared_ptr<const DataModel> dm);
        ~scoped_lock();
        int a, b, c;
    };
};
}

class CDataModelPropGrid {
public:
    static shared_ptr<RBX::DataModel> getDataModel() throw();
    void OnFillColorChanged(NMHDR* pNMHDR, LRESULT* pResult);
};

void CDataModelPropGrid::OnFillColorChanged(NMHDR* pNMHDR, LRESULT* pResult)
{
    ColorPicker* picker = reinterpret_cast<NMCOLORPICKER*>(pNMHDR)->picker;
    G3D::Color3uint8 color;
    color.r = (unsigned char)(picker->GetColor());
    color.g = (unsigned char)(((unsigned short)picker->GetColor()) >> 8);
    color.b = (unsigned char)(picker->GetColor() >> 16);
    RBX::fillColor.setColor(RBX::BrickColor::closest(color));
    if (getDataModel())
    {
        RBX::DataModel::scoped_lock lock(getDataModel());
        RBX::Verb* verb = getDataModel()->getVerb("FillTool");
        verb->doIt(getDataModel().get());
    }
    *pResult = 1;
}
