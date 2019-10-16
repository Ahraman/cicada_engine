#include "cicada/util/logging/logger.h"

#include <iostream>

ccd::logger::logger() noexcept
	: m_name("Logger"),
	m_severity(log_severity::info)
{}

ccd::logger::logger(const std::string& p_name, log_severity p_initialSeverity) noexcept
	: m_name(p_name),
	m_severity(p_initialSeverity)
{}

ccd::logger& ccd::logger::operator<<(log_severity p_severity) noexcept
{
	this->m_severity = p_severity;
	return (*this);
}

const ccd::logger& ccd::logger::operator<<(const std::string& p_message) const noexcept
{
	std::cout << "[" + to_string(this->m_severity) + "]" << p_message;
	return (*this);
}

std::string ccd::to_string(log_severity p_severity) noexcept
{
	switch (p_severity)
	{
	case log_severity::verbose:
		return "verbose";
	case log_severity::debug:
		return "debug";
	case log_severity::warning:
		return "warning";
	case log_severity::error:
		return "error";
	case log_severity::fatal:
		return "fatal";
	default:
		return "unknown";
	}
}
