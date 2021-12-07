#pragma once

/*
* STATECONTROL.H
* 
* virtual void Init() --> Initializes the variables in the constructor
* virtual void HandleInput() --> Handle the input from Init
* virtual void Update() --> Since these are iteratios each one needs to be updated
* virtual void Draw() --> Show images, text, etc on the window
* virtual void Pause() & Resume() --> Just control
* 
* float dt --> Delta time, time between frames
*/


namespace Sky
{
	class SkyControl
	{
	public:
		virtual void Init() = 0;

	
		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;

		virtual void Pause() { }
		virtual void Resume() { }
	};
}