#pragma once
// Declaration-only overlay for RBX::Workspace used by tests/record_native_click_detector.py for the
// NATIVE_CLICKDETECTOR_PENDING build (copied as out/native-layouts/click-detector-pending/v8datamodel/Workspace.h);
// not a shared header. The donor Workspace.h does not compile against the 2008 reflection.h. ClickDetector only needs
// a complete polymorphic RBX::Workspace derived from RBX::Instance for dynamic_cast (type descriptor 009481b8
// .?AVWorkspace@RBX@@, used by isClickable 00629b20). No member or layout is claimed here.
#include "v8tree/Instance.h"

namespace RBX
{
	class Workspace : public Instance
	{
	private:
		Workspace();
	};
}
