// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#pragma inline_depth(1)
namespace RBX {
class Name {
public:
    int dictionary;
    std::string str;
    const std::string& toString() const { return str; }
    const char* c_str() const { return str.c_str(); }
};
namespace Reflection {
class Descriptor {
public:
    virtual ~Descriptor();
    virtual bool isReadOnly() const;
    int a;
    int b;
    const Name& name;
};
template<class T> class TypedPropertyDescriptor : public Descriptor {};
}
}
namespace G3D { class Vector3; }
class CObject { public: virtual ~CObject(); };
class CCmdTarget : public CObject { public: char pad[0x1c]; };
class CXTPAccessible { public: virtual void accessible(); };
class CString;
class CXTPPropertyGridItem : public CCmdTarget, public CXTPAccessible {
public:
    CXTPPropertyGridItem(const char* caption, const char* value = 0, CString* bind = 0);
    virtual ~CXTPPropertyGridItem();
    void SetReadOnly(int readOnly);
    void SetFlags(int flags) { m_nFlags = flags; }
    char pad1[0xfc - 0x24];
    int m_nFlags;
    char pad2[0x114 - 0x100];
};
class CPropGrid {
public:
    class Item {
    public:
        Item(RBX::Reflection::Descriptor* desc, CPropGrid* grid);
        virtual ~Item();
        virtual void update();
        char pad[0x14];
    };
};
template<class T, class Base, class Desc>
class XItem : public Base, public CPropGrid::Item {
public:
    Desc* desc;
    XItem(Desc* desc, CPropGrid* grid)
        : Base(desc->name.c_str()), CPropGrid::Item(desc, grid), desc(desc)
    {
        this->SetFlags(1);
        this->SetReadOnly(desc->isReadOnly());
    }
    virtual ~XItem();
    virtual void accessible();
    virtual void update();
};
template class XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> >;


