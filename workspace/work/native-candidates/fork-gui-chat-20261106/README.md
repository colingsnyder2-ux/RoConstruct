# Inactive fork GUI candidate

Source: mewpokemons/RoConstruct, branch claude/optimistic-shannon-0xccuy,
commit 86d17d748a3193d4adc2109c054650136e6e0f87,
rebuild/2008-06/native-classes/GuiWidgets2008Chat.cpp.

ChatButton::isVisible at 0064ea90 independently matches 51 original code bytes
and referenced data. Direct calls at offsets 4 and 28 bind to 00491d50 and
00495e60, using identities independently recorded in existing network/team
recorder maps and checked against original assembly. Source and object hashes,
compiler/headers and checks are in the adjacent proof receipt.

Other bodies behind NATIVE_GUIWIDGETS_PENDING were retained unmodified but not
compiled or verified. The class layout, callee ABI, linked provider selection,
P5/P6/runtime and server credit remain unproven. Do not select this provider
or combine it with a duplicate ChatButton implementation without owner review.
