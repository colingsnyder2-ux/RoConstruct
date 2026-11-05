// from server: 100% by colin
// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_slotclear_1daf5782a29bf221.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
extern unsigned int counter;struct Object{virtual ~Object();};inline unsigned int slot(){static unsigned int value=counter++;return value;}struct Context{std::vector<Object*> entries;void clear();};void Context::clear(){if(entries.size()>slot()){delete entries[slot()];entries[slot()]=0;}}