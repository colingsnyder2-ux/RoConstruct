// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-raknet roc_espeon_aug2007_bitstream_network_id_members_9f660cda4b8ecff5.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("BitStream.h","roc_espeon_aug2007_bitstream_network_id_members_header_45e2470c31276223.cpp")
#include "BitStream.h"
void (RakNet::BitStream::*emitNetworkIDWrite)(NetworkID)=&RakNet::BitStream::Write<NetworkID>;
