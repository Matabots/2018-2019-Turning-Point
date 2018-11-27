#include "timer.h"

// timer::timer(){
// 	bool IsStarted();
// 	bool IsStopped();
// 	bool IsPaused();
// 	bool IsActive();
// 	void Pause();
// 	void Resume();
// 	void Stop();
// 	void Start();
// 	void Reset();
// 	std::clock_t GetTicks();
// };
timer::timer()
{
	startedAt = 0;
	pausedAt = 0;
	paused = false;
	started = false;
}
bool timer::IsStarted()
{
	return started;
}
bool timer::IsStopped()
{
	return !started;
}
bool timer::IsPaused()
{
	return paused;
}
bool timer::IsActive()
{
	return !paused & started;
}
void timer::Pause()
{
	if( paused || !started )
		return;
	paused = true;
	pausedAt = std::clock();
}
void timer::Resume()
{
	if( !paused )
		return;
	paused = false;
	startedAt += std::clock() - pausedAt;
}
void timer::Stop()
{
	started = false;
}
void timer::Start()
{
	if( started )
		return;
	started = true;
	paused = false;
	startedAt = std::clock();
}
void timer::Reset()
{
	paused = false;
	startedAt = std::clock();
}
std::clock_t timer::GetTicks()
{
	if( !started )
		return 0;
	if( paused )
		return pausedAt - startedAt;
	return std::clock() - startedAt;
}
