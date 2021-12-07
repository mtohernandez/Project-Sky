#pragma once
/*
* STATEMACHINE. H
* 
* typedef std::unique_ptr<SkyControl> StateRef --> Creates a unique type of pointer that has the functions from SkyControl
* 
* AddState() --> To add a new state in the game loop
* RemoState() --> To remove a state from the game loop
* ProcessStateChanges() --> Proccess the changes between states, if it is adding, replacing or removing
* 
* StateRef& GetActiveState() --> Reference to know which state is active
* 
* std::stack<StateRef> _states --> Creates a stack for the states: This helps because the top is the screen the player is seeing
* 
* bool _isRemoving, _isAdding, _isReplacing --> To check what is happening 
* 
*/

#include <memory>
#include <stack>

#include "StateControl.h"

namespace Sky
{
	typedef std::unique_ptr<SkyControl> StateRef; //Change the declaration of pointer with SkyControl to StateRef

	class StateMachine
	{
	public:
		StateMachine() { }
		~StateMachine() { }

		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();
		void ProcessStateChanges();

		StateRef& GetActiveState(); //To get the top State

	private:
		std::stack<StateRef> _states; //Stack of pointers
		StateRef _newState;

		bool _isRemoving, _isAdding, _isReplacing;
	};
}