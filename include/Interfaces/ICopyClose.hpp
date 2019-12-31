#ifndef __INTER_COPY_CLOSE_HPP
#define __INTER_COPY_CLOSE_HPP

// Complected

/*
	Уточнить куда же его пихать - в интерфейсы или в... Хм. Куда?
	По сути, это не интерфейс.
	Мой не велосипед, а аналог boost::noncopyable и sf::NonCopyable.
*/

namespace interfaces
{

class ICopyClose
{
public:
	ICopyClose() = default;
	virtual ~ICopyClose() = 0;

private:
	ICopyClose(const ICopyClose& _iCopyClose) = delete;
	ICopyClose& operator =(const ICopyClose& _iCopyClose) = delete;
};

} // namespace Interfaces

#endif /* __INTER_COPY_CLOSE_HPP */
