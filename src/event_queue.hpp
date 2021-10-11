#include "queue.hpp"
#include <functional>
#include <cstdint>

struct event_t
{
	uint64_t time;
	uint64_t order;
	std::function<void(void)> operate;
};

class compare_event
{
public:
	constexpr bool operator()(const event_t &x,const event_t &y)const noexcept
	{
		return x.time==y.time?x.order<y.order:x.time>y.time;
	}
};

typedef zzc::priority_queue<event_t,compare_event> event_queue_t;

extern event_queue_t g_event_queue;
