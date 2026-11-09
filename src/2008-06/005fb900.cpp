// from server: 100% by EspClaude
// from server: 96% by Espeon
// roc 2008-06 005fb900  unit: RBX::LocalBackpackItem  size: 746 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fb900
//
// 005fb900  6aff                 push -1
// 005fb902  68c17d7d00           push 0x7d7dc1
// 005fb907  64a100000000         mov eax, dword ptr fs:[0]
// 005fb90d  50                   push eax
// 005fb90e  64892500000000       mov dword ptr fs:[0], esp
// 005fb915  81ec80000000         sub esp, 0x80
// 005fb91b  53                   push ebx
// 005fb91c  55                   push ebp
// 005fb91d  56                   push esi
// 005fb91e  57                   push edi
// 005fb91f  6a0c                 push 0xc
// 005fb921  8bf1                 mov esi, ecx
// 005fb923  e8487ef7ff           call 0x573770
// 005fb928  89442414             mov dword ptr [esp + 0x14], eax
// 005fb92c  83c404               add esp, 4
// 005fb92f  8d442430             lea eax, [esp + 0x30]
// 005fb933  50                   push eax
// 005fb934  8bce                 mov ecx, esi
// 005fb936  e8d579f7ff           call 0x573310
// 005fb93b  d9442438             fld dword ptr [esp + 0x38]
// 005fb93f  d9442430             fld dword ptr [esp + 0x30]
// 005fb943  8d4c2438             lea ecx, [esp + 0x38]
// 005fb947  dce9                 fsub st(1), st(0)
// 005fb949  51                   push ecx
// 005fb94a  d9c9                 fxch st(1)
// 005fb94c  8d542434             lea edx, [esp + 0x34]
// 005fb950  52                   push edx
// 005fb951  d80df8498200         fmul dword ptr [0x8249f8]
// 005fb957  8d442458             lea eax, [esp + 0x58]
// 005fb95b  d90534c48100         fld dword ptr [0x81c434]
// 005fb961  50                   push eax
// 005fb962  dcc2                 fadd st(2), st(0)
// 005fb964  d86c2448             fsubr dword ptr [esp + 0x48]
// 005fb968  d8e1                 fsub st(1)
// 005fb96a  d9c2                 fld st(2)
// 005fb96c  d8c2                 fadd st(2)
// 005fb96e  d9c1                 fld st(1)
// 005fb970  dec3                 faddp st(3)
// 005fb972  d9cb                 fxch st(3)
// 005fb974  d95c244c             fstp dword ptr [esp + 0x4c]
// 005fb978  d95c2450             fstp dword ptr [esp + 0x50]
// 005fb97c  d9c9                 fxch st(1)
// 005fb97e  d95c2454             fstp dword ptr [esp + 0x54]
// 005fb982  d95c2458             fstp dword ptr [esp + 0x58]
// 005fb986  e8457cefff           call 0x4f35d0
// 005fb98b  8bbc24ac000000       mov edi, dword ptr [esp + 0xac]
// 005fb992  8b1f                 mov ebx, dword ptr [edi]
// 005fb994  83c40c               add esp, 0xc
// 005fb997  83c32c               add ebx, 0x2c
// 005fb99a  e8f178f7ff           call 0x573290
// 005fb99f  8b13                 mov edx, dword ptr [ebx]
// 005fb9a1  50                   push eax
// 005fb9a2  8d4c2454             lea ecx, [esp + 0x54]
// 005fb9a6  51                   push ecx
// 005fb9a7  8bcf                 mov ecx, edi
// 005fb9a9  ffd2                 call edx
// 005fb9ab  e87090f1ff           call 0x514a20
// 005fb9b0  d900                 fld dword ptr [eax]
// 005fb9b2  d95c2420             fstp dword ptr [esp + 0x20]
// 005fb9b6  8d4c2440             lea ecx, [esp + 0x40]
// 005fb9ba  d94004               fld dword ptr [eax + 4]
// 005fb9bd  8d542450             lea edx, [esp + 0x50]
// 005fb9c1  d95c2424             fstp dword ptr [esp + 0x24]
// 005fb9c5  d94008               fld dword ptr [eax + 8]
// 005fb9c8  8d442448             lea eax, [esp + 0x48]
// 005fb9cc  50                   push eax
// 005fb9cd  d95c242c             fstp dword ptr [esp + 0x2c]
// 005fb9d1  d9e8                 fld1 
// 005fb9d3  51                   push ecx
// 005fb9d4  52                   push edx
// 005fb9d5  d95c2438             fstp dword ptr [esp + 0x38]
// 005fb9d9  e8f27befff           call 0x4f35d0
// 005fb9de  8b07                 mov eax, dword ptr [edi]
// 005fb9e0  8b402c               mov eax, dword ptr [eax + 0x2c]
// 005fb9e3  83c40c               add esp, 0xc
// 005fb9e6  8d4c2420             lea ecx, [esp + 0x20]
// 005fb9ea  51                   push ecx
// 005fb9eb  8d542454             lea edx, [esp + 0x54]
// 005fb9ef  52                   push edx
// 005fb9f0  8bcf                 mov ecx, edi
// 005fb9f2  ffd0                 call eax
// 005fb9f4  e86790f1ff           call 0x514a60
// 005fb9f9  d900                 fld dword ptr [eax]
// 005fb9fb  d95c2450             fstp dword ptr [esp + 0x50]
// 005fb9ff  d94004               fld dword ptr [eax + 4]
// 005fba02  d95c2454             fstp dword ptr [esp + 0x54]
// 005fba06  d94008               fld dword ptr [eax + 8]
// 005fba09  8b8e04010000         mov ecx, dword ptr [esi + 0x104]
// 005fba0f  d95c2458             fstp dword ptr [esp + 0x58]
// 005fba13  d9e8                 fld1 
// 005fba15  56                   push esi
// 005fba16  d95c2460             fstp dword ptr [esp + 0x60]
// 005fba1a  e8a1d0f5ff           call 0x558ac0
// 005fba1f  8d4c2414             lea ecx, [esp + 0x14]
// 005fba23  51                   push ecx
// 005fba24  8d542474             lea edx, [esp + 0x74]
// 005fba28  40                   inc eax
// 005fba29  52                   push edx
// 005fba2a  8944241c             mov dword ptr [esp + 0x1c], eax
// 005fba2e  e8bd24fcff           call 0x5bdef0
// 005fba33  83c408               add esp, 8
// 005fba36  8be8                 mov ebp, eax
// 005fba38  d9442448             fld dword ptr [esp + 0x48]
// 005fba3c  d8442440             fadd dword ptr [esp + 0x40]
// 005fba40  8b1f                 mov ebx, dword ptr [edi]
// 005fba42  d944244c             fld dword ptr [esp + 0x4c]
// 005fba46  6a00                 push 0
// 005fba48  d8442448             fadd dword ptr [esp + 0x48]
// 005fba4c  6a02                 push 2
// 005fba4e  d905ac9b8100         fld dword ptr [0x819bac]
// 005fba54  6a02                 push 2
// 005fba56  dcca                 fmul st(2), st(0)
// 005fba58  c78424a400000000000000 mov dword ptr [esp + 0xa4], 0
// 005fba63  dec9                 fmulp st(1)
// 005fba65  83c334               add ebx, 0x34
// 005fba68  d9c9                 fxch st(1)
// 005fba6a  d95c2424             fstp dword ptr [esp + 0x24]
// 005fba6e  d95c2428             fstp dword ptr [esp + 0x28]
// 005fba72  e899f41b00           call 0x7baf10
// 005fba77  db44241c             fild dword ptr [esp + 0x1c]
// 005fba7b  50                   push eax
// 005fba7c  8d442460             lea eax, [esp + 0x60]
// 005fba80  50                   push eax
// 005fba81  8b03                 mov eax, dword ptr [ebx]
// 005fba83  83ec08               sub esp, 8
// 005fba86  dd1c24               fstp qword ptr [esp]
// 005fba89  8d4c2434             lea ecx, [esp + 0x34]
// 005fba8d  51                   push ecx
// 005fba8e  55                   push ebp
// 005fba8f  8d542444             lea edx, [esp + 0x44]
// 005fba93  52                   push edx
// 005fba94  8bcf                 mov ecx, edi
// 005fba96  ffd0                 call eax
// 005fba98  8d4c2470             lea ecx, [esp + 0x70]
// 005fba9c  c7842498000000ffffffff mov dword ptr [esp + 0x98], 0xffffffff
// 005fbaa7  ff1568248000         call dword ptr [0x802468]
// 005fbaad  8b8e48010000         mov ecx, dword ptr [esi + 0x148]
// 005fbab3  85c9                 test ecx, ecx
// 005fbab5  0f840c010000         je 0x5fbbc7
// 005fbabb  8b11                 mov edx, dword ptr [ecx]
// 005fbabd  8b8280000000         mov eax, dword ptr [edx + 0x80]
// 005fbac3  ffd0                 call eax
// 005fbac5  84c0                 test al, al
// 005fbac7  7453                 je 0x5fbb1c
// 005fbac9  e8128ef1ff           call 0x5148e0
// 005fbace  d900                 fld dword ptr [eax]
// 005fbad0  d95c2450             fstp dword ptr [esp + 0x50]
// 005fbad4  8d4c2438             lea ecx, [esp + 0x38]
// 005fbad8  d94004               fld dword ptr [eax + 4]
// 005fbadb  51                   push ecx
// 005fbadc  d95c2458             fstp dword ptr [esp + 0x58]
// 005fbae0  8d542434             lea edx, [esp + 0x34]
// 005fbae4  d94008               fld dword ptr [eax + 8]
// 005fbae7  52                   push edx
// 005fbae8  d95c2460             fstp dword ptr [esp + 0x60]
// 005fbaec  8d442448             lea eax, [esp + 0x48]
// 005fbaf0  d9e8                 fld1 
// 005fbaf2  50                   push eax
// 005fbaf3  d95c2468             fstp dword ptr [esp + 0x68]
// 005fbaf7  e8d47aefff           call 0x4f35d0
// 005fbafc  d90580e38100         fld dword ptr [0x81e380]
// 005fbb02  8b17                 mov edx, dword ptr [edi]
// 005fbb04  8b5228               mov edx, dword ptr [edx + 0x28]
// 005fbb07  83c40c               add esp, 0xc
// 005fbb0a  8d442450             lea eax, [esp + 0x50]
// 005fbb0e  50                   push eax
// 005fbb0f  51                   push ecx
// 005fbb10  8d4c2448             lea ecx, [esp + 0x48]
// 005fbb14  d91c24               fstp dword ptr [esp]
// 005fbb17  51                   push ecx
// 005fbb18  8bcf                 mov ecx, edi
// 005fbb1a  ffd2                 call edx
// 005fbb1c  8b8e48010000         mov ecx, dword ptr [esi + 0x148]
// 005fbb22  8d442470             lea eax, [esp + 0x70]
// 005fbb26  50                   push eax
// 005fbb27  e83436fdff           call 0x5cf160
// 005fbb2c  50                   push eax
// 005fbb2d  8dae50010000         lea ebp, [esi + 0x150]
// 005fbb33  57                   push edi
// 005fbb34  8bcd                 mov ecx, ebp
// 005fbb36  c78424a000000001000000 mov dword ptr [esp + 0xa0], 1
// 005fbb41  e80a6c0400           call 0x642750
// 005fbb46  8d4c2470             lea ecx, [esp + 0x70]
// 005fbb4a  8ad8                 mov bl, al
// 005fbb4c  c7842498000000ffffffff mov dword ptr [esp + 0x98], 0xffffffff
// 005fbb57  ff1568248000         call dword ptr [0x802468]
// 005fbb5d  84db                 test bl, bl
// 005fbb5f  7451                 je 0x5fbbb2
// 005fbb61  db442410             fild dword ptr [esp + 0x10]
// 005fbb65  8b9644010000         mov edx, dword ptr [esi + 0x144]
// 005fbb6b  d9442430             fld dword ptr [esp + 0x30]
// 005fbb6f  8b8e48010000         mov ecx, dword ptr [esi + 0x148]
// 005fbb75  52                   push edx
// 005fbb76  d8c1                 fadd st(1)
// 005fbb78  8d442464             lea eax, [esp + 0x64]
// 005fbb7c  50                   push eax
// 005fbb7d  d95c2468             fstp dword ptr [esp + 0x68]
// 005fbb81  d944243c             fld dword ptr [esp + 0x3c]
// 005fbb85  d8c1                 fadd st(1)
// 005fbb87  d95c246c             fstp dword ptr [esp + 0x6c]
// 005fbb8b  d9442440             fld dword ptr [esp + 0x40]
// 005fbb8f  d8e1                 fsub st(1)
// 005fbb91  d95c2470             fstp dword ptr [esp + 0x70]
// 005fbb95  d86c2444             fsubr dword ptr [esp + 0x44]
// 005fbb99  d95c2474             fstp dword ptr [esp + 0x74]
// 005fbb9d  8b11                 mov edx, dword ptr [ecx]
// 005fbb9f  8b427c               mov eax, dword ptr [edx + 0x7c]
// 005fbba2  ffd0                 call eax
// 005fbba4  0fb6c8               movzx ecx, al
// 005fbba7  51                   push ecx
// 005fbba8  57                   push edi
// 005fbba9  8bcd                 mov ecx, ebp
// 005fbbab  e830720400           call 0x642de0
// 005fbbb0  eb1d                 jmp 0x5fbbcf
// 005fbbb2  8b8648010000         mov eax, dword ptr [esi + 0x148]
// 005fbbb8  8b16                 mov edx, dword ptr [esi]
// 005fbbba  8b5204               mov edx, dword ptr [edx + 4]
// 005fbbbd  0510010000           add eax, 0x110
// 005fbbc2  50                   push eax
// 005fbbc3  8bce                 mov ecx, esi
// 005fbbc5  ffd2                 call edx
// 005fbbc7  57                   push edi
// 005fbbc8  8bce                 mov ecx, esi
// 005fbbca  e851690400           call 0x642520
// 005fbbcf  8b8c2490000000       mov ecx, dword ptr [esp + 0x90]
// 005fbbd6  5f                   pop edi
// 005fbbd7  5e                   pop esi
// 005fbbd8  5d                   pop ebp
// 005fbbd9  5b                   pop ebx
// 005fbbda  64890d00000000       mov dword ptr fs:[0], ecx
// 005fbbe1  81c48c000000         add esp, 0x8c
// 005fbbe7  c20400               ret 4

