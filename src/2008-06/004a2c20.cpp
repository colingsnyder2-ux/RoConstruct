// from server: 100% by auto
// from server: 100% by EspClaude
// from server: 81% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net-dll roc_espclaude_04a5f891e6e8a658.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#include "raknet30/Source/BitStream.h"
#include "raknet30/Source/RakNetTypes.h"
#pragma include_alias("util/Name.h", "../App/roc_espeon_insertnativeheader115b7bccd0a9061e.cpp")
#include "util/Guid.h"
#include "util/StandardOut.h"
#include <stdexcept>
#include <boost/shared_ptr.hpp>
#include <G3D/format.h>
struct PlayerView {void activate(bool);};
struct SettingsView {};
SettingsView* settings();
boost::shared_ptr<PlayerView> playerReference(void*);
struct ReaderView {bool read(RakNet::BitStream&,void*&,RBX::Guid::Data&);};
class ClientProxyRecovery {
public:
 template<class T> T& field(unsigned offset) {return *reinterpret_cast<T*>(reinterpret_cast<char*>(this)+offset);}
 int forward(void*,Packet*);
 int process(void*,Packet*);
};
int ClientProxyRecovery::process(void* source,Packet* packet) {
 SystemAddress* sender=&packet->systemAddress;
 if(*sender==field<SystemAddress>(0x1e0)) return forward(source,packet);
 switch(packet->data[0]) {
 case 76:
 try {
  RakNet::BitStream stream(packet->data,packet->length,false);
  stream.IgnoreBits(8);
  RBX::Guid::Data identifier;
  if(reinterpret_cast<ReaderView*>(reinterpret_cast<char*>(this)-0x2b74)->read(stream,source,identifier)) {
  if(*reinterpret_cast<bool*>(reinterpret_cast<char*>(settings())+0x131))
   RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO,"Received remotePlayer %s from %s",reinterpret_cast<char*>(this)-0x2b74,identifier.readableString(4).c_str(),sender->ToString(true));
  field<boost::shared_ptr<PlayerView> >(0x1f4)=playerReference(source?static_cast<char*>(source)+0xe4:0);
  if(!field<boost::shared_ptr<PlayerView> >(0x1f4)) throw std::runtime_error("remotePlayer is NULL");
  field<boost::shared_ptr<PlayerView> >(0x1f4)->activate(true);
  } else {
   throw std::runtime_error(G3D::format("Couldn't resolve remotePlayer %s from %s",identifier.readableString(4).c_str(),sender->ToString(true)));
  }
 } catch(const std::exception& error) {
  RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR,"Replicator::ClientProxy::OnReceive packet %d: %s",packet->data[0],error.what());
 }
 break;
 default:
  return forward(source,packet);
 }
 return 0;
}

