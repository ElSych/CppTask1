#include <iostream>
using namespace std;
template <typename T>
class smart_pointer {
    T *m_obj;
public:
    smart_pointer(T *obj): m_obj(obj){ }
    ~smart_pointer() {
        delete m_obj;
    }
    T* operator->() {
    	 return m_obj;
    }
    T& operator* () {
    	 return *m_obj;
    }
};
