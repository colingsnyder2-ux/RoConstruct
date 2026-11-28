// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "reflection/reflection.h"
#include "reflection/enumconverter.h"
#include "v8datamodel/Mouse.h"
#include "v8datamodel/PartInstance.h"
#include "GfxBase/RenderSettings.h"
typedef RBX::Reflection::RefPropDescriptor<RBX::Mouse, RBX::PartInstance> RPD;
typedef RBX::Reflection::EnumDesc<CRenderSettings::AntialiasingMode> ED;
template class RBX::Reflection::RefPropDescriptor<RBX::Mouse, RBX::PartInstance>;
template class RBX::Reflection::EnumDesc<CRenderSettings::AntialiasingMode>;
void _gemini_force_rpd(RPD* p, RPD* a) {
    volatile void* v1 = (void*)&RPD::equalValues;
    delete p; delete[] a;
}
void _gemini_force_ed(ED* p, ED* a) { delete p; delete[] a; }
