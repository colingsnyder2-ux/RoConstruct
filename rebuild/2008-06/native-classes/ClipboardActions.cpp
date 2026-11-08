// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
#include <afxwin.h>
#include <sstream>
#include <algorithm>
#include <boost/bind.hpp>
#include <intrin.h>
#include "ClipboardVerbs.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/SerializerV2.h"
#include "v8xml/XmlSerializer.h"

using namespace RBX;
void __cdecl collectSelection(XmlElement*, boost::shared_ptr<Instance>);
namespace RBX {
inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);
}

void CopyVerb::doIt(IDataState*)
{
    XmlElement* root = SerializerV2::newRootElement();
    Selection* selected = dataModel ? dataModel->create<Selection>() : NULL;
    std::for_each(selected->selection->begin(), selected->selection->end(), boost::bind(&collectSelection, root, _1));
    std::ostringstream stream(std::ios::out);
    TextXmlWriter writer(stream);
    writer.serialize(root);
    delete root;
    if (OpenClipboard(AfxGetMainWnd()->m_hWnd)) {
        EmptyClipboard();
        std::string text = stream.str();
        HGLOBAL memory = GlobalAlloc(GMEM_MOVEABLE, text.length() + 1);
        char* destination = static_cast<char*>(GlobalLock(memory));
        strcpy(destination, text.c_str());
        GlobalUnlock(memory);
        SetClipboardData(getClipboardFormat(), memory);
        CloseClipboard();
    }
}

void PasteVerb::doIt(IDataState* state)
{
    if (dataModel->findFirstChildByName("NetworkClient")) return;
    if (!OpenClipboard(AfxGetMainWnd()->m_hWnd)) return;
    HGLOBAL data = GetClipboardData(getClipboardFormat());
    const char* text = static_cast<const char*>(GlobalLock(data));
    std::vector<boost::shared_ptr<Instance> > instances;
    {
        std::istringstream input(text, std::ios::in);
        TextXmlParser parser(input.rdbuf());
        std::auto_ptr<XmlElement> root(parser.parse());
        Selection* selected = dataModel ? dataModel->create<Selection>() : NULL;
        Instance* parent = pasteInto && selected->size() == 1 ? selected->front().get() : dataModel->getWorkspace();
        InsertMode mode = pasteInto ? INSERT_TO_TREE : INSERT_TO_3D_VIEW;
        SerializerV2 serializer;
        serializer.loadInstances(root.get(), instances);
        dataModel->getWorkspace()->insertInstances(instances, parent, mode, SUPPRESS_PROMPTS);
        selected->setSelection(instances.begin(), instances.end());
    }
    GlobalUnlock(data);
    CloseClipboard();
    const Name& verbName = getName();
    _ReadWriteBarrier();
    recordCameraHistory(verbName.c_str(), dataModel);
    state->setDirty(true);
}
