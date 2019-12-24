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
	~ICopyClose() = default;

private:
	ICopyClose(const ICopyClose& iCopyClose) = delete;
	ICopyClose& operator =(const ICopyClose& iCopyClose) = delete;
};

} // namespace Interfaces

#endif /* __INTER_COPY_CLOSE_HPP */
