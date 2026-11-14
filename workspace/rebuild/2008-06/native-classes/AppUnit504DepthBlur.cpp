// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
#include "AppUnit504/RenderEffects.h"
#include <GLG3D/Draw.h>
#include <GLG3D/GLCaps.h>
namespace RBX {
namespace Render {
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
