#include "CRobloxApp.h"
#include <algorithm>
#include <boost/bind.hpp>
#include "CIDEDocManager.h"
#include "CRobloxDoc.h"

BOOL CRobloxApp::openFile(std::string file)
{
    CDocTemplate* documents = static_cast<CIDEDocManager*>(m_pDocManager)->templates[1];
    POSITION position = documents->GetFirstDocPosition();
    while (position) {
        CRobloxDoc* document = static_cast<CRobloxDoc*>(documents->GetNextDoc(position));
        if (!document->loadFromString(file)) return FALSE;
    }
    return TRUE;
}

BOOL CRobloxApp::openFiles(std::vector<std::string>::iterator first,
                          std::vector<std::string>::iterator last)
{
    return std::find_if(first, last, boost::bind(&CRobloxApp::openFileFailed, this, _1)) == last;
}

int CRobloxApp::openFileFailed(std::string file)
{
    return !openFile(file);
}
