// from server: 100% by EspClaude
// from server: 89% by EspClaude
// roc-cl: 21022
// from server: 87% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <string>
#include <math.h>
#include <algorithm>
namespace G3D {
template<class T>inline T min(const T&x,const T&y){return std::min<T>(x,y);}
template<class T>inline T max(const T&x,const T&y){return std::max<T>(x,y);}
class Vector2 {public:float x,y;Vector2():x(0),y(0){}Vector2(float a,float b):x(a),y(b){}Vector2(const Vector2&v):x(v.x),y(v.y){}Vector2&operator=(const Vector2&v){x=v.x;y=v.y;return*this;}Vector2 operator+(const Vector2&v)const{return Vector2(x+v.x,y+v.y);}Vector2 operator-(const Vector2&v)const{return Vector2(x-v.x,y-v.y);}Vector2 min(const Vector2&v)const{return Vector2(G3D::min(v.x,x),G3D::min(v.y,y));}Vector2 max(const Vector2&v)const{return Vector2(G3D::max(v.x,x),G3D::max(v.y,y));}};
class Vector3 {public:float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}float magnitude()const{return sqrtf(x*x+y*y+z*z);}Vector2 xy()const;static const Vector3&zero();};
class Matrix3 {public:float elt[3][3];Matrix3(){}Matrix3(const Matrix3&);static const Matrix3&identity();};
class CoordinateFrame {public:Matrix3 rotation;Vector3 translation;CoordinateFrame():rotation(Matrix3::identity()),translation(Vector3::zero()){}CoordinateFrame(const CoordinateFrame&v):rotation(v.rotation),translation(v.translation){}~CoordinateFrame(){}};
class Color3 {public:float r,g,b;Color3(){}Color3(float x,float y,float z):r(x),g(y),b(z){}Color3(const Color3&v):r(v.r),g(v.g),b(v.b){}static const Color3&white();static const Color3&black();static const Color3&red();};
class Color4 {public:float r,g,b,a;Color4(){}Color4(const Color3&v,float alpha=1.0f):r(v.r),g(v.g),b(v.b),a(alpha){}Color4(const Color4&v):r(v.r),g(v.g),b(v.b),a(v.a){}};
class Rect2D {Vector2 min,max;public:Rect2D(){}inline static Rect2D xyxy(const Vector2&v0,const Vector2&v1){Rect2D r;r.min=v0.min(v1);r.max=v0.max(v1);return r;}};
class GCamera {float fieldOfView,imagePlaneDepth,nearPlane,farPlane;CoordinateFrame cframe;public:GCamera();virtual~GCamera();CoordinateFrame getCoordinateFrame()const;Vector3 project(const Vector3&,const Rect2D&)const;};
class AABox;class Sphere;class Ray;class LineSegment;
template<class T>class ReferenceCountedPointer;
}
namespace RBX {
class TextureProxyBase;
class __declspec(novtable) Adorn
{
public:
	enum XAlign
	{
		XALIGN_RIGHT = 0,
		XALIGN_LEFT = 1,
		XALIGN_CENTER = 2
	};

	enum YAlign
	{
		YALIGN_TOP = 0,
		YALIGN_BASELINE = 1,
		YALIGN_CENTER = 2,
		YALIGN_BOTTOM = 3
	};

	enum Spacing
	{
		PROPORTIONAL_SPACING = 0,
		FIXED_SPACING = 1
	};

	virtual ~Adorn(); // vtable+0x00

	virtual G3D::ReferenceCountedPointer<TextureProxyBase> createTextureProxy(
		const std::string& name
	) = 0;                                       // vtable+0x04
	virtual void prepareRenderPass() = 0;        // vtable+0x08
	virtual void finishRenderPass() = 0;         // vtable+0x0c
	virtual G3D::Rect2D getViewport() const = 0; // vtable+0x10
	virtual int getWidth() const = 0;            // vtable+0x14
	virtual int getHeight() const = 0;           // vtable+0x18

	virtual void setTexture(int stage, G3D::ReferenceCountedPointer<TextureProxyBase> texture) = 0; // vtable+0x1c

	virtual G3D::Rect2D getTextureSize(G3D::ReferenceCountedPointer<TextureProxyBase> texture) const = 0; // vtable+0x20

	virtual void line2d(
		const G3D::Vector2& from,
		const G3D::Vector2& to,
		const G3D::Color4& color
	) const = 0; // vtable+0x24

	virtual void outlineRect2d(
		const G3D::Rect2D& rect,
		float thickness,
		const G3D::Color4& color
	) const = 0; // vtable+0x28

	virtual void rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const = 0; // vtable+0x2c

	virtual G3D::Vector2 get2DStringBounds(const std::string& s, double size, Spacing spacing) const = 0; // vtable+0x30

	virtual G3D::Vector2 drawFont2D(
		const std::string& s,
		const G3D::Vector2& position,
		double size,
		const G3D::Color4& color,
		const G3D::Color4& outline,
		XAlign xAlign,
		YAlign yAlign,
		Spacing spacing
	) const = 0; // vtable+0x34

	virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& coord) = 0; // vtable+0x38
	virtual void setColor(const G3D::Color4& color) = 0;                        // vtable+0x3c

	virtual void box(const G3D::AABox& box, const G3D::Color4& solid, const G3D::Color4& wire) = 0; // vtable+0x40
	virtual void sphere(
		const G3D::Sphere& sphere,
		const G3D::Color4& solid,
		const G3D::Color4& wire
	) = 0; // vtable+0x44
	virtual void explosion(
		const G3D::Sphere& sphere,
		const G3D::Color4& solid,
		const G3D::Color4& wire
	) = 0; // vtable+0x48

	virtual void cylinderAlongX(
		float radius,
		float length,
		const G3D::Color4& solid,
		const G3D::Color4& wire
	) = 0; // vtable+0x4c

	virtual void ray(const G3D::Ray& ray, const G3D::Color4& color, float scale) = 0;                     // vtable+0x50
	virtual void lineSegment(const G3D::LineSegment& segment, const G3D::Color4& color, float scale) = 0; // vtable+0x54
	virtual void axes(const G3D::Color4& x, const G3D::Color4& y, const G3D::Color4& z, float scale) = 0; // vtable+0x58

	virtual void quad(
		const G3D::Vector3& v0,
		const G3D::Vector3& v1,
		const G3D::Vector3& v2,
		const G3D::Vector3& v3,
		const G3D::Color4& color
	) = 0; // vtable+0x5c
};


// Borrowed existing-object prefixes. No construction or full owner-size claim.
class Instance {unsigned char beforeName[0x110];std::string name;public:const std::string&getName()const{return name;}};
class PartInstance {unsigned char beforeTransparency[0x1e8];float transparency;public:float getTransparencyXml()const{return transparency;}const G3D::CoordinateFrame&getCoordinateFrame()const;};
class Humanoid {unsigned char beforeParent[0x104];Instance*parent;unsigned char beforeHealth[0x1a8-0x108];float health,maxHealth;public:float getHealth()const{return health;}float getMaxHealth()const{return maxHealth;}float relativeHealth()const{return health/maxHealth;}PartInstance*getHead()const;Instance*getParent()const{return parent;}void renderMultiplayer(Adorn*,const G3D::GCamera&);};
class Teams {public:G3D::Color3 getTeamColorForHumanoid(Humanoid*);};
class ServiceProvider {public:template<class T>static T*find(Instance*);};
class Color {public:static const G3D::Color3&lightGreen();};
using G3D::Vector2;using G3D::Vector3;using G3D::CoordinateFrame;
class Rect {public:Vector2 low,high;Rect(const Vector2&l,const Vector2&h):low(l),high(h){}Rect();G3D::Rect2D toRect2D()const{return G3D::Rect2D::xyxy(low,high);}Vector2 size()const{return high-low;}static Rect fromLowSize(const Vector2&low,const Vector2&size){return Rect(low,low+size);}};
void Humanoid::renderMultiplayer(Adorn* adorn, const G3D::GCamera& camera)
{
	PartInstance* headPart = getHead();
 if (headPart != NULL) {
		const CoordinateFrame& headCoord = headPart->getCoordinateFrame();

		Vector3 headPosition = headCoord.translation;
 headPosition.y += 1.5f;

		Vector3 projected = camera.project(headPosition, adorn->getViewport());

		float distance = (camera.getCoordinateFrame().translation - headPosition).magnitude();

		if (distance < 100.0f && headPart->getTransparencyXml() < 0.99f) {
			int fontSize = 8;

			if (distance < 20.0f) fontSize = 12;
			else if (distance < 50.0f) fontSize = 10;

			Teams* teams = ServiceProvider::find<Teams>(reinterpret_cast<Instance*>(this));

			G3D::Color3 nameColor = teams != NULL ? teams->getTeamColorForHumanoid(this) : G3D::Color3::white();

			adorn->drawFont2D(
				getParent()->getName(),
				projected.xy(),
				fontSize,
				G3D::Color4(nameColor, 1.0f),
				G3D::Color4(G3D::Color3::black(), 1.0f),
				Adorn::XALIGN_CENTER,
				Adorn::YALIGN_BOTTOM,
				Adorn::PROPORTIONAL_SPACING
			);

			float width = (float) (fontSize * 4);
			Vector2 low(projected.x - 0.5f * width, projected.y);
			Vector2 high = low + Vector2(width, (float)(fontSize / 2));
			float healthX = low.x + relativeHealth() * width;
			Rect greenBarRect(low, Vector2(healthX, high.y));
			Rect redBarRect(Vector2(healthX, low.y), high);
			adorn->rect2d(greenBarRect.toRect2D(), Color::lightGreen());
			adorn->rect2d(redBarRect.toRect2D(), G3D::Color3::red());
		}
	}
}


}
