// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <vector>

struct Instance;
struct ClassDescriptor;
struct InstancePtr { Instance* px; void* pn; };
typedef std::vector<InstancePtr> Instances;
typedef std::map<const ClassDescriptor*, Instances> Selection;

class CXTPPropertyGridItem {
public:
    virtual ~CXTPPropertyGridItem();
    void SetHidden(int bHidden);
    char pad[0x108];
};

struct UpdateBase {
    virtual void update(Selection& selection);
    std::vector<const ClassDescriptor*> classes;
};

struct ScriptItem : CXTPPropertyGridItem, UpdateBase {
    void update(Selection& selection);
};

void ScriptItem::update(Selection& selection)
{
    Selection::iterator selectionEnd = selection.end();
    for (std::vector<const ClassDescriptor*>::const_iterator c = classes.begin(), ce = classes.end(); c != ce; ++c) {
        const ClassDescriptor* key = *c;
        Selection::iterator selected = selection.find(key);
        size_t n = selected != selection.end() ? selected->second.size() : 0;
        if (n > 0) {
            SetHidden(0);
            return;
        }
    }
    SetHidden(1);
}
