// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-appdraw roc_espeon_aug2007_adorn_pass_e97a3eef279c22c5.cpp

// Candidate translation unit (score above; library headers required).
#pragma once
#include <string>
#include <G3D/Vector2.h>
#include <G3D/Rect2D.h>
#include <G3D/Color4.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/AABox.h>
#include <G3D/Sphere.h>
#include <G3D/LineSegment.h>
#include "RbxGraphics/TextureProxyBase.h"

namespace RBX
{
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
// August 2007 primary AdornG3D table has one pass hook at +8; viewport is +12.
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

#pragma once

#include "AppDraw/Part.h"
#include "AppDraw/SelectState.h"
#include "G3D/Rect2D.h"

namespace RBX
{
	class Draw
	{
	private:
		static void spokes(float radius, float axis, Adorn* adorn);
		static void adornSurfaces(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor);
		static void adornCylinder(const Part&, Adorn*);
		static void frameBox(const Part&, Adorn*, const G3D::Color4&);
		static void constraint(const Part& part, Adorn* adorn, int face, const G3D::Color3& controllerColor);

	public:
		static const G3D::Color3& selectColor();
		static void selectionSquare(const G3D::Rect2D&, float);
		static void partAdorn(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor);
		static void selectionBox(const Part& part, Adorn* adorn, SelectState selectState);
		static void selectionBox(const Part& part, Adorn* adorn, const G3D::Color4& selectColor);
	};
}


#include "util/Math.h"

namespace RBX
{
	void Draw::spokes(float radius, float axis, Adorn* adorn)
    {
        // no idea where the 0.51 comes from lol
        float halfAxis = axis*0.51f;
        float subRadius = radius*0.7f;

        for (int i = 0; i < 2; i++)
        {
            float x = (i == 0) ? halfAxis : -halfAxis;
            float ccw = i ? -1.0f : 1.0f;

            for (int j = 0; j < 2; j++)
            {
                float y = (j == 0) ? subRadius : 0.1f;
                float z = (j == 0) ? 0.1f : subRadius;

                adorn->quad(
                    G3D::Vector3(x, y * ccw, z),
                    G3D::Vector3(x, -y * ccw, z),
                    G3D::Vector3(x, -y * ccw, -z),
                    G3D::Vector3(x, y * ccw, -z),
                    G3D::Color4(0.5f, 0.5f, 0.5f, 1.0f)
                );
            }
        }
    }

	void Draw::partAdorn(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor)
    {
        adornSurfaces(part, adorn, controllerColor);

        if (part.type == Part::CYLINDER_PART)
        {
            adorn->setObjectToWorldMatrix(part.coordinateFrame);

            G3D::Vector3 bleh = part.gridSize;
            spokes(bleh.z * 0.5, bleh.x, adorn);
        }
    }

    const G3D::Color3& Draw::selectColor()
    {
        static G3D::Color3 c(0.1f, 0.6f, 1.0f);
        return c;
    }

	void Draw::selectionBox(const Part& part, Adorn* adorn, SelectState selectState)
    {
        Draw::selectionBox(part, adorn, (selectState == SELECT_NORMAL) ? Draw::selectColor() : G3D::Color3(0.2f, 0.7f, 1.0f));
    }

	void Draw::adornSurfaces(const Part& part, Adorn* adorn, const G3D::Color3& controllerColor)
    {
        for (int i = 0; i < 6; i++)
        {
			SurfaceType type = part.surfaceType[i];
            if (type >= ROTATE && type <= ROTATE_P) // ROTATE, ROTATE_V, ROTATE_P
            {
                Draw::constraint(part, adorn, i, controllerColor);
            }
        }
    }

    // TODO: 94.56% match
	// classic case of MSVC optimizer being really inconsistent
	void Draw::constraint(const Part& part, Adorn* adorn, int face, const G3D::Color3& controllerColor)
    {
		SurfaceType surfaceType = part.surfaceType[face];

        G3D::Vector3 halfSize = part.gridSize * 0.5f;

        const G3D::Matrix3& rot = Math::getAxisRotationMatrix(face);

        G3D::Vector3 relativeTranslation;

        int axis = face % 3;
        float posNeg = (face > 2) ? -1.0f : 1.0f;

        relativeTranslation[axis] = halfSize[axis]*posNeg;

        G3D::CoordinateFrame translation(rot, relativeTranslation);
        G3D::CoordinateFrame newObject = part.coordinateFrame*translation;

        adorn->setObjectToWorldMatrix(newObject);
        adorn->cylinderAlongX(0.2f, 1.0f, G3D::Color3::yellow(), G3D::Color4::clear());

        if (surfaceType == ROTATE_V || surfaceType == ROTATE_P)
        {
            adorn->cylinderAlongX(0.4f, 0.25f, controllerColor, G3D::Color4::clear());
        }
    }

	void Draw::selectionBox(const Part& part, Adorn* adorn, const G3D::Color4& selectColor)
    {
        adorn->setObjectToWorldMatrix(part.coordinateFrame);

        G3D::Vector3 halfSize = part.gridSize*0.5;

        const float offset = 0.15f;

        for (int ix = 0; ix < 3; ix++)
        {
            int iy = (ix+1) % 3;
            int iz = (ix+2) % 3;

            for (int d2 = -1; d2 < 2; d2+=2)
            {
                for (int d3 = -1; d3 < 2; d3+=2)
                {
                    G3D::Vector3 p0;
                    G3D::Vector3 p1;

                    p0[ix] = -halfSize[ix] - offset;
                    p0[iy] = d2 * halfSize[iy] - offset;
                    p0[iz] = d3 * halfSize[iz] - offset;

                    p1[ix] = halfSize[ix] + offset;
                    p1[iy] = d2 * halfSize[iy] + offset;
                    p1[iz] = d3 * halfSize[iz] + offset;

                    adorn->box(G3D::AABox(p0, p1), selectColor, G3D::Color4::clear());
                }
            }
        }
    }
}
