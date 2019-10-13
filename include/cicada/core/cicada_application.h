#ifndef CICADA_CORE_CICADA_APPLICATION_HEADER_GUARD
# define CICADA_CORE_CICADA_APPLICATION_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

namespace ccd {
	class cicada_application
	{
	public:
		CICADA_API virtual ~cicada_application();
	};
}

#endif