// from server: 86% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <string>
#include <string.h>
namespace G3D {
struct Vector2 {
 float x,y;
 Vector2():x(0),y(0){}Vector2(float a,float b):x(a),y(b){}Vector2(const Vector2&r):x(r.x),y(r.y){}
 Vector2 operator+(const Vector2&r)const{return Vector2(x+r.x,y+r.y);}Vector2 operator-(const Vector2&r)const{return Vector2(x-r.x,y-r.y);}Vector2 operator*(float f)const{return Vector2(x*f,y*f);}
};
struct Vector3;struct CoordinateFrame;struct AABox;struct Sphere;struct Ray;struct LineSegment;
struct Color3 {float r,g,b;static const Color3&gray();static const Color3&white();static const Color3&green();};
struct Color4 {float r,g,b,a;Color4(const Color3&c,float alpha=1):r(c.r),g(c.g),b(c.b),a(alpha){}static const Color4&zero();};
struct Rect2D {Vector2 min,max;static Rect2D xyxy(const Vector2&,const Vector2&);};
template<class T>struct ReferenceCountedPointer {T*pointer;};
}
namespace boost {template<class T>struct shared_ptr {T*px;void*pi;T*get()const{return px;}T*operator->()const{return px;}};}
namespace RBX {
struct TextureProxyBase;
struct Adorn {
 enum Spacing {PROPORTIONAL_SPACING,FIXED_SPACING};enum XAlign{XALIGN_RIGHT,XALIGN_LEFT,XALIGN_CENTER};enum YAlign{YALIGN_TOP,YALIGN_BASELINE,YALIGN_CENTER,YALIGN_BOTTOM};
 virtual ~Adorn();
 virtual G3D::ReferenceCountedPointer<TextureProxyBase>createTextureProxy(const std::string&)=0;
 virtual void prepareRenderPass()=0;virtual void finishRenderPass()=0;virtual G3D::Rect2D getViewport()const=0;virtual int getWidth()const=0;virtual int getHeight()const=0;
 virtual void setTexture(int,G3D::ReferenceCountedPointer<TextureProxyBase>)=0;virtual G3D::Rect2D getTextureSize(G3D::ReferenceCountedPointer<TextureProxyBase>)const=0;
 virtual void line2d(const G3D::Vector2&,const G3D::Vector2&,const G3D::Color4&)const=0;
 virtual void outlineRect2d(const G3D::Rect2D&,float,const G3D::Color4&)const=0;
 virtual void rect2d(const G3D::Rect2D&,const G3D::Color4&)const=0;
 virtual G3D::Vector2 get2DStringBounds(const std::string&,double,Spacing)const=0;
 virtual G3D::Vector2 drawFont2D(const std::string&,const G3D::Vector2&,double,const G3D::Color4&,const G3D::Color4&,XAlign,YAlign,Spacing)const=0;
};
struct Rect {
 G3D::Vector2 low,high;
 Rect(const G3D::Vector2&l,const G3D::Vector2&h):low(l),high(h){}
 Rect(float x0,float y0,float x1,float y1):low(x0,y0),high(x1,y1){}
 G3D::Rect2D toRect2D()const{return G3D::Rect2D::xyxy(low,high);}
 G3D::Vector2 size()const{return high-low;}G3D::Vector2 center()const{return (low+high)*.5f;}
 static Rect fromLowSize(const G3D::Vector2&l,const G3D::Vector2&s){return Rect(l,l+s);}
};
struct Name;
struct ContentId {std::string id;const Name*mimeTypePtr;};struct TextureId:ContentId{};
struct Instance {
 virtual ~Instance();virtual void setName(const std::string&);
 char opaque[0x104-4];Instance*parent;char opaque108[8];std::string name;
 int findChildIndex(const Instance*)const;
};
struct GuiItem:Instance {
 Rect getMyRect()const;static const G3D::Color4&translucentBackdrop();
};
struct GuiRoot {static int normalizedFontSize(int);};
struct Widget:GuiItem {
 enum WidgetState{NOTHING,HOVER,DOWN_OVER,DOWN_AWAY};
 char opaque12c[0x144-0x12c];WidgetState widgetState;
 void render2d(Adorn*);
};
struct BackpackItem:Widget {
 TextureId getTextureId()const;
 virtual void pv2(); virtual void pv3(); virtual void pv4(); virtual void pv5(); virtual void pv6(); virtual void pv7(); virtual void pv8(); virtual void pv9(); virtual void pv10(); virtual void pv11(); virtual void pv12(); virtual void pv13(); virtual void pv14(); virtual void pv15(); virtual void pv16(); virtual void pv17(); virtual void pv18(); virtual void pv19(); virtual void pv20(); virtual void pv21(); virtual void pv22(); virtual void pv23(); virtual void pv24(); virtual void pv25(); virtual void pv26(); virtual void pv27(); virtual void pv28(); virtual void pv29(); virtual void pv30();
 virtual bool drawEnabled()const;virtual bool drawSelected()const;
};
struct GuiDrawImage {
 TextureId currentTexture;G3D::ReferenceCountedPointer<TextureProxyBase>normal,disable,hover,down;G3D::Vector2 size;
 bool setImage(Adorn*,const TextureId&);void render2d(Adorn*,bool,Rect&,Widget::WidgetState);
};
template<class T>struct StringConverter;template<>struct StringConverter<int>{static std::string convertToString(const int&);};
struct LocalBackpackItem:Widget {
 boost::shared_ptr<BackpackItem>myItem;GuiDrawImage guiImageDraw;
 void render2d(Adorn*);
 void drawBack(Adorn*,const Rect&,float,int);
};
typedef char LayoutCheck[(sizeof(std::string)==28&&sizeof(Instance)==0x12c&&sizeof(Widget)==0x148&&sizeof(GuiDrawImage)==56)?1:-1];
__forceinline void LocalBackpackItem::drawBack(Adorn*adorn,const Rect&rect,float side,int fontSize){
 Rect numberRect=Rect::fromLowSize(G3D::Vector2(rect.low.x+2,rect.high.y-2-side),G3D::Vector2(side,side));
 adorn->rect2d(rect.toRect2D(),translucentBackdrop());
 adorn->rect2d(numberRect.toRect2D(),G3D::Color3::gray());
 {G3D::Color4 fontColor(G3D::Color3::white());
 int number=parent->findChildIndex(this)+1;
 adorn->drawFont2D(StringConverter<int>::convertToString(number),numberRect.center(),fontSize,fontColor,G3D::Color4::zero(),Adorn::XALIGN_CENTER,Adorn::YALIGN_CENTER,Adorn::PROPORTIONAL_SPACING);
 }
}
void LocalBackpackItem::render2d(Adorn*adorn){
 int fontSize=GuiRoot::normalizedFontSize(12);
 Rect rect=getMyRect();
 float side=rect.size().x*.2f;
 drawBack(adorn,rect,side,fontSize);
 if(myItem.get()){
  if(myItem->drawSelected())adorn->outlineRect2d(rect.toRect2D(),3,G3D::Color3::green());
  if(guiImageDraw.setImage(adorn,myItem->getTextureId())){
   Rect imageRect(rect.low.x+fontSize,rect.low.y+fontSize,rect.high.x-fontSize,rect.high.y-fontSize);
   guiImageDraw.render2d(adorn,myItem->drawEnabled(),imageRect,widgetState);
  }else{setName(myItem->name);Widget::render2d(adorn);}
 }else Widget::render2d(adorn);
}
}
