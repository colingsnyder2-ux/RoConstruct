#include "gui/Gui.h"

namespace RBX
{
	class Team;
	class RunService;

	namespace Network
	{
		class Players;
	}

	class BoardData
	{
	public:
		std::vector<std::vector<std::string>> data;
		std::vector<std::string> fields;

	public:
		BoardData();
		void SetSize(int, int);
		void AddField(std::string, int);
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
		LeaderboardData(Instance*);
		void CompileData();
	private:
		void AddTuple(std::string, Team*, std::string, int);
	};

	class ScoreHud : public GuiItem,
		             public Listener<Instance, ChildAdded>,
					 public Listener<Instance, ChildRemoved>
	{
	protected:
		enum BoardType
		{
			PLAYER_LIST,
			FFA,
			TEAM_DEATHMATCH,
			TEAM_LIST
		};

	protected:
		RunService* runService;
		Network::Players* players;

	protected:
		void BuildBoardData(BoardData&);
		virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);
		virtual void onEvent(const Instance*, ChildRemoved);
		virtual void onEvent(const Instance*, ChildAdded);
		virtual void render2d(Adorn*);
		void renderTeamDeathmatchLeaderboard(Adorn*, BoardType);
		void renderFFALeaderboard(Adorn*);
		BoardType DetermineBoardType();
	public:
		ScoreHud(const ServiceProvider*);
		virtual ~ScoreHud();
	};
}
