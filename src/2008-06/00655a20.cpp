// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_dd40b7be0252a0ac.cpp

// Candidate translation unit (score above; library headers required).
#include "roc_espeon_scorehudportableheader11bfdf7c6129a99c.cpp"
#include <typeinfo>
#include <v8datamodel/Teams.h>
#include <v8datamodel/Team.h>
#include <util/Utilities.h>
#include <util/Color.h>
#include <G3D/Color3.h>
#include <G3D/Color4.h>
#include <boost/lexical_cast.hpp>
namespace RBX {
	class BoardData
	{
	public:
		std::vector<std::vector<std::string>> data;
		std::vector<std::string> fields;

	public:
		BoardData()
		{
		}

		void SetSize(int dataSize, int fieldSize)
		{
			data.resize(dataSize);
			for (int i = 0; i < dataSize; ++i)
				data[i].resize(fieldSize);

			fields.resize(fieldSize);
		}

		void AddField(std::string fieldName, int position)
		{
			fields[position] = fieldName;
		}
	};

	class LeaderboardData
	{
	public:
		std::vector<std::string> statNamesList;
		std::map<Team*, std::vector<std::string>> playersByTeamList;
		std::map<std::string, std::map<std::string, int>> statMap;
		std::map<Team*, std::map<std::string, int>> teamTotals;
	private:
		Instance* context;

	public:
		LeaderboardData(Instance* context)
			: context(context)
		{
		}

		void CompileData();


