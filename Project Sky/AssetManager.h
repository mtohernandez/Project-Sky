#pragma once

/*
* LoadTexture() --> To load a texture using the sfml library
* LoadFont() -_> To load a font using the sfml library
* 
* GetTerture() & GetFont() --> Returns the texture at the the name we specify
* 
* map --> A diccionary in cpp (i guess) that contains the textures and the fonts.
*/



#include <map>
#include <SFML/Graphics.hpp>

namespace Sky
{
	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
	};
}