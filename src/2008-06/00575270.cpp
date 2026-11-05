// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_serviceexitnative69b4472e2afa98b9.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <stdexcept>
struct Verb {virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void execute(void*);};
struct Registry {Verb* find(std::string);};
struct Provider {char prefix[0x1c8];Registry registry;void exit();};
void Provider::exit(){Verb* verb=registry.find("Exit");if(!verb)throw std::runtime_error("Couldn't find Exit Verb");verb->execute(0);}
