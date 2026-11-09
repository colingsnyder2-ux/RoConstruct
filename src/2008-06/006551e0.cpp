// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <string>
#include <vector>
#include <algorithm>
#include <stddef.h>
namespace G3D {
template<class T>class ReferenceCountedPointer;
class CoordinateFrame;class AABox;class Sphere;class Ray;class LineSegment;class Vector3;
class Vector2 {public:float x,y;
 Vector2(){} Vector2(float X,float Y):x(X),y(Y){}
 Vector2(const Vector2&v):x(v.x),y(v.y){}
 Vector2&operator=(const Vector2&v){x=v.x;y=v.y;return *this;}
 Vector2 operator+(const Vector2&v)const{Vector2 result;result.x=x+v.x;result.y=y+v.y;return result;}
 Vector2 operator-(const Vector2&v)const{return Vector2(x-v.x,y-v.y);}
};
class Color3 {public:float r,g,b;
 Color3(const Color3&v):r(v.r),g(v.g),b(v.b){}
 Color3&operator=(const Color3&v){r=v.r;g=v.g;b=v.b;return *this;}
 static const Color3&white();static const Color3&red();
};
class Color4 {public:float r,g,b,a;
 Color4(const Color3&c,float A=1):r(c.r),g(c.g),b(c.b),a(A){}
 Color4(float R,float G,float B,float A=1):r(R),g(G),b(B),a(A){}
 static const Color4&zero();
};
class Rect2D {Vector2 min,max;public:
 static Rect2D xyxy(const Vector2&,const Vector2&);
 float width()const{return max.x-min.x;}
};
}
namespace RBX
{
class TextureProxyBase;
	class Adorn
	{
	public:
		enum Spacing
		{
			PROPORTIONAL_SPACING,
			FIXED_SPACING
		};
		enum XAlign
		{
			XALIGN_RIGHT,
			XALIGN_LEFT,
			XALIGN_CENTER
		};
		enum YAlign
		{
			YALIGN_TOP,
			YALIGN_BASELINE,
			YALIGN_CENTER,
			YALIGN_BOTTOM
		};

	public:
		Adorn()
		{
		}
		virtual ~Adorn()
		{
		}
	public:
		virtual G3D::ReferenceCountedPointer<TextureProxyBase> createTextureProxy(const std::string& filename) = 0;
		virtual void prepareRenderPass() = 0;
		virtual void finishRenderPass() = 0;
		virtual G3D::Rect2D getViewport() const = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual void setTexture(int id, G3D::ReferenceCountedPointer<TextureProxyBase> _texture) = 0;
		virtual G3D::Rect2D getTextureSize(G3D::ReferenceCountedPointer<TextureProxyBase> _texture) const = 0;
		virtual void line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const = 0;
		virtual void outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const = 0;
		virtual void rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const = 0;
		virtual G3D::Vector2 get2DStringBounds(const std::string& s, double size, Spacing spacing) const = 0;
		virtual G3D::Vector2 drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size, const G3D::Color4& color, const G3D::Color4& outline, XAlign xalign, YAlign yalign, Spacing spacing) const = 0;
		virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c) = 0;
		virtual void setColor(const G3D::Color4& color) = 0;
		virtual void box(const G3D::AABox& box, const G3D::Color4& solidColor, const G3D::Color4& wireColor) = 0;
		virtual void sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor, const G3D::Color4& wireColor) = 0;
		virtual void explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor, const G3D::Color4& wireColor) = 0;
		virtual void cylinderAlongX(float radius, float length, const G3D::Color4& solidColor, const G3D::Color4& wireColor) = 0;
		virtual void ray(const G3D::Ray& ray, const G3D::Color4& color, float scale) = 0;
		virtual void lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale) = 0;
		virtual void axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor, float scale) = 0;
		virtual void quad(const G3D::Vector3& v0, const G3D::Vector3& v1, const G3D::Vector3& v2, const G3D::Vector3& v3, const G3D::Color4& color) = 0;
	};
}

