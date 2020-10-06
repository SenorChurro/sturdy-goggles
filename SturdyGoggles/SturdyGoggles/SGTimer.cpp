#include "SGTimer.h"

using namespace std::chrono;

SGTimer::SGTimer() noexcept
{
	last = steady_clock::now();
}

// Will tell you the time that has elapsed since the last time
// that Mark was called and reset a new Mark point
float SGTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

// Will tell you the time that has elapsed since the last time
// that Mark was called and will not reset the mark point
float SGTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}