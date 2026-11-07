// >>> native-status (generated) -- do not edit >>>
// ChangeHistoryLifetime | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 97e3932d | roc native-status --write
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"

RBX::ChangeHistoryService::ChangeHistoryService()
    : DescribedCreatable<ChangeHistoryService, Instance, sChangeHistoryService>("ChangeHistoryService"),
      current(NULL), playing(false), enabled(false)
{
}

RBX::ChangeHistoryService::~ChangeHistoryService()
{
    delete current;
}
