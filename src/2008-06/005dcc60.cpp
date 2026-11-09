// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_renderportablerectbody55fa2d066e9d3a20.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <string>
namespace G3D{
struct Vector2{float x,y;Vector2():x(0),y(0){}Vector2(float a,float b):x(a),y(b){}Vector2(const Vector2&v):x(v.x),y(v.y){}Vector2 operator+(const Vector2&v)const{return Vector2(x+v.x,y+v.y);}Vector2 operator*(float f)const{return Vector2(f*x,f*y);}};
struct Rect2D{Vector2 lo,hi;float x0()const{return lo.x;}float y0()const{return lo.y;}float x1()const{return hi.x;}float y1()const{return hi.y;}static Rect2D xyxy(const Vector2&a,const Vector2&b){Rect2D r;r.lo.x=a.x<b.x?a.x:b.x;r.lo.y=a.y<b.y?a.y:b.y;r.hi.x=a.x>b.x?a.x:b.x;r.hi.y=a.y>b.y?a.y:b.y;return r;}};
struct Color3{float r,g,b;static const Color3& black();static const Color3& white();};
struct Color4{float r,g,b,a;Color4(float r,float g,float b,float a):r(r),g(g),b(b),a(a){}Color4(const Color3&v,float alpha=1.0f){r=v.r;g=v.g;b=v.b;a=alpha;}Color4(const Color4&v){r=v.r;g=v.g;b=v.b;a=v.a;}static const Color4& clear();};
}
namespace RBX{
struct Rect{G3D::Vector2 low,high;Rect(float a,float b,float c,float d):low(a,b),high(c,d){}G3D::Vector2 center()const{return(low+high)*.5f;}G3D::Rect2D toRect2D()const{return G3D::Rect2D::xyxy(low,high);}};
struct Adorn{enum XAlign{XALIGN_RIGHT,XALIGN_LEFT,XALIGN_CENTER};enum YAlign{YALIGN_TOP,YALIGN_BASELINE,YALIGN_CENTER};enum Spacing{PROPORTIONAL_SPACING,FIXED_SPACING};virtual~Adorn();virtual void slot1();virtual void slot2();virtual void slot3();virtual G3D::Rect2D getViewport()const;virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void rect2d(const G3D::Rect2D&,const G3D::Color4&)const;virtual void slot12();virtual G3D::Vector2 drawFont2D(const std::string&,const G3D::Vector2&,double,const G3D::Color4&,const G3D::Color4&,XAlign,YAlign,Spacing)const;};
}
struct Message{char prefix[0x140];std::string text;void render(RBX::Adorn*);};
void Message::render(RBX::Adorn* adorn){G3D::Rect2D rect=adorn->getViewport();RBX::Rect area(0,0,0,0);area.low.x=rect.x0()+30.0f;area.low.y=rect.y0()+30.0f;area.high.x=rect.x1()*0.25f+30.0f;area.high.y=rect.y1()*0.25f+30.0f;G3D::Vector2 textPos=area.center();adorn->rect2d(area.toRect2D(),G3D::Color4(.5f,.5f,.5f,.5f));adorn->drawFont2D(text,textPos,14.0,G3D::Color3::white(),G3D::Color3::black(),RBX::Adorn::XALIGN_CENTER,RBX::Adorn::YALIGN_CENTER,RBX::Adorn::PROPORTIONAL_SPACING);}
