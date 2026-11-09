// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_2779ba3d3cbeb828.cpp

// Candidate translation unit (score above; library headers required).
#include "util/TextureId.h"
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
extern const Reflection::PropertyDescriptor textureDescriptor;
class BackpackItem;
class DrawChanged {};
struct DrawNotifier { void raise(DrawChanged) const; };
struct WorkspaceView {
    char opaquePrefix[0x344];
    DrawNotifier drawChanged;
    void raiseDrawChanged() const { drawChanged.raise(DrawChanged()); }
};
extern WorkspaceView* __cdecl findWorkspace(const BackpackItem*);
class BackpackItem {
    char opaquePrefix[0x180];
    TextureId textureId;
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
    void setTextureId(const TextureId&);
};
void BackpackItem::setTextureId(const TextureId& value) {
    if (value != textureId) {
        textureId = value;
        WorkspaceView* workspace = findWorkspace(this);
        if (workspace) workspace->raiseDrawChanged();
        raisePropertyChanged(textureDescriptor);
    }
}
}
