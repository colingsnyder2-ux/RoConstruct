// from server: 82% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 005d05d0  unit: RBX::VHopperBin::?$FactoryProduct  size: 830 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d05d0
//
// 005d05d0  6aff                 push -1
// 005d05d2  6809e77c00           push 0x7ce709
// 005d05d7  64a100000000         mov eax, dword ptr fs:[0]
// 005d05dd  50                   push eax
// 005d05de  64892500000000       mov dword ptr fs:[0], esp
// 005d05e5  81ec84000000         sub esp, 0x84
// 005d05eb  55                   push ebp
// 005d05ec  56                   push esi
// 005d05ed  8be9                 mov ebp, ecx
// 005d05ef  57                   push edi
// 005d05f0  55                   push ebp
// 005d05f1  c644241300           mov byte ptr [esp + 0x13], 0
// 005d05f6  e85518ecff           call 0x491e50
// 005d05fb  83c404               add esp, 4
// 005d05fe  85c0                 test eax, eax
// 005d0600  744a                 je 0x5d064c
// 005d0602  83b83c04000000       cmp dword ptr [eax + 0x43c], 0
// 005d0609  7441                 je 0x5d064c
// 005d060b  d905784d9700         fld dword ptr [0x974d78]
// 005d0611  c644240f01           mov byte ptr [esp + 0xf], 1
// 005d0616  d95c2440             fstp dword ptr [esp + 0x40]
// 005d061a  d9057c4d9700         fld dword ptr [0x974d7c]
// 005d0620  d95c2444             fstp dword ptr [esp + 0x44]
// 005d0624  e87795f3ff           call 0x509ba0
// 005d0629  d900                 fld dword ptr [eax]
// 005d062b  d95c2410             fstp dword ptr [esp + 0x10]
// 005d062f  d94004               fld dword ptr [eax + 4]
// 005d0632  8d442410             lea eax, [esp + 0x10]
// 005d0636  d95c2414             fstp dword ptr [esp + 0x14]
// 005d063a  d9442440             fld dword ptr [esp + 0x40]
// 005d063e  d95c2418             fstp dword ptr [esp + 0x18]
// 005d0642  d9442444             fld dword ptr [esp + 0x44]
// 005d0646  d95c241c             fstp dword ptr [esp + 0x1c]
// 005d064a  eb0c                 jmp 0x5d0658
// 005d064c  8d442420             lea eax, [esp + 0x20]
// 005d0650  50                   push eax
// 005d0651  8bcd                 mov ecx, ebp
// 005d0653  e8b82cfaff           call 0x573310
// 005d0658  d900                 fld dword ptr [eax]
// 005d065a  6a0c                 push 0xc
// 005d065c  d95c2434             fstp dword ptr [esp + 0x34]
// 005d0660  d94004               fld dword ptr [eax + 4]
// 005d0663  d95c2438             fstp dword ptr [esp + 0x38]
// 005d0667  d94008               fld dword ptr [eax + 8]
// 005d066a  d95c243c             fstp dword ptr [esp + 0x3c]
// 005d066e  d9400c               fld dword ptr [eax + 0xc]
// 005d0671  d95c2440             fstp dword ptr [esp + 0x40]
// 005d0675  e8f630faff           call 0x573770
// 005d067a  d944243c             fld dword ptr [esp + 0x3c]
// 005d067e  8bb424a4000000       mov esi, dword ptr [esp + 0xa4]
// 005d0685  d9442434             fld dword ptr [esp + 0x34]
// 005d0689  83c404               add esp, 4
// 005d068c  807c240f00           cmp byte ptr [esp + 0xf], 0
// 005d0691  dce9                 fsub st(1), st(0)
// 005d0693  d9c9                 fxch st(1)
// 005d0695  89442448             mov dword ptr [esp + 0x48], eax
// 005d0699  d80df8498200         fmul dword ptr [0x8249f8]
// 005d069f  d90534c48100         fld dword ptr [0x81c434]
// 005d06a5  dcc2                 fadd st(2), st(0)
// 005d06a7  d86c243c             fsubr dword ptr [esp + 0x3c]
// 005d06ab  d8e1                 fsub st(1)
// 005d06ad  d9c2                 fld st(2)
// 005d06af  d8c2                 fadd st(2)
// 005d06b1  d9c1                 fld st(1)
// 005d06b3  dec3                 faddp st(3)
// 005d06b5  d9cb                 fxch st(3)
// 005d06b7  d95c2410             fstp dword ptr [esp + 0x10]
// 005d06bb  d95c2414             fstp dword ptr [esp + 0x14]
// 005d06bf  d9c9                 fxch st(1)
// 005d06c1  d95c2418             fstp dword ptr [esp + 0x18]
// 005d06c5  d95c241c             fstp dword ptr [esp + 0x1c]
// 005d06c9  752d                 jne 0x5d06f8
// 005d06cb  8d4c2438             lea ecx, [esp + 0x38]
// 005d06cf  51                   push ecx
// 005d06d0  8d542434             lea edx, [esp + 0x34]
// 005d06d4  52                   push edx
// 005d06d5  8d442428             lea eax, [esp + 0x28]
// 005d06d9  50                   push eax
// 005d06da  e8f12ef2ff           call 0x4f35d0
// 005d06df  8b3e                 mov edi, dword ptr [esi]
// 005d06e1  83c40c               add esp, 0xc
// 005d06e4  83c72c               add edi, 0x2c
// 005d06e7  e8a42bfaff           call 0x573290
// 005d06ec  8b17                 mov edx, dword ptr [edi]
// 005d06ee  50                   push eax
// 005d06ef  8d4c2424             lea ecx, [esp + 0x24]
// 005d06f3  51                   push ecx
// 005d06f4  8bce                 mov ecx, esi
// 005d06f6  ffd2                 call edx
// 005d06f8  8b4500               mov eax, dword ptr [ebp]
// 005d06fb  8b5078               mov edx, dword ptr [eax + 0x78]
// 005d06fe  8bcd                 mov ecx, ebp
// 005d0700  ffd2                 call edx
// 005d0702  84c0                 test al, al
// 005d0704  0f840d010000         je 0x5d0817
// 005d070a  e81143f4ff           call 0x514a20
// 005d070f  d900                 fld dword ptr [eax]
// 005d0711  d95c244c             fstp dword ptr [esp + 0x4c]
// 005d0715  8d4c2410             lea ecx, [esp + 0x10]
// 005d0719  d94004               fld dword ptr [eax + 4]
// 005d071c  8d542420             lea edx, [esp + 0x20]
// 005d0720  d95c2450             fstp dword ptr [esp + 0x50]
// 005d0724  d94008               fld dword ptr [eax + 8]
// 005d0727  8d442418             lea eax, [esp + 0x18]
// 005d072b  50                   push eax
// 005d072c  d95c2458             fstp dword ptr [esp + 0x58]
// 005d0730  d9e8                 fld1 
// 005d0732  51                   push ecx
// 005d0733  52                   push edx
// 005d0734  d95c2464             fstp dword ptr [esp + 0x64]
// 005d0738  e8932ef2ff           call 0x4f35d0
// 005d073d  8b06                 mov eax, dword ptr [esi]
// 005d073f  8b402c               mov eax, dword ptr [eax + 0x2c]
// 005d0742  83c40c               add esp, 0xc
// 005d0745  8d4c244c             lea ecx, [esp + 0x4c]
// 005d0749  51                   push ecx
// 005d074a  8d542424             lea edx, [esp + 0x24]
// 005d074e  52                   push edx
// 005d074f  8bce                 mov ecx, esi
// 005d0751  ffd0                 call eax
// 005d0753  e80843f4ff           call 0x514a60
// 005d0758  d900                 fld dword ptr [eax]
// 005d075a  8b8d04010000         mov ecx, dword ptr [ebp + 0x104]
// 005d0760  d95c2420             fstp dword ptr [esp + 0x20]
// 005d0764  d94004               fld dword ptr [eax + 4]
// 005d0767  d95c2424             fstp dword ptr [esp + 0x24]
// 005d076b  d94008               fld dword ptr [eax + 8]
// 005d076e  d95c2428             fstp dword ptr [esp + 0x28]
// 005d0772  d9e8                 fld1 
// 005d0774  d95c242c             fstp dword ptr [esp + 0x2c]
// 005d0778  85c9                 test ecx, ecx
// 005d077a  7408                 je 0x5d0784
// 005d077c  55                   push ebp
// 005d077d  e83e83f8ff           call 0x558ac0
// 005d0782  eb03                 jmp 0x5d0787
// 005d0784  83c8ff               or eax, 0xffffffff
// 005d0787  53                   push ebx
// 005d0788  8d4c2444             lea ecx, [esp + 0x44]
// 005d078c  51                   push ecx
// 005d078d  8d54247c             lea edx, [esp + 0x7c]
// 005d0791  40                   inc eax
// 005d0792  52                   push edx
// 005d0793  8944244c             mov dword ptr [esp + 0x4c], eax
// 005d0797  e854d7feff           call 0x5bdef0
// 005d079c  83c408               add esp, 8
// 005d079f  8bd8                 mov ebx, eax
// 005d07a1  d944241c             fld dword ptr [esp + 0x1c]
// 005d07a5  d8442414             fadd dword ptr [esp + 0x14]
// 005d07a9  8b3e                 mov edi, dword ptr [esi]
// 005d07ab  d9442420             fld dword ptr [esp + 0x20]
// 005d07af  6a00                 push 0
// 005d07b1  d844241c             fadd dword ptr [esp + 0x1c]
// 005d07b5  6a02                 push 2
// 005d07b7  d905ac9b8100         fld dword ptr [0x819bac]
// 005d07bd  6a02                 push 2
// 005d07bf  dcca                 fmul st(2), st(0)
// 005d07c1  c78424a800000000000000 mov dword ptr [esp + 0xa8], 0
// 005d07cc  dec9                 fmulp st(1)
// 005d07ce  83c734               add edi, 0x34
// 005d07d1  d9c9                 fxch st(1)
// 005d07d3  d95c246c             fstp dword ptr [esp + 0x6c]
// 005d07d7  d95c2470             fstp dword ptr [esp + 0x70]
// 005d07db  e830a71e00           call 0x7baf10
// 005d07e0  db442458             fild dword ptr [esp + 0x58]
// 005d07e4  50                   push eax
// 005d07e5  8d442434             lea eax, [esp + 0x34]
// 005d07e9  50                   push eax
// 005d07ea  8b07                 mov eax, dword ptr [edi]
// 005d07ec  83ec08               sub esp, 8
// 005d07ef  dd1c24               fstp qword ptr [esp]
// 005d07f2  8d4c247c             lea ecx, [esp + 0x7c]
// 005d07f6  51                   push ecx
// 005d07f7  53                   push ebx
// 005d07f8  8d542474             lea edx, [esp + 0x74]
// 005d07fc  52                   push edx
// 005d07fd  8bce                 mov ecx, esi
// 005d07ff  ffd0                 call eax
// 005d0801  8d4c2478             lea ecx, [esp + 0x78]
// 005d0805  c784249c000000ffffffff mov dword ptr [esp + 0x9c], 0xffffffff
// 005d0810  ff1568248000         call dword ptr [0x802468]
// 005d0816  5b                   pop ebx
// 005d0817  8b5500               mov edx, dword ptr [ebp]
// 005d081a  8b8280000000         mov eax, dword ptr [edx + 0x80]
// 005d0820  8bcd                 mov ecx, ebp
// 005d0822  ffd0                 call eax
// 005d0824  84c0                 test al, al
// 005d0826  7453                 je 0x5d087b
// 005d0828  e8b340f4ff           call 0x5148e0
// 005d082d  d900                 fld dword ptr [eax]
// 005d082f  d95c2420             fstp dword ptr [esp + 0x20]
// 005d0833  8d4c2438             lea ecx, [esp + 0x38]
// 005d0837  d94004               fld dword ptr [eax + 4]
// 005d083a  51                   push ecx
// 005d083b  d95c2428             fstp dword ptr [esp + 0x28]
// 005d083f  8d542434             lea edx, [esp + 0x34]
// 005d0843  d94008               fld dword ptr [eax + 8]
// 005d0846  52                   push edx
// 005d0847  d95c2430             fstp dword ptr [esp + 0x30]
// 005d084b  8d442418             lea eax, [esp + 0x18]
// 005d084f  d9e8                 fld1 
// 005d0851  50                   push eax
// 005d0852  d95c2438             fstp dword ptr [esp + 0x38]
// 005d0856  e8752df2ff           call 0x4f35d0
// 005d085b  d90580e38100         fld dword ptr [0x81e380]
// 005d0861  8b16                 mov edx, dword ptr [esi]
// 005d0863  8b5228               mov edx, dword ptr [edx + 0x28]
// 005d0866  83c40c               add esp, 0xc
// 005d0869  8d442420             lea eax, [esp + 0x20]
// 005d086d  50                   push eax
// 005d086e  51                   push ecx
// 005d086f  8d4c2418             lea ecx, [esp + 0x18]
// 005d0873  d91c24               fstp dword ptr [esp]
// 005d0876  51                   push ecx
// 005d0877  8bce                 mov ecx, esi
// 005d0879  ffd2                 call edx
// 005d087b  8d8580010000         lea eax, [ebp + 0x180]
// 005d0881  50                   push eax
// 005d0882  8dbd48010000         lea edi, [ebp + 0x148]
// 005d0888  56                   push esi
// 005d0889  8bcf                 mov ecx, edi
// 005d088b  e8c01e0700           call 0x642750
// 005d0890  8bcd                 mov ecx, ebp
// 005d0892  84c0                 test al, al
// 005d0894  7458                 je 0x5d08ee
// 005d0896  8b5500               mov edx, dword ptr [ebp]
// 005d0899  8b4278               mov eax, dword ptr [edx + 0x78]
// 005d089c  ffd0                 call eax
// 005d089e  84c0                 test al, al
// 005d08a0  7506                 jne 0x5d08a8
// 005d08a2  3844240f             cmp byte ptr [esp + 0xf], al
// 005d08a6  7402                 je 0x5d08aa
// 005d08a8  b001                 mov al, 1
// 005d08aa  db442448             fild dword ptr [esp + 0x48]
// 005d08ae  8b8d44010000         mov ecx, dword ptr [ebp + 0x144]
// 005d08b4  d9442430             fld dword ptr [esp + 0x30]
// 005d08b8  51                   push ecx
// 005d08b9  8d542468             lea edx, [esp + 0x68]
// 005d08bd  d8c1                 fadd st(1)
// 005d08bf  52                   push edx
// 005d08c0  50                   push eax
// 005d08c1  56                   push esi
// 005d08c2  d95c2474             fstp dword ptr [esp + 0x74]
// 005d08c6  8bcf                 mov ecx, edi
// 005d08c8  d9442444             fld dword ptr [esp + 0x44]
// 005d08cc  d8c1                 fadd st(1)
// 005d08ce  d95c2478             fstp dword ptr [esp + 0x78]
// 005d08d2  d9442448             fld dword ptr [esp + 0x48]
// 005d08d6  d8e1                 fsub st(1)
// 005d08d8  d95c247c             fstp dword ptr [esp + 0x7c]
// 005d08dc  d86c244c             fsubr dword ptr [esp + 0x4c]
// 005d08e0  d99c2480000000       fstp dword ptr [esp + 0x80]
// 005d08e7  e8f4240700           call 0x642de0
// 005d08ec  eb06                 jmp 0x5d08f4
// 005d08ee  56                   push esi
// 005d08ef  e82c1c0700           call 0x642520
// 005d08f4  8b8c2490000000       mov ecx, dword ptr [esp + 0x90]
// 005d08fb  5f                   pop edi
// 005d08fc  5e                   pop esi
// 005d08fd  5d                   pop ebp
// 005d08fe  64890d00000000       mov dword ptr fs:[0], ecx
// 005d0905  81c490000000         add esp, 0x90
// 005d090b  c20400               ret 4

