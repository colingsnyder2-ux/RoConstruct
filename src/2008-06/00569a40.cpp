// from server: 100% by EspClaude
// from server: 76% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_86534036f8ae5a54.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
extern int mode;
struct Output {char prefix[28];std::string label;void emit(int,const char*,int);
void first(int,int,const char*,const char*,int);
void second(int,int,const char*,const char*,int);};
void Output::emit(int a,const char* b,int c){if(label.empty()){if(mode==0)first(1,a,b,0,c);else if(mode==1)second(1,a,b,0,c);}else{const char* p=label.c_str();if(mode==0)first(1,a,b,p,c);else if(mode==1)second(1,a,b,p,c);}}

