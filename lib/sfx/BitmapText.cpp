#include "BitmapText.h"

namespace sfx {
	void BitmapText::setString(const sf::String& string) {
		this->string = string;
		cacheGeometrie();
	}



	const sf::String& BitmapText::getString() const {
		return this->string;
	}



	void BitmapText::setUtf8String(const std::string& string) {
		this->setString(sf::String::fromUtf8(string.begin(), string.end()));
	}



	void BitmapText::setFont(const BitmapFont& font) {
		this->font = &font;
		cacheGeometrie();
	}



	const BitmapFont& BitmapText::getFont() const {
		return *this->font;
	}



	void BitmapText::setCharacterScale(unsigned scale) {
		this->char_scale = scale;
		cacheGeometrie();
	}



	unsigned BitmapText::getCharacterScale() const {
		return this->char_scale;
	}



	void BitmapText::setTabSize(unsigned indent) {
		this->tab_indent = indent;
		cacheGeometrie();
	}



	unsigned BitmapText::getTabSize() const {
		return this->tab_indent;
	}



	void BitmapText::setFillColor(sf::Color color) {
		this->color = color;
		cacheGeometrie();
	}



	sf::Color BitmapText::getFillColor() const {
		return this->color;
	}



	sf::FloatRect BitmapText::getGlobalBounds() const {
		return this->getTransform().transformRect(this->vertecies.getBounds());
	}



	sf::FloatRect BitmapText::getLocalBounds() const {
		return this->vertecies.getBounds();
	}


	void BitmapText::cacheGeometrie() {
		if (this->font) {
			this->vertecies.clear();
			this->vertecies.setPrimitiveType(sf::Quads);
			for (std::size_t i = 0, ix = 0, iy = 0; i < this->string.getSize(); i++) {
				const auto chr = string[i];

				if (chr == '\n') {
					ix = 0;
					++iy;
				}
				else if (chr == '\t') {
					ix += this->tab_indent;
				}
				else if (std::isspace(static_cast<int>(chr))) {
					++ix;
				}
				else {
					const auto x = chr % 16;
					const auto y = chr / 16;

					const auto glyph_size = this->font->getGlyphSize();

					const auto csize = sf::Vector2f{
						static_cast<float>(glyph_size.x * this->char_scale),
						static_cast<float>(glyph_size.y * this->char_scale),
					};

					// glyph
					const float glyph_x1 = static_cast<float>(x * glyph_size.x);
					const float glyph_y1 = static_cast<float>(y * glyph_size.y);
					const float glyph_x2 = static_cast<float>(glyph_size.x) + glyph_x1;
					const float glyph_y2 = static_cast<float>(glyph_size.y) + glyph_y1;

					// character
					const float char_x1 = static_cast<float>(ix) * csize.x;
					const float char_y1 = static_cast<float>(iy) * csize.y;
					const float char_x2 = csize.x + char_x1;
					const float char_y2 = csize.y + char_y1;


					this->vertecies.append(sf::Vertex{
						{char_x1, char_y1},
						color,
						{glyph_x1, glyph_y1} });

					this->vertecies.append(sf::Vertex{
						{char_x2, char_y1},
						color,
						{glyph_x2, glyph_y1} });

					this->vertecies.append(sf::Vertex{
						{char_x2, char_y2},
						color,
						{glyph_x2, glyph_y2} });

					this->vertecies.append(sf::Vertex{
						{char_x1, char_y2},
						color,
						{glyph_x1, glyph_y2} });

					ix++;
				}
			}
		}
	}


	void BitmapText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
		if (this->font) {
			states.transform.combine(this->getTransform());
			states.texture = &this->font->getTexture();
			target.draw(this->vertecies, states);
		}
	}
}