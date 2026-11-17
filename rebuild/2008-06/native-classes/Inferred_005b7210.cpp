// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005b7210: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "SoundChannel/SoundChannel.h"

typedef std::_Tmap_traits<
	RBX::Soundscape::SoundId,
	boost::shared_ptr<RBX::Soundscape::Sound>,
	std::less<RBX::Soundscape::SoundId>,
	std::allocator<std::pair<RBX::Soundscape::SoundId const, boost::shared_ptr<RBX::Soundscape::Sound> > >,
	false> SoundMapTraits;

template std::_Tree_nod<SoundMapTraits>::_Node *
std::_Tree<SoundMapTraits>::_Lbound(const RBX::Soundscape::SoundId& _Keyval) const;
