#pragma once
#include <afxwin.h>

class CBrowserDocManager : public CDocManager {
    CDocTemplate* browserTemplate;
public:
    CBrowserDocManager();
};
