// =============================================================================
// HistoryRecord.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/HistoryRecord.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "reflection/type.h"
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace RBX
{
class ChangeHistoryService;
class Instance;
namespace Reflection { class PropertyDescriptor; class Property; }

// Types and member order follow the original history-record constructor and
// map operations; individual record behavior still requires recovery.
struct HistoryItem {
	ChangeHistoryService* service;
	boost::shared_ptr<Instance> object;
	int kind;
	boost::shared_ptr<Instance> parent;
	std::map<const Reflection::PropertyDescriptor*, Reflection::Value> properties;
	HistoryItem(ChangeHistoryService*, boost::shared_ptr<Instance>);
	void play();
	void unplay();
	void captureAll();
	void reset();
	void captureProperty(const Reflection::PropertyDescriptor*);
	void capture(const Reflection::Property&);
	HistoryItem();
	void mergeProperty(const std::pair<const Reflection::PropertyDescriptor*, Reflection::Value>&);
	void update(const Reflection::PropertyDescriptor*);
	void applyProperty(const std::pair<const Reflection::PropertyDescriptor*, Reflection::Value>&);
	void unplayProperty(const std::pair<const Reflection::PropertyDescriptor*, Reflection::Value>&);
public:
	~HistoryItem(void);   // INFERRED: ??1HistoryItem@RBX@@QAE@XZ (header gap, header_gap_fill.py)
};

struct HistoryRecord : std::map<Instance*, HistoryItem> {
	ChangeHistoryService* service;
	std::string name;
	HistoryRecord(ChangeHistoryService*);
	HistoryItem* get(boost::shared_ptr<Instance>);
	bool empty();
	void merge(HistoryRecord*);
	void play();
	void unplay();
public:
	~HistoryRecord(void);   // INFERRED: ??1HistoryRecord@RBX@@QAE@XZ (header gap, header_gap_fill.py)
};
}
