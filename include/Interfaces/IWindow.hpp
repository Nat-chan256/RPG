#ifndef __INTER_WINDOW_HPP
#define __INTER_WINDOW_HPP

#include <inttypes.h>
#include <string>

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

	virtual void open() = 0;
	virtual void close() = 0;
	virtual bool isOpen() const = 0;

	virtual inline VectorUI16 getSize() const = 0;
	virtual inline void setSize(const VectorI16& _size) const = 0;

	virtual void setVsync(uint8_t _condition) = 0;
	virtual uint8_t isVsyncEnables() const = 0;

	virtual void setTitle(const std::wstring& _title) = 0;
	virtual const std::wstring& getTitle() const = 0;

	virtual void setCursorVisible(uint8_t _condition) = 0;
	virtual uint8_t isVsyncEnables() const = 0;

	virtual void setFocus(uint8_t _condition) = 0;
	virtual uint8_t hasFocus() const = 0;

	virtual void setFullscreen(uint8_t _condition) = 0;
	virtual uint8_t isFullscreen() const = 0;

	virtual void clear() = 0;
	virtual void render(const IRender& _target) = 0;
	virtual void display() = 0;

protected:
	virtual void m_initialize() = 0;
};

} // namespace Interfaces

#endif /* __WINDOW_HPP */