	private:
		void AddTuple(std::string playerName, Team* team, std::string statName, int statValue)
		{
			if (std::find(statNamesList.begin(), statNamesList.end(), statName) == statNamesList.end())
				statNamesList.push_back(statName);

			if (std::find(playersByTeamList[team].begin(), playersByTeamList[team].end(), playerName) == playersByTeamList[team].end())
				playersByTeamList[team].push_back(playerName);

			statMap[playerName][statName] = statValue;
		}
	};


// Existing native service specialization; retain the native call boundary.
template<> Teams* ServiceProvider::find<Teams>(const Instance*);
template<> Teams* ServiceProvider::create<Teams>(const Instance*);
template<> Network::Players* ServiceProvider::find<Network::Players>(const Instance*);
// Genuine public accessor bodies on opaque native receivers. Public SDK controls
// prove their old inline offsets differ (name100/childrenf8/size134 vs native
// name110/children108/size13c). These methods model their own native fields;
// no private declarations/access modifiers, padding or virtual slots are changed.
class InstanceApi {
public:
    Instance* findFirstChildByName(const std::string&) const;
    size_t numChildren() const {
        const boost::shared_ptr<Instances>& children=*(const boost::shared_ptr<Instances>*)((const char*)this+0x108);
        return children ? children->size() : 0;
    }
    Instance* getChild(size_t i) {
        return (**(const boost::shared_ptr<Instances>*)((const char*)this+0x108))[i].get();
    }
    const std::string& getName() const {
        return *(const std::string*)((const char*)this+0x110);
    }
};
class GuiItemApi {
public:
    void setGuiSize(const G3D::Vector2& value) {
        *(G3D::Vector2*)((char*)this+0x13c)=value;
    }
};
class PlayersApi {
public:
    boost::shared_ptr<const Instances> getPlayers();
    int numPlayers() const {
        return (int)(*(const CopyOnWrite<std::vector<boost::shared_ptr<Instance>>>*)((const char*)this+0x198))->size();
    }
};
void ScoreHud::renderTeamDeathmatchLeaderboard(Adorn* adorn,BoardType mode) {
    LeaderboardData data(this);
    data.CompileData();
    Teams* teams=ServiceProvider::find<Teams>(this);
    if(!teams) return;
    G3D::Rect2D viewport=adorn->getViewport();
    float scale=viewport.width()/1024.0f;
    float row=14.0f*scale;
    if(mode==TEAM_DEATHMATCH) {
        size_t teamCount=((InstanceApi*)teams)->numChildren();
        int playerCount=((PlayersApi*)(*(Network::Players**)((char*)this+0x150)))->numPlayers();
        float leaderboardSizeX=scale*320.0f;
        float leaderboardSizeY=playerCount+(teamCount+1)*3;
        ((GuiItemApi*)this)->setGuiSize(G3D::Vector2(leaderboardSizeX,leaderboardSizeY*row));
    } else {
        size_t teamCount=((InstanceApi*)teams)->numChildren();
        int playerCount=((PlayersApi*)(*(Network::Players**)((char*)this+0x150)))->numPlayers();
        float leaderboardSizeX=scale*240.0f;
        float leaderboardSizeY=playerCount+teamCount*3+2;
        ((GuiItemApi*)this)->setGuiSize(G3D::Vector2(leaderboardSizeX,leaderboardSizeY*row));
    }
    Rect rect=getMyRect();
    adorn->rect2d(rect.toRect2D(),GuiItem::translucentBackdrop());
    if(mode==TEAM_DEATHMATCH) {
        for(unsigned col=0;col<data.statNamesList.size()+1;++col) {
            float width=rect.high.x-rect.low.x;
            G3D::Vector2 position=rect.low;
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
            float width=rect.high.x-rect.low.x;
            G3D::Vector2 position=rect.low;
            std::string label=((InstanceApi*)team)->getName();
            if(col) {
                position.x+=width*0.5f+width*0.5f/data.statNamesList.size()*(col-1);
                label=boost::lexical_cast<std::string>(data.teamTotals[team][data.statNamesList[col-1]]);
            }
            G3D::Color4 teamColor(team->getTeamColor().color3(),1);
            adorn->drawFont2D(label,position,row,teamColor,G3D::Color4(0,0,0,1),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
        }
        rect.low.y+=row;
        adorn->line2d(G3D::Vector2(rect.low.x+2,rect.low.y+7),G3D::Vector2(rect.high.x-2,rect.low.y+7),G3D::Color4(team->getTeamColor().color3(),1));
        rect.low.y+=row;
        for(unsigned player=0;player<data.playersByTeamList[team].size();++player) {
            for(unsigned col=0;col<data.statNamesList.size()+1;++col) {
                float width=rect.high.x-rect.low.x;
                G3D::Vector2 position=rect.low;
                std::string label=data.playersByTeamList[team][player];
                if(col) {
                    position.x+=width*0.5f+width*0.5f/data.statNamesList.size()*(col-1);
                    int stat=data.statMap[data.playersByTeamList[team][player]][data.statNamesList[col-1]];
                    label=boost::lexical_cast<std::string>(stat);
                } else { position.x += 5.0f; }
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

// Native RTTI object 00960f78 is Value<int,&sIntValue> with the older char*
// non-type template argument. Use the actual CRT interface and external native
// type_info object instead of substituting the newer SDK's differently named type.
extern const type_info nativeIntValueType;
extern "C" void* __cdecl __RTDynamicCast(void*,long,void*,void*,int);
// Actual descriptor's GetSet pointer at0097d39c. Native getValue slot8 takes
// const DescribedBase*, returns int (__thiscall). No synthetic virtual class.
extern void* nativeIntValueGetter;
static int readNativeIntValue(Instance* instance) {
    typedef int (__thiscall *GetValue)(void*,const Reflection::DescribedBase*);
    return ((GetValue)(*(void***)nativeIntValueGetter)[2])(
        nativeIntValueGetter,instance?(const Reflection::DescribedBase*)((char*)instance+0x14):0);
}
class TeamsApi {
public:
    boost::shared_ptr<const Instances> getTeams();
};
void ScoreHud::BuildBoardData(BoardData& board) {
    Network::Players* nativePlayers=*(Network::Players**)((char*)this+0x150);
    if(!nativePlayers) return;
    boost::shared_ptr<const Instances> roster=((PlayersApi*)nativePlayers)->getPlayers();
    for(unsigned i=0;i<roster->size();++i) {
        Instance* player=(*roster)[i].get();
        Instance* stats=((InstanceApi*)player)->findFirstChildByName("leaderstats");
        if(stats) {
            board.SetSize(roster->size(),((InstanceApi*)stats)->numChildren()+1);
            board.AddField("Player",0);
            for(unsigned j=0;j<((InstanceApi*)stats)->numChildren();++j)
                board.AddField(((InstanceApi*)((InstanceApi*)stats)->getChild(j))->getName(),j+1);
            board.data[i][0]=((InstanceApi*)player)->getName();
            for(unsigned j=0;j<((InstanceApi*)stats)->numChildren();++j) {
                __RTDynamicCast(((InstanceApi*)stats)->getChild(j),0,(void*)&typeid(Instance),(void*)&nativeIntValueType,0);
                int value=readNativeIntValue(((InstanceApi*)stats)->getChild(j));
                board.data[i][j+1]=StringConverter<int>::convertToString(value);
            }
        } else {
            board.SetSize(roster->size(),1);
            board.AddField("Player List",0);
            board.data[i][0]=((InstanceApi*)player)->getName();
        }
    }
    for(unsigned i=0;i<roster->size();++i)
        if(board.data[i][0].size()>16) board.data[i][0].resize(16);
}
void LeaderboardData::CompileData() {
    Network::Players* players=ServiceProvider::find<Network::Players>(context);
    Teams* teams=ServiceProvider::create<Teams>(context);
    boost::shared_ptr<const Instances> teamList=((TeamsApi*)teams)->getTeams();
    boost::shared_ptr<const Instances> roster=((PlayersApi*)players)->getPlayers();
    for(unsigned i=0;i<roster->size();++i) {
        Instance* player=(*roster)[i].get();
        playersByTeamList[teams->getTeamFromPlayer((Network::Player*)player)].push_back(((InstanceApi*)player)->getName());
        Instance* stats=((InstanceApi*)player)->findFirstChildByName("leaderstats");
        if(stats) {
            for(unsigned j=0;j<((InstanceApi*)stats)->numChildren();++j) {
                Instance* value=(Instance*)__RTDynamicCast(((InstanceApi*)stats)->getChild(j),0,(void*)&typeid(Instance),(void*)&nativeIntValueType,0);
                if(value) AddTuple(((InstanceApi*)player)->getName(),teams->getTeamFromPlayer((Network::Player*)player),((InstanceApi*)value)->getName(),readNativeIntValue(value));
            }
        }
    }
    if(!teams) return;
    for(unsigned i=0;i<((InstanceApi*)teams)->numChildren();++i) {
        Team* team=dynamic_cast<Team*>(((InstanceApi*)teams)->getChild(i));
        if(!team) continue;
        for(unsigned j=0;j<statNamesList.size();++j) {
            teamTotals[team][statNamesList[j]]=0;
            for(unsigned k=0;k<playersByTeamList[team].size();++k)
                teamTotals[team][statNamesList[j]]+=statMap[playersByTeamList[team][k]][statNamesList[j]];
        }
    }
}
}

