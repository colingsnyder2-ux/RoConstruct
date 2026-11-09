// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_replicationnativecontexte97b90c623137883.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include "security/SecurityContext.h"
struct Reader { bool read(unsigned char*,int,bool); };
struct ClientProxy {
 char pad[0x2d5c]; int lastType;
 void process(Reader&);
 void readDelete(Reader&);void readNew(Reader&);void readChange(Reader&);void readMarker(Reader&);
};
void ClientProxy::process(Reader& stream) {
 RBX::Security::Impersonator impersonate(RBX::Security::Replicator);
 bool done=false;
 do {
  int value=0;
  stream.read((unsigned char*)&value,2,true);
  if(value<1 || value>3) stream.read((unsigned char*)&value,32,true);
  switch(value) {
  case 1:readDelete(stream);break;
  case 2:readNew(stream);break;
  case 3:readChange(stream);break;
  case 4:readMarker(stream);break;
  case 0:done=true;break;
  }
  lastType=value;
 } while(!done);
}
