// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/datamodel-2008 /I{headers}/instance-ancestor-inline /I{headers}/slingshot-load
// 2008-06 native RBX::DataModel methods (inactive until proved):
//   00579c10 save(ContentId)                    - descriptor-ptm, BoundFuncDesc<DataModel,void(ContentId),1> fn #0
//   00575890 processAccelerators(const GuiEvent&) - callgraph-adjacency, private method
// Authentic declarations: rebuild/2008-06/native-headers/v8datamodel/DataModel.h.
// Statement order from the byte-exact donors src/2008-06/<addr>.cpp and the authentic
// tools/openrbx .../v8datamodel/DataModel.cpp; external call identities are bound from the
// original image relocations (root_ref_bind). The datamodel-2008 header variants carry only
// the 2008-06 destructor/shape differences evidenced by these two bodies (// INFERRED lines).
#include "v8datamodel/DataModel.h"
#include "util/ContentProvider.h"
#include "metadata-load/v8xml/SerializerV2.h"
#include "util/Http.h"
#include "gui/GuiEvent.h"
#include "util/RunStateOwner.h"
#include "Network/Players.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/Accoutrement.h"
#include "LocalBackpack2008/LocalBackpack2008.h"
#include <sstream>

namespace RBX {
void DataModel::save(ContentId contentId)
{
    std::stringstream stream;
    {
        boost::scoped_ptr<XmlElement> root(SerializerV2::newRootElement());
        writeChildren(root.get());
        TextXmlWriterWithEmbeddedContent machine(this ? getContentProvider() : 0, stream);
        machine.serialize(root.get());
        stream.flush();
    }
    std::string response;
    Http(contentId.toString()).post(stream, true, response);
}

GuiResponse DataModel::processAccelerators(const GuiEvent& event)
{
    Verb* verb = NULL;
    switch (event.eventType)
    {
    case UIEvent::KEY_DOWN:
        if (event.key > '0' && event.key <= '9')
        {
            if (localBackpack->onKey(event.key - '0'))
                return GuiResponse::used();
        }
        else
        {
            switch (event.key)
            {
            case 27:
                runService->setRunState(RS_PAUSED);
                break;
            case 8:
                if (ModelInstance* player = Network::Players::findLocalCharacter(this))
                    Tool::dropAll(player);
                break;
            case ',':
                verb = workspace->getVerb("CameraPanLeft");
                break;
            case 'o':
                verb = workspace->getVerb("CameraZoomOut");
                break;
            case '.':
                verb = workspace->getVerb("CameraPanRight");
                break;
            case 280:
                verb = workspace->getVerb("CameraTiltDown");
                break;
            case 281:
                verb = workspace->getVerb("CameraTiltUp");
                break;
            case '=':
                if (ModelInstance* player = Network::Players::findLocalCharacter(this))
                    Hat::dropAll(player);
                break;
            case ']':
                localBackpack->cycleUp();
                break;
            case '[':
                localBackpack->cycleDown();
                break;
            case 282:
                if (event.mod == 0)
                    verb = getVerb("Help");
                else
                    verb = getVerb("Stats");
                break;
            case 'i':
                verb = workspace->getVerb("CameraZoomIn");
                break;
            }
        }
        break;
    case UIEvent::MOUSE_WHEEL_FORWARD:
        verb = workspace->getVerb("CameraZoomIn");
        break;
    case UIEvent::MOUSE_WHEEL_BACKWARD:
        verb = workspace->getVerb("CameraZoomOut");
        break;
    }
    if (verb && verb->isEnabled())
    {
        verb->doIt(this);
        return GuiResponse::used();
    }
    return GuiResponse::notUsed();
}
}
