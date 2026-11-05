// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_leaderboardtuplecb88f93d387c30b6.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <map>
#include <string>
#include <algorithm>
namespace RBX {class Team;class Instance;
class LeaderboardData {public:std::vector<std::string> statNamesList;std::map<Team*,std::vector<std::string> > playersByTeamList;std::map<std::string,std::map<std::string,int> > statMap;std::map<Team*,std::map<std::string,int> > teamTotals;Instance*context;void AddTuple(std::string,Team*,std::string,int);};
void LeaderboardData::AddTuple(std::string playerName,Team*team,std::string statName,int statValue){if(std::find(statNamesList.begin(),statNamesList.end(),statName)==statNamesList.end())statNamesList.push_back(statName);if(std::find(playersByTeamList[team].begin(),playersByTeamList[team].end(),playerName)==playersByTeamList[team].end())playersByTeamList[team].push_back(playerName);statMap[playerName][statName]=statValue;}}
