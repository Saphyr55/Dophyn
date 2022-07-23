#pragma once

#ifndef MOUSE_LISTENER_HPP
#define MOUSE_LISTENER_HPP

#include "utils/vector.hpp"

namespace Dophyn
{
	namespace Listeners
	{

		class MouseListener
		{
		public:
			MouseListener() = delete;
			~MouseListener() = delete;

			static vector::Vec2<float> getMousePos();

		private:

		};


	}
}


#endif 