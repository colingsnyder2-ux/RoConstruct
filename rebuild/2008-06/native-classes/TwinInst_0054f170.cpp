// native-flags: /Od /Ob0 /GS- /MD
// 0054f170: explicit instantiation of the class the body at 0054f170 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include <map>
template class std::map<unsigned short, unsigned char>;
