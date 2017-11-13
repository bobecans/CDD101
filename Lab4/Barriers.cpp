/*!  \Author: Robert Scully
     \created: 25-10-17
     \license: GNU GENERAL PUBLIC LICENSE
     \Update: 13-11-17
 */

#include "Barriers.h"
/*! \class Barriers
    \brief A Barriers Implementation

   Uses C++11 features such as mutex and condition variables to implement Barriers

*/

void Barriers::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}


void Barriers::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
