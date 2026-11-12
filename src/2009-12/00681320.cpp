// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll App/v8datamodel/Message.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Message.h"

#include "network/Player.h"
#include "rbxgraphics/Adorn.h"
#include "reflection/property.h"
#include "util/Rect.h"

namespace RBX {

char sHint[] = "Hint";

char sMessage[] = "Message";

static Reflection::PropDescriptor<Message, std::string> desc_Text(
	"Text", "Appearance", &Message::getText, &Message::setText
);

// FUNCTION: WEBSERVICE 0x100ee4d0
// FUNCTION: ROBLOX 0x0062d5d0
void Message::renderFullScreen(Adorn* adorn)
{
	G3D::Rect2D rect = adorn->getViewport();

	Rect translucentArea(rect);
	G3D::Vector2 textPos = translucentArea.center();

	adorn->rect2d(translucentArea.toRect2D(), G3D::Color4(0.5f, 0.5f, 0.5f, 0.5f));

	adorn->drawFont2D(
		text,
		textPos,
		14,
		G3D::Color4(G3D::Color3::white()),
		G3D::Color4(G3D::Color3::black()),
		Adorn::XALIGN_CENTER,
		Adorn::YALIGN_CENTER,
		Adorn::PROPORTIONAL_SPACING
	);
}

// FUNCTION: WEBSERVICE 0x100ee5e0
// FUNCTION: ROBLOX 0x0062d6e0
void Message::renderPersonalMsg(Adorn* adorn)
{
	G3D::Rect2D rect = adorn->getViewport();

	Rect translucentArea(rect.x0() + 30, rect.y0() + 30, rect.x1() * 0.25f + 30, rect.y1() * 0.25f + 30);
	G3D::Vector2 textPos = translucentArea.center();

	adorn->rect2d(translucentArea.toRect2D(), G3D::Color4(0.5f, 0.5f, 0.5f, 0.5f));

	adorn->drawFont2D(
		text,
		textPos,
		14,
		G3D::Color4(G3D::Color3::white()),
		G3D::Color4(G3D::Color3::black()),
		Adorn::XALIGN_CENTER,
		Adorn::YALIGN_CENTER,
		Adorn::PROPORTIONAL_SPACING
	);
}

// FUNCTION: WEBSERVICE 0x100ee710
// FUNCTION: ROBLOX 0x0062d810
void Message::render2d(Adorn* adorn)
{
	if (text.size() > 0) {
		Instance* parent = getParent();
		Network::Player* player = dynamic_cast<Network::Player*>(parent);
		if (player == NULL) {
			renderFullScreen(adorn);
		}
		else {
			renderPersonalMsg(adorn);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100ee760
// FUNCTION: ROBLOX 0x0062d860
void Hint::render2d(Adorn* adorn)
{
	G3D::Rect2D rect = adorn->getViewport();

	Rect blackArea(rect.x0(), rect.y1() - 20, rect.x1(), rect.y1());
	G3D::Vector2 textPos = blackArea.center();

	adorn->rect2d(blackArea.toRect2D(), G3D::Color4(G3D::Color3::black()));

	adorn->drawFont2D(
		text,
		textPos,
		14,
		G3D::Color4(G3D::Color3::white()),
		G3D::Color4::clear(),
		Adorn::XALIGN_CENTER,
		Adorn::YALIGN_CENTER,
		Adorn::PROPORTIONAL_SPACING
	);
}

// FUNCTION: WEBSERVICE 0x100eea50
// FUNCTION: ROBLOX 0x0062db60
Message::Message() : DescribedCreatable<Message, Instance, sMessage>("Message")
{
}

// FUNCTION: WEBSERVICE 0x100eebb0
// FUNCTION: ROBLOX 0x0062dcc0
void Message::setText(const std::string& value)
{
	if (text != value) {
		text = value;
		raisePropertyChanged(desc_Text);
	}
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Hint, RBX::Message, RBX::sHint>;
template class RBX::DescribedCreatable<RBX::Hint, RBX::Message, RBX::sHint>;

template class RBX::FactoryProduct<RBX::Message, RBX::Instance, RBX::sMessage>;
template class RBX::Reflection::
	Described<RBX::Message, RBX::sMessage, RBX::FactoryProduct<RBX::Message, RBX::Instance, RBX::sMessage> >;
template class RBX::DescribedCreatable<RBX::Message, RBX::Instance, RBX::sMessage>;
