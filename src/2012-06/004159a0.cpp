// roc-cl: 21022
// roc-lang: cpp
// roc-flags: /O2 /Ob0 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared-rtm roc_espeon_nativedocumentfamilyad94f610efff160c.cpp

// Candidate translation unit (score above; library headers required).
#include <afxwin.h>
#include <afxpriv.h>
#include <shlobj.h>
#include <stdexcept>
static __declspec(noinline) void executeCommand(const char* first,const char* second) {
 CStringA directory;
 if(SHGetFolderPathA(0,CSIDL_COMMON_APPDATA,0,0,directory.GetBuffer(MAX_PATH))!=S_OK)
   throw std::runtime_error("Unable to get common document folder");
 directory.ReleaseBuffer();
 CStringA executable;
 AfxGetModuleShortFileName(AfxGetApp()->m_hInstance,executable);
 CStringA arguments;
 if(first)arguments+=first;
 if(second)arguments+=second;
 CWnd* window=AfxGetMainWnd();
 if(window)window=window->GetLastActivePopup();
 if((INT_PTR)ShellExecuteA(window->GetSafeHwnd(),"open",executable,arguments,directory,5)<=32)
   throw std::runtime_error("ShellExecute failed");
}
struct Document;
extern CStringA makeText();
extern CStringA documentText(Document*,const char*);
struct Document{void visitGame();void startServer();void joinServer();};
void Document::visitGame(){
 try {executeCommand(documentText(this,"Visit")," -script \"loadfile('"+makeText()+"/game/visit.ashx')()\"");}
 catch(const std::exception& e){AfxMessageBox(e.what(),0,0);}
}

void Document::startServer(){
 try {executeCommand(documentText(this,"Server")," -script \"loadfile('"+makeText()+"/game/gameserver.ashx')(0, 53640)\"");}
 catch(const std::exception& e){AfxMessageBox(e.what(),0,0);}
}
void Document::joinServer(){
 try {executeCommand(0," -script \"loadfile('"+makeText()+"/game/join.ashx?UserID=0&serverPort=53640')()\"");}
 catch(const std::exception& e){AfxMessageBox(e.what(),0,0);}
}
