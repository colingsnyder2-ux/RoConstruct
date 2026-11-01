// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-raknet roc_espeon_aug2007_bitstream_compressed_float_be3bb96b6dd3bbbb.cpp

// Candidate translation unit (score above; library headers required).
#include "BitStream.h"
void (RakNet::BitStream::*emitCompressedFloatWrite)(float)=&RakNet::BitStream::WriteCompressed<float>;
void (RakNet::BitStream::*emitCompressedDoubleWrite)(double)=&RakNet::BitStream::WriteCompressed<double>;
bool (RakNet::BitStream::*emitCompressedFloatRead)(float&)=&RakNet::BitStream::ReadCompressed<float>;
bool (RakNet::BitStream::*emitCompressedDoubleRead)(double&)=&RakNet::BitStream::ReadCompressed<double>;
