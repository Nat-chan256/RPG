#include <Engine/Layer.hpp>

void Layer::loadTestLayer(const std::vector<std::vector<TileId>>& coolLayer)
{
	m_matrix = coolLayer;
}

TileId Layer::getTile(size_t _x, size_t _y) const
{
	return m_matrix.at(_y).at(_x);
}

TileId Layer::getTile(sf::Vector2i _position) const
{
	return getTile(_position.x, _position.y);
}

void Layer::setTile(size_t _x, size_t _y, TileId _id)
{
	m_matrix.at(_y).at(_x) = _id;
}

void Layer::setTile(sf::Vector2i _position, TileId _id)
{
	setTile(_position.x, _position.y, _id);
}

void Layer::bindTilesData(std::weak_ptr<ResourcesMenager<Tile>> _ptr)
{
	m_tilesData = _ptr;
}

sf::Vector2i Layer::getSizes() const noexcept
{
	int h = m_matrix.size();
	int w = 0;

	if (h != 0)
		w = m_matrix[0].size();
	
	return {w, h};
}

static const uint8_t TILE_SIZE = 32; // убрать
void Layer::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{
	auto tilesData = m_tilesData.lock();

	// Эта хрень - охранное выражение.
	if (tilesData == nullptr)
		return; // throw печальбеда("ноташапомоги");

	sf::Vector2f position;
	sf::Sprite sprite;

	for (const auto & i : m_matrix)
	{
		for (const auto & j : i)
		{
			const Tile& tile = tilesData->get(j); // Сюда еще исключение для отрисовки ошибок
			sprite.setTexture(*tile.getTexture().lock());
			sprite.setPosition(position);

			position.x += TILE_SIZE;
		}

		position.x = 0;
		position.y += TILE_SIZE;
	}
}
