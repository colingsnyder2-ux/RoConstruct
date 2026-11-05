// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <set>
namespace RBX {
class Edge;
class JointStage {
public:
	char pad[0x58];
	std::set<Edge*> edges;
	int contains(int, Edge* e);
};
int JointStage::contains(int, Edge* e) {
	if (e && edges.find(e) != edges.end())
		return 1;
	return 0;
}
}
