// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
struct Base{virtual void vfunc();char padding[80];Base();~Base();};
struct Owner{void*pointer;Owner():pointer(0){}~Owner();};
struct CRobloxDoc:Base{char pad[0x74-84];Owner field74;std::vector<void*> inner;void*field90;void*field94;CRobloxDoc();};
CRobloxDoc::CRobloxDoc():field74(),field90(0),field94(0){}
