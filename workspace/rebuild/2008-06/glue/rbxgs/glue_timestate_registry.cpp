// Rebuild shim, tracked: a DataModel's TimeState.
// rbxgs keeps it in DataModel::timeState, but the 2008 DataModel (0x264 bytes, destructor 0x57ad70) has no such
// member. This table keeps rbxgs's time keeping working on the 2008 layout; it is not recovered 2008 code.
#include "v8datamodel/DataModel.h"
#include "v8datamodel/TimeState.h"
#include <map>

namespace RBX
{
	TimeState* DataModel::getTimeState() const
	{
		// ponytail: one TimeState per DataModel, never freed (a process has one or two DataModels)
		static std::map<const DataModel*, TimeState*> table;
		TimeState*& state = table[this];
		if (!state)
			state = new TimeState;
		return state;
	}
}
