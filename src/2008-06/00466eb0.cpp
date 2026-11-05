// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_settingsdialog_436d76c11c2c1728.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
extern "C" int __stdcall query(int,int,int);
struct Service {
    void action();
};

typedef boost::shared_ptr<Service> Shared;
Shared __cdecl getService();

struct Dialog {
    char storage[0x3d4];
    Dialog(void*);
    ~Dialog();
    int run();
};

void __cdecl settings(void* argument)
{
    if (query(0x88, 0x31, -1) == 1) {
        Dialog dialog(argument);
        if (dialog.run() == 1) {
            query(0x8e, 0x40, -1);
            getService()->action();
        }
    }
}
