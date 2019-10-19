#ifndef CICADA_UTIL_STRING_STRING_LITERAL_HEADER_GUARD
# define CICADA_UTIL_STRING_STRING_LITERAL_HEADER_GUARD (1)

# include "cicada/util/logging/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include <string>

namespace ccd {
	enum class log_severity
	{
		verbose = 0,
		debug,
		info,
		warning,
		error,
		fatal,

		count,
		unknown = -1
	};

	extern CICADA_UTIL_LOGGING_API std::string to_string(log_severity p_severity) noexcept;

	class logger
	{
	public:
		CICADA_UTIL_LOGGING_API logger() noexcept;
		CICADA_UTIL_LOGGING_API explicit logger(const std::string& p_name, log_severity p_initialSeverity = log_severity::info) noexcept;


		CICADA_UTIL_LOGGING_API logger& operator<<(log_severity p_severity) noexcept;
		CICADA_UTIL_LOGGING_API const logger& operator<<(const std::string& p_message) const noexcept;
	private:
		std::string m_name;
		log_severity m_severity;
	};
}

#endif