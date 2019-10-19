#ifndef CICADA_RENDER_D3D12_RENDER_DEVICE_HEADER_GUARD
# define CICADA_RENDER_D3D12_RENDER_DEVICE_HEADER_GUARD (1)

# include "cicada/render/d3d12/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# ifdef CICADA_OS_WINDOWS

#  include <d3d12.h>

namespace ccd {
	class d3d12_device
	{
	public:
		CICADA_RENDER_D3D12_API d3d12_device();
	private:
		ID3D12Device* m_handle;
	};
}

# endif

#endif