namespace RBX {
class Rect {public:G3D::Vector2 low,high;
 Rect(const G3D::Vector2&L,const G3D::Vector2&H):low(L),high(H){}
 Rect(float lowX,float lowY,float highX,float highY):low(lowX,lowY),high(highX,highY){}
 G3D::Rect2D toRect2D()const{return G3D::Rect2D::xyxy(low,high);}
};
// The native GuiItem nonvirtual interface is opaque here. ChatOutput's first
// base is GuiItem in the native header, so its observed receiver address is unchanged.
class GuiItem {public:Rect getMyRect()const;static const G3D::Color4&translucentBackdrop();};
class BoardData
	{
	public:
		std::vector<std::vector<std::string>> data;
		std::vector<std::string> fields;

	public:
		BoardData()
		{
		}

		void SetSize(int dataSize, int fieldSize)
		{
			data.resize(dataSize);
			for (int i = 0; i < dataSize; ++i)
				data[i].resize(fieldSize);

			fields.resize(fieldSize);
		}

		void AddField(std::string fieldName, int position)
		{
			fields[position] = fieldName;
		}
	};

class Hash {public:static unsigned int hash(const std::string&);};
class Color {public:static const G3D::Color3&colorFromIndex8(int);};
// Observed ScoreHud data view. Native GuiItem is the primary base at offset0.
// The rendering method only writes native GuiItem::guiSize at13c/140.
class ScoreHud {public:
 char unobserved00[0x13c];G3D::Vector2 guiSize;
 void setGuiSize(const G3D::Vector2&v){guiSize=v;}
 void BuildBoardData(BoardData&);
 void renderFFALeaderboard(Adorn*);
};
typedef char score_gui_size_offset[offsetof(ScoreHud,guiSize)==0x13c?1:-1];
typedef char score_board_size[sizeof(BoardData)==48?1:-1];
void ScoreHud::renderFFALeaderboard(Adorn* adorn) {
    bool hasStats=true;
    BoardData data;
    BuildBoardData(data);
    if(data.fields.empty()) return;
    if(data.fields.size()==1) hasStats=false;
    G3D::Rect2D viewport=adorn->getViewport();
    float viewportWidth=viewport.width();
    float scale=viewportWidth*(1.0f/1024.0f);
    float row=scale*14.0f;
    float width=viewportWidth*0.33f;
    if(!hasStats) width*=0.5f;
    float height=(data.data.size()+2.5f)*row;
    setGuiSize(G3D::Vector2(width,height));
    Rect rect=reinterpret_cast<const GuiItem*>(this)->getMyRect();
    adorn->rect2d(rect.toRect2D(),GuiItem::translucentBackdrop());
    for(unsigned col=0;col<data.fields.size();++col) {
        float extent=rect.high.x-rect.low.x;
        G3D::Vector2 position(rect.low.x,rect.low.y);
        if(col) position.x+=extent*0.5f+extent*0.5f/data.fields.size()*(col-1);
        adorn->drawFont2D(data.fields[col],position,row,G3D::Color4(G3D::Color3::white(),1),G3D::Color4::zero(),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
    }
    rect.low.y+=row*2;
    for(unsigned col=0;col<data.fields.size();++col) {
        for(unsigned index=0;index<data.data.size();++index) {
            G3D::Color3 color=G3D::Color3::white();
            if(!col) color=Color::colorFromIndex8(Hash::hash(data.data[index][0])&7);
            float extent=rect.high.x-rect.low.x;
            G3D::Vector2 position(rect.low.x,rect.low.y);
            if(col) position.x+=extent*0.5f+extent*0.5f/data.fields.size()*(col-1);
            position.y+=index*row;
            adorn->drawFont2D(data.data[index][col],position,row,G3D::Color4(color,1),G3D::Color4::zero(),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
        }
    }
}
}
