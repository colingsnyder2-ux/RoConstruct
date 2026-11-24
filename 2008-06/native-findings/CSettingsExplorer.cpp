#include "CSettingsExplorer.h"

void CSettingsExplorer::onEvent(const RBX::Instance* source, RBX::DescendantAdded event)
{
    CInstanceExplorer::onMarshaledEvent(source, event);
}

void CSettingsExplorer::onEvent(const RBX::Instance* source, RBX::DescendantRemoving event)
{
    CInstanceExplorer::onMarshaledEvent(source, event);
}