#include "../native-headers/v8datamodel/DataModel.h"
#include <cstddef>
template<int N> struct Show { char bad[-N - 1]; };
Show<offsetof(RBX::DataModel, workspace)> showWorkspace;
Show<sizeof(RBX::DataModel)> showSize;
Show<(int)static_cast<RBX::VerbContainer*>(reinterpret_cast<RBX::DataModel*>(0x10000)) - 0x10000 + 5000> showVerbContainer;
