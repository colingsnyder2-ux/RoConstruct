// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-raknet roc_espeon_aug2007_raknet_resend_underflow_clear_ad793c387039678d.cpp

// Candidate translation unit (score above; library headers required).
#include <cassert>
#include <cstring>
#pragma include_alias("DS_BPlusTree.h","roc_espeon_aug2007_bplus_underflow_clear_525fa1d3a7e21149.cpp")
#include "InternalPacket.h"
#include "DS_BPlusTree.h"
template bool DataStructures::BPlusTree<MessageNumberType, InternalPacket*, 32>::Delete(const MessageNumberType, InternalPacket*&);
