/*!  \Author: Robert Scully
     \created: 25-10-17
     \license: GNU GENERAL PUBLIC LICENSE
     \Update: 13-11-17
 */

#include <mutex>
#include <condition_variable>
/*! \class Barriers
    \brief A Barriers Implementation

   Uses C++11 features such as mutex and condition variables to implement Barriers

*/
class Barriers
{
private:
    unsigned int m_uiCount; /*!< Holds the Barriers count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Barriers(unsigned int uiCount=0)
          : m_uiCount(uiCount) { };
    void Wait();
    void Signal();

};
