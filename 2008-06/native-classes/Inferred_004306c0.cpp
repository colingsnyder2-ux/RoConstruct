// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_004306c0 (placeholder name for 004306c0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8datamodel/DataModel.h"

namespace RBX { class DataModel; }

extern boost::shared_ptr<RBX::DataModel> activeDocDataModel;

boost::shared_ptr<RBX::DataModel> sub_004306c0()
{
    return activeDocDataModel;
}
