// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#include <map>

// value_type size from max_size immediate: 0xFFFFFFFF/(imm+1) = 28 bytes.
struct ValueN { int words[6]; };
template class std::map<int, ValueN>;
