#pragma once 

#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <string>

namespace Dophyn
{
	class TextureManager
	{

	public:
		TextureManager() = delete;
		~TextureManager() = delete;

		static void load(std::string id, std::string filename);
		static void drop(std::string id);

	private:


	};
}

#endif
