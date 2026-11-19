// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 005cd8b0: EnumDesc<T>::callDoSingleton and its target doSingleton (005cd850); T is read from the RTTI vftable the constructor called by 005cd850 installs (thunk_lane.py, no model)
#include "v8datamodel/Camera.h"
#include "reflection/enumconverter.h"
template class RBX::Reflection::EnumDesc<RBX::Camera::CameraType>;
