// from server: 100% by colin
// from server: 94% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

namespace G3D {
class Vector2 {
public:
    float x, y;
    Vector2() : x(0.0f), y(0.0f) {}
    Vector2(const Vector2& v) { x = v.x; y = v.y; }
    Vector2& operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }
};
}

namespace RBX {
class Instance {
public:
    virtual ~Instance();
};
class GuiItem : public Instance {
public:
    virtual ~GuiItem();
};
}

struct SharedInstance {
    RBX::Instance* px;
    void* pn;
    RBX::Instance* get() const { return px; }
};

struct Children {
    void* proxy[3];
    SharedInstance* first;
    SharedInstance* last;
    SharedInstance* end;
    unsigned int size() const { return last - first; }
    const SharedInstance& operator[](unsigned int pos) const
    {
        if (pos >= size())
            _invalid_parameter_noinfo();
        return *(first + pos);
    }
};

typedef G3D::Vector2 Vec2;
struct GuiItem {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25();
    virtual Vec2 initial();
    virtual Vec2 offset();
    char padding[0x104];
    Children* children;
    unsigned int count();
    Vec2 f(GuiItem* stop);
};
Vec2 GuiItem::f(GuiItem* stop) {
 Vec2 result=initial();
 for(unsigned i=0;i<count();++i) {
  RBX::Instance* instance=(*children)[i].get();
  GuiItem* item=reinterpret_cast<GuiItem*>(dynamic_cast<RBX::GuiItem*>(instance));
  if(item) {
   if(item==stop) return result;
   result+=offset();
  }
 }
 return result;
}
