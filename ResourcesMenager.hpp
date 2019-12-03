#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>

using ResourceId = uint16_t;

template <typename T>
class ResourcesMenager
{
public:
	ResourcesMenager() = default;
	~ResourcesMenager() = default;

	const T& operator [] (ResourceId id) const
	{
		return get(id);
	}

	const T& get(ResourceId id) const
	{
		return *m_data.at(id);
	}

	std::shared_ptr<T> give(ResourceId id) const
	{
		return m_data.at(id);
	}

	size_t add(std::shared_ptr<T> resource)
	{
		ResourceId newId = -1;

		if (m_data.empty())
			newId = 1;
		
		else
			newId = m_data.rbegin()->first + 1;

		m_data[newId] = resource;
		return newId;
	}

	void changeResource(const T& resource, ResourceId id)
	{
		auto resourceInData = m_data.at(id);
		*resourceInData = resource;
	}

private:
	std::map<ResourceId, std::shared_ptr<T>> m_data;
};

using TexturesMenager = ResourcesMenager<sf::Texture>;
