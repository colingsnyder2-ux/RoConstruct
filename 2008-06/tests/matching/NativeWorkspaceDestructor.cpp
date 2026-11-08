#include "CWorkspace.h"

void destroyNativeWorkspace(CWorkspace* workspace)
{
    workspace->CWorkspace::~CWorkspace();
}
