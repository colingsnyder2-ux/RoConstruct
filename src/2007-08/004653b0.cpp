// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_mouse_buffer_delta_3f991d444c4341cd.cpp

// Candidate translation unit (score above; library headers required).
#define _MT 1
#define _DLL 1
#include <windows.h>
#include <G3D/Vector2.h>
#include <G3D/Array.h>
#include "../Rendering/g3d/GLG3Dcpp/directinput8.h"
G3D::Vector2 bufferedMouseDelta(const G3D::DIDEVICEOBJECTDATA& event) { G3D::Vector2 result(0,0); float delta = (float)(LONG)event.dwData; if (event.dwOfs == 0) result.x=delta; else result.y=delta; return result; }
