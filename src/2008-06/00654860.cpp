// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_931b70be6c9e7dec.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
template<class T> class CopyOnWrite { boost::shared_ptr<T> object;
public: const T& operator*() const { return *object; } const T* operator->() const { return object.get(); } };
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
template<class T> class TypedPropertyDescriptor { public:
  class GetSet { public: virtual bool isReadOnly() const=0; virtual bool isWriteOnly() const=0; virtual T getValue(const DescribedBase*) const=0; };
  char pad[0x1c]; GetSet* getset;
  T getValue(const DescribedBase* o) const { return getset->getValue(o); }
};
}
class Base0 { public: virtual ~Base0(); char pad[0x10]; };
class Instance : public Base0, public Reflection::DescribedBase {
public:
  char pad[0x108-0x18]; CopyOnWrite<Instances> children; std::string name;
  size_t numChildren() const;
  Instance* getChild(size_t i) { return (*children)[i].get(); }
  const std::string& getName() const { return name; }
  Instance* findFirstChildByName(const std::string&) const;
};
extern char* sIntValue;
template<typename ValueType, const char* const* ClassName> class Value : public Instance { public: static Reflection::TypedPropertyDescriptor<ValueType> desc_Value; };
typedef Value<int, &sIntValue> IntValue;
class Team : public Instance {};
namespace Network {
class Player : public Instance {};
class Players : public Instance { public: char ppad[0x198-0x128]; boost::shared_ptr<Instances> players; __declspec(noinline) boost::shared_ptr<const Instances> getPlayers() { return players; } };
}
class Teams : public Instance { public: boost::shared_ptr<const Instances> getTeams(); Team* getTeamFromPlayer(Network::Player*); };
class ServiceProvider { public: template<class T> static T* find(const Instance*); };
template<> Teams* ServiceProvider::find<Teams>(const Instance*);
template<> Network::Players* ServiceProvider::find<Network::Players>(const Instance*);

class LeaderboardData {
public:
  std::vector<std::string> statNamesList;
  std::map<Team*, std::vector<std::string> > playersByTeamList;
  std::map<std::string, std::map<std::string, int> > statMap;
  std::map<Team*, std::map<std::string, int> > teamTotals;
private:
  Instance* context;
public:
  void CompileData();
private:
  void AddTuple(std::string playerName, Team* team, std::string statName, int statValue);
};

void LeaderboardData::CompileData()
{
  Network::Players* players = ServiceProvider::find<Network::Players>(context);
  Teams* teams = ServiceProvider::find<Teams>(context);
  boost::shared_ptr<const Instances> teamList = teams->getTeams();
  boost::shared_ptr<const Instances> playerList = players->getPlayers();
  for (size_t i = 0; i < playerList->size(); ++i)
  {
    Network::Player* player = static_cast<Network::Player*>(playerList->at(i).get());
    Team* team = teams->getTeamFromPlayer(player);
    playersByTeamList[team].push_back(player->getName());
    Instance* stats = player->findFirstChildByName("leaderstats");
    if (stats)
    {
      for (size_t j = 0; j < stats->numChildren(); ++j)
      {
        if (IntValue* intValue = dynamic_cast<IntValue*>(stats->getChild(j)))
          AddTuple(player->getName(), teams->getTeamFromPlayer(player), intValue->getName(), IntValue::desc_Value.getValue(intValue));
      }
    }
  }
  if (!teams) return;
  for (size_t i = 0; i < teams->numChildren(); ++i)
  {
    Team* team = dynamic_cast<Team*>(teams->getChild(i));
    if (team)
    for (size_t j = 0; j < statNamesList.size(); ++j)
    {
      teamTotals[team][statNamesList[j]] = 0;
      for (size_t k = 0; k < playersByTeamList[team].size(); ++k)
      {
        int statValue = statMap[playersByTeamList[team][k]][statNamesList[j]];
        teamTotals[team][statNamesList[j]] += statValue;
      }
    }
  }
}
}

