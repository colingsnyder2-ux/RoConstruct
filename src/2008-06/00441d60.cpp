// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared-rtm roc_espeon_texturedialogpointercopyfd8ed757bf5a89be.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias(<atlsimpstr.h>, <roc_espeon_mfcimportedstringcastfb14fe2507201232.cpp>)
#include <afxwin.h>
#include <afxdlgs.h>
#include <fstream>
#include <string>
namespace RBX { class Name; class ContentId { std::string id; const Name* mimeTypePtr; public: ContentId(const ContentId* source):id(source->id),mimeTypePtr(source->mimeTypePtr) {} }; }
const RBX::Name& getMimeType(const char*);
RBX::ContentId registerContent(std::istream&,const RBX::Name&);
struct EditSession { void prepare(); };
// Only the target-read member offsets are represented; preceding bytes are unknown.
struct PropertyOwner { unsigned char unknownPrefix[0x198]; EditSession* session; };
struct TextureItem { unsigned char unknownPrefix[0x128]; PropertyOwner* owner; void accept(const RBX::ContentId&); void importFile(); };
inline const RBX::ContentId* addressIdentifier(const RBX::ContentId& source) { return &source; }
void TextureItem::importFile() {
 CString filter; filter.LoadString(0x84);
 CFileDialog dialog(TRUE,0,0,0,filter);
 if(dialog.DoModal()==IDOK) {
  std::ifstream stream(dialog.GetPathName(),std::ios::in|std::ios::binary);
  if(owner->session) owner->session->prepare();
  RBX::ContentId id(addressIdentifier(registerContent(stream,getMimeType(dialog.GetPathName()))));
  accept(id);
 }
}
