// from server: 100% by EspClaude
// roc 2007-08 00410e40  PasteVerb::isEnabled: Roblox clipboard format available and (not selection-only or exactly one selected)
#include <vector>
extern "C" __declspec(dllimport) unsigned int __stdcall RegisterClipboardFormatA(const char* lpszFormat);
extern "C" __declspec(dllimport) int __stdcall IsClipboardFormatAvailable(unsigned int format);

struct Entry {
    void* value;
    void* owner;
};
typedef std::vector<Entry> Instances;

struct Selection {
    char padding[0x104];
    Instances* items;
};

struct DataModel {
    Selection* getSelection();
};

class PasteVerb {
    char padding[0xc];
    DataModel* dataModel;
    bool intoSelection;
public:
    bool isEnabled() const;
};

bool PasteVerb::isEnabled() const
{
    static unsigned int format = RegisterClipboardFormatA("Roblox");
    if (IsClipboardFormatAvailable(format) != 1)
        return false;
    if (!intoSelection)
        return true;
    Selection* selection = dataModel ? dataModel->getSelection() : 0;
    return selection->items->size() == 1;
}
