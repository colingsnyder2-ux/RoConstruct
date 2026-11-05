// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_imagefileprivatecontextf69cbca4933a66ef.cpp

// Candidate translation unit (score above; library headers required).
#include <util/ContentProvider.h>
#include <fstream>
namespace RBX {
const Name& getMimeType(const char* filename);
ContentId registerImageContent(std::istream&,const Name&);
static __declspec(noinline) ContentId registerImageFile(const char* filename) {
 std::ifstream stream(filename,std::ios::in|std::ios::binary);
 return registerImageContent(stream,getMimeType(filename));
}
void acceptContent(const ContentId&);
void loadImageFile(const char* filename) {
 ContentId id=registerImageFile(filename);
 acceptContent(id);
}
}
