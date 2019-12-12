#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>

using ResourceId = uint16_t;

template <typename T, typename I = ResourceId>
class ResourcesMenager
{
public:
	ResourcesMenager() = default;
	~ResourcesMenager() = default;

	const T& operator [] (ResourceId id_) const
	{
		return get(id_);
	}

	const T& get(ResourceId id_) const
	{
		return *m_data.at(id_);
	}

	std::shared_ptr<T> give(ResourceId id_) const
	{
		return m_data.at(id_);
	}

	size_t add(std::shared_ptr<T> resource_)
	{
		ResourceId newId = -1;

		if (m_data.empty())
			newId = 1;
		
		else
			newId = m_data.rbegin()->first + 1;

		m_data[newId] = resource_;
		return newId;
	}

	void changeResource(const T& resource_, ResourceId id)
	{
		auto resourceInData = m_data.at(id);
		*resourceInData = resource_;
	}

private:
	std::map<ResourceId, std::shared_ptr<T>> m_data;
};

using TexturesMenager = ResourcesMenager<sf::Texture>;
using TilesMenager = ResourcesMenager<Tile, TileId>;
