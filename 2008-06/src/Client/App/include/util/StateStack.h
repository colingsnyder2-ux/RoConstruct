#pragma once
#include "util/Name.h"
#include <vector>
#include <string>

namespace RBX
{
	template<class T>
	class StateStack
	{
		struct StateEntry
		{
		public:
			std::string name;
			T* undoState;
			T* redoState;
		};

	private:
		int currentState;
		std::vector<StateEntry> stack;
	public:
		StateStack()
		{
			currentState = -1; // see DataModel constructor
		}

		~StateStack()
		{
			clearStackAfter(-1);
			currentState = -1;
		}

		void pushState(const Name&, T*, T*);
		void pushState(std::string, T*, T*);
		void clearStack();
		bool canUndo(std::string&) const;
		T* undo();
		bool canRedo(std::string&) const;
		T* redo();
	protected:
		size_t getStackSize() const
		{
			return stack.size();
		}
		virtual bool isStackTooBig() const
		{
			return false;
		}
	private:
		void clearStackAfter(int index)
		{
			for (int i = stack.size() - 1; i > index; i--)
			{
				delete stack[i].redoState;
				delete stack[i].undoState;
			}

			stack.resize(index + 1);
		}
	};
}

// rebuild overlay: StateStack members rbxgs declares but never defines
namespace RBX
{

	template<typename T>
	void StateStack<T>::pushState(std::string name, T* undoState, T* redoState)
	{
		clearStackAfter(currentState);
		StateEntry entry;
		entry.name = name;
		entry.undoState = undoState;
		entry.redoState = redoState;
		stack.push_back(entry);
		currentState = (int)stack.size() - 1;
		while (isStackTooBig() && !stack.empty())
		{
			delete stack.front().undoState;
			delete stack.front().redoState;
			stack.erase(stack.begin());
			--currentState;
		}
	}

	template<typename T>
	void StateStack<T>::pushState(const Name& name, T* undoState, T* redoState)
	{
		pushState(name.toString(), undoState, redoState);
	}

	template<typename T>
	void StateStack<T>::clearStack()
	{
		clearStackAfter(-1);
		currentState = -1;
	}

	template<typename T>
	bool StateStack<T>::canUndo(std::string& name) const
	{
		if (currentState < 0)
			return false;
		name = stack[currentState].name;
		return true;
	}

	template<typename T>
	T* StateStack<T>::undo()
	{
		return currentState < 0 ? NULL : stack[currentState--].undoState;
	}

	template<typename T>
	bool StateStack<T>::canRedo(std::string& name) const
	{
		if (currentState + 1 >= (int)stack.size())
			return false;
		name = stack[currentState + 1].name;
		return true;
	}

	template<typename T>
	T* StateStack<T>::redo()
	{
		return currentState + 1 >= (int)stack.size() ? NULL : stack[++currentState].redoState;
	}

}
