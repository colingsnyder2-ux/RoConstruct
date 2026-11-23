// =============================================================================
// Utilities.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/Utilities.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <string>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

namespace RBX
{
	template<typename T>
	class CopyOnWrite : public boost::noncopyable
	{
	private:
		boost::shared_ptr<T> object;

	public:
		CopyOnWrite(const T& object)
			: object(new T(object))
		{
		}
		CopyOnWrite()
		{
		}
	public:
		// this allows functions to easily check if object is NULL
		// VERY hacky...
		operator typename boost::shared_ptr<T>::unspecified_bool_type() const
		{
			return object;
		}
		const T& operator*() const
		{
			return *object.get();
		}
		const T* operator->() const
		{
			return object.get();
		}
		boost::shared_ptr<const T> read() const
		{
			return object;
		}
		boost::shared_ptr<T>& write()
		{
			if (!object)
			{
				object = boost::shared_ptr<T>(new T());
				return object;
			}
			else if (object.use_count() <= 1)
			{
				return object;
			}
			else
			{
				object = boost::shared_ptr<T>(new T(*object));
				return object;
			}
		}
		void reset()
		{
			object.reset();
		}
	};

	template<typename T>
	class StringConverter
	{
	public:
		static std::string convertToString(const T& value);
		static bool convertToValue(const std::string& text, T& value);
	};

	// NOTE: original file for this class is unknown
	template<typename Class>
	class Parent
	{
	private:
		Class* first;
		Class* last;

	public:
		Parent()
			: first(NULL),
			  last(NULL)
		{
		}

	public:
		void pushBackChild(Class* child)
		{
			if (!last)
				first = child;
			else
				last->setNextSibling(child);

			last = child;
		}
		void pushFrontChild(Class*);
		void addChild(Class*);
		void removeChild(Class*);
		const Class* firstChild() const
		{
			return first;
		}
		Class* firstChild()
		{
			return first;
		}
		const Class* nextChild(const Class* child) const
		{
			return child->nextSibling();
		}
		Class* nextChild(Class* child)
		{
			return child->nextSibling();
		}
	};

	// NOTE: original file for this class is unknown
	template<typename Class>
	class Sibling
	{
		template<typename Class>
		friend class Parent;

	private:
		Class* next;

	protected:
		Sibling(Class*);
		Sibling()
			: next(NULL)
		{
		}

	public:
		Class* nextSibling()
		{
			return next;
		}
		const Class* nextSibling() const
		{
			return next;
		}
	private:
		void setNextSibling(Class* sibling)
		{
			next = sibling;
		}
	};
}
