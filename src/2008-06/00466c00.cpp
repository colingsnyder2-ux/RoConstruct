// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_settingsexplorer_8fdbe5e0b4bce0ed.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Service {
    void invoke();
};

typedef boost::shared_ptr<Service> ServiceHandle;
extern ServiceHandle __cdecl getService();

struct CSettingsExplorer {
    long sendMessage(unsigned int, unsigned int, long);
    int showWindow(int);
    void update();
};

void CSettingsExplorer::update() {
    sendMessage(0x8f, 0x40, -1);
    getService()->invoke();
    showWindow(2);
}
