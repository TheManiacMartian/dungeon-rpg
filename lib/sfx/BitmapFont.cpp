#include "BitmapFont.h"
#include "BitmapText.h"


namespace sfx {
	bool BitmapFont::loadFromFile(const std::string& filename) {
		return this->texture.loadFromFile(filename);
	}

	bool BitmapFont::loadFromMemory(const void* data, std::size_t sizeInBytes) {
		return this->texture.loadFromMemory(data, sizeInBytes);
	}

	bool BitmapFont::loadFromStream(sf::InputStream& stream) {
		return this->texture.loadFromStream(stream);
	}



	const sf::Texture& BitmapFont::getTexture() const {
		return this->texture;
	}



	void BitmapFont::setGlyphSize(unsigned width, unsigned height) {
		this->setGlyphSize({ width, height });
	}

	void BitmapFont::setGlyphSize(sf::Vector2u size) {
		this->size = size;
	}


	sf::Vector2u BitmapFont::getGlyphSize() const {
		return this->size;
	}
}