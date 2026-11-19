// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00489aa0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include <G3D/platform.h>
#include <G3D/System.h>
#include <G3D/Rect2D.h>
#include <G3D/Array.h>
#include "util/Name.h"

template void G3D::Array<G3D::Rect2D>::realloc(int);
