#pragma once

#include <cstdint>

namespace Display
{
	void Init(uint32_t width, uint32_t height);
	void Shutdown();
	void Resize(uint32_t width, uint32_t height);
	void Present(bool vsync = true);
}

namespace Graphics
{
	extern uint32_t kDisplayWidth;
	extern uint32_t kDisplayHeight;
}