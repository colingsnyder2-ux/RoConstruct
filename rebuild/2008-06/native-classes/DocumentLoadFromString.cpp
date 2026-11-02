#include <afxwin.h>
#include "CRobloxDoc.h"
#include "v8datamodel/DataModel.h"
#include "script/ScriptContext.h"
#include "reflection/type.h"

int CRobloxDoc::loadFromString(std::string text)
{
    RBX::DataModel::Lock lock(getDataModel());
    RBX::Reflection::ValueCollection args;
    try {
        getDataModel()->create<RBX::ScriptContext>()->executeInNewThread(
            RBX::Security::LocalGUI, text.c_str(), "Doc script", args);
        return 1;
    } catch (...) {
        return 0;
    }
}
