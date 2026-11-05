// from server: 100% by EspClaude
// from server: 57% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_73b86d085320c898.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <string>
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
namespace RBX {
class Name;
class ContentId {
private:
	std::string id;
	const Name* mimeTypePtr;
};
class Instance;
class Workspace {
public:
	enum InsertMode { INSERT_TO_TREE = 1 };
	enum PromptMode { SUPPRESS_PROMPTS = 1 };
	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > insertContent(ContentId contentId);
	void insertContent(ContentId contentId, std::vector<boost::shared_ptr<Instance> >& items, InsertMode insertMode, PromptMode promptMode);
};
static void append(const boost::shared_ptr<Instance>& item, std::vector<boost::shared_ptr<Instance> >* values)
{
	values->push_back(item);
}
boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Workspace::insertContent(ContentId contentId)
{
	std::vector<boost::shared_ptr<Instance> > items;
	insertContent(contentId, items, INSERT_TO_TREE, SUPPRESS_PROMPTS);

	boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > values(new std::vector<boost::shared_ptr<Instance> >);
	std::for_each(items.begin(), items.end(), boost::bind(&append, _1, values.get()));

	return values;
}
}
