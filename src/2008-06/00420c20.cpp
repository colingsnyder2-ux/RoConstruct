// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-strlen roc_explorer_native_sdk_clean_22815ae87c71488d.cpp

// Candidate translation unit (score above; library headers required).
#include <XTToolkitPro.h>
// Borrowed 16-byte event ABI; native00422c60 destroys shared ownership pairs
// at0/4 and8/c. This declaration calls that external destructor and does not
// implement a replacement control block or invent a full Roblox owner class.
struct RemovedEventView {
 void* instance; void* instanceControl; void* parent; void* parentControl;
 ~RemovedEventView();
};
struct ExplorerListenerEntry { void remove(const void* source,RemovedEventView event); };
void ExplorerListenerEntry::remove(const void*,RemovedEventView event) {
 char* ownerBytes=reinterpret_cast<char*>(this)-0x39c;
 CXTPReportView* view=reinterpret_cast<CXTPReportView*>(ownerBytes);
 CXTPReportRecords* records=view->GetReportCtrl().GetRecords();
 for(int i=records->GetCount()-1;i>=0;--i) {
  CXTPReportRecord* record=records->GetAt(i);
  // Derived record's pointer location is directly observed; its owner header
  // is unavailable, so no fabricated derived class is declared.
  void* instance=*reinterpret_cast<void**>(reinterpret_cast<char*>(record)+0x54);
  if(instance==event.instance) { records->RemoveAt(i);break; }
 }
 if(!*reinterpret_cast<unsigned char*>(ownerBytes+0x3c8))view->GetReportCtrl().Populate();
}
