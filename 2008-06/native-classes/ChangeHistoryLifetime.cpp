#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"

RBX::ChangeHistoryService::ChangeHistoryService()
    : DescribedCreatable<ChangeHistoryService, Instance, &sChangeHistoryService>("ChangeHistoryService"),
      current(NULL), playing(false), enabled(false)
{
}

RBX::ChangeHistoryService::~ChangeHistoryService()
{
    delete current;
}
