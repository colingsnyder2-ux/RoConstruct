#pragma once
// >>> native-status (generated) -- do not edit >>>
// CScriptDoc | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 126550ee | roc native-status --write
#include <afxwin.h>
#include <boost/shared_ptr.hpp>
#include "CBrowserDoc.h"

namespace RBX { class Script; }

// Inactive layout recovery. RTTI of vtable 0081b2ac (46 slots): CScriptDoc : CNullDoc : CDocument : CCmdTarget
// : CObject. CRuntimeClass 0081b1ec (size 0x5c, schema 0xffff, CreateObject 004647b0, base getter 0040df90 ->
// CNullDoc 004332e0). Own virtual overrides: slot 0 GetRuntimeClass 004638a0, slot 1 deleting destructor 004646f0
// (-> destructor 00464670); slots 3/12/24/25 are CNullDoc's entries (GetMessageMap 00433360 returns CNullDoc's
// map 0081242c), so CScriptDoc has no message map of its own. CreateObject inlines CDocument::CDocument + the
// shared_ptr default constructor (+0x54 px = 0, +0x58 pn = 0); the destructor releases the counter at +0x58.
// CScriptEditor::OnUpdate 004657f0 reads the script shared_ptr at +0x54.
class CScriptDoc : public CNullDoc {
    DECLARE_DYNCREATE(CScriptDoc)
public:
    boost::shared_ptr<RBX::Script> script;   // +0x54
};
