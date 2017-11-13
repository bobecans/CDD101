/*!  \Author: Robert Scully
     \created: 3-10-17
     \license: GNU GENERAL PUBLIC LICENSE
     \Update: 13-11-17
 */
#include <mutex>
#include <condition_variable>
/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/
class Semaphore
{
	private:
	    int m_uiCount; /*!< Holds the Semaphore count */
	    std::mutex m_mutex;
	    std::condition_variable m_condition;

	public:
	    Semaphore(unsigned int uiCount=0)
		  : m_uiCount(uiCount) { };
	    void Wait();
	    void Signal();
};
