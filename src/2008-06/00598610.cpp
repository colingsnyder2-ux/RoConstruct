// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_decaltextureidnative2a16a7e66333a1e9.cpp

// Candidate translation unit (score above; library headers required).
#include "util/TextureId.h"
struct Property;
extern Property textureProperty;
struct Decal {char prefix[0x144];RBX::TextureId texture;void raisePropertyChanged(const Property&);void setTexture(RBX::TextureId);};
void Decal::setTexture(RBX::TextureId value){if(texture!=value){texture=value;raisePropertyChanged(textureProperty);}}
