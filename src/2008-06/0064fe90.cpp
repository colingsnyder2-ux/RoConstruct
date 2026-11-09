// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <string>
#include <deque>
#include <algorithm>
#include <stddef.h>
#include <intrin.h>
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
class ChatLine {public:
 G3D::Color3 userColor;std::string user,message;float dieTime;bool profane;
};
// Observed ChatOutput data view; no allocation, RTTI, vtable emission or self dispatch.
class ChatOutput {public:
 char unobserved00[0x174];std::deque<ChatLine*> fifo;
 void render2d(Adorn*);
};
typedef char chat_line_message_offset[offsetof(ChatLine,message)==0x28?1:-1];
typedef char chat_line_profane_offset[offsetof(ChatLine,profane)==0x48?1:-1];
typedef char chat_deque_size[sizeof(std::deque<ChatLine*>)==32?1:-1];
typedef char chat_deque_offset[offsetof(ChatOutput,fifo)==0x174?1:-1];
	void ChatOutput::render2d(Adorn* adorn)
	{
		const int fontSize = 12;

		Rect uiRect = reinterpret_cast<const GuiItem*>(this)->getMyRect();

		G3D::Vector2 topPos = uiRect.low;
		topPos.y -= fontSize * fifo.size();

		for (size_t i = 0; i < fifo.size(); ++i)
		{
			std::string username = fifo[i]->user + "; ";

			G3D::Vector2 usernameBounds = adorn->get2DStringBounds(username, fontSize, Adorn::PROPORTIONAL_SPACING);
			G3D::Vector2 messageBounds = adorn->get2DStringBounds(fifo[i]->message, fontSize, Adorn::PROPORTIONAL_SPACING);
			float usernameXOffset = std::max(usernameBounds.x + 4.0f, 20.0f);

			float backgroundWidth = messageBounds.x + usernameXOffset;
            Rect backgroundRect(topPos.x - 2.0f, topPos.y + 1.0f,
                topPos.x + backgroundWidth + 2.0f,
                topPos.y + usernameBounds.y - 1.0f);
			adorn->rect2d(backgroundRect.toRect2D(), GuiItem::translucentBackdrop());

			G3D::Color3 messageColor = G3D::Color3::white();
			if (fifo[i]->profane)
				messageColor = G3D::Color3::red();

			adorn->drawFont2D(
				username,
				topPos,
				fontSize,
				fifo[i]->userColor,
				G3D::Color4::zero(),
				Adorn::XALIGN_LEFT,
				Adorn::YALIGN_TOP,
				Adorn::PROPORTIONAL_SPACING
			);

			adorn->drawFont2D(
				fifo[i]->message,
				topPos + G3D::Vector2(usernameXOffset, 0.0f),
				fontSize,
				messageColor,
				G3D::Color4::zero(),
				Adorn::XALIGN_LEFT,
				Adorn::YALIGN_TOP,
				Adorn::PROPORTIONAL_SPACING
			);

			topPos.y += fontSize + 2;
		}
	}
}

