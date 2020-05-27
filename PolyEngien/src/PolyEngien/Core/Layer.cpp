#include "pepch.h"
#include "PolyEngien/Core/Layer.h"

namespace PolyEngien {
	Layer::Layer(const std::string& name) 
		: m_DebugName(name)
	{
	}

	Layer::~Layer()
	{
	}
}