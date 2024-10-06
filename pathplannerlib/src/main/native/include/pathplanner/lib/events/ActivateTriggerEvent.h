#pragma once

#include "pathplanner/lib/events/Event.h"
#include "pathplanner/lib/events/EventScheduler.h"
#include <string>

namespace pathplanner {
class ActivateTriggerEvent: public Event {
public:
	/**
	 * Create an event for changing the value of a named trigger
	 *
	 * @param timestamp The trajectory timestamp of this event
	 * @param name The name of the trigger to control
	 */
	ActivateTriggerEvent(units::second_t timestamp, std::string name) : Event(
			timestamp), m_name(name) {
	}

	inline void handleEvent(EventScheduler *eventScheduler) override {
		EventScheduler::setCondition(m_name, true);
	}

	inline void cancelEvent(EventScheduler *eventScheduler) override {
		// Do nothing
	}

	inline std::shared_ptr<Event> copyWithTimestamp(units::second_t timestamp)
			override {
		return std::make_shared < ActivateTriggerEvent > (timestamp, m_name);
	}

private:
	std::string m_name;
};
}