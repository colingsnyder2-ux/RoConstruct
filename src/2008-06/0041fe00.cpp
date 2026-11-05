// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_insertempty_09d04325881939a3.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
#include <vector>
typedef boost::shared_ptr<void> Shared;

struct DialogBase {
    char storage[112];
    DialogBase(unsigned int, void*);
    virtual ~DialogBase();
};

typedef std::vector<Shared> ObjectList;

typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

struct StringStorage {
    void* data;
    __declspec(dllimport) StringStorage(const char*);
    ~StringStorage();
};

struct String : StringStorage {
    __declspec(dllimport) String(const char*);
    ~String();
};

struct Auxiliary {
    unsigned int storage[2];
    Auxiliary();
    ~Auxiliary();
};

struct WindowBase {
    WindowBase();
    virtual ~WindowBase();
};

struct DialogWindow : WindowBase {
    DialogWindow();
    virtual ~DialogWindow();
};

inline DialogWindow::DialogWindow() : WindowBase() {}

struct CInsertObjectDialog : DialogBase {
    Shared selected;
    ObjectList objects;
    String title;
    Shared temporary;
    Auxiliary auxiliary;
    DialogWindow window;

    CInsertObjectDialog(Shared, void*);
    virtual ~CInsertObjectDialog();
};

CInsertObjectDialog::CInsertObjectDialog(Shared value, void* parent)
    : DialogBase(value ? 107 : 214, parent),
      selected(value),
      objects(),
      title(""),
      temporary(),
      auxiliary(),
      window()
{
}