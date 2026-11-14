// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "AppUnit504/RenderEffects.h"
#include <GLG3D/Draw.h>
#include <GLG3D/GLCaps.h>
namespace RBX {
namespace Render {
void DepthBlur::allocateTextures(const G3D::Rect2D& screenRect)
{
	if (!depth.isNull() && depth->vector2Bounds() == screenRect.wh()) {
		return;
	}

	depth = G3D::Texture::createEmpty(
		"Depth Buffer",
		(int) screenRect.width(),
		(int) screenRect.height(),
		G3D::TextureFormat::depth(0),
		G3D::Texture::DIM_2D_NPOT,
		G3D::Texture::Settings::video()
	);

	color = G3D::Texture::createEmpty(
		"Color Buffer",
		(int) screenRect.width(),
		(int) screenRect.height(),
		G3D::TextureFormat::RGB8,
		G3D::Texture::DIM_2D_NPOT,
		G3D::Texture::Settings::video()
	);

	shader->args.set("depth", depth);
	shader->args.set("color", color);
}


void DepthBlur::apply(G3D::RenderDevice* rd)
		{
			if (!shader.isNull())
			{
				rd->push2D();

				G3D::Rect2D screenRect = rd->getViewport();

				allocateTextures(screenRect);

				depth->copyFromScreen(screenRect, true);
				color->copyFromScreen(screenRect, true);

				rd->setShader(shader);

				G3D::Draw::fastRect2D(screenRect, rd, G3D::Color4(G3D::Color3::white(), 1));

				rd->pop2D();
			}
		}
}
}
