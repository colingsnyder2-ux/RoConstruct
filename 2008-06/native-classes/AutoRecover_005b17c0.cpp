// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the analog is a 16-byte stub that forwards its first argument to
// Accoutrement::dropAllOthers(model, 0), so the body is just that call.
// INFERRED: the header path below is a guess at where Accoutrement is declared.
#include "v8datamodel/Accoutrement.h"

extern "C" void str_match(RBX::ModelInstance* model)
{
    RBX::Accoutrement::dropAllOthers(model, 0);
}
