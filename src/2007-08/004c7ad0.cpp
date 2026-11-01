// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-raknet roc_espeon_aug2007_raknet_resend_root_clear_2517f4e7b26c8129.cpp

// Candidate translation unit (score above; library headers required).
#include <cassert>
#include <cstring>
#pragma include_alias("DS_BPlusTree.h","roc_espeon_aug2007_bplus_historical_clear_040b45b8c86157f2.cpp")
#include "InternalPacket.h"
#include "DS_BPlusTree.h"
template bool DataStructures::BPlusTree<MessageNumberType, InternalPacket*, 32>::Delete(const MessageNumberType, InternalPacket*&);
