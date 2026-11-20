// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Tool (inactive): state-walk members of the original Tool unit 005fd3a0..006004d0.
// Statement order from donor tools/rbxgs v8datamodel/Tool.cpp (roc_espclaude_cc7153d713b9aac6.cpp.i).
#include "v8datamodel/Tool.h"

namespace RBX
{
	// 005fd3d0: single-instruction tail call. INFERRED: fn_00642fc0 is the unresolved target of the
	// original 5-byte jmp; the name is not in the identity registry, so the member is kept as sub_005fd3d0.
	extern void fn_00642fc0();
	void Tool::sub_005fd3d0()
	{
		fn_00642fc0();
	}

	// 0097b7e0 is the C-linkage data symbol _prop_BackendToolState (identity registry), defined static in
	// native-classes/Tool.cpp. extern "C" reproduces that reference name.
	extern "C" { extern Reflection::PropDescriptor<Tool, int> prop_BackendToolState; }

	// The original unit defines these three helpers with empty bodies (donor 139563-139565). Local
	// inline empty stand-ins reproduce the inlined-to-nothing switch cases and the original 7/6-entry
	// jump tables without redefining Tool members from the separate Tool.cpp unit.
	namespace { inline void emptyUpToWorkspace() {} inline void emptyUpToActivated() {}
	           inline void emptyDownFromWorkspace() {} }

	// 005ff900: walk backendToolState one step at a time toward the desired state.
	// setBackendToolState is inlined here (it lives in the separate Tool.cpp unit); the donor body is
	// switch-on-backendToolState with all 7 up / 6 down enum cases.
	void Tool::setDesiredState(ToolState desiredState, const ServiceProvider* serviceProvider)
	{
		do
		{
			int next;

			if ((int)desiredState > (int)backendToolState)
			{
				switch (backendToolState)
				{
				case HAS_TORSO:    upTo_Equipped();     break;
				case IN_CHARACTER: upTo_HasTorso();     break;
				case IN_WORKSPACE: upTo_InCharacter();  break;
				case HAS_HANDLE:   emptyUpToWorkspace();   break;
				case NOTHING:      connectTouchEvent();    break;
				case EQUIPPED:     emptyUpToActivated();    break;
				case ACTIVATED:    emptyUpToActivated();    break;
				}
				next = (int)backendToolState + 1;
			}
			else if ((int)desiredState < (int)backendToolState)
			{
				switch (backendToolState)
				{
				case EQUIPPED:     downFrom_Equipped();    break;
				case HAS_TORSO:    downFrom_HasTorso();    break;
				case IN_CHARACTER: downFrom_InCharacter(); break;
				case IN_WORKSPACE: emptyDownFromWorkspace();  break;
				case HAS_HANDLE:   handleTouched.disconnect(); break; // downFrom_HasHandle() inlined
				case NOTHING:      emptyDownFromWorkspace(); break;
				}
				next = (int)backendToolState - 1;
			}
			else
			{
				continue;
			}

			// inlined setBackendToolState(next)
			if (next != (int)backendToolState)
			{
				setBackendToolStateNoReplicate(next);
				raisePropertyChanged(prop_BackendToolState);
			}
		}
		while ((int)desiredState != (int)backendToolState);
	}
}
