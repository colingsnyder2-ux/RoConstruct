// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Message.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Message.h"

#include "reflection/property.h"

namespace RBX {

char sHint[] = "Hint";

char sMessage[] = "Message";

static Reflection::PropDescriptor<Message, std::string> desc_Text(
	"Text",
	"Appearance",
	&RBX::Message::getText,
	&RBX::Message::setText
);

// FUNCTION: WEBSERVICE 0x100eebb0
void Message::setText(const std::string& value)
{
	if (text != value) {
		text = value;
		raisePropertyChanged(desc_Text);
	}
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Hint, RBX::Message, RBX::sHint>;
template class RBX::Reflection::
	Described<RBX::Hint, RBX::sHint, RBX::FactoryProduct<RBX::Hint, RBX::Message, RBX::sHint> >;
template class RBX::DescribedCreatable<RBX::Hint, RBX::Message, RBX::sHint>;

template class RBX::FactoryProduct<RBX::Message, RBX::Instance, RBX::sMessage>;
template class RBX::Reflection::
	Described<RBX::Message, RBX::sMessage, RBX::FactoryProduct<RBX::Message, RBX::Instance, RBX::sMessage> >;
template class RBX::DescribedCreatable<RBX::Message, RBX::Instance, RBX::sMessage>;
