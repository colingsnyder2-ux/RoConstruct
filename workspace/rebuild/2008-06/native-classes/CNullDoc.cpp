#include "CBrowserDoc.h"

void CNullDoc::OnUpdateDisabledCommand(CCmdUI* command)
{
    command->Enable(FALSE);
}
