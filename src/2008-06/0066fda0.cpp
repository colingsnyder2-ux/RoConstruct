// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_bd485405c430e8eb.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <string>
#include "G3D/Vector2.h"
#include "G3D/Color4.h"
namespace G3D { class RenderDevice; }
namespace RBX {
class GFont
{
public:
	G3D::Vector2 draw2D(G3D::RenderDevice* rd, const std::string& s, const G3D::Vector2& pos2d, double size, const G3D::Color4& color, const G3D::Color4& outline, int xalign, int yalign, int spacing) const;
};
extern GFont* font;
class Adorn
{
public:
	enum XAlign { XALIGN_LEFT };
	enum YAlign { YALIGN_TOP };
	enum Spacing { PROPORTIONAL_SPACING };
	virtual ~Adorn();
	virtual void s1();
	virtual void s2();
	virtual void s3();
	virtual void s4();
	virtual void s5();
	virtual int getHeight() const = 0;
};
class AdornRbxGfx : public Adorn
{
public:
	G3D::RenderDevice* rd;
	virtual int getHeight() const;
	virtual G3D::Vector2 drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size, const G3D::Color4& color, const G3D::Color4& outline, XAlign xalign, YAlign yalign, Spacing spacing) const;
};
G3D::Vector2 AdornRbxGfx::drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size, const G3D::Color4& color, const G3D::Color4& outline, XAlign xalign, YAlign yalign, Spacing spacing) const
{
	float x = pos2d.x;
	G3D::Vector2 pos(x, (getHeight() - 1) - pos2d.y);
	G3D::Vector2 result = font->draw2D(rd, s, pos, size, color, outline, xalign, yalign, spacing);
	return G3D::Vector2(result.x, result.y);
}
}
