// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native camera verb bodies and the VerbContainer-taking EditSelectionVerb / DeleteBase constructors of the
// StandardVerbs / command verbs translation unit (0057d250..005831ff) inside the application range 00580000..00584000,
// inactive. Verified by tests/record_native_app_unit580.py. Every header is a committed native header, read-only here
// (StandardVerbs.h, NativeCameraCommands.h, v8datamodel/Workspace.h, Selection.h, util/Sound.h).
//
// The bodies are the ones the committed native-classes/DocumentInitialize.cpp carries next to CRobloxDoc code
// (maintainer exclusion: that file is not compiled here); this unit holds only the verb rows:
//   * EditSelectionVerb(VerbContainer*, std::string, DataModel*) 00580b50, DeleteBase(VerbContainer*, DataModel*,
//     std::string) 00581010;
//   * CameraVerb::doIt 005819a0 (SoundService STEP_SOUND, setDirty), CameraPanLeft / PanRight / TiltUp / TiltDown /
//     ZoomIn / ZoomOut / ModelView doIt 005819d0..00581bc0 (vtable slot 4 of each camera verb vtable);
//   * CameraCenterCommand::isEnabled 00582300 (slot 2).
#include "StandardVerbs.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
#include "util/Sound.h"

namespace RBX
{
	inline const G3D::Rect2D& RootInstance::getViewPort() { return viewPort; }
}
#include "NativeCameraCommands.h"

namespace RBX
{
	void CameraVerb::doIt(IDataState* state)
	{
		ServiceProvider::create<Soundscape::SoundService>(static_cast<Instance*>(workspace))->playSound(STEP_SOUND);
		state->setDirty(true);
	}

	void CameraPanLeftCommand::doIt(IDataState* state)
	{
		workspace->getCamera()->panUnits(-1);
		CameraVerb::doIt(state);
	}

	void CameraPanRightCommand::doIt(IDataState* state)
	{
		workspace->getCamera()->panUnits(1);
		CameraVerb::doIt(state);
	}

	void CameraTiltUpCommand::doIt(IDataState* state)
	{
		Camera* camera = workspace->getCamera();
		if (camera->tiltUnits(-1))
			CameraVerb::doIt(state);
	}

	void CameraTiltDownCommand::doIt(IDataState* state)
	{
		Camera* camera = workspace->getCamera();
		if (camera->tiltUnits(1))
			CameraVerb::doIt(state);
	}

	void CameraZoomInCommand::doIt(IDataState* state)
	{
		Camera* camera = workspace->getCamera();
		if (camera->zoom(1.0f))
			CameraVerb::doIt(state);
	}

	void CameraZoomOutCommand::doIt(IDataState* state)
	{
		Camera* camera = workspace->getCamera();
		if (camera->zoom(-1.0f))
			CameraVerb::doIt(state);
	}

	void CameraModelViewCommand::doIt(IDataState* state)
	{
		workspace->setImageServerView(workspace->getViewPort());
		CameraVerb::doIt(state);
	}

	bool CameraCenterCommand::isEnabled() const
	{
		bool hasSelection = ServiceClient<FilteredSelection<PVInstance> >(workspace)->size() >= 1;
		if (hasSelection)
		{
			Camera* camera = workspace->getCamera();
			if (camera && camera->getCameraType() == Camera::FIXED_CAMERA)
				return true;
		}
		return false;
	}

	template<> boost::shared_ptr<Workspace> shared_from<Workspace>(Workspace*);

	EditSelectionVerb::EditSelectionVerb(VerbContainer* container, std::string name, DataModel* dm)
		: Verb(container, name), workspace(shared_from(dm ? dm->create<Workspace>() : NULL)), selection(dm), dataModel(dm)
	{
	}

	DeleteBase::DeleteBase(VerbContainer* container, DataModel* dm, std::string name)
		: EditSelectionVerb(container, name, dm), rewardHopper(false)
	{
	}
}
