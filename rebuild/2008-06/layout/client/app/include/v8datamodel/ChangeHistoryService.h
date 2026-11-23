// =============================================================================
// ChangeHistoryService.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/ChangeHistoryService.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/Service.h"
#include <boost/signals/connection.hpp>
#include <list>
#include <string>
namespace RBX
{
class HistoryRecord;
namespace Reflection { struct Tuple; }
extern char sChangeHistoryService[];
class ChangeHistoryService : public DescribedCreatable<ChangeHistoryService, Instance, sChangeHistoryService>,
                             public Service {
public:
	Instance* context; // 0058c620: recorded event source; ownership unverified.
	HistoryRecord* current;
	std::list<HistoryRecord*> history;
	std::list<HistoryRecord*>::iterator forward;
	std::list<HistoryRecord*>::iterator backward;
	bool playing;
	bool enabled;
	boost::signals::scoped_connection connectionAdded;
	boost::signals::scoped_connection connectionRemoved;
	boost::signals::scoped_connection connectionChanged;
	ChangeHistoryService();
	virtual ~ChangeHistoryService();
	virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);
	virtual void onHistoryAdded(boost::shared_ptr<Instance>);
	virtual void onHistoryRemoving(boost::shared_ptr<Instance>);
	virtual void onHistoryChanged(boost::shared_ptr<Instance>, const Reflection::PropertyDescriptor*);
	void setEnabled(bool);
	void start();
	void commit(const char*);
	void prepare();
	void mergeFirst();
	void reset();
	void unplay();
	void play();
	bool queryUnplay(std::string&, int);
	bool queryPlay(std::string&, int);
	void initializeBase();
	public:
		void sub_0058c540(std::string name);   // INFERRED: 0058c540, placeholder name (identity tier), body byte-proved (Inferred_0058c540.cpp)
		// INFERRED: 00589d60, BoundFuncDesc N=0 registration at 007f40b0 pushes string "GetCanUndo" (0x8319a0); result Tuple (reflection.h; RTTI .?AUTuple@Reflection@RBX@@)
		Reflection::Tuple getCanUndo();
		// INFERRED: 00589ed0, BoundFuncDesc N=0 registration at 007f40e0 pushes string "GetCanRedo" (0x8319ac); result Tuple (reflection.h)
		Reflection::Tuple getCanRedo();
};
}