// from server: 86% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <string>
#include <string.h>
namespace G3D {
struct Vector2 {
 float x,y;
 static const Vector2&zero();
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
 Rect(const G3D::Vector2&s):low(G3D::Vector2::zero()),high(s){}
 Rect(const G3D::Vector2&l,const G3D::Vector2&h):low(l),high(h){}
 Rect(float x0,float y0,float x1,float y1):low(x0,y0),high(x1,y1){}
 G3D::Rect2D toRect2D()const{return G3D::Rect2D::xyxy(low,high);}
 G3D::Vector2 size()const{return high-low;}G3D::Vector2 center()const{return (low+high)*.5f;}
 Rect inset(int n){return Rect(low.x+n,low.y+n,high.x-n,high.y-n);}
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
struct GuiRoot {static int normalizedFontSize(int);static G3D::Vector2 canvasSize;static G3D::Vector2 getCanvasSize(){return canvasSize;}};
struct Widget:GuiItem {
 enum WidgetState{NOTHING,HOVER,DOWN_OVER,DOWN_AWAY};
 char opaque12c[0x144-0x12c];WidgetState widgetState;
 void render2d(Adorn*);
};
struct GuiDrawImage {
 TextureId currentTexture;G3D::ReferenceCountedPointer<TextureProxyBase>normal,disable,hover,down;G3D::Vector2 size;
 bool setImage(Adorn*,const TextureId&);void render2d(Adorn*,bool,Rect&,Widget::WidgetState);
};
template<class T>struct StringConverter;template<>struct StringConverter<int>{static std::string convertToString(const int&);};
struct Workspace {char opaque[0x43c];int overlayLayout;static Workspace*findWorkspace(const Instance*);};
struct BackpackItem:Widget {
 GuiDrawImage guiImageDraw;TextureId textureId;
 virtual void pv2(); virtual void pv3(); virtual void pv4(); virtual void pv5(); virtual void pv6(); virtual void pv7(); virtual void pv8(); virtual void pv9(); virtual void pv10(); virtual void pv11(); virtual void pv12(); virtual void pv13(); virtual void pv14(); virtual void pv15(); virtual void pv16(); virtual void pv17(); virtual void pv18(); virtual void pv19(); virtual void pv20(); virtual void pv21(); virtual void pv22(); virtual void pv23(); virtual void pv24(); virtual void pv25(); virtual void pv26(); virtual void pv27(); virtual void pv28(); virtual void pv29();
 virtual bool isEnabled()const; virtual void pv31(); virtual bool drawSelected()const;
 void render2d(Adorn*);
 void drawBack(Adorn*,const Rect&,bool,int);
};
typedef char LayoutCheck[(sizeof(std::string)==28&&sizeof(Widget)==0x148&&sizeof(GuiDrawImage)==56&&sizeof(BackpackItem)==0x1a0)?1:-1];
__forceinline void BackpackItem::drawBack(Adorn*adorn,const Rect&rect,bool overlay,int fontSize){

 float side=rect.size().x*.2f;
 Rect numberRect=Rect::fromLowSize(G3D::Vector2(rect.low.x+2,rect.high.y-2-side),G3D::Vector2(side,side));
 if(!overlay)adorn->rect2d(rect.toRect2D(),translucentBackdrop());
 if(isEnabled()){
  adorn->rect2d(numberRect.toRect2D(),G3D::Color3::gray());
  {G3D::Color4 fontColor(G3D::Color3::white());
  int number=(parent?parent->findChildIndex(this):-1)+1;
  adorn->drawFont2D(StringConverter<int>::convertToString(number),numberRect.center(),fontSize,fontColor,G3D::Color4::zero(),Adorn::XALIGN_CENTER,Adorn::YALIGN_CENTER,Adorn::PROPORTIONAL_SPACING);
 }}
 
}
void BackpackItem::render2d(Adorn*adorn){
 bool overlay=false;
 Workspace*workspace=Workspace::findWorkspace(this);
 if(workspace&&workspace->overlayLayout)overlay=true;
 Rect rect=overlay?Rect(GuiRoot::getCanvasSize()):getMyRect();
 int fontSize=GuiRoot::normalizedFontSize(12);
 drawBack(adorn,rect,overlay,fontSize);
 if(drawSelected())adorn->outlineRect2d(rect.toRect2D(),3,G3D::Color3::green());
 if(guiImageDraw.setImage(adorn,textureId)){
  guiImageDraw.render2d(adorn,isEnabled()||overlay,rect.inset(fontSize),widgetState);
 }else Widget::render2d(adorn);
}
}
