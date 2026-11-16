// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "gui/ChatOutput.h"
#include "Network/Player.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Team.h"
#include "v8tree/Service.h"
#include "util/Color.h"
namespace RBX {
// Identity registry: 00669f60.
unsigned int stringHash(const std::string&);
ChatLine::ChatLine(Network::Player* player, const std::string& text, float timestamp)
    : user(), message(text), dieTime(timestamp), profane(false)
{
    user = player->getName();
    Teams* teams = ServiceProvider::find<Teams>(player);
    if (teams && teams->isTeamGame()) {
        if (!player->getNeutral()) {
            Team* team = teams->getTeamFromPlayer(player);
            if (team) userColor = team->getTeamColor().color3();
            else userColor = G3D::Color3::black();
        } else userColor = G3D::Color3::white();
    } else userColor = Color::colorFromIndex8(stringHash(user) & 7);
}
}
