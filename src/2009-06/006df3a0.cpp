// from server: 100% by EspClaude
// from server: 96% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_358f453a8f59c668.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/CoordinateFrame.h"
namespace RBX
{
	class ICharacterSubject
	{
	public:
		static G3D::CoordinateFrame getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal);
	};

	G3D::CoordinateFrame ICharacterSubject::getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal)
	{
		G3D::CoordinateFrame temp = cameraFocus;
		temp.lookAt(cameraGoal.translation);

		return temp;
	}
}
