// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /FImalloc.h /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source /I{headers}/../native-classes
// 004cfb00: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "RakBPlusTree2008.cpp"
// INFERRED: 004cfb00 is a 5-byte jump to DataStructures::MemoryPool<struct DataStructures::Page<unsigned int,struct InternalPacket *,32> >::Clear; the forwarder name and owner are placeholders.
struct Thunk_004cfb00 : DataStructures::MemoryPool<struct DataStructures::Page<unsigned int,struct InternalPacket *,32> > { void sub_004cfb00(); };
void Thunk_004cfb00::sub_004cfb00() { DataStructures::MemoryPool<struct DataStructures::Page<unsigned int,struct InternalPacket *,32> >::Clear(); }
