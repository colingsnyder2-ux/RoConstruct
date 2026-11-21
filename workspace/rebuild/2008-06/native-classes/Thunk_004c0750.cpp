// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASE /FImalloc.h /I{headers}/../../../tools/openrbx/Client/Network/raknet30/Source /I{headers}/../../../tools/openrbx/util /I{headers}/../native-classes
// 004c0750: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "RSACryptDtor.cpp"
// INFERRED: 004c0750 is a 5-byte jump to big::RSACrypt<unsigned int [8]>::reset; the forwarder name and owner are placeholders.
struct Thunk_004c0750 : big::RSACrypt<unsigned int [8]> { void sub_004c0750(); };
void Thunk_004c0750::sub_004c0750() { big::RSACrypt<unsigned int [8]>::reset(); }
