// from server: 100% by EspClaude
// from server: 93% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: rbxgs-dll roc_claude_dfbe6bfbe46af088.cpp

// Candidate translation unit (score above; library headers required).
struct Descriptor;extern Descriptor stateProperty;
struct Connection{void disconnect();};
struct Accoutrement{char prefix[0xfc];int state;char gap[0x13c-0x100];Connection connection;void enterWorkspace();void leaveWorkspace();void equip();void enterCharacter();void connectTouch();void unequip();void leaveCharacter();void changed(const Descriptor&);void setState(int v){if(v!=state){state=v;changed(stateProperty);}}void setDesired(int,const void*);};
void Accoutrement::setDesired(int desired,const void*){do{if(state<desired){switch(state){case 3:equip();break;case 2:enterCharacter();break;case 1:enterWorkspace();break;case 0:connectTouch();break;}setState(state+1);}else if(desired<state){switch(state){case 4:unequip();break;case 3:leaveCharacter();break;case 2:leaveWorkspace();break;case 1:connection.disconnect();break;}setState(state-1);}}while(desired!=state);}

void Accoutrement::enterWorkspace(){}
void Accoutrement::leaveWorkspace(){}
