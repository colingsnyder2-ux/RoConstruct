// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_scorehud_family_1346da7936040480.cpp

// Candidate translation unit (score above; library headers required).
#include <gui/ScoreHud.h>
#include <v8datamodel/Teams.h>
#include <v8datamodel/Team.h>
#include <util/Utilities.h>
#include <util/Color.h>
#include <G3D/Color3.h>
#include <G3D/Color4.h>
namespace RBX {
// Existing native service specialization; retain the native call boundary.
template<> Teams* ServiceProvider::create<Teams>(const Instance*);
// Opaque public API receivers keep older headers' private Instance/Gui/Players
// layouts out of these calls. Signatures are the genuine public declarations.
class InstanceApi { public: size_t numChildren() const; Instance* getChild(size_t); const std::string& getName() const; };
class GuiItemApi { public: void setGuiSize(const G3D::Vector2&); };
class PlayersApi { public: int numPlayers() const; };
void ScoreHud::renderTeamDeathmatchLeaderboard(Adorn* adorn,BoardType mode) {
    LeaderboardData data(this);
    data.CompileData();
    Teams* teams=ServiceProvider::create<Teams>(this);
    if(!teams) return;
    float scale=adorn->getViewport().width()/1024.0f;
    float row=14.0f*scale;
    unsigned teamCount=((InstanceApi*)teams)->numChildren();
    Network::Players* nativePlayers=*(Network::Players**)((char*)this+0x150);
    unsigned playerCount=((PlayersApi*)nativePlayers)->numPlayers();
    unsigned rows=mode==TEAM_DEATHMATCH ? playerCount+3*(teamCount+1) : playerCount+3*teamCount+2;
    ((GuiItemApi*)this)->setGuiSize(G3D::Vector2(scale*(mode==TEAM_DEATHMATCH?320.0f:240.0f),rows*row));
    Rect rect=getMyRect();
    adorn->rect2d(rect.toRect2D(),GuiItem::translucentBackdrop());
    if(mode==TEAM_DEATHMATCH) {
        for(unsigned col=0;col<data.statNamesList.size()+1;++col) {
            G3D::Vector2 position(rect.low.x,rect.low.y);
            float width=rect.high.x-rect.low.x;
            std::string label("Team");
            if(col) {
                position.x+=width*0.5f+width*0.5f/data.statNamesList.size()*(col-1);
                label=data.statNamesList[col-1];
            }
            adorn->drawFont2D(label,position,row,G3D::Color4(G3D::Color3::white(),1),G3D::Color4::zero(),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
        }
        rect.low.y+=row;
    }
    for(unsigned teamIndex=0;teamIndex<((InstanceApi*)teams)->numChildren();++teamIndex) {
        Team* team=dynamic_cast<Team*>(((InstanceApi*)teams)->getChild(teamIndex));
        if(!team) continue;
        for(unsigned col=0;col<data.statNamesList.size()+1;++col) {
            G3D::Vector2 position(rect.low.x,rect.low.y);
            float width=rect.high.x-rect.low.x;
            std::string label=((InstanceApi*)team)->getName();
            if(col) {
                position.x+=width*0.5f+width*0.5f/data.statNamesList.size()*(col-1);
                label=StringConverter<int>::convertToString(data.teamTotals[team][data.statNamesList[col-1]]);
            }
            adorn->drawFont2D(label,position,row,G3D::Color4(team->getTeamColor().color3(),1),G3D::Color4(0,0,0,1),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
        }
        rect.low.y+=row;
        adorn->line2d(G3D::Vector2(rect.low.x+2,rect.low.y+7),G3D::Vector2(rect.high.x-2,rect.low.y+7),G3D::Color4(team->getTeamColor().color3(),1));
        rect.low.y+=row;
        for(unsigned player=0;player<data.playersByTeamList[team].size();++player) {
            for(unsigned col=0;col<data.statNamesList.size()+1;++col) {
                G3D::Vector2 position(rect.low.x,rect.low.y);
                float width=rect.high.x-rect.low.x;
                std::string label=data.playersByTeamList[team][player];
                if(col) {
                    position.x+=width*0.5f+width*0.5f/data.statNamesList.size()*(col-1);
                    int stat=data.statMap[data.playersByTeamList[team][player]][data.statNamesList[col-1]];
                    label=StringConverter<int>::convertToString(stat);
                }
                adorn->drawFont2D(label,position,row,G3D::Color4(team->getTeamColor().color3(),1),G3D::Color4::zero(),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
                if(!col) position.x-=5.0f; // Observed native post-draw store.
            }
            rect.low.y+=row;
        }
        rect.low.y+=row;
    }
}

// Native00669f60 consumes one string reference, returns a32-bit hash; caller
// retains the lowthree bits for the genuine Color::colorFromIndex8 palette.
unsigned int playerNameHash(const std::string&);
void ScoreHud::renderFFALeaderboard(Adorn* adorn) {
    BoardData data;
    BuildBoardData(data);
    if(data.fields.empty()) return;
    bool hasStats=data.fields.size()!=1;
    float viewportWidth=adorn->getViewport().width();
    float row=viewportWidth/1024.0f*14.0f;
    float width=viewportWidth*0.33f;
    if(!hasStats) width*=0.5f;
    ((GuiItemApi*)this)->setGuiSize(G3D::Vector2(width,(data.data.size()+2.5f)*row));
    Rect rect=getMyRect();
    adorn->rect2d(rect.toRect2D(),GuiItem::translucentBackdrop());
    for(unsigned col=0;col<data.fields.size();++col) {
        G3D::Vector2 position(rect.low.x,rect.low.y);
        float extent=rect.high.x-rect.low.x;
        if(col) position.x+=extent*0.5f+extent*0.5f/data.fields.size()*(col-1);
        adorn->drawFont2D(data.fields[col],position,row,G3D::Color4(G3D::Color3::white(),1),G3D::Color4::zero(),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
    }
    rect.low.y+=row*2;
    for(unsigned col=0;col<data.fields.size();++col) {
        for(unsigned index=0;index<data.data.size();++index) {
            G3D::Color3 color=G3D::Color3::white();
            if(!col) color=Color::colorFromIndex8(playerNameHash(data.data[index][0])&7);
            float extent=rect.high.x-rect.low.x;
            G3D::Vector2 position(rect.low.x,rect.low.y+index*row);
            if(col) position.x+=extent*0.5f+extent*0.5f/data.fields.size()*(col-1);
            adorn->drawFont2D(data.data[index][col],position,row,G3D::Color4(color,1),G3D::Color4::zero(),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
        }
    }
}
}
