// 2008-06 native Ogre::RbxAdornState: SGI GLU quadric state (libutil quad.c GLUquadric) ported by Roblox onto
// Ogre::ManualObject for AdornRbxGfx shapes (inactive recovery).
//
// Class name: registry ??0RbxAdornState@Ogre@@QAE@XZ (00685e30). Layout, binary-derived:
//   ctor 00685e30 stores +0 = 0, +4 = (byte)0, +8 = 0, +0xc = 2, ColourValue +0x10 (default ctor, then -1 x4),
//   Vector3 +0x20 = 0,0,0 -> 0x2c. The shape builders read +0 (compared with 0/1), +4 (byte test), +8 (== 0 keeps
//   the sign), +0xc (4-way jump table), +0x10 colour (passed to ManualObject::colour when set) and +0x20..+0x28
//   (added to every position).
// INFERRED (owner rule 2026-11-11): member, enum and method names are GLU's (normals/textureCoords/orientation/
// drawStyle, GLU_SMOOTH/FLAT/NONE, GLU_OUTSIDE/INSIDE, GLU_POINT/LINE/FILL/SILHOUETTE, gluSphere/gluCylinder/
// gluPartialDisk/gluDisk): the ctor defaults are exactly GLU's newQuadric defaults (SMOOTH, no texture, OUTSIDE,
// FILL) and the bodies are quad.c with GL calls replaced by ManualObject calls; colour and offset are Roblox's.
// Enum value order follows the bodies' comparisons, not GL's constants.
#pragma once
// >>> native-status (generated) -- do not edit >>>
// RbxAdornState2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 0c2226f4 | roc native-status --write

#include <OgreString.h>
#include <OgreColourValue.h>
#include <OgreVector3.h>

namespace Ogre
{
	class ManualObject;
	class SceneManager;

	class RbxAdornState
	{
	public:
		enum NormalStyle {Smooth = 0, Flat = 1, None = 2};
		enum Orientation {Outside = 0, Inside = 1};
		enum DrawStyle {Point = 0, Line = 1, Fill = 2, Silhouette = 3};

		NormalStyle normals;                                                          // +0x00
		bool textureCoords;                                                           // +0x04
		Orientation orientation;                                                      // +0x08
		DrawStyle drawStyle;                                                          // +0x0c
		ColourValue colour;                                                           // +0x10 (-1: unset)
		Vector3 offset;                                                               // +0x20

		void setOffset(const Vector3& value); // 00685e10, INFERRED name.
		RbxAdornState();                                                              // 00685e30

		ManualObject* cylinder(SceneManager* manager, const String& name, ManualObject* object, float baseRadius,
		                       float topRadius, float height, int slices, int stacks);              // 00685ea0
		ManualObject* partialDisk(SceneManager* manager, const String& name, ManualObject* object, float innerRadius,
		                          float outerRadius, int slices, int loops, float startAngle,
		                          float sweepAngle);                                                // 00687860
		ManualObject* disk(SceneManager* manager, const String& name, ManualObject* object, float innerRadius,
		                   float outerRadius, int slices, int loops);                               // 0068b5c0
		ManualObject* sphere(SceneManager* manager, const String& name, ManualObject* object, float radius,
		                     int slices, int stacks);                                               // 006892d0
	};
}
