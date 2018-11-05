#ifndef TIMER_H
#define TIMER_H
#include <ctime>

class timer
{
private:
	std::clock_t startedAt;
	std::clock_t pausedAt;
	bool started;
	bool paused;
	public:
	// timer();
	// bool IsStarted();
	// bool IsStopped();
	// bool IsPaused();
	// bool IsActive();
	// void Pause();
	// void Resume();
	// void Stop();
	// void Start();
	// void Reset();
	// std::clock_t GetTicks();
// public:
timer();
	bool IsStarted();
	bool IsStopped();
	bool IsPaused();
	bool IsActive();
	void Pause();
	void Resume();
	void Stop();
	void Start();
	void Reset();
	std::clock_t GetTicks();
};
#endif
