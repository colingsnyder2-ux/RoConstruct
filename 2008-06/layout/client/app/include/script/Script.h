// =============================================================================
// Script.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/script/Script.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/Instance.h"
#include "boost/shared_ptr.hpp"
#include "boost/signals.hpp"

namespace RBX
{
	class ScriptContext;

	extern char sScript[];
	class Script : public DescribedCreatable<Script, Instance, sScript>
	{
	public:
		class Slot
		{
		public:
			boost::shared_ptr<boost::signals::connection> cnction;

		protected:
			Slot()
				: cnction(new boost::signals::connection())
			{
			}
		};

	private:
	  	boost::shared_ptr<const std::string> embeddedSource;
	  	ContentId scriptId;
	  	bool disabled;
	  	class IScriptOwner* owner;

	public:
	  	static Reflection::BoundProp<bool, true> prop_Disabled;
	  	static const Reflection::PropDescriptor<Script, std::string> prop_EmbeddedSourceCode;
	  	static const Reflection::PropDescriptor<Script, ContentId> prop_SourceCodeId;

	public:
	  	Script(const Script&);
	  	Script();
	  	virtual ~Script();

		bool isDisabled() const
		{
			return disabled;
		}

	  	virtual bool askSetParent(const Instance*) const;
	  	bool isCodeEmbedded() const;
	  	boost::shared_ptr<const std::string> requestCode();

		void setEmbeddedCode(const std::string& value);
		const std::string& getEmbeddedCode() const
		{
			return *embeddedSource.get();
		}

		const ContentId& getScriptId() const
		{
			return scriptId;
		}
		void setScriptId(const ContentId& value);

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
		virtual void onAncestorChanged(const AncestorChanged& event);
	};

	extern char sLocalScript[];
	class LocalScript : public DescribedCreatable<LocalScript, Script, sLocalScript>
	{
	public:
		LocalScript();
		virtual ~LocalScript();
	};

	class __declspec(novtable) IScriptOwner
	{
		friend class Script;

	protected:
		virtual IScriptOwner* scriptShouldRun(Script* script) = 0;
		virtual void runScript(Script* script, ScriptContext* context);
		virtual void releaseScript(Script* script);
	};
}
