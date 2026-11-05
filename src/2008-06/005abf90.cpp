// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_vectorprocessrange009998d621c1fa19.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
struct Item {unsigned char data[8];};
extern int processItem(Item*,void*);
int processRange(std::vector<Item>*container,void*argument){int result=0;for(std::vector<Item>::iterator current=container->begin(),end=container->end();current!=end;++current)result+=processItem(&*current,argument);return result;}
