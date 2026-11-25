// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header excerpt was provided, so the include path below is a guess.
// The target is the compiler-generated adjustor{16} thunk (this -= 16; jmp the real
// vector deleting destructor) for the secondary-base vtable slot. Explicitly
// instantiating the real template makes the compiler emit it, so no class is redefined here.
#include "v8datamodel/Workspace.h"

// INFERRED: the previous attempt failed because sWorkspace is declared as an array
// (char[]), so &sWorkspace has type char(*)[]. The template parameter is a
// const char*, so the array name is passed directly and decays to a pointer.
template class RBX::DescribedNonCreatable<RBX::Workspace, RBX::RootInstance, RBX::sWorkspace>;
