// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_king_originala_gui_rect_a2492bc6f5a7c7b1.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Rect.h"
#include <intrin.h>
struct NativeGuiRect {
 char prefix[0x1c8]; short x0,y0,x1,y1;
 RBX::Rect getRect()const;
};
RBX::Rect NativeGuiRect::getRect()const {
 const G3D::Vector2 low((float)x0,(float)y0);
 const G3D::Vector2 high((float)x1,(float)y1);
 return RBX::Rect(low,high);
}
