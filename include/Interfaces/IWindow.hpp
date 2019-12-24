#ifndef __INTER_WINDOW_HPP
#define __INTER_WINDOW_HPP

#include <inttypes.h>

#include <Data/Vector.hpp>

#include <IRender.hpp>

using namespace data;

namespace interfaces
{

class IWindow
{
public:
	IWindow() = default;
	virtual ~IWindow() = 0;

	virtual inline VectorUI16 getSize() const;
	virtual inline void setSize(const VectorI16& _size) const;

	virtual void clear();
	virtual void render(const IRender& target);
	virtual void display();

protected:
};

} // namespace Interfaces

#endif /* __WINDOW_HPP */
