// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_228eb1d10142a247.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#define lineSegment(a, b, c) lineSegment(a, b, c) = 0; virtual void exeAdornExtra()
#include "RbxGraphics/Adorn.h"
#undef lineSegment
#include "AppDraw/Draw.h"
#include "util/Math.h"

namespace RBX
{
	void Draw::spokes(float radius, float axis, Adorn* adorn)
    {
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
}
