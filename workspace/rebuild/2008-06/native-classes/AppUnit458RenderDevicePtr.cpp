// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <memory>
#include <GLG3D/RenderDevice.h>

template std::auto_ptr<G3D::RenderDevice>::~auto_ptr();
