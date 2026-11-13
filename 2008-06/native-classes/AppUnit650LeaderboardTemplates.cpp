// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native std template instances of the ScoreHud unit's leaderboard tables, in the application range
// 00650000..00654000 (inactive). Verified by tests/record_native_app_unit650.py (receipt app-unit650-working.json).
//
// The element types are the members of BoardData / LeaderboardData in the read-only native gui/ScoreHud.h (owner:
// ScoreHud / ChatOutput): BoardData::data (vector<vector<string>>, +0x00), LeaderboardData::playersByTeamList
// (map<Team*, vector<string>>, +0x18), statMap (map<string, map<string, int>>, +0x38) and teamTotals
// (map<Team*, map<string, int>>, +0x58). Every instance below is called only from rows of this unit
// (AddTuple 006546d0, CompileData 00654860, SetSize 00654630, ~BoardData 00654100, ~LeaderboardData 006558f0,
// renderFFALeaderboard 006551e0, renderTeamDeathmatchLeaderboard 00655a20), from each other, or from their EH
// funclets (the recorder checks every caller).
//
// Explicit instantiations only (no helper function that the binary does not contain).
#include "gui/ScoreHud.h"

template class std::map<RBX::Team*, std::vector<std::string> >;
template class std::_Tree<std::_Tmap_traits<RBX::Team*, std::vector<std::string>, std::less<RBX::Team*>,
	std::allocator<std::pair<RBX::Team* const, std::vector<std::string> > >, false> >;

template class std::map<std::string, int>;
template class std::_Tree<std::_Tmap_traits<std::string, int, std::less<std::string>,
	std::allocator<std::pair<const std::string, int> >, false> >;

template class std::map<std::string, std::map<std::string, int> >;
template class std::_Tree<std::_Tmap_traits<std::string, std::map<std::string, int>, std::less<std::string>,
	std::allocator<std::pair<const std::string, std::map<std::string, int> > >, false> >;

template class std::map<RBX::Team*, std::map<std::string, int> >;
template class std::_Tree<std::_Tmap_traits<RBX::Team*, std::map<std::string, int>, std::less<RBX::Team*>,
	std::allocator<std::pair<RBX::Team* const, std::map<std::string, int> > >, false> >;

template class std::vector<std::vector<std::string> >;

// AddTuple 006546d0 searches statNamesList / playersByTeamList[team] with std::find; the checked iterators unwrap to
// _Find<string*, string> (00650eb0).
template std::string* std::_Find<std::string*, std::string>(std::string*, std::string*, const std::string&);
