#pragma once
// 2008-06 native (inactive): the two Vector3 force-limit accessors of the humanoid state unit 00664000..00668000.
// Evidence (no RTTI; analog names, the original names are unknown):
//   00666350  returns a copy of a function-local static Vector3 (1000, 10000, 1000): guard 0097d974 bit 1, storage
//             0097d968 / 0097d96c / 0097d970, constants __real@447a0000 0x00819dcc and __real@461c4000 0x0082746c,
//             the hidden return pointer at [esp + 4] (cdecl, plain `ret`).
//   006663a0  the same shape for (-1000, 0, -1000): guard 0097d984, storage 0097d978 .. 0097d980, __real@c47a0000
//             0x0084cc24.
// Callers: RunningBase::onComputeForce 00666550 (0066674a reads only .y of the upper limit; 006668a0 / 006668ac pass
// both to G3D::Vector3::clamp 004a6100 as high / low) and Freefall::onComputeForce 006675d0 (0066776d / 00667779, the
// same clamp). Both callers live in different humanoid state rows of one image range, and the two bodies are each a
// single COMDAT, so they are shared header-level functions of the HUMAN states; they are declared here out of line.
#include <G3D/Vector3.h>

namespace RBX
{
	namespace HUMAN
	{
		G3D::Vector3 maxMoveForce();   // 00666350 (analog name): (1000, 10000, 1000)
		G3D::Vector3 minMoveForce();   // 006663a0 (analog name): (-1000, 0, -1000)
	}
}
