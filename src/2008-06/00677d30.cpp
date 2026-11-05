// from server: 100% by auto
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_contenttexturenamed2399d7549f79d9cc.cpp

// Candidate translation unit (score above; library headers required).
#include <util/ContentProvider.h>
#include <RbxGraphics/Adorn.h>
extern RBX::ContentProvider* provider;
RBX::TextureProxyBaseRef createTextureProxy(RBX::Adorn* adorn,const RBX::ContentId& id){try{std::string filename=provider->getFile(id);return adorn->createTextureProxy(filename);}catch(std::exception&){return RBX::TextureProxyBaseRef(0);}